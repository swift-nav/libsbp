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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGridDefinitionDepA.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.ssr.MsgSsrGridDefinitionDepA;


public class auto_check_sbp_ssr_MsgSsrGridDefinitionDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrGridDefinitionDepATest.test1");
        byte[] payload = new byte[] {(byte)11,(byte)84,(byte)171,(byte)229,(byte)132,(byte)143,(byte)46,(byte)204,(byte)52,(byte)92,(byte)104,(byte)25,(byte)204,(byte)182,(byte)22,(byte)98,(byte)203,(byte)123,(byte)211,(byte)38,(byte)13,(byte)253,(byte)129,(byte)173,(byte)171,(byte)235,(byte)253,(byte)26,(byte)203,(byte)3,(byte)120,(byte)126,(byte)42,(byte)44,(byte)39,(byte)87,(byte)69,(byte)154,(byte)13,(byte)28,(byte)179,(byte)32,(byte)47,(byte)36,(byte)195,(byte)39,(byte)198,(byte)134,(byte)235,(byte)134,(byte)57,(byte)120,(byte)243,(byte)151,(byte)35,(byte)17,(byte)201,(byte)211,(byte)125,(byte)117,(byte)164,(byte)142,(byte)101,(byte)239,(byte)144,(byte)158,(byte)239,(byte)90,(byte)56,(byte)71,(byte)120,(byte)67,(byte)221,(byte)114,(byte)10,(byte)190,(byte)4,(byte)230,(byte)164,(byte)171,(byte)78,(byte)185,(byte)90,(byte)46,(byte)177,(byte)82,(byte)228,(byte)123,(byte)222,(byte)227,(byte)145,(byte)195,(byte)219,(byte)27,(byte)56,(byte)227,(byte)246,(byte)215,(byte)144,(byte)158,(byte)31,(byte)214,(byte)241,(byte)254,(byte)200,(byte)86,(byte)142,(byte)89,(byte)12,(byte)121,(byte)29,(byte)124,(byte)9,(byte)19,(byte)153,(byte)44,(byte)35,(byte)126,(byte)14,(byte)217,(byte)65,(byte)116,(byte)26,(byte)139,(byte)122,(byte)114,(byte)90,(byte)124,(byte)81,(byte)0,(byte)186,(byte)246,(byte)46,(byte)98,(byte)179,(byte)243,(byte)198,(byte)217,(byte)36,(byte)30,(byte)202,(byte)12,(byte)135,(byte)61,(byte)42,(byte)150,(byte)221,(byte)102,(byte)83,(byte)179,(byte)43,(byte)252,(byte)81,(byte)62,(byte)126,(byte)204,(byte)195,(byte)238,(byte)18,(byte)128,(byte)193,(byte)53,(byte)94,(byte)99,(byte)63,(byte)182,(byte)2,(byte)186,(byte)220,(byte)77,(byte)186,(byte)224,(byte)220,(byte)13,(byte)212,(byte)182,(byte)88,(byte)15,(byte)151,(byte)5,(byte)93,(byte)251,(byte)164,(byte)18,(byte)228,(byte)168,(byte)226,(byte)195,(byte)44,(byte)170,(byte)145,(byte)36,(byte)58,(byte)96,(byte)107,(byte)144,(byte)11,(byte)228,(byte)12,(byte)163,(byte)238,(byte)247,(byte)159,(byte)189,(byte)1,(byte)115,(byte)65,(byte)202,(byte)121,(byte)47,(byte)193,(byte)11,(byte)96,(byte)93,(byte)72,(byte)81,(byte)207,(byte)121,(byte)19,(byte)151,(byte)136,(byte)233,(byte)51,(byte)133,(byte)195,(byte)77,(byte)44,(byte)147,(byte)206,(byte)120,(byte)252,(byte)77,(byte)212,(byte)68,(byte)60,(byte)206,(byte)106,(byte)207,(byte)243,(byte)158,(byte)94,(byte)6,(byte)3,(byte)205,(byte)92,(byte)84,(byte)2,(byte)220,(byte)50,(byte)61,(byte)38,(byte)141,(byte)117,(byte)108,(byte)101, };
        SBPMessage sbp = new SBPMessage( 0xf7b5, 0x5f5, payload );
        MsgSsrGridDefinitionDepA msg = new MsgSsrGridDefinitionDepA( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.area_width;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.area_width + "' != '" + 43860 + "'", value.equals(BigInteger.valueOf( 43860L ) ) );
        } else {
            value = value.longValue();
            expected = 43860L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.lat_nw_corner_enc;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.lat_nw_corner_enc + "' != '" + 34021 + "'", value.equals(BigInteger.valueOf( 34021L ) ) );
        } else {
            value = value.longValue();
            expected = 34021L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.lon_nw_corner_enc;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.lon_nw_corner_enc + "' != '" + 11919 + "'", value.equals(BigInteger.valueOf( 11919L ) ) );
        } else {
            value = value.longValue();
            expected = 11919L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.num_msgs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.num_msgs + "' != '" + 204 + "'", value.equals(BigInteger.valueOf( 204L ) ) );
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.region_size_inverse;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.region_size_inverse + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.seq_num;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.seq_num + "' != '" + 52 + "'", value.equals(BigInteger.valueOf( 52L ) ) );
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[0] + "' != '" + 92 + "'", value.equals(BigInteger.valueOf( 92L ) ) );
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[1] + "' != '" + 104 + "'", value.equals(BigInteger.valueOf( 104L ) ) );
        } else {
            value = value.longValue();
            expected = 104L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[2] + "' != '" + 25 + "'", value.equals(BigInteger.valueOf( 25L ) ) );
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[3] + "' != '" + 204 + "'", value.equals(BigInteger.valueOf( 204L ) ) );
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[4] + "' != '" + 182 + "'", value.equals(BigInteger.valueOf( 182L ) ) );
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[5] + "' != '" + 22 + "'", value.equals(BigInteger.valueOf( 22L ) ) );
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[6] + "' != '" + 98 + "'", value.equals(BigInteger.valueOf( 98L ) ) );
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[7] + "' != '" + 203 + "'", value.equals(BigInteger.valueOf( 203L ) ) );
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[8] + "' != '" + 123 + "'", value.equals(BigInteger.valueOf( 123L ) ) );
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[9] + "' != '" + 211 + "'", value.equals(BigInteger.valueOf( 211L ) ) );
        } else {
            value = value.longValue();
            expected = 211L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[10] + "' != '" + 38 + "'", value.equals(BigInteger.valueOf( 38L ) ) );
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[11] + "' != '" + 13 + "'", value.equals(BigInteger.valueOf( 13L ) ) );
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[12] + "' != '" + 253 + "'", value.equals(BigInteger.valueOf( 253L ) ) );
        } else {
            value = value.longValue();
            expected = 253L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[13] + "' != '" + 129 + "'", value.equals(BigInteger.valueOf( 129L ) ) );
        } else {
            value = value.longValue();
            expected = 129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[14] + "' != '" + 173 + "'", value.equals(BigInteger.valueOf( 173L ) ) );
        } else {
            value = value.longValue();
            expected = 173L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[15] + "' != '" + 171 + "'", value.equals(BigInteger.valueOf( 171L ) ) );
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[16] + "' != '" + 235 + "'", value.equals(BigInteger.valueOf( 235L ) ) );
        } else {
            value = value.longValue();
            expected = 235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[17] + "' != '" + 253 + "'", value.equals(BigInteger.valueOf( 253L ) ) );
        } else {
            value = value.longValue();
            expected = 253L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[18] + "' != '" + 26 + "'", value.equals(BigInteger.valueOf( 26L ) ) );
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[19] + "' != '" + 203 + "'", value.equals(BigInteger.valueOf( 203L ) ) );
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[20] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[21];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[21] + "' != '" + 120 + "'", value.equals(BigInteger.valueOf( 120L ) ) );
        } else {
            value = value.longValue();
            expected = 120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[22];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[22] + "' != '" + 126 + "'", value.equals(BigInteger.valueOf( 126L ) ) );
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[23];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[23] + "' != '" + 42 + "'", value.equals(BigInteger.valueOf( 42L ) ) );
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[24];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[24] + "' != '" + 44 + "'", value.equals(BigInteger.valueOf( 44L ) ) );
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[25];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[25] + "' != '" + 39 + "'", value.equals(BigInteger.valueOf( 39L ) ) );
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[26];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[26] + "' != '" + 87 + "'", value.equals(BigInteger.valueOf( 87L ) ) );
        } else {
            value = value.longValue();
            expected = 87L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[27];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[27] + "' != '" + 69 + "'", value.equals(BigInteger.valueOf( 69L ) ) );
        } else {
            value = value.longValue();
            expected = 69L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[28];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[28] + "' != '" + 154 + "'", value.equals(BigInteger.valueOf( 154L ) ) );
        } else {
            value = value.longValue();
            expected = 154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[29];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[29] + "' != '" + 13 + "'", value.equals(BigInteger.valueOf( 13L ) ) );
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[30];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[30] + "' != '" + 28 + "'", value.equals(BigInteger.valueOf( 28L ) ) );
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[31];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[31] + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[32];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[32] + "' != '" + 32 + "'", value.equals(BigInteger.valueOf( 32L ) ) );
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[33];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[33] + "' != '" + 47 + "'", value.equals(BigInteger.valueOf( 47L ) ) );
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[34];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[34] + "' != '" + 36 + "'", value.equals(BigInteger.valueOf( 36L ) ) );
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[35];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[35] + "' != '" + 195 + "'", value.equals(BigInteger.valueOf( 195L ) ) );
        } else {
            value = value.longValue();
            expected = 195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[36];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[36] + "' != '" + 39 + "'", value.equals(BigInteger.valueOf( 39L ) ) );
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[37];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[37] + "' != '" + 198 + "'", value.equals(BigInteger.valueOf( 198L ) ) );
        } else {
            value = value.longValue();
            expected = 198L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[38];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[38] + "' != '" + 134 + "'", value.equals(BigInteger.valueOf( 134L ) ) );
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[39];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[39] + "' != '" + 235 + "'", value.equals(BigInteger.valueOf( 235L ) ) );
        } else {
            value = value.longValue();
            expected = 235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[40];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[40] + "' != '" + 134 + "'", value.equals(BigInteger.valueOf( 134L ) ) );
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[41];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[41] + "' != '" + 57 + "'", value.equals(BigInteger.valueOf( 57L ) ) );
        } else {
            value = value.longValue();
            expected = 57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[42];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[42] + "' != '" + 120 + "'", value.equals(BigInteger.valueOf( 120L ) ) );
        } else {
            value = value.longValue();
            expected = 120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[43];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[43] + "' != '" + 243 + "'", value.equals(BigInteger.valueOf( 243L ) ) );
        } else {
            value = value.longValue();
            expected = 243L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[44];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[44] + "' != '" + 151 + "'", value.equals(BigInteger.valueOf( 151L ) ) );
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[45];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[45] + "' != '" + 35 + "'", value.equals(BigInteger.valueOf( 35L ) ) );
        } else {
            value = value.longValue();
            expected = 35L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[46];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[46] + "' != '" + 17 + "'", value.equals(BigInteger.valueOf( 17L ) ) );
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[47];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[47] + "' != '" + 201 + "'", value.equals(BigInteger.valueOf( 201L ) ) );
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[48];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[48] + "' != '" + 211 + "'", value.equals(BigInteger.valueOf( 211L ) ) );
        } else {
            value = value.longValue();
            expected = 211L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[49];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[49] + "' != '" + 125 + "'", value.equals(BigInteger.valueOf( 125L ) ) );
        } else {
            value = value.longValue();
            expected = 125L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[50];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[50] + "' != '" + 117 + "'", value.equals(BigInteger.valueOf( 117L ) ) );
        } else {
            value = value.longValue();
            expected = 117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[51];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[51] + "' != '" + 164 + "'", value.equals(BigInteger.valueOf( 164L ) ) );
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[52];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[52] + "' != '" + 142 + "'", value.equals(BigInteger.valueOf( 142L ) ) );
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[53];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[53] + "' != '" + 101 + "'", value.equals(BigInteger.valueOf( 101L ) ) );
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[54];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[54] + "' != '" + 239 + "'", value.equals(BigInteger.valueOf( 239L ) ) );
        } else {
            value = value.longValue();
            expected = 239L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[55];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[55] + "' != '" + 144 + "'", value.equals(BigInteger.valueOf( 144L ) ) );
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[56];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[56] + "' != '" + 158 + "'", value.equals(BigInteger.valueOf( 158L ) ) );
        } else {
            value = value.longValue();
            expected = 158L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[57];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[57] + "' != '" + 239 + "'", value.equals(BigInteger.valueOf( 239L ) ) );
        } else {
            value = value.longValue();
            expected = 239L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[58];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[58] + "' != '" + 90 + "'", value.equals(BigInteger.valueOf( 90L ) ) );
        } else {
            value = value.longValue();
            expected = 90L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[59];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[59] + "' != '" + 56 + "'", value.equals(BigInteger.valueOf( 56L ) ) );
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[60];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[60] + "' != '" + 71 + "'", value.equals(BigInteger.valueOf( 71L ) ) );
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[61];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[61] + "' != '" + 120 + "'", value.equals(BigInteger.valueOf( 120L ) ) );
        } else {
            value = value.longValue();
            expected = 120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[62];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[62] + "' != '" + 67 + "'", value.equals(BigInteger.valueOf( 67L ) ) );
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[63];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[63] + "' != '" + 221 + "'", value.equals(BigInteger.valueOf( 221L ) ) );
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[64];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[64] + "' != '" + 114 + "'", value.equals(BigInteger.valueOf( 114L ) ) );
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[65];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[65] + "' != '" + 10 + "'", value.equals(BigInteger.valueOf( 10L ) ) );
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[66];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[66] + "' != '" + 190 + "'", value.equals(BigInteger.valueOf( 190L ) ) );
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[67];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[67] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[68];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[68] + "' != '" + 230 + "'", value.equals(BigInteger.valueOf( 230L ) ) );
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[69];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[69] + "' != '" + 164 + "'", value.equals(BigInteger.valueOf( 164L ) ) );
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[70];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[70] + "' != '" + 171 + "'", value.equals(BigInteger.valueOf( 171L ) ) );
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[71];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[71] + "' != '" + 78 + "'", value.equals(BigInteger.valueOf( 78L ) ) );
        } else {
            value = value.longValue();
            expected = 78L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[72];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[72] + "' != '" + 185 + "'", value.equals(BigInteger.valueOf( 185L ) ) );
        } else {
            value = value.longValue();
            expected = 185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[73];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[73] + "' != '" + 90 + "'", value.equals(BigInteger.valueOf( 90L ) ) );
        } else {
            value = value.longValue();
            expected = 90L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[74];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[74] + "' != '" + 46 + "'", value.equals(BigInteger.valueOf( 46L ) ) );
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[75];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[75] + "' != '" + 177 + "'", value.equals(BigInteger.valueOf( 177L ) ) );
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[76];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[76] + "' != '" + 82 + "'", value.equals(BigInteger.valueOf( 82L ) ) );
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[77];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[77] + "' != '" + 228 + "'", value.equals(BigInteger.valueOf( 228L ) ) );
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[78];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[78] + "' != '" + 123 + "'", value.equals(BigInteger.valueOf( 123L ) ) );
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[79];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[79] + "' != '" + 222 + "'", value.equals(BigInteger.valueOf( 222L ) ) );
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[80];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[80] + "' != '" + 227 + "'", value.equals(BigInteger.valueOf( 227L ) ) );
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[81];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[81] + "' != '" + 145 + "'", value.equals(BigInteger.valueOf( 145L ) ) );
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[82];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[82] + "' != '" + 195 + "'", value.equals(BigInteger.valueOf( 195L ) ) );
        } else {
            value = value.longValue();
            expected = 195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[83];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[83] + "' != '" + 219 + "'", value.equals(BigInteger.valueOf( 219L ) ) );
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[84];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[84] + "' != '" + 27 + "'", value.equals(BigInteger.valueOf( 27L ) ) );
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[85];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[85] + "' != '" + 56 + "'", value.equals(BigInteger.valueOf( 56L ) ) );
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[86];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[86] + "' != '" + 227 + "'", value.equals(BigInteger.valueOf( 227L ) ) );
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[87];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[87] + "' != '" + 246 + "'", value.equals(BigInteger.valueOf( 246L ) ) );
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[88];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[88] + "' != '" + 215 + "'", value.equals(BigInteger.valueOf( 215L ) ) );
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[89];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[89] + "' != '" + 144 + "'", value.equals(BigInteger.valueOf( 144L ) ) );
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[90];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[90] + "' != '" + 158 + "'", value.equals(BigInteger.valueOf( 158L ) ) );
        } else {
            value = value.longValue();
            expected = 158L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[91];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[91] + "' != '" + 31 + "'", value.equals(BigInteger.valueOf( 31L ) ) );
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[92];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[92] + "' != '" + 214 + "'", value.equals(BigInteger.valueOf( 214L ) ) );
        } else {
            value = value.longValue();
            expected = 214L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[93];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[93] + "' != '" + 241 + "'", value.equals(BigInteger.valueOf( 241L ) ) );
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[94];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[94] + "' != '" + 254 + "'", value.equals(BigInteger.valueOf( 254L ) ) );
        } else {
            value = value.longValue();
            expected = 254L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[95];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[95] + "' != '" + 200 + "'", value.equals(BigInteger.valueOf( 200L ) ) );
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[96];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[96] + "' != '" + 86 + "'", value.equals(BigInteger.valueOf( 86L ) ) );
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[97];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[97] + "' != '" + 142 + "'", value.equals(BigInteger.valueOf( 142L ) ) );
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[98];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[98] + "' != '" + 89 + "'", value.equals(BigInteger.valueOf( 89L ) ) );
        } else {
            value = value.longValue();
            expected = 89L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[99];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[99] + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[100];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[100] + "' != '" + 121 + "'", value.equals(BigInteger.valueOf( 121L ) ) );
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[101];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[101] + "' != '" + 29 + "'", value.equals(BigInteger.valueOf( 29L ) ) );
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[102];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[102] + "' != '" + 124 + "'", value.equals(BigInteger.valueOf( 124L ) ) );
        } else {
            value = value.longValue();
            expected = 124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[103];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[103] + "' != '" + 9 + "'", value.equals(BigInteger.valueOf( 9L ) ) );
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[104];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[104] + "' != '" + 19 + "'", value.equals(BigInteger.valueOf( 19L ) ) );
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[105];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[105] + "' != '" + 153 + "'", value.equals(BigInteger.valueOf( 153L ) ) );
        } else {
            value = value.longValue();
            expected = 153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[106];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[106] + "' != '" + 44 + "'", value.equals(BigInteger.valueOf( 44L ) ) );
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[107];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[107] + "' != '" + 35 + "'", value.equals(BigInteger.valueOf( 35L ) ) );
        } else {
            value = value.longValue();
            expected = 35L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[108];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[108] + "' != '" + 126 + "'", value.equals(BigInteger.valueOf( 126L ) ) );
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[109];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[109] + "' != '" + 14 + "'", value.equals(BigInteger.valueOf( 14L ) ) );
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[110];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[110] + "' != '" + 217 + "'", value.equals(BigInteger.valueOf( 217L ) ) );
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[111];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[111] + "' != '" + 65 + "'", value.equals(BigInteger.valueOf( 65L ) ) );
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[112];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[112] + "' != '" + 116 + "'", value.equals(BigInteger.valueOf( 116L ) ) );
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[113];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[113] + "' != '" + 26 + "'", value.equals(BigInteger.valueOf( 26L ) ) );
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[114];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[114] + "' != '" + 139 + "'", value.equals(BigInteger.valueOf( 139L ) ) );
        } else {
            value = value.longValue();
            expected = 139L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[115];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[115] + "' != '" + 122 + "'", value.equals(BigInteger.valueOf( 122L ) ) );
        } else {
            value = value.longValue();
            expected = 122L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[116];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[116] + "' != '" + 114 + "'", value.equals(BigInteger.valueOf( 114L ) ) );
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[117];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[117] + "' != '" + 90 + "'", value.equals(BigInteger.valueOf( 90L ) ) );
        } else {
            value = value.longValue();
            expected = 90L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[118];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[118] + "' != '" + 124 + "'", value.equals(BigInteger.valueOf( 124L ) ) );
        } else {
            value = value.longValue();
            expected = 124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[119];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[119] + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[120];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[120] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[121];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[121] + "' != '" + 186 + "'", value.equals(BigInteger.valueOf( 186L ) ) );
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[122];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[122] + "' != '" + 246 + "'", value.equals(BigInteger.valueOf( 246L ) ) );
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[123];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[123] + "' != '" + 46 + "'", value.equals(BigInteger.valueOf( 46L ) ) );
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[124];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[124] + "' != '" + 98 + "'", value.equals(BigInteger.valueOf( 98L ) ) );
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[125];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[125] + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[126];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[126] + "' != '" + 243 + "'", value.equals(BigInteger.valueOf( 243L ) ) );
        } else {
            value = value.longValue();
            expected = 243L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[127];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[127] + "' != '" + 198 + "'", value.equals(BigInteger.valueOf( 198L ) ) );
        } else {
            value = value.longValue();
            expected = 198L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[128];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[128] + "' != '" + 217 + "'", value.equals(BigInteger.valueOf( 217L ) ) );
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[129];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[129] + "' != '" + 36 + "'", value.equals(BigInteger.valueOf( 36L ) ) );
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[130];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[130] + "' != '" + 30 + "'", value.equals(BigInteger.valueOf( 30L ) ) );
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[131];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[131] + "' != '" + 202 + "'", value.equals(BigInteger.valueOf( 202L ) ) );
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[132];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[132] + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[133];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[133] + "' != '" + 135 + "'", value.equals(BigInteger.valueOf( 135L ) ) );
        } else {
            value = value.longValue();
            expected = 135L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[134];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[134] + "' != '" + 61 + "'", value.equals(BigInteger.valueOf( 61L ) ) );
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[135];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[135] + "' != '" + 42 + "'", value.equals(BigInteger.valueOf( 42L ) ) );
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[136];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[136] + "' != '" + 150 + "'", value.equals(BigInteger.valueOf( 150L ) ) );
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[137];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[137] + "' != '" + 221 + "'", value.equals(BigInteger.valueOf( 221L ) ) );
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[138];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[138] + "' != '" + 102 + "'", value.equals(BigInteger.valueOf( 102L ) ) );
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[139];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[139] + "' != '" + 83 + "'", value.equals(BigInteger.valueOf( 83L ) ) );
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[140];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[140] + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[141];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[141] + "' != '" + 43 + "'", value.equals(BigInteger.valueOf( 43L ) ) );
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[142];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[142] + "' != '" + 252 + "'", value.equals(BigInteger.valueOf( 252L ) ) );
        } else {
            value = value.longValue();
            expected = 252L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[143];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[143] + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[144];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[144] + "' != '" + 62 + "'", value.equals(BigInteger.valueOf( 62L ) ) );
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[145];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[145] + "' != '" + 126 + "'", value.equals(BigInteger.valueOf( 126L ) ) );
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[146];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[146] + "' != '" + 204 + "'", value.equals(BigInteger.valueOf( 204L ) ) );
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[147];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[147] + "' != '" + 195 + "'", value.equals(BigInteger.valueOf( 195L ) ) );
        } else {
            value = value.longValue();
            expected = 195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[148];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[148] + "' != '" + 238 + "'", value.equals(BigInteger.valueOf( 238L ) ) );
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[149];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[149] + "' != '" + 18 + "'", value.equals(BigInteger.valueOf( 18L ) ) );
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[150];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[150] + "' != '" + 128 + "'", value.equals(BigInteger.valueOf( 128L ) ) );
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[151];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[151] + "' != '" + 193 + "'", value.equals(BigInteger.valueOf( 193L ) ) );
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[152];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[152] + "' != '" + 53 + "'", value.equals(BigInteger.valueOf( 53L ) ) );
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[153];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[153] + "' != '" + 94 + "'", value.equals(BigInteger.valueOf( 94L ) ) );
        } else {
            value = value.longValue();
            expected = 94L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[154];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[154] + "' != '" + 99 + "'", value.equals(BigInteger.valueOf( 99L ) ) );
        } else {
            value = value.longValue();
            expected = 99L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[155];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[155] + "' != '" + 63 + "'", value.equals(BigInteger.valueOf( 63L ) ) );
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[156];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[156] + "' != '" + 182 + "'", value.equals(BigInteger.valueOf( 182L ) ) );
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[157];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[157] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[158];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[158] + "' != '" + 186 + "'", value.equals(BigInteger.valueOf( 186L ) ) );
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[159];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[159] + "' != '" + 220 + "'", value.equals(BigInteger.valueOf( 220L ) ) );
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[160];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[160] + "' != '" + 77 + "'", value.equals(BigInteger.valueOf( 77L ) ) );
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[161];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[161] + "' != '" + 186 + "'", value.equals(BigInteger.valueOf( 186L ) ) );
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[162];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[162] + "' != '" + 224 + "'", value.equals(BigInteger.valueOf( 224L ) ) );
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[163];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[163] + "' != '" + 220 + "'", value.equals(BigInteger.valueOf( 220L ) ) );
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[164];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[164] + "' != '" + 13 + "'", value.equals(BigInteger.valueOf( 13L ) ) );
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[165];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[165] + "' != '" + 212 + "'", value.equals(BigInteger.valueOf( 212L ) ) );
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[166];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[166] + "' != '" + 182 + "'", value.equals(BigInteger.valueOf( 182L ) ) );
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[167];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[167] + "' != '" + 88 + "'", value.equals(BigInteger.valueOf( 88L ) ) );
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[168];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[168] + "' != '" + 15 + "'", value.equals(BigInteger.valueOf( 15L ) ) );
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[169];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[169] + "' != '" + 151 + "'", value.equals(BigInteger.valueOf( 151L ) ) );
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[170];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[170] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[171];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[171] + "' != '" + 93 + "'", value.equals(BigInteger.valueOf( 93L ) ) );
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[172];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[172] + "' != '" + 251 + "'", value.equals(BigInteger.valueOf( 251L ) ) );
        } else {
            value = value.longValue();
            expected = 251L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[173];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[173] + "' != '" + 164 + "'", value.equals(BigInteger.valueOf( 164L ) ) );
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[174];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[174] + "' != '" + 18 + "'", value.equals(BigInteger.valueOf( 18L ) ) );
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[175];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[175] + "' != '" + 228 + "'", value.equals(BigInteger.valueOf( 228L ) ) );
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[176];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[176] + "' != '" + 168 + "'", value.equals(BigInteger.valueOf( 168L ) ) );
        } else {
            value = value.longValue();
            expected = 168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[177];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[177] + "' != '" + 226 + "'", value.equals(BigInteger.valueOf( 226L ) ) );
        } else {
            value = value.longValue();
            expected = 226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[178];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[178] + "' != '" + 195 + "'", value.equals(BigInteger.valueOf( 195L ) ) );
        } else {
            value = value.longValue();
            expected = 195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[179];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[179] + "' != '" + 44 + "'", value.equals(BigInteger.valueOf( 44L ) ) );
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[180];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[180] + "' != '" + 170 + "'", value.equals(BigInteger.valueOf( 170L ) ) );
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[181];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[181] + "' != '" + 145 + "'", value.equals(BigInteger.valueOf( 145L ) ) );
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[182];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[182] + "' != '" + 36 + "'", value.equals(BigInteger.valueOf( 36L ) ) );
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[183];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[183] + "' != '" + 58 + "'", value.equals(BigInteger.valueOf( 58L ) ) );
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[184];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[184] + "' != '" + 96 + "'", value.equals(BigInteger.valueOf( 96L ) ) );
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[185];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[185] + "' != '" + 107 + "'", value.equals(BigInteger.valueOf( 107L ) ) );
        } else {
            value = value.longValue();
            expected = 107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[186];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[186] + "' != '" + 144 + "'", value.equals(BigInteger.valueOf( 144L ) ) );
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[187];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[187] + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[188];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[188] + "' != '" + 228 + "'", value.equals(BigInteger.valueOf( 228L ) ) );
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[189];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[189] + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[190];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[190] + "' != '" + 163 + "'", value.equals(BigInteger.valueOf( 163L ) ) );
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[191];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[191] + "' != '" + 238 + "'", value.equals(BigInteger.valueOf( 238L ) ) );
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[192];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[192] + "' != '" + 247 + "'", value.equals(BigInteger.valueOf( 247L ) ) );
        } else {
            value = value.longValue();
            expected = 247L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[193];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[193] + "' != '" + 159 + "'", value.equals(BigInteger.valueOf( 159L ) ) );
        } else {
            value = value.longValue();
            expected = 159L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[194];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[194] + "' != '" + 189 + "'", value.equals(BigInteger.valueOf( 189L ) ) );
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[195];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[195] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[196];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[196] + "' != '" + 115 + "'", value.equals(BigInteger.valueOf( 115L ) ) );
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[197];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[197] + "' != '" + 65 + "'", value.equals(BigInteger.valueOf( 65L ) ) );
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[198];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[198] + "' != '" + 202 + "'", value.equals(BigInteger.valueOf( 202L ) ) );
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[199];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[199] + "' != '" + 121 + "'", value.equals(BigInteger.valueOf( 121L ) ) );
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[200];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[200] + "' != '" + 47 + "'", value.equals(BigInteger.valueOf( 47L ) ) );
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[201];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[201] + "' != '" + 193 + "'", value.equals(BigInteger.valueOf( 193L ) ) );
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[202];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[202] + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[203];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[203] + "' != '" + 96 + "'", value.equals(BigInteger.valueOf( 96L ) ) );
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[204];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[204] + "' != '" + 93 + "'", value.equals(BigInteger.valueOf( 93L ) ) );
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[205];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[205] + "' != '" + 72 + "'", value.equals(BigInteger.valueOf( 72L ) ) );
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[206];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[206] + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[207];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[207] + "' != '" + 207 + "'", value.equals(BigInteger.valueOf( 207L ) ) );
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[208];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[208] + "' != '" + 121 + "'", value.equals(BigInteger.valueOf( 121L ) ) );
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[209];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[209] + "' != '" + 19 + "'", value.equals(BigInteger.valueOf( 19L ) ) );
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[210];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[210] + "' != '" + 151 + "'", value.equals(BigInteger.valueOf( 151L ) ) );
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[211];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[211] + "' != '" + 136 + "'", value.equals(BigInteger.valueOf( 136L ) ) );
        } else {
            value = value.longValue();
            expected = 136L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[212];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[212] + "' != '" + 233 + "'", value.equals(BigInteger.valueOf( 233L ) ) );
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[213];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[213] + "' != '" + 51 + "'", value.equals(BigInteger.valueOf( 51L ) ) );
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[214];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[214] + "' != '" + 133 + "'", value.equals(BigInteger.valueOf( 133L ) ) );
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[215];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[215] + "' != '" + 195 + "'", value.equals(BigInteger.valueOf( 195L ) ) );
        } else {
            value = value.longValue();
            expected = 195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[216];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[216] + "' != '" + 77 + "'", value.equals(BigInteger.valueOf( 77L ) ) );
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[217];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[217] + "' != '" + 44 + "'", value.equals(BigInteger.valueOf( 44L ) ) );
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[218];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[218] + "' != '" + 147 + "'", value.equals(BigInteger.valueOf( 147L ) ) );
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[219];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[219] + "' != '" + 206 + "'", value.equals(BigInteger.valueOf( 206L ) ) );
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[220];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[220] + "' != '" + 120 + "'", value.equals(BigInteger.valueOf( 120L ) ) );
        } else {
            value = value.longValue();
            expected = 120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[221];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[221] + "' != '" + 252 + "'", value.equals(BigInteger.valueOf( 252L ) ) );
        } else {
            value = value.longValue();
            expected = 252L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[222];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[222] + "' != '" + 77 + "'", value.equals(BigInteger.valueOf( 77L ) ) );
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[223];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[223] + "' != '" + 212 + "'", value.equals(BigInteger.valueOf( 212L ) ) );
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[224];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[224] + "' != '" + 68 + "'", value.equals(BigInteger.valueOf( 68L ) ) );
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[225];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[225] + "' != '" + 60 + "'", value.equals(BigInteger.valueOf( 60L ) ) );
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[226];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[226] + "' != '" + 206 + "'", value.equals(BigInteger.valueOf( 206L ) ) );
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[227];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[227] + "' != '" + 106 + "'", value.equals(BigInteger.valueOf( 106L ) ) );
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[228];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[228] + "' != '" + 207 + "'", value.equals(BigInteger.valueOf( 207L ) ) );
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[229];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[229] + "' != '" + 243 + "'", value.equals(BigInteger.valueOf( 243L ) ) );
        } else {
            value = value.longValue();
            expected = 243L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[230];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[230] + "' != '" + 158 + "'", value.equals(BigInteger.valueOf( 158L ) ) );
        } else {
            value = value.longValue();
            expected = 158L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[231];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[231] + "' != '" + 94 + "'", value.equals(BigInteger.valueOf( 94L ) ) );
        } else {
            value = value.longValue();
            expected = 94L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[232];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[232] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[233];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[233] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[234];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[234] + "' != '" + 205 + "'", value.equals(BigInteger.valueOf( 205L ) ) );
        } else {
            value = value.longValue();
            expected = 205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[235];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[235] + "' != '" + 92 + "'", value.equals(BigInteger.valueOf( 92L ) ) );
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[236];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[236] + "' != '" + 84 + "'", value.equals(BigInteger.valueOf( 84L ) ) );
        } else {
            value = value.longValue();
            expected = 84L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[237];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[237] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[238];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[238] + "' != '" + 220 + "'", value.equals(BigInteger.valueOf( 220L ) ) );
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[239];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[239] + "' != '" + 50 + "'", value.equals(BigInteger.valueOf( 50L ) ) );
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[240];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[240] + "' != '" + 61 + "'", value.equals(BigInteger.valueOf( 61L ) ) );
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[241];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[241] + "' != '" + 38 + "'", value.equals(BigInteger.valueOf( 38L ) ) );
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[242];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[242] + "' != '" + 141 + "'", value.equals(BigInteger.valueOf( 141L ) ) );
        } else {
            value = value.longValue();
            expected = 141L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[243];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[243] + "' != '" + 117 + "'", value.equals(BigInteger.valueOf( 117L ) ) );
        } else {
            value = value.longValue();
            expected = 117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[244];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[244] + "' != '" + 108 + "'", value.equals(BigInteger.valueOf( 108L ) ) );
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rle_list[245];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.rle_list[245] + "' != '" + 101 + "'", value.equals(BigInteger.valueOf( 101L ) ) );
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
