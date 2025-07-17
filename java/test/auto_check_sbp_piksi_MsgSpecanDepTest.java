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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgSpecanDep.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.piksi.MsgSpecanDep;


public class auto_check_sbp_piksi_MsgSpecanDepTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgSpecanDepTest.test1");
        byte[] payload = new byte[] {(byte)246,(byte)22,(byte)221,(byte)56,(byte)37,(byte)59,(byte)45,(byte)27,(byte)154,(byte)97,(byte)198,(byte)69,(byte)154,(byte)1,(byte)144,(byte)69,(byte)205,(byte)20,(byte)18,(byte)70,(byte)51,(byte)211,(byte)89,(byte)69,(byte)240,(byte)14,(byte)179,(byte)186,(byte)227,(byte)244,(byte)173,(byte)240,(byte)182,(byte)71,(byte)166,(byte)117,(byte)196,(byte)13,(byte)44,(byte)27,(byte)33,(byte)28,(byte)67,(byte)254,(byte)3,(byte)249,(byte)92,(byte)44,(byte)122,(byte)169,(byte)77,(byte)186,(byte)68,(byte)135,(byte)63,(byte)168,(byte)162,(byte)89,(byte)36,(byte)186,(byte)99,(byte)63,(byte)105,(byte)116,(byte)216,(byte)44,(byte)67,(byte)212,(byte)156,(byte)75,(byte)81,(byte)53,(byte)250,(byte)225,(byte)23,(byte)205,(byte)26,(byte)34,(byte)119,(byte)50,(byte)101,(byte)64,(byte)7,(byte)231,(byte)124,(byte)183,(byte)203,(byte)102,(byte)234,(byte)84,(byte)83,(byte)208,(byte)23,(byte)68,(byte)54,(byte)179,(byte)98,(byte)96,(byte)116,(byte)244,(byte)246,(byte)94,(byte)104,(byte)94,(byte)13,(byte)56,(byte)210,(byte)18,(byte)191,(byte)22,(byte)133,(byte)81,(byte)153,(byte)159,(byte)161,(byte)219,(byte)59,(byte)21,(byte)164,(byte)121,(byte)145,(byte)203,(byte)171,(byte)132,(byte)57,(byte)180,(byte)102,(byte)101,(byte)11,(byte)229,(byte)175,(byte)145,(byte)73,(byte)72,(byte)124,(byte)4,(byte)184,(byte)228,(byte)61,(byte)234,(byte)218,(byte)62,(byte)226,(byte)217,(byte)193,(byte)7,(byte)109,(byte)44,(byte)83,(byte)201,(byte)20,(byte)101,(byte)9,(byte)140,(byte)186,(byte)162,(byte)81,(byte)91,(byte)30,(byte)231,(byte)161,(byte)81,(byte)216,(byte)114,(byte)60,(byte)231,(byte)163,(byte)163,(byte)49,(byte)237,(byte)244,(byte)185,(byte)240,(byte)89,(byte)143,(byte)174,(byte)165,(byte)211,(byte)241,(byte)13,(byte)16,(byte)61,(byte)141,(byte)101,(byte)89,(byte)37,(byte)117,(byte)189,(byte)86,(byte)118,(byte)176,(byte)228,(byte)12,(byte)14,(byte)119,(byte)135,(byte)129,(byte)243,(byte)50,(byte)29,(byte)207,(byte)198,(byte)117,(byte)100,(byte)225,(byte)6,(byte)139,(byte)110,(byte)39,(byte)210,(byte)68,(byte)199,(byte)43,(byte)132,(byte)64,(byte)17,(byte)51,(byte)173,(byte)181,(byte)12,(byte)140,(byte)16,(byte)247,(byte)84,(byte)183,(byte)105,(byte)39,(byte)157,(byte)77,(byte)30,(byte)205,(byte)194,(byte)59,(byte)64,(byte)241,(byte)183,(byte)238,(byte)105,(byte)181,(byte)170,(byte)45,(byte)8,(byte)166,(byte)164,(byte)238,(byte)83,(byte)148,(byte)173,(byte)108,(byte)228,(byte)67,(byte)89,(byte)189,(byte)67,(byte)26, };
        SBPMessage sbp = new SBPMessage( 0xd970, 0x50, payload );
        MsgSpecanDep msg = new MsgSpecanDep( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.amplitude_ref, 9.34920019531250000e+03, DELTA);
        org.junit.Assert.assertEquals(msg.amplitude_unit, 3.48519995117187500e+03, DELTA);
        value = msg.amplitude_value[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[0] + "' != '" + 240 + "'", value.equals(BigInteger.valueOf( 240L ) ) );
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[1] + "' != '" + 14 + "'", value.equals(BigInteger.valueOf( 14L ) ) );
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[2] + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[3] + "' != '" + 186 + "'", value.equals(BigInteger.valueOf( 186L ) ) );
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[4] + "' != '" + 227 + "'", value.equals(BigInteger.valueOf( 227L ) ) );
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[5] + "' != '" + 244 + "'", value.equals(BigInteger.valueOf( 244L ) ) );
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[6] + "' != '" + 173 + "'", value.equals(BigInteger.valueOf( 173L ) ) );
        } else {
            value = value.longValue();
            expected = 173L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[7] + "' != '" + 240 + "'", value.equals(BigInteger.valueOf( 240L ) ) );
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[8] + "' != '" + 182 + "'", value.equals(BigInteger.valueOf( 182L ) ) );
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[9] + "' != '" + 71 + "'", value.equals(BigInteger.valueOf( 71L ) ) );
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[10] + "' != '" + 166 + "'", value.equals(BigInteger.valueOf( 166L ) ) );
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[11] + "' != '" + 117 + "'", value.equals(BigInteger.valueOf( 117L ) ) );
        } else {
            value = value.longValue();
            expected = 117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[12] + "' != '" + 196 + "'", value.equals(BigInteger.valueOf( 196L ) ) );
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[13] + "' != '" + 13 + "'", value.equals(BigInteger.valueOf( 13L ) ) );
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[14] + "' != '" + 44 + "'", value.equals(BigInteger.valueOf( 44L ) ) );
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[15] + "' != '" + 27 + "'", value.equals(BigInteger.valueOf( 27L ) ) );
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[16] + "' != '" + 33 + "'", value.equals(BigInteger.valueOf( 33L ) ) );
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[17] + "' != '" + 28 + "'", value.equals(BigInteger.valueOf( 28L ) ) );
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[18] + "' != '" + 67 + "'", value.equals(BigInteger.valueOf( 67L ) ) );
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[19] + "' != '" + 254 + "'", value.equals(BigInteger.valueOf( 254L ) ) );
        } else {
            value = value.longValue();
            expected = 254L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[20] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[21];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[21] + "' != '" + 249 + "'", value.equals(BigInteger.valueOf( 249L ) ) );
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[22];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[22] + "' != '" + 92 + "'", value.equals(BigInteger.valueOf( 92L ) ) );
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[23];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[23] + "' != '" + 44 + "'", value.equals(BigInteger.valueOf( 44L ) ) );
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[24];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[24] + "' != '" + 122 + "'", value.equals(BigInteger.valueOf( 122L ) ) );
        } else {
            value = value.longValue();
            expected = 122L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[25];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[25] + "' != '" + 169 + "'", value.equals(BigInteger.valueOf( 169L ) ) );
        } else {
            value = value.longValue();
            expected = 169L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[26];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[26] + "' != '" + 77 + "'", value.equals(BigInteger.valueOf( 77L ) ) );
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[27];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[27] + "' != '" + 186 + "'", value.equals(BigInteger.valueOf( 186L ) ) );
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[28];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[28] + "' != '" + 68 + "'", value.equals(BigInteger.valueOf( 68L ) ) );
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[29];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[29] + "' != '" + 135 + "'", value.equals(BigInteger.valueOf( 135L ) ) );
        } else {
            value = value.longValue();
            expected = 135L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[30];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[30] + "' != '" + 63 + "'", value.equals(BigInteger.valueOf( 63L ) ) );
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[31];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[31] + "' != '" + 168 + "'", value.equals(BigInteger.valueOf( 168L ) ) );
        } else {
            value = value.longValue();
            expected = 168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[32];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[32] + "' != '" + 162 + "'", value.equals(BigInteger.valueOf( 162L ) ) );
        } else {
            value = value.longValue();
            expected = 162L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[33];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[33] + "' != '" + 89 + "'", value.equals(BigInteger.valueOf( 89L ) ) );
        } else {
            value = value.longValue();
            expected = 89L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[34];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[34] + "' != '" + 36 + "'", value.equals(BigInteger.valueOf( 36L ) ) );
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[35];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[35] + "' != '" + 186 + "'", value.equals(BigInteger.valueOf( 186L ) ) );
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[36];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[36] + "' != '" + 99 + "'", value.equals(BigInteger.valueOf( 99L ) ) );
        } else {
            value = value.longValue();
            expected = 99L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[37];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[37] + "' != '" + 63 + "'", value.equals(BigInteger.valueOf( 63L ) ) );
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[38];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[38] + "' != '" + 105 + "'", value.equals(BigInteger.valueOf( 105L ) ) );
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[39];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[39] + "' != '" + 116 + "'", value.equals(BigInteger.valueOf( 116L ) ) );
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[40];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[40] + "' != '" + 216 + "'", value.equals(BigInteger.valueOf( 216L ) ) );
        } else {
            value = value.longValue();
            expected = 216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[41];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[41] + "' != '" + 44 + "'", value.equals(BigInteger.valueOf( 44L ) ) );
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[42];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[42] + "' != '" + 67 + "'", value.equals(BigInteger.valueOf( 67L ) ) );
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[43];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[43] + "' != '" + 212 + "'", value.equals(BigInteger.valueOf( 212L ) ) );
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[44];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[44] + "' != '" + 156 + "'", value.equals(BigInteger.valueOf( 156L ) ) );
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[45];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[45] + "' != '" + 75 + "'", value.equals(BigInteger.valueOf( 75L ) ) );
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[46];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[46] + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[47];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[47] + "' != '" + 53 + "'", value.equals(BigInteger.valueOf( 53L ) ) );
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[48];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[48] + "' != '" + 250 + "'", value.equals(BigInteger.valueOf( 250L ) ) );
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[49];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[49] + "' != '" + 225 + "'", value.equals(BigInteger.valueOf( 225L ) ) );
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[50];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[50] + "' != '" + 23 + "'", value.equals(BigInteger.valueOf( 23L ) ) );
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[51];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[51] + "' != '" + 205 + "'", value.equals(BigInteger.valueOf( 205L ) ) );
        } else {
            value = value.longValue();
            expected = 205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[52];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[52] + "' != '" + 26 + "'", value.equals(BigInteger.valueOf( 26L ) ) );
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[53];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[53] + "' != '" + 34 + "'", value.equals(BigInteger.valueOf( 34L ) ) );
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[54];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[54] + "' != '" + 119 + "'", value.equals(BigInteger.valueOf( 119L ) ) );
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[55];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[55] + "' != '" + 50 + "'", value.equals(BigInteger.valueOf( 50L ) ) );
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[56];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[56] + "' != '" + 101 + "'", value.equals(BigInteger.valueOf( 101L ) ) );
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[57];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[57] + "' != '" + 64 + "'", value.equals(BigInteger.valueOf( 64L ) ) );
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[58];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[58] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[59];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[59] + "' != '" + 231 + "'", value.equals(BigInteger.valueOf( 231L ) ) );
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[60];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[60] + "' != '" + 124 + "'", value.equals(BigInteger.valueOf( 124L ) ) );
        } else {
            value = value.longValue();
            expected = 124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[61];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[61] + "' != '" + 183 + "'", value.equals(BigInteger.valueOf( 183L ) ) );
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[62];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[62] + "' != '" + 203 + "'", value.equals(BigInteger.valueOf( 203L ) ) );
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[63];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[63] + "' != '" + 102 + "'", value.equals(BigInteger.valueOf( 102L ) ) );
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[64];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[64] + "' != '" + 234 + "'", value.equals(BigInteger.valueOf( 234L ) ) );
        } else {
            value = value.longValue();
            expected = 234L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[65];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[65] + "' != '" + 84 + "'", value.equals(BigInteger.valueOf( 84L ) ) );
        } else {
            value = value.longValue();
            expected = 84L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[66];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[66] + "' != '" + 83 + "'", value.equals(BigInteger.valueOf( 83L ) ) );
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[67];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[67] + "' != '" + 208 + "'", value.equals(BigInteger.valueOf( 208L ) ) );
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[68];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[68] + "' != '" + 23 + "'", value.equals(BigInteger.valueOf( 23L ) ) );
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[69];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[69] + "' != '" + 68 + "'", value.equals(BigInteger.valueOf( 68L ) ) );
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[70];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[70] + "' != '" + 54 + "'", value.equals(BigInteger.valueOf( 54L ) ) );
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[71];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[71] + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[72];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[72] + "' != '" + 98 + "'", value.equals(BigInteger.valueOf( 98L ) ) );
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[73];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[73] + "' != '" + 96 + "'", value.equals(BigInteger.valueOf( 96L ) ) );
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[74];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[74] + "' != '" + 116 + "'", value.equals(BigInteger.valueOf( 116L ) ) );
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[75];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[75] + "' != '" + 244 + "'", value.equals(BigInteger.valueOf( 244L ) ) );
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[76];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[76] + "' != '" + 246 + "'", value.equals(BigInteger.valueOf( 246L ) ) );
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[77];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[77] + "' != '" + 94 + "'", value.equals(BigInteger.valueOf( 94L ) ) );
        } else {
            value = value.longValue();
            expected = 94L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[78];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[78] + "' != '" + 104 + "'", value.equals(BigInteger.valueOf( 104L ) ) );
        } else {
            value = value.longValue();
            expected = 104L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[79];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[79] + "' != '" + 94 + "'", value.equals(BigInteger.valueOf( 94L ) ) );
        } else {
            value = value.longValue();
            expected = 94L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[80];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[80] + "' != '" + 13 + "'", value.equals(BigInteger.valueOf( 13L ) ) );
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[81];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[81] + "' != '" + 56 + "'", value.equals(BigInteger.valueOf( 56L ) ) );
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[82];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[82] + "' != '" + 210 + "'", value.equals(BigInteger.valueOf( 210L ) ) );
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[83];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[83] + "' != '" + 18 + "'", value.equals(BigInteger.valueOf( 18L ) ) );
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[84];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[84] + "' != '" + 191 + "'", value.equals(BigInteger.valueOf( 191L ) ) );
        } else {
            value = value.longValue();
            expected = 191L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[85];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[85] + "' != '" + 22 + "'", value.equals(BigInteger.valueOf( 22L ) ) );
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[86];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[86] + "' != '" + 133 + "'", value.equals(BigInteger.valueOf( 133L ) ) );
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[87];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[87] + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[88];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[88] + "' != '" + 153 + "'", value.equals(BigInteger.valueOf( 153L ) ) );
        } else {
            value = value.longValue();
            expected = 153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[89];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[89] + "' != '" + 159 + "'", value.equals(BigInteger.valueOf( 159L ) ) );
        } else {
            value = value.longValue();
            expected = 159L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[90];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[90] + "' != '" + 161 + "'", value.equals(BigInteger.valueOf( 161L ) ) );
        } else {
            value = value.longValue();
            expected = 161L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[91];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[91] + "' != '" + 219 + "'", value.equals(BigInteger.valueOf( 219L ) ) );
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[92];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[92] + "' != '" + 59 + "'", value.equals(BigInteger.valueOf( 59L ) ) );
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[93];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[93] + "' != '" + 21 + "'", value.equals(BigInteger.valueOf( 21L ) ) );
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[94];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[94] + "' != '" + 164 + "'", value.equals(BigInteger.valueOf( 164L ) ) );
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[95];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[95] + "' != '" + 121 + "'", value.equals(BigInteger.valueOf( 121L ) ) );
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[96];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[96] + "' != '" + 145 + "'", value.equals(BigInteger.valueOf( 145L ) ) );
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[97];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[97] + "' != '" + 203 + "'", value.equals(BigInteger.valueOf( 203L ) ) );
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[98];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[98] + "' != '" + 171 + "'", value.equals(BigInteger.valueOf( 171L ) ) );
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[99];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[99] + "' != '" + 132 + "'", value.equals(BigInteger.valueOf( 132L ) ) );
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[100];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[100] + "' != '" + 57 + "'", value.equals(BigInteger.valueOf( 57L ) ) );
        } else {
            value = value.longValue();
            expected = 57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[101];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[101] + "' != '" + 180 + "'", value.equals(BigInteger.valueOf( 180L ) ) );
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[102];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[102] + "' != '" + 102 + "'", value.equals(BigInteger.valueOf( 102L ) ) );
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[103];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[103] + "' != '" + 101 + "'", value.equals(BigInteger.valueOf( 101L ) ) );
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[104];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[104] + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[105];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[105] + "' != '" + 229 + "'", value.equals(BigInteger.valueOf( 229L ) ) );
        } else {
            value = value.longValue();
            expected = 229L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[106];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[106] + "' != '" + 175 + "'", value.equals(BigInteger.valueOf( 175L ) ) );
        } else {
            value = value.longValue();
            expected = 175L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[107];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[107] + "' != '" + 145 + "'", value.equals(BigInteger.valueOf( 145L ) ) );
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[108];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[108] + "' != '" + 73 + "'", value.equals(BigInteger.valueOf( 73L ) ) );
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[109];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[109] + "' != '" + 72 + "'", value.equals(BigInteger.valueOf( 72L ) ) );
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[110];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[110] + "' != '" + 124 + "'", value.equals(BigInteger.valueOf( 124L ) ) );
        } else {
            value = value.longValue();
            expected = 124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[111];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[111] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[112];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[112] + "' != '" + 184 + "'", value.equals(BigInteger.valueOf( 184L ) ) );
        } else {
            value = value.longValue();
            expected = 184L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[113];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[113] + "' != '" + 228 + "'", value.equals(BigInteger.valueOf( 228L ) ) );
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[114];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[114] + "' != '" + 61 + "'", value.equals(BigInteger.valueOf( 61L ) ) );
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[115];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[115] + "' != '" + 234 + "'", value.equals(BigInteger.valueOf( 234L ) ) );
        } else {
            value = value.longValue();
            expected = 234L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[116];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[116] + "' != '" + 218 + "'", value.equals(BigInteger.valueOf( 218L ) ) );
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[117];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[117] + "' != '" + 62 + "'", value.equals(BigInteger.valueOf( 62L ) ) );
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[118];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[118] + "' != '" + 226 + "'", value.equals(BigInteger.valueOf( 226L ) ) );
        } else {
            value = value.longValue();
            expected = 226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[119];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[119] + "' != '" + 217 + "'", value.equals(BigInteger.valueOf( 217L ) ) );
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[120];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[120] + "' != '" + 193 + "'", value.equals(BigInteger.valueOf( 193L ) ) );
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[121];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[121] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[122];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[122] + "' != '" + 109 + "'", value.equals(BigInteger.valueOf( 109L ) ) );
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[123];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[123] + "' != '" + 44 + "'", value.equals(BigInteger.valueOf( 44L ) ) );
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[124];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[124] + "' != '" + 83 + "'", value.equals(BigInteger.valueOf( 83L ) ) );
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[125];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[125] + "' != '" + 201 + "'", value.equals(BigInteger.valueOf( 201L ) ) );
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[126];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[126] + "' != '" + 20 + "'", value.equals(BigInteger.valueOf( 20L ) ) );
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[127];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[127] + "' != '" + 101 + "'", value.equals(BigInteger.valueOf( 101L ) ) );
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[128];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[128] + "' != '" + 9 + "'", value.equals(BigInteger.valueOf( 9L ) ) );
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[129];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[129] + "' != '" + 140 + "'", value.equals(BigInteger.valueOf( 140L ) ) );
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[130];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[130] + "' != '" + 186 + "'", value.equals(BigInteger.valueOf( 186L ) ) );
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[131];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[131] + "' != '" + 162 + "'", value.equals(BigInteger.valueOf( 162L ) ) );
        } else {
            value = value.longValue();
            expected = 162L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[132];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[132] + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[133];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[133] + "' != '" + 91 + "'", value.equals(BigInteger.valueOf( 91L ) ) );
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[134];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[134] + "' != '" + 30 + "'", value.equals(BigInteger.valueOf( 30L ) ) );
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[135];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[135] + "' != '" + 231 + "'", value.equals(BigInteger.valueOf( 231L ) ) );
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[136];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[136] + "' != '" + 161 + "'", value.equals(BigInteger.valueOf( 161L ) ) );
        } else {
            value = value.longValue();
            expected = 161L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[137];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[137] + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[138];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[138] + "' != '" + 216 + "'", value.equals(BigInteger.valueOf( 216L ) ) );
        } else {
            value = value.longValue();
            expected = 216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[139];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[139] + "' != '" + 114 + "'", value.equals(BigInteger.valueOf( 114L ) ) );
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[140];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[140] + "' != '" + 60 + "'", value.equals(BigInteger.valueOf( 60L ) ) );
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[141];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[141] + "' != '" + 231 + "'", value.equals(BigInteger.valueOf( 231L ) ) );
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[142];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[142] + "' != '" + 163 + "'", value.equals(BigInteger.valueOf( 163L ) ) );
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[143];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[143] + "' != '" + 163 + "'", value.equals(BigInteger.valueOf( 163L ) ) );
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[144];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[144] + "' != '" + 49 + "'", value.equals(BigInteger.valueOf( 49L ) ) );
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[145];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[145] + "' != '" + 237 + "'", value.equals(BigInteger.valueOf( 237L ) ) );
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[146];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[146] + "' != '" + 244 + "'", value.equals(BigInteger.valueOf( 244L ) ) );
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[147];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[147] + "' != '" + 185 + "'", value.equals(BigInteger.valueOf( 185L ) ) );
        } else {
            value = value.longValue();
            expected = 185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[148];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[148] + "' != '" + 240 + "'", value.equals(BigInteger.valueOf( 240L ) ) );
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[149];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[149] + "' != '" + 89 + "'", value.equals(BigInteger.valueOf( 89L ) ) );
        } else {
            value = value.longValue();
            expected = 89L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[150];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[150] + "' != '" + 143 + "'", value.equals(BigInteger.valueOf( 143L ) ) );
        } else {
            value = value.longValue();
            expected = 143L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[151];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[151] + "' != '" + 174 + "'", value.equals(BigInteger.valueOf( 174L ) ) );
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[152];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[152] + "' != '" + 165 + "'", value.equals(BigInteger.valueOf( 165L ) ) );
        } else {
            value = value.longValue();
            expected = 165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[153];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[153] + "' != '" + 211 + "'", value.equals(BigInteger.valueOf( 211L ) ) );
        } else {
            value = value.longValue();
            expected = 211L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[154];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[154] + "' != '" + 241 + "'", value.equals(BigInteger.valueOf( 241L ) ) );
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[155];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[155] + "' != '" + 13 + "'", value.equals(BigInteger.valueOf( 13L ) ) );
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[156];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[156] + "' != '" + 16 + "'", value.equals(BigInteger.valueOf( 16L ) ) );
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[157];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[157] + "' != '" + 61 + "'", value.equals(BigInteger.valueOf( 61L ) ) );
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[158];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[158] + "' != '" + 141 + "'", value.equals(BigInteger.valueOf( 141L ) ) );
        } else {
            value = value.longValue();
            expected = 141L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[159];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[159] + "' != '" + 101 + "'", value.equals(BigInteger.valueOf( 101L ) ) );
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[160];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[160] + "' != '" + 89 + "'", value.equals(BigInteger.valueOf( 89L ) ) );
        } else {
            value = value.longValue();
            expected = 89L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[161];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[161] + "' != '" + 37 + "'", value.equals(BigInteger.valueOf( 37L ) ) );
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[162];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[162] + "' != '" + 117 + "'", value.equals(BigInteger.valueOf( 117L ) ) );
        } else {
            value = value.longValue();
            expected = 117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[163];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[163] + "' != '" + 189 + "'", value.equals(BigInteger.valueOf( 189L ) ) );
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[164];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[164] + "' != '" + 86 + "'", value.equals(BigInteger.valueOf( 86L ) ) );
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[165];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[165] + "' != '" + 118 + "'", value.equals(BigInteger.valueOf( 118L ) ) );
        } else {
            value = value.longValue();
            expected = 118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[166];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[166] + "' != '" + 176 + "'", value.equals(BigInteger.valueOf( 176L ) ) );
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[167];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[167] + "' != '" + 228 + "'", value.equals(BigInteger.valueOf( 228L ) ) );
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[168];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[168] + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[169];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[169] + "' != '" + 14 + "'", value.equals(BigInteger.valueOf( 14L ) ) );
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[170];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[170] + "' != '" + 119 + "'", value.equals(BigInteger.valueOf( 119L ) ) );
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[171];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[171] + "' != '" + 135 + "'", value.equals(BigInteger.valueOf( 135L ) ) );
        } else {
            value = value.longValue();
            expected = 135L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[172];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[172] + "' != '" + 129 + "'", value.equals(BigInteger.valueOf( 129L ) ) );
        } else {
            value = value.longValue();
            expected = 129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[173];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[173] + "' != '" + 243 + "'", value.equals(BigInteger.valueOf( 243L ) ) );
        } else {
            value = value.longValue();
            expected = 243L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[174];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[174] + "' != '" + 50 + "'", value.equals(BigInteger.valueOf( 50L ) ) );
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[175];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[175] + "' != '" + 29 + "'", value.equals(BigInteger.valueOf( 29L ) ) );
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[176];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[176] + "' != '" + 207 + "'", value.equals(BigInteger.valueOf( 207L ) ) );
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[177];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[177] + "' != '" + 198 + "'", value.equals(BigInteger.valueOf( 198L ) ) );
        } else {
            value = value.longValue();
            expected = 198L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[178];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[178] + "' != '" + 117 + "'", value.equals(BigInteger.valueOf( 117L ) ) );
        } else {
            value = value.longValue();
            expected = 117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[179];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[179] + "' != '" + 100 + "'", value.equals(BigInteger.valueOf( 100L ) ) );
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[180];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[180] + "' != '" + 225 + "'", value.equals(BigInteger.valueOf( 225L ) ) );
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[181];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[181] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[182];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[182] + "' != '" + 139 + "'", value.equals(BigInteger.valueOf( 139L ) ) );
        } else {
            value = value.longValue();
            expected = 139L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[183];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[183] + "' != '" + 110 + "'", value.equals(BigInteger.valueOf( 110L ) ) );
        } else {
            value = value.longValue();
            expected = 110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[184];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[184] + "' != '" + 39 + "'", value.equals(BigInteger.valueOf( 39L ) ) );
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[185];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[185] + "' != '" + 210 + "'", value.equals(BigInteger.valueOf( 210L ) ) );
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[186];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[186] + "' != '" + 68 + "'", value.equals(BigInteger.valueOf( 68L ) ) );
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[187];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[187] + "' != '" + 199 + "'", value.equals(BigInteger.valueOf( 199L ) ) );
        } else {
            value = value.longValue();
            expected = 199L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[188];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[188] + "' != '" + 43 + "'", value.equals(BigInteger.valueOf( 43L ) ) );
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[189];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[189] + "' != '" + 132 + "'", value.equals(BigInteger.valueOf( 132L ) ) );
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[190];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[190] + "' != '" + 64 + "'", value.equals(BigInteger.valueOf( 64L ) ) );
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[191];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[191] + "' != '" + 17 + "'", value.equals(BigInteger.valueOf( 17L ) ) );
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[192];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[192] + "' != '" + 51 + "'", value.equals(BigInteger.valueOf( 51L ) ) );
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[193];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[193] + "' != '" + 173 + "'", value.equals(BigInteger.valueOf( 173L ) ) );
        } else {
            value = value.longValue();
            expected = 173L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[194];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[194] + "' != '" + 181 + "'", value.equals(BigInteger.valueOf( 181L ) ) );
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[195];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[195] + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[196];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[196] + "' != '" + 140 + "'", value.equals(BigInteger.valueOf( 140L ) ) );
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[197];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[197] + "' != '" + 16 + "'", value.equals(BigInteger.valueOf( 16L ) ) );
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[198];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[198] + "' != '" + 247 + "'", value.equals(BigInteger.valueOf( 247L ) ) );
        } else {
            value = value.longValue();
            expected = 247L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[199];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[199] + "' != '" + 84 + "'", value.equals(BigInteger.valueOf( 84L ) ) );
        } else {
            value = value.longValue();
            expected = 84L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[200];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[200] + "' != '" + 183 + "'", value.equals(BigInteger.valueOf( 183L ) ) );
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[201];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[201] + "' != '" + 105 + "'", value.equals(BigInteger.valueOf( 105L ) ) );
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[202];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[202] + "' != '" + 39 + "'", value.equals(BigInteger.valueOf( 39L ) ) );
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[203];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[203] + "' != '" + 157 + "'", value.equals(BigInteger.valueOf( 157L ) ) );
        } else {
            value = value.longValue();
            expected = 157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[204];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[204] + "' != '" + 77 + "'", value.equals(BigInteger.valueOf( 77L ) ) );
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[205];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[205] + "' != '" + 30 + "'", value.equals(BigInteger.valueOf( 30L ) ) );
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[206];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[206] + "' != '" + 205 + "'", value.equals(BigInteger.valueOf( 205L ) ) );
        } else {
            value = value.longValue();
            expected = 205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[207];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[207] + "' != '" + 194 + "'", value.equals(BigInteger.valueOf( 194L ) ) );
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[208];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[208] + "' != '" + 59 + "'", value.equals(BigInteger.valueOf( 59L ) ) );
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[209];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[209] + "' != '" + 64 + "'", value.equals(BigInteger.valueOf( 64L ) ) );
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[210];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[210] + "' != '" + 241 + "'", value.equals(BigInteger.valueOf( 241L ) ) );
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[211];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[211] + "' != '" + 183 + "'", value.equals(BigInteger.valueOf( 183L ) ) );
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[212];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[212] + "' != '" + 238 + "'", value.equals(BigInteger.valueOf( 238L ) ) );
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[213];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[213] + "' != '" + 105 + "'", value.equals(BigInteger.valueOf( 105L ) ) );
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[214];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[214] + "' != '" + 181 + "'", value.equals(BigInteger.valueOf( 181L ) ) );
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[215];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[215] + "' != '" + 170 + "'", value.equals(BigInteger.valueOf( 170L ) ) );
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[216];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[216] + "' != '" + 45 + "'", value.equals(BigInteger.valueOf( 45L ) ) );
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[217];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[217] + "' != '" + 8 + "'", value.equals(BigInteger.valueOf( 8L ) ) );
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[218];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[218] + "' != '" + 166 + "'", value.equals(BigInteger.valueOf( 166L ) ) );
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[219];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[219] + "' != '" + 164 + "'", value.equals(BigInteger.valueOf( 164L ) ) );
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[220];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[220] + "' != '" + 238 + "'", value.equals(BigInteger.valueOf( 238L ) ) );
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[221];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[221] + "' != '" + 83 + "'", value.equals(BigInteger.valueOf( 83L ) ) );
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[222];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[222] + "' != '" + 148 + "'", value.equals(BigInteger.valueOf( 148L ) ) );
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[223];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[223] + "' != '" + 173 + "'", value.equals(BigInteger.valueOf( 173L ) ) );
        } else {
            value = value.longValue();
            expected = 173L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[224];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[224] + "' != '" + 108 + "'", value.equals(BigInteger.valueOf( 108L ) ) );
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[225];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[225] + "' != '" + 228 + "'", value.equals(BigInteger.valueOf( 228L ) ) );
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[226];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[226] + "' != '" + 67 + "'", value.equals(BigInteger.valueOf( 67L ) ) );
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[227];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[227] + "' != '" + 89 + "'", value.equals(BigInteger.valueOf( 89L ) ) );
        } else {
            value = value.longValue();
            expected = 89L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[228];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[228] + "' != '" + 189 + "'", value.equals(BigInteger.valueOf( 189L ) ) );
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[229];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[229] + "' != '" + 67 + "'", value.equals(BigInteger.valueOf( 67L ) ) );
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.amplitude_value[230];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.amplitude_value[230] + "' != '" + 26 + "'", value.equals(BigInteger.valueOf( 26L ) ) );
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.channel_tag;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.channel_tag + "' != '" + 5878 + "'", value.equals(BigInteger.valueOf( 5878L ) ) );
        } else {
            value = value.longValue();
            expected = 5878L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.freq_ref, 6.34820019531250000e+03, DELTA);
        org.junit.Assert.assertEquals(msg.freq_step, 4.60820019531250000e+03, DELTA);
        value = msg.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.t.tow + "' != '" + 992295133 + "'", value.equals(BigInteger.valueOf( 992295133L ) ) );
        } else {
            value = value.longValue();
            expected = 992295133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.t.wn + "' != '" + 6957 + "'", value.equals(BigInteger.valueOf( 6957L ) ) );
        } else {
            value = value.longValue();
            expected = 6957L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
