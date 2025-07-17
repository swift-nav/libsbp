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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCellModemStatus.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.piksi.MsgCellModemStatus;


public class auto_check_sbp_piksi_MsgCellModemStatusTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgCellModemStatusTest.test1");
        byte[] payload = new byte[] {(byte)103,(byte)205,(byte)48,(byte)6,(byte)70,(byte)123,(byte)242,(byte)46,(byte)52,(byte)64,(byte)176,(byte)154,(byte)98,(byte)43,(byte)132,(byte)196,(byte)89,(byte)253,(byte)161,(byte)250,(byte)174,(byte)204,(byte)110,(byte)47,(byte)38,(byte)187,(byte)63,(byte)102,(byte)177,(byte)162,(byte)49,(byte)80,(byte)194,(byte)37,(byte)107,(byte)60,(byte)225,(byte)52,(byte)101,(byte)178,(byte)142,(byte)246,(byte)21,(byte)17,(byte)93,(byte)75,(byte)169,(byte)86,(byte)16,(byte)209,(byte)80,(byte)243,(byte)30,(byte)206,(byte)220,(byte)206,(byte)115,(byte)47,(byte)154,(byte)91,(byte)227,(byte)88,(byte)11,(byte)1,(byte)85,(byte)146,(byte)100,(byte)190,(byte)232,(byte)207,(byte)61,(byte)61,(byte)201,(byte)220,(byte)31,(byte)78,(byte)34,(byte)57,(byte)82,(byte)59,(byte)104,(byte)65,(byte)221,(byte)0,(byte)43,(byte)210,(byte)9,(byte)32,(byte)122,(byte)29,(byte)237,(byte)11,(byte)151,(byte)223,(byte)18,(byte)81,(byte)204,(byte)172,(byte)234,(byte)127,(byte)3,(byte)82,(byte)133,(byte)169,(byte)12,(byte)176,(byte)193,(byte)0,(byte)24,(byte)121,(byte)85,(byte)55,(byte)214,(byte)198,(byte)75,(byte)234,(byte)179,(byte)214,(byte)85,(byte)94,(byte)115,(byte)21,(byte)73,(byte)121,(byte)75,(byte)46,(byte)158,(byte)63,(byte)100,(byte)122,(byte)213,(byte)20,(byte)85,(byte)212,(byte)131,(byte)50,(byte)224,(byte)218,(byte)215,(byte)215,(byte)149,(byte)2,(byte)19,(byte)129,(byte)39,(byte)164,(byte)5,(byte)175,(byte)6,(byte)62,(byte)51,(byte)78,(byte)66,(byte)248,(byte)116,(byte)88,(byte)90,(byte)128,(byte)226,(byte)177,(byte)0,(byte)47,(byte)140,(byte)33,(byte)126,(byte)221,(byte)110,(byte)144,(byte)97,(byte)74,(byte)250,(byte)181,(byte)199,(byte)27,(byte)176,(byte)65,(byte)185,(byte)110,(byte)92,(byte)34,(byte)44,(byte)131,(byte)96,(byte)178,(byte)40,(byte)176,(byte)4,(byte)90,(byte)36,(byte)7,(byte)180,(byte)244,(byte)244,(byte)23,(byte)108,(byte)171,(byte)204,(byte)196,(byte)61,(byte)51,(byte)179,(byte)242,(byte)156,(byte)81,(byte)83,(byte)16,(byte)15,(byte)134,(byte)40,(byte)245,(byte)253,(byte)150,(byte)94,(byte)150,(byte)144,(byte)197,(byte)113,(byte)5,(byte)141,(byte)232,(byte)33,(byte)101,(byte)231,(byte)38,(byte)75,(byte)178,(byte)243,(byte)119,(byte)1,(byte)248,(byte)218,(byte)86,(byte)7,(byte)88,(byte)197,(byte)148,(byte)240,(byte)227,(byte)2,(byte)65,(byte)173,(byte)122,(byte)143,(byte)251,(byte)156,(byte)217,(byte)67,(byte)239,(byte)219,(byte)31,(byte)224,(byte)176,(byte)129,(byte)81,(byte)80, };
        SBPMessage sbp = new SBPMessage( 0x1b13, 0xbe, payload );
        MsgCellModemStatus msg = new MsgCellModemStatus( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.reserved[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[0] + "' != '" + 123 + "'", value.equals(BigInteger.valueOf( 123L ) ) );
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[1] + "' != '" + 242 + "'", value.equals(BigInteger.valueOf( 242L ) ) );
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[2] + "' != '" + 46 + "'", value.equals(BigInteger.valueOf( 46L ) ) );
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[3] + "' != '" + 52 + "'", value.equals(BigInteger.valueOf( 52L ) ) );
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[4] + "' != '" + 64 + "'", value.equals(BigInteger.valueOf( 64L ) ) );
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[5] + "' != '" + 176 + "'", value.equals(BigInteger.valueOf( 176L ) ) );
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[6] + "' != '" + 154 + "'", value.equals(BigInteger.valueOf( 154L ) ) );
        } else {
            value = value.longValue();
            expected = 154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[7] + "' != '" + 98 + "'", value.equals(BigInteger.valueOf( 98L ) ) );
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[8] + "' != '" + 43 + "'", value.equals(BigInteger.valueOf( 43L ) ) );
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[9] + "' != '" + 132 + "'", value.equals(BigInteger.valueOf( 132L ) ) );
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[10] + "' != '" + 196 + "'", value.equals(BigInteger.valueOf( 196L ) ) );
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[11] + "' != '" + 89 + "'", value.equals(BigInteger.valueOf( 89L ) ) );
        } else {
            value = value.longValue();
            expected = 89L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[12] + "' != '" + 253 + "'", value.equals(BigInteger.valueOf( 253L ) ) );
        } else {
            value = value.longValue();
            expected = 253L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[13] + "' != '" + 161 + "'", value.equals(BigInteger.valueOf( 161L ) ) );
        } else {
            value = value.longValue();
            expected = 161L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[14] + "' != '" + 250 + "'", value.equals(BigInteger.valueOf( 250L ) ) );
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[15] + "' != '" + 174 + "'", value.equals(BigInteger.valueOf( 174L ) ) );
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[16] + "' != '" + 204 + "'", value.equals(BigInteger.valueOf( 204L ) ) );
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[17] + "' != '" + 110 + "'", value.equals(BigInteger.valueOf( 110L ) ) );
        } else {
            value = value.longValue();
            expected = 110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[18] + "' != '" + 47 + "'", value.equals(BigInteger.valueOf( 47L ) ) );
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[19] + "' != '" + 38 + "'", value.equals(BigInteger.valueOf( 38L ) ) );
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[20] + "' != '" + 187 + "'", value.equals(BigInteger.valueOf( 187L ) ) );
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[21];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[21] + "' != '" + 63 + "'", value.equals(BigInteger.valueOf( 63L ) ) );
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[22];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[22] + "' != '" + 102 + "'", value.equals(BigInteger.valueOf( 102L ) ) );
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[23];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[23] + "' != '" + 177 + "'", value.equals(BigInteger.valueOf( 177L ) ) );
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[24];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[24] + "' != '" + 162 + "'", value.equals(BigInteger.valueOf( 162L ) ) );
        } else {
            value = value.longValue();
            expected = 162L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[25];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[25] + "' != '" + 49 + "'", value.equals(BigInteger.valueOf( 49L ) ) );
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[26];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[26] + "' != '" + 80 + "'", value.equals(BigInteger.valueOf( 80L ) ) );
        } else {
            value = value.longValue();
            expected = 80L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[27];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[27] + "' != '" + 194 + "'", value.equals(BigInteger.valueOf( 194L ) ) );
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[28];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[28] + "' != '" + 37 + "'", value.equals(BigInteger.valueOf( 37L ) ) );
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[29];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[29] + "' != '" + 107 + "'", value.equals(BigInteger.valueOf( 107L ) ) );
        } else {
            value = value.longValue();
            expected = 107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[30];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[30] + "' != '" + 60 + "'", value.equals(BigInteger.valueOf( 60L ) ) );
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[31];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[31] + "' != '" + 225 + "'", value.equals(BigInteger.valueOf( 225L ) ) );
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[32];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[32] + "' != '" + 52 + "'", value.equals(BigInteger.valueOf( 52L ) ) );
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[33];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[33] + "' != '" + 101 + "'", value.equals(BigInteger.valueOf( 101L ) ) );
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[34];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[34] + "' != '" + 178 + "'", value.equals(BigInteger.valueOf( 178L ) ) );
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[35];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[35] + "' != '" + 142 + "'", value.equals(BigInteger.valueOf( 142L ) ) );
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[36];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[36] + "' != '" + 246 + "'", value.equals(BigInteger.valueOf( 246L ) ) );
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[37];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[37] + "' != '" + 21 + "'", value.equals(BigInteger.valueOf( 21L ) ) );
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[38];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[38] + "' != '" + 17 + "'", value.equals(BigInteger.valueOf( 17L ) ) );
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[39];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[39] + "' != '" + 93 + "'", value.equals(BigInteger.valueOf( 93L ) ) );
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[40];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[40] + "' != '" + 75 + "'", value.equals(BigInteger.valueOf( 75L ) ) );
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[41];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[41] + "' != '" + 169 + "'", value.equals(BigInteger.valueOf( 169L ) ) );
        } else {
            value = value.longValue();
            expected = 169L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[42];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[42] + "' != '" + 86 + "'", value.equals(BigInteger.valueOf( 86L ) ) );
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[43];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[43] + "' != '" + 16 + "'", value.equals(BigInteger.valueOf( 16L ) ) );
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[44];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[44] + "' != '" + 209 + "'", value.equals(BigInteger.valueOf( 209L ) ) );
        } else {
            value = value.longValue();
            expected = 209L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[45];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[45] + "' != '" + 80 + "'", value.equals(BigInteger.valueOf( 80L ) ) );
        } else {
            value = value.longValue();
            expected = 80L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[46];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[46] + "' != '" + 243 + "'", value.equals(BigInteger.valueOf( 243L ) ) );
        } else {
            value = value.longValue();
            expected = 243L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[47];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[47] + "' != '" + 30 + "'", value.equals(BigInteger.valueOf( 30L ) ) );
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[48];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[48] + "' != '" + 206 + "'", value.equals(BigInteger.valueOf( 206L ) ) );
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[49];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[49] + "' != '" + 220 + "'", value.equals(BigInteger.valueOf( 220L ) ) );
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[50];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[50] + "' != '" + 206 + "'", value.equals(BigInteger.valueOf( 206L ) ) );
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[51];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[51] + "' != '" + 115 + "'", value.equals(BigInteger.valueOf( 115L ) ) );
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[52];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[52] + "' != '" + 47 + "'", value.equals(BigInteger.valueOf( 47L ) ) );
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[53];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[53] + "' != '" + 154 + "'", value.equals(BigInteger.valueOf( 154L ) ) );
        } else {
            value = value.longValue();
            expected = 154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[54];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[54] + "' != '" + 91 + "'", value.equals(BigInteger.valueOf( 91L ) ) );
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[55];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[55] + "' != '" + 227 + "'", value.equals(BigInteger.valueOf( 227L ) ) );
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[56];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[56] + "' != '" + 88 + "'", value.equals(BigInteger.valueOf( 88L ) ) );
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[57];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[57] + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[58];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[58] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[59];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[59] + "' != '" + 85 + "'", value.equals(BigInteger.valueOf( 85L ) ) );
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[60];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[60] + "' != '" + 146 + "'", value.equals(BigInteger.valueOf( 146L ) ) );
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[61];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[61] + "' != '" + 100 + "'", value.equals(BigInteger.valueOf( 100L ) ) );
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[62];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[62] + "' != '" + 190 + "'", value.equals(BigInteger.valueOf( 190L ) ) );
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[63];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[63] + "' != '" + 232 + "'", value.equals(BigInteger.valueOf( 232L ) ) );
        } else {
            value = value.longValue();
            expected = 232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[64];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[64] + "' != '" + 207 + "'", value.equals(BigInteger.valueOf( 207L ) ) );
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[65];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[65] + "' != '" + 61 + "'", value.equals(BigInteger.valueOf( 61L ) ) );
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[66];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[66] + "' != '" + 61 + "'", value.equals(BigInteger.valueOf( 61L ) ) );
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[67];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[67] + "' != '" + 201 + "'", value.equals(BigInteger.valueOf( 201L ) ) );
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[68];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[68] + "' != '" + 220 + "'", value.equals(BigInteger.valueOf( 220L ) ) );
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[69];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[69] + "' != '" + 31 + "'", value.equals(BigInteger.valueOf( 31L ) ) );
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[70];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[70] + "' != '" + 78 + "'", value.equals(BigInteger.valueOf( 78L ) ) );
        } else {
            value = value.longValue();
            expected = 78L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[71];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[71] + "' != '" + 34 + "'", value.equals(BigInteger.valueOf( 34L ) ) );
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[72];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[72] + "' != '" + 57 + "'", value.equals(BigInteger.valueOf( 57L ) ) );
        } else {
            value = value.longValue();
            expected = 57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[73];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[73] + "' != '" + 82 + "'", value.equals(BigInteger.valueOf( 82L ) ) );
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[74];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[74] + "' != '" + 59 + "'", value.equals(BigInteger.valueOf( 59L ) ) );
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[75];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[75] + "' != '" + 104 + "'", value.equals(BigInteger.valueOf( 104L ) ) );
        } else {
            value = value.longValue();
            expected = 104L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[76];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[76] + "' != '" + 65 + "'", value.equals(BigInteger.valueOf( 65L ) ) );
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[77];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[77] + "' != '" + 221 + "'", value.equals(BigInteger.valueOf( 221L ) ) );
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[78];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[78] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[79];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[79] + "' != '" + 43 + "'", value.equals(BigInteger.valueOf( 43L ) ) );
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[80];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[80] + "' != '" + 210 + "'", value.equals(BigInteger.valueOf( 210L ) ) );
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[81];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[81] + "' != '" + 9 + "'", value.equals(BigInteger.valueOf( 9L ) ) );
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[82];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[82] + "' != '" + 32 + "'", value.equals(BigInteger.valueOf( 32L ) ) );
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[83];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[83] + "' != '" + 122 + "'", value.equals(BigInteger.valueOf( 122L ) ) );
        } else {
            value = value.longValue();
            expected = 122L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[84];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[84] + "' != '" + 29 + "'", value.equals(BigInteger.valueOf( 29L ) ) );
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[85];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[85] + "' != '" + 237 + "'", value.equals(BigInteger.valueOf( 237L ) ) );
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[86];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[86] + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[87];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[87] + "' != '" + 151 + "'", value.equals(BigInteger.valueOf( 151L ) ) );
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[88];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[88] + "' != '" + 223 + "'", value.equals(BigInteger.valueOf( 223L ) ) );
        } else {
            value = value.longValue();
            expected = 223L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[89];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[89] + "' != '" + 18 + "'", value.equals(BigInteger.valueOf( 18L ) ) );
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[90];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[90] + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[91];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[91] + "' != '" + 204 + "'", value.equals(BigInteger.valueOf( 204L ) ) );
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[92];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[92] + "' != '" + 172 + "'", value.equals(BigInteger.valueOf( 172L ) ) );
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[93];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[93] + "' != '" + 234 + "'", value.equals(BigInteger.valueOf( 234L ) ) );
        } else {
            value = value.longValue();
            expected = 234L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[94];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[94] + "' != '" + 127 + "'", value.equals(BigInteger.valueOf( 127L ) ) );
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[95];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[95] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[96];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[96] + "' != '" + 82 + "'", value.equals(BigInteger.valueOf( 82L ) ) );
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[97];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[97] + "' != '" + 133 + "'", value.equals(BigInteger.valueOf( 133L ) ) );
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[98];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[98] + "' != '" + 169 + "'", value.equals(BigInteger.valueOf( 169L ) ) );
        } else {
            value = value.longValue();
            expected = 169L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[99];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[99] + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[100];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[100] + "' != '" + 176 + "'", value.equals(BigInteger.valueOf( 176L ) ) );
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[101];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[101] + "' != '" + 193 + "'", value.equals(BigInteger.valueOf( 193L ) ) );
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[102];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[102] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[103];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[103] + "' != '" + 24 + "'", value.equals(BigInteger.valueOf( 24L ) ) );
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[104];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[104] + "' != '" + 121 + "'", value.equals(BigInteger.valueOf( 121L ) ) );
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[105];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[105] + "' != '" + 85 + "'", value.equals(BigInteger.valueOf( 85L ) ) );
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[106];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[106] + "' != '" + 55 + "'", value.equals(BigInteger.valueOf( 55L ) ) );
        } else {
            value = value.longValue();
            expected = 55L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[107];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[107] + "' != '" + 214 + "'", value.equals(BigInteger.valueOf( 214L ) ) );
        } else {
            value = value.longValue();
            expected = 214L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[108];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[108] + "' != '" + 198 + "'", value.equals(BigInteger.valueOf( 198L ) ) );
        } else {
            value = value.longValue();
            expected = 198L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[109];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[109] + "' != '" + 75 + "'", value.equals(BigInteger.valueOf( 75L ) ) );
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[110];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[110] + "' != '" + 234 + "'", value.equals(BigInteger.valueOf( 234L ) ) );
        } else {
            value = value.longValue();
            expected = 234L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[111];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[111] + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[112];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[112] + "' != '" + 214 + "'", value.equals(BigInteger.valueOf( 214L ) ) );
        } else {
            value = value.longValue();
            expected = 214L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[113];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[113] + "' != '" + 85 + "'", value.equals(BigInteger.valueOf( 85L ) ) );
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[114];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[114] + "' != '" + 94 + "'", value.equals(BigInteger.valueOf( 94L ) ) );
        } else {
            value = value.longValue();
            expected = 94L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[115];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[115] + "' != '" + 115 + "'", value.equals(BigInteger.valueOf( 115L ) ) );
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[116];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[116] + "' != '" + 21 + "'", value.equals(BigInteger.valueOf( 21L ) ) );
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[117];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[117] + "' != '" + 73 + "'", value.equals(BigInteger.valueOf( 73L ) ) );
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[118];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[118] + "' != '" + 121 + "'", value.equals(BigInteger.valueOf( 121L ) ) );
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[119];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[119] + "' != '" + 75 + "'", value.equals(BigInteger.valueOf( 75L ) ) );
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[120];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[120] + "' != '" + 46 + "'", value.equals(BigInteger.valueOf( 46L ) ) );
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[121];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[121] + "' != '" + 158 + "'", value.equals(BigInteger.valueOf( 158L ) ) );
        } else {
            value = value.longValue();
            expected = 158L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[122];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[122] + "' != '" + 63 + "'", value.equals(BigInteger.valueOf( 63L ) ) );
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[123];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[123] + "' != '" + 100 + "'", value.equals(BigInteger.valueOf( 100L ) ) );
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[124];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[124] + "' != '" + 122 + "'", value.equals(BigInteger.valueOf( 122L ) ) );
        } else {
            value = value.longValue();
            expected = 122L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[125];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[125] + "' != '" + 213 + "'", value.equals(BigInteger.valueOf( 213L ) ) );
        } else {
            value = value.longValue();
            expected = 213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[126];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[126] + "' != '" + 20 + "'", value.equals(BigInteger.valueOf( 20L ) ) );
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[127];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[127] + "' != '" + 85 + "'", value.equals(BigInteger.valueOf( 85L ) ) );
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[128];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[128] + "' != '" + 212 + "'", value.equals(BigInteger.valueOf( 212L ) ) );
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[129];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[129] + "' != '" + 131 + "'", value.equals(BigInteger.valueOf( 131L ) ) );
        } else {
            value = value.longValue();
            expected = 131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[130];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[130] + "' != '" + 50 + "'", value.equals(BigInteger.valueOf( 50L ) ) );
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[131];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[131] + "' != '" + 224 + "'", value.equals(BigInteger.valueOf( 224L ) ) );
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[132];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[132] + "' != '" + 218 + "'", value.equals(BigInteger.valueOf( 218L ) ) );
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[133];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[133] + "' != '" + 215 + "'", value.equals(BigInteger.valueOf( 215L ) ) );
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[134];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[134] + "' != '" + 215 + "'", value.equals(BigInteger.valueOf( 215L ) ) );
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[135];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[135] + "' != '" + 149 + "'", value.equals(BigInteger.valueOf( 149L ) ) );
        } else {
            value = value.longValue();
            expected = 149L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[136];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[136] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[137];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[137] + "' != '" + 19 + "'", value.equals(BigInteger.valueOf( 19L ) ) );
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[138];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[138] + "' != '" + 129 + "'", value.equals(BigInteger.valueOf( 129L ) ) );
        } else {
            value = value.longValue();
            expected = 129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[139];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[139] + "' != '" + 39 + "'", value.equals(BigInteger.valueOf( 39L ) ) );
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[140];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[140] + "' != '" + 164 + "'", value.equals(BigInteger.valueOf( 164L ) ) );
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[141];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[141] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[142];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[142] + "' != '" + 175 + "'", value.equals(BigInteger.valueOf( 175L ) ) );
        } else {
            value = value.longValue();
            expected = 175L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[143];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[143] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[144];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[144] + "' != '" + 62 + "'", value.equals(BigInteger.valueOf( 62L ) ) );
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[145];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[145] + "' != '" + 51 + "'", value.equals(BigInteger.valueOf( 51L ) ) );
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[146];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[146] + "' != '" + 78 + "'", value.equals(BigInteger.valueOf( 78L ) ) );
        } else {
            value = value.longValue();
            expected = 78L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[147];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[147] + "' != '" + 66 + "'", value.equals(BigInteger.valueOf( 66L ) ) );
        } else {
            value = value.longValue();
            expected = 66L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[148];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[148] + "' != '" + 248 + "'", value.equals(BigInteger.valueOf( 248L ) ) );
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[149];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[149] + "' != '" + 116 + "'", value.equals(BigInteger.valueOf( 116L ) ) );
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[150];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[150] + "' != '" + 88 + "'", value.equals(BigInteger.valueOf( 88L ) ) );
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[151];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[151] + "' != '" + 90 + "'", value.equals(BigInteger.valueOf( 90L ) ) );
        } else {
            value = value.longValue();
            expected = 90L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[152];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[152] + "' != '" + 128 + "'", value.equals(BigInteger.valueOf( 128L ) ) );
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[153];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[153] + "' != '" + 226 + "'", value.equals(BigInteger.valueOf( 226L ) ) );
        } else {
            value = value.longValue();
            expected = 226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[154];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[154] + "' != '" + 177 + "'", value.equals(BigInteger.valueOf( 177L ) ) );
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[155];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[155] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[156];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[156] + "' != '" + 47 + "'", value.equals(BigInteger.valueOf( 47L ) ) );
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[157];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[157] + "' != '" + 140 + "'", value.equals(BigInteger.valueOf( 140L ) ) );
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[158];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[158] + "' != '" + 33 + "'", value.equals(BigInteger.valueOf( 33L ) ) );
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[159];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[159] + "' != '" + 126 + "'", value.equals(BigInteger.valueOf( 126L ) ) );
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[160];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[160] + "' != '" + 221 + "'", value.equals(BigInteger.valueOf( 221L ) ) );
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[161];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[161] + "' != '" + 110 + "'", value.equals(BigInteger.valueOf( 110L ) ) );
        } else {
            value = value.longValue();
            expected = 110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[162];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[162] + "' != '" + 144 + "'", value.equals(BigInteger.valueOf( 144L ) ) );
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[163];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[163] + "' != '" + 97 + "'", value.equals(BigInteger.valueOf( 97L ) ) );
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[164];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[164] + "' != '" + 74 + "'", value.equals(BigInteger.valueOf( 74L ) ) );
        } else {
            value = value.longValue();
            expected = 74L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[165];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[165] + "' != '" + 250 + "'", value.equals(BigInteger.valueOf( 250L ) ) );
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[166];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[166] + "' != '" + 181 + "'", value.equals(BigInteger.valueOf( 181L ) ) );
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[167];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[167] + "' != '" + 199 + "'", value.equals(BigInteger.valueOf( 199L ) ) );
        } else {
            value = value.longValue();
            expected = 199L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[168];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[168] + "' != '" + 27 + "'", value.equals(BigInteger.valueOf( 27L ) ) );
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[169];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[169] + "' != '" + 176 + "'", value.equals(BigInteger.valueOf( 176L ) ) );
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[170];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[170] + "' != '" + 65 + "'", value.equals(BigInteger.valueOf( 65L ) ) );
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[171];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[171] + "' != '" + 185 + "'", value.equals(BigInteger.valueOf( 185L ) ) );
        } else {
            value = value.longValue();
            expected = 185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[172];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[172] + "' != '" + 110 + "'", value.equals(BigInteger.valueOf( 110L ) ) );
        } else {
            value = value.longValue();
            expected = 110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[173];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[173] + "' != '" + 92 + "'", value.equals(BigInteger.valueOf( 92L ) ) );
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[174];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[174] + "' != '" + 34 + "'", value.equals(BigInteger.valueOf( 34L ) ) );
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[175];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[175] + "' != '" + 44 + "'", value.equals(BigInteger.valueOf( 44L ) ) );
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[176];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[176] + "' != '" + 131 + "'", value.equals(BigInteger.valueOf( 131L ) ) );
        } else {
            value = value.longValue();
            expected = 131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[177];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[177] + "' != '" + 96 + "'", value.equals(BigInteger.valueOf( 96L ) ) );
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[178];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[178] + "' != '" + 178 + "'", value.equals(BigInteger.valueOf( 178L ) ) );
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[179];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[179] + "' != '" + 40 + "'", value.equals(BigInteger.valueOf( 40L ) ) );
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[180];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[180] + "' != '" + 176 + "'", value.equals(BigInteger.valueOf( 176L ) ) );
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[181];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[181] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[182];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[182] + "' != '" + 90 + "'", value.equals(BigInteger.valueOf( 90L ) ) );
        } else {
            value = value.longValue();
            expected = 90L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[183];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[183] + "' != '" + 36 + "'", value.equals(BigInteger.valueOf( 36L ) ) );
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[184];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[184] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[185];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[185] + "' != '" + 180 + "'", value.equals(BigInteger.valueOf( 180L ) ) );
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[186];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[186] + "' != '" + 244 + "'", value.equals(BigInteger.valueOf( 244L ) ) );
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[187];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[187] + "' != '" + 244 + "'", value.equals(BigInteger.valueOf( 244L ) ) );
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[188];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[188] + "' != '" + 23 + "'", value.equals(BigInteger.valueOf( 23L ) ) );
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[189];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[189] + "' != '" + 108 + "'", value.equals(BigInteger.valueOf( 108L ) ) );
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[190];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[190] + "' != '" + 171 + "'", value.equals(BigInteger.valueOf( 171L ) ) );
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[191];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[191] + "' != '" + 204 + "'", value.equals(BigInteger.valueOf( 204L ) ) );
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[192];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[192] + "' != '" + 196 + "'", value.equals(BigInteger.valueOf( 196L ) ) );
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[193];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[193] + "' != '" + 61 + "'", value.equals(BigInteger.valueOf( 61L ) ) );
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[194];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[194] + "' != '" + 51 + "'", value.equals(BigInteger.valueOf( 51L ) ) );
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[195];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[195] + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[196];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[196] + "' != '" + 242 + "'", value.equals(BigInteger.valueOf( 242L ) ) );
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[197];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[197] + "' != '" + 156 + "'", value.equals(BigInteger.valueOf( 156L ) ) );
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[198];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[198] + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[199];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[199] + "' != '" + 83 + "'", value.equals(BigInteger.valueOf( 83L ) ) );
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[200];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[200] + "' != '" + 16 + "'", value.equals(BigInteger.valueOf( 16L ) ) );
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[201];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[201] + "' != '" + 15 + "'", value.equals(BigInteger.valueOf( 15L ) ) );
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[202];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[202] + "' != '" + 134 + "'", value.equals(BigInteger.valueOf( 134L ) ) );
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[203];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[203] + "' != '" + 40 + "'", value.equals(BigInteger.valueOf( 40L ) ) );
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[204];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[204] + "' != '" + 245 + "'", value.equals(BigInteger.valueOf( 245L ) ) );
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[205];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[205] + "' != '" + 253 + "'", value.equals(BigInteger.valueOf( 253L ) ) );
        } else {
            value = value.longValue();
            expected = 253L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[206];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[206] + "' != '" + 150 + "'", value.equals(BigInteger.valueOf( 150L ) ) );
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[207];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[207] + "' != '" + 94 + "'", value.equals(BigInteger.valueOf( 94L ) ) );
        } else {
            value = value.longValue();
            expected = 94L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[208];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[208] + "' != '" + 150 + "'", value.equals(BigInteger.valueOf( 150L ) ) );
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[209];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[209] + "' != '" + 144 + "'", value.equals(BigInteger.valueOf( 144L ) ) );
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[210];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[210] + "' != '" + 197 + "'", value.equals(BigInteger.valueOf( 197L ) ) );
        } else {
            value = value.longValue();
            expected = 197L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[211];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[211] + "' != '" + 113 + "'", value.equals(BigInteger.valueOf( 113L ) ) );
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[212];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[212] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[213];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[213] + "' != '" + 141 + "'", value.equals(BigInteger.valueOf( 141L ) ) );
        } else {
            value = value.longValue();
            expected = 141L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[214];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[214] + "' != '" + 232 + "'", value.equals(BigInteger.valueOf( 232L ) ) );
        } else {
            value = value.longValue();
            expected = 232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[215];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[215] + "' != '" + 33 + "'", value.equals(BigInteger.valueOf( 33L ) ) );
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[216];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[216] + "' != '" + 101 + "'", value.equals(BigInteger.valueOf( 101L ) ) );
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[217];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[217] + "' != '" + 231 + "'", value.equals(BigInteger.valueOf( 231L ) ) );
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[218];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[218] + "' != '" + 38 + "'", value.equals(BigInteger.valueOf( 38L ) ) );
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[219];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[219] + "' != '" + 75 + "'", value.equals(BigInteger.valueOf( 75L ) ) );
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[220];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[220] + "' != '" + 178 + "'", value.equals(BigInteger.valueOf( 178L ) ) );
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[221];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[221] + "' != '" + 243 + "'", value.equals(BigInteger.valueOf( 243L ) ) );
        } else {
            value = value.longValue();
            expected = 243L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[222];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[222] + "' != '" + 119 + "'", value.equals(BigInteger.valueOf( 119L ) ) );
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[223];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[223] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[224];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[224] + "' != '" + 248 + "'", value.equals(BigInteger.valueOf( 248L ) ) );
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[225];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[225] + "' != '" + 218 + "'", value.equals(BigInteger.valueOf( 218L ) ) );
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[226];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[226] + "' != '" + 86 + "'", value.equals(BigInteger.valueOf( 86L ) ) );
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[227];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[227] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[228];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[228] + "' != '" + 88 + "'", value.equals(BigInteger.valueOf( 88L ) ) );
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[229];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[229] + "' != '" + 197 + "'", value.equals(BigInteger.valueOf( 197L ) ) );
        } else {
            value = value.longValue();
            expected = 197L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[230];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[230] + "' != '" + 148 + "'", value.equals(BigInteger.valueOf( 148L ) ) );
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[231];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[231] + "' != '" + 240 + "'", value.equals(BigInteger.valueOf( 240L ) ) );
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[232];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[232] + "' != '" + 227 + "'", value.equals(BigInteger.valueOf( 227L ) ) );
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[233];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[233] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[234];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[234] + "' != '" + 65 + "'", value.equals(BigInteger.valueOf( 65L ) ) );
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[235];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[235] + "' != '" + 173 + "'", value.equals(BigInteger.valueOf( 173L ) ) );
        } else {
            value = value.longValue();
            expected = 173L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[236];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[236] + "' != '" + 122 + "'", value.equals(BigInteger.valueOf( 122L ) ) );
        } else {
            value = value.longValue();
            expected = 122L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[237];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[237] + "' != '" + 143 + "'", value.equals(BigInteger.valueOf( 143L ) ) );
        } else {
            value = value.longValue();
            expected = 143L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[238];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[238] + "' != '" + 251 + "'", value.equals(BigInteger.valueOf( 251L ) ) );
        } else {
            value = value.longValue();
            expected = 251L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[239];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[239] + "' != '" + 156 + "'", value.equals(BigInteger.valueOf( 156L ) ) );
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[240];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[240] + "' != '" + 217 + "'", value.equals(BigInteger.valueOf( 217L ) ) );
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[241];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[241] + "' != '" + 67 + "'", value.equals(BigInteger.valueOf( 67L ) ) );
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[242];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[242] + "' != '" + 239 + "'", value.equals(BigInteger.valueOf( 239L ) ) );
        } else {
            value = value.longValue();
            expected = 239L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[243];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[243] + "' != '" + 219 + "'", value.equals(BigInteger.valueOf( 219L ) ) );
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[244];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[244] + "' != '" + 31 + "'", value.equals(BigInteger.valueOf( 31L ) ) );
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[245];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[245] + "' != '" + 224 + "'", value.equals(BigInteger.valueOf( 224L ) ) );
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[246];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[246] + "' != '" + 176 + "'", value.equals(BigInteger.valueOf( 176L ) ) );
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[247];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[247] + "' != '" + 129 + "'", value.equals(BigInteger.valueOf( 129L ) ) );
        } else {
            value = value.longValue();
            expected = 129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[248];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[248] + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[249];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reserved[249] + "' != '" + 80 + "'", value.equals(BigInteger.valueOf( 80L ) ) );
        } else {
            value = value.longValue();
            expected = 80L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.signal_error_rate, 8.58820019531250000e+03, DELTA);
        value = msg.signal_strength;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signal_strength + "' != '" + 103 + "'", value.equals(BigInteger.valueOf( 103L ) ) );
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
