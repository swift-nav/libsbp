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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadResp.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.file_io.MsgFileioReadResp;


public class auto_check_sbp_file_io_MsgFileioReadRespTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_file_io_MsgFileioReadRespTest.test1");
        byte[] payload = new byte[] {(byte)67,(byte)183,(byte)115,(byte)15,(byte)73,(byte)231,(byte)227,(byte)179,(byte)18,(byte)76,(byte)68,(byte)229,(byte)216,(byte)21,(byte)98,(byte)183,(byte)69,(byte)190,(byte)5,(byte)252,(byte)176,(byte)55,(byte)32,(byte)78,(byte)8,(byte)52,(byte)127,(byte)50,(byte)71,(byte)106,(byte)61,(byte)79,(byte)191,(byte)106,(byte)46,(byte)79,(byte)118,(byte)248,(byte)118,(byte)207,(byte)206,(byte)210,(byte)91,(byte)73,(byte)251,(byte)81,(byte)131,(byte)205,(byte)193,(byte)146,(byte)206,(byte)185,(byte)140,(byte)249,(byte)163,(byte)231,(byte)65,(byte)67,(byte)94,(byte)250,(byte)109,(byte)152,(byte)95,(byte)123,(byte)77,(byte)224,(byte)124,(byte)238,(byte)205,(byte)65,(byte)103,(byte)35,(byte)104,(byte)209,(byte)5,(byte)191,(byte)47,(byte)249,(byte)176,(byte)166,(byte)213,(byte)46,(byte)192,(byte)86,(byte)32,(byte)103,(byte)146,(byte)252,(byte)4,(byte)16,(byte)54,(byte)161,(byte)60,(byte)6,(byte)13,(byte)191,(byte)116,(byte)182,(byte)42,(byte)191,(byte)213,(byte)20,(byte)217,(byte)8,(byte)142,(byte)187,(byte)238,(byte)120,(byte)184,(byte)250,(byte)31,(byte)151,(byte)37,(byte)51,(byte)177,(byte)130,(byte)190,(byte)155,(byte)71,(byte)68,(byte)56,(byte)238,(byte)92,(byte)130,(byte)37,(byte)137,(byte)146,(byte)246,(byte)114,(byte)116,(byte)138,(byte)165,(byte)217,(byte)79,(byte)10,(byte)189,(byte)128,(byte)189,(byte)2,(byte)240,(byte)92,(byte)28,(byte)126,(byte)105,(byte)236,(byte)228,(byte)194,(byte)0,(byte)51,(byte)61,(byte)74,(byte)41,(byte)10,(byte)239,(byte)133,(byte)106,(byte)190,(byte)30,(byte)27,(byte)3,(byte)240,(byte)205,(byte)253,(byte)113,(byte)25,(byte)28,(byte)187,(byte)81,(byte)101,(byte)216,(byte)121,(byte)41,(byte)179,(byte)120,(byte)152,(byte)18,(byte)116,(byte)53,(byte)212,(byte)100,(byte)2,(byte)114,(byte)198,(byte)200,(byte)10,(byte)147,(byte)25,(byte)33,(byte)115,(byte)208,(byte)113,(byte)60,(byte)179,(byte)183,(byte)0,(byte)41,(byte)217,(byte)206,(byte)255,(byte)211,(byte)225,(byte)142,(byte)191,(byte)133,(byte)81,(byte)15,(byte)248,(byte)193,(byte)66,(byte)191,(byte)244,(byte)221,(byte)248,(byte)199,(byte)241,(byte)112,(byte)51,(byte)1,(byte)180,(byte)180,(byte)125,(byte)97,(byte)145,(byte)25,(byte)72,(byte)210,(byte)215,(byte)208,(byte)15,(byte)126,(byte)56,(byte)38,(byte)65,(byte)4,(byte)64,(byte)19,(byte)74,(byte)223,(byte)111,(byte)109,(byte)52,(byte)43,(byte)167,(byte)186,(byte)202,(byte)111,(byte)11,(byte)91,(byte)21,(byte)236,(byte)234,(byte)196,(byte)36,(byte)171,(byte)147, };
        SBPMessage sbp = new SBPMessage( 0x04c3, 0xa3, payload );
        MsgFileioReadResp msg = new MsgFileioReadResp( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.contents[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[0] + "' != '" + 73 + "'", value.equals(BigInteger.valueOf( 73L ) ) );
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[1] + "' != '" + 231 + "'", value.equals(BigInteger.valueOf( 231L ) ) );
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[2] + "' != '" + 227 + "'", value.equals(BigInteger.valueOf( 227L ) ) );
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[3] + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[4] + "' != '" + 18 + "'", value.equals(BigInteger.valueOf( 18L ) ) );
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[5] + "' != '" + 76 + "'", value.equals(BigInteger.valueOf( 76L ) ) );
        } else {
            value = value.longValue();
            expected = 76L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[6] + "' != '" + 68 + "'", value.equals(BigInteger.valueOf( 68L ) ) );
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[7] + "' != '" + 229 + "'", value.equals(BigInteger.valueOf( 229L ) ) );
        } else {
            value = value.longValue();
            expected = 229L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[8] + "' != '" + 216 + "'", value.equals(BigInteger.valueOf( 216L ) ) );
        } else {
            value = value.longValue();
            expected = 216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[9] + "' != '" + 21 + "'", value.equals(BigInteger.valueOf( 21L ) ) );
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[10] + "' != '" + 98 + "'", value.equals(BigInteger.valueOf( 98L ) ) );
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[11] + "' != '" + 183 + "'", value.equals(BigInteger.valueOf( 183L ) ) );
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[12] + "' != '" + 69 + "'", value.equals(BigInteger.valueOf( 69L ) ) );
        } else {
            value = value.longValue();
            expected = 69L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[13] + "' != '" + 190 + "'", value.equals(BigInteger.valueOf( 190L ) ) );
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[14] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[15] + "' != '" + 252 + "'", value.equals(BigInteger.valueOf( 252L ) ) );
        } else {
            value = value.longValue();
            expected = 252L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[16] + "' != '" + 176 + "'", value.equals(BigInteger.valueOf( 176L ) ) );
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[17] + "' != '" + 55 + "'", value.equals(BigInteger.valueOf( 55L ) ) );
        } else {
            value = value.longValue();
            expected = 55L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[18] + "' != '" + 32 + "'", value.equals(BigInteger.valueOf( 32L ) ) );
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[19] + "' != '" + 78 + "'", value.equals(BigInteger.valueOf( 78L ) ) );
        } else {
            value = value.longValue();
            expected = 78L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[20] + "' != '" + 8 + "'", value.equals(BigInteger.valueOf( 8L ) ) );
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[21];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[21] + "' != '" + 52 + "'", value.equals(BigInteger.valueOf( 52L ) ) );
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[22];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[22] + "' != '" + 127 + "'", value.equals(BigInteger.valueOf( 127L ) ) );
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[23];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[23] + "' != '" + 50 + "'", value.equals(BigInteger.valueOf( 50L ) ) );
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[24];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[24] + "' != '" + 71 + "'", value.equals(BigInteger.valueOf( 71L ) ) );
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[25];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[25] + "' != '" + 106 + "'", value.equals(BigInteger.valueOf( 106L ) ) );
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[26];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[26] + "' != '" + 61 + "'", value.equals(BigInteger.valueOf( 61L ) ) );
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[27];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[27] + "' != '" + 79 + "'", value.equals(BigInteger.valueOf( 79L ) ) );
        } else {
            value = value.longValue();
            expected = 79L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[28];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[28] + "' != '" + 191 + "'", value.equals(BigInteger.valueOf( 191L ) ) );
        } else {
            value = value.longValue();
            expected = 191L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[29];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[29] + "' != '" + 106 + "'", value.equals(BigInteger.valueOf( 106L ) ) );
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[30];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[30] + "' != '" + 46 + "'", value.equals(BigInteger.valueOf( 46L ) ) );
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[31];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[31] + "' != '" + 79 + "'", value.equals(BigInteger.valueOf( 79L ) ) );
        } else {
            value = value.longValue();
            expected = 79L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[32];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[32] + "' != '" + 118 + "'", value.equals(BigInteger.valueOf( 118L ) ) );
        } else {
            value = value.longValue();
            expected = 118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[33];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[33] + "' != '" + 248 + "'", value.equals(BigInteger.valueOf( 248L ) ) );
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[34];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[34] + "' != '" + 118 + "'", value.equals(BigInteger.valueOf( 118L ) ) );
        } else {
            value = value.longValue();
            expected = 118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[35];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[35] + "' != '" + 207 + "'", value.equals(BigInteger.valueOf( 207L ) ) );
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[36];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[36] + "' != '" + 206 + "'", value.equals(BigInteger.valueOf( 206L ) ) );
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[37];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[37] + "' != '" + 210 + "'", value.equals(BigInteger.valueOf( 210L ) ) );
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[38];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[38] + "' != '" + 91 + "'", value.equals(BigInteger.valueOf( 91L ) ) );
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[39];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[39] + "' != '" + 73 + "'", value.equals(BigInteger.valueOf( 73L ) ) );
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[40];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[40] + "' != '" + 251 + "'", value.equals(BigInteger.valueOf( 251L ) ) );
        } else {
            value = value.longValue();
            expected = 251L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[41];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[41] + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[42];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[42] + "' != '" + 131 + "'", value.equals(BigInteger.valueOf( 131L ) ) );
        } else {
            value = value.longValue();
            expected = 131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[43];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[43] + "' != '" + 205 + "'", value.equals(BigInteger.valueOf( 205L ) ) );
        } else {
            value = value.longValue();
            expected = 205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[44];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[44] + "' != '" + 193 + "'", value.equals(BigInteger.valueOf( 193L ) ) );
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[45];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[45] + "' != '" + 146 + "'", value.equals(BigInteger.valueOf( 146L ) ) );
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[46];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[46] + "' != '" + 206 + "'", value.equals(BigInteger.valueOf( 206L ) ) );
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[47];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[47] + "' != '" + 185 + "'", value.equals(BigInteger.valueOf( 185L ) ) );
        } else {
            value = value.longValue();
            expected = 185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[48];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[48] + "' != '" + 140 + "'", value.equals(BigInteger.valueOf( 140L ) ) );
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[49];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[49] + "' != '" + 249 + "'", value.equals(BigInteger.valueOf( 249L ) ) );
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[50];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[50] + "' != '" + 163 + "'", value.equals(BigInteger.valueOf( 163L ) ) );
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[51];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[51] + "' != '" + 231 + "'", value.equals(BigInteger.valueOf( 231L ) ) );
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[52];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[52] + "' != '" + 65 + "'", value.equals(BigInteger.valueOf( 65L ) ) );
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[53];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[53] + "' != '" + 67 + "'", value.equals(BigInteger.valueOf( 67L ) ) );
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[54];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[54] + "' != '" + 94 + "'", value.equals(BigInteger.valueOf( 94L ) ) );
        } else {
            value = value.longValue();
            expected = 94L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[55];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[55] + "' != '" + 250 + "'", value.equals(BigInteger.valueOf( 250L ) ) );
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[56];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[56] + "' != '" + 109 + "'", value.equals(BigInteger.valueOf( 109L ) ) );
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[57];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[57] + "' != '" + 152 + "'", value.equals(BigInteger.valueOf( 152L ) ) );
        } else {
            value = value.longValue();
            expected = 152L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[58];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[58] + "' != '" + 95 + "'", value.equals(BigInteger.valueOf( 95L ) ) );
        } else {
            value = value.longValue();
            expected = 95L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[59];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[59] + "' != '" + 123 + "'", value.equals(BigInteger.valueOf( 123L ) ) );
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[60];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[60] + "' != '" + 77 + "'", value.equals(BigInteger.valueOf( 77L ) ) );
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[61];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[61] + "' != '" + 224 + "'", value.equals(BigInteger.valueOf( 224L ) ) );
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[62];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[62] + "' != '" + 124 + "'", value.equals(BigInteger.valueOf( 124L ) ) );
        } else {
            value = value.longValue();
            expected = 124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[63];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[63] + "' != '" + 238 + "'", value.equals(BigInteger.valueOf( 238L ) ) );
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[64];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[64] + "' != '" + 205 + "'", value.equals(BigInteger.valueOf( 205L ) ) );
        } else {
            value = value.longValue();
            expected = 205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[65];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[65] + "' != '" + 65 + "'", value.equals(BigInteger.valueOf( 65L ) ) );
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[66];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[66] + "' != '" + 103 + "'", value.equals(BigInteger.valueOf( 103L ) ) );
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[67];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[67] + "' != '" + 35 + "'", value.equals(BigInteger.valueOf( 35L ) ) );
        } else {
            value = value.longValue();
            expected = 35L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[68];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[68] + "' != '" + 104 + "'", value.equals(BigInteger.valueOf( 104L ) ) );
        } else {
            value = value.longValue();
            expected = 104L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[69];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[69] + "' != '" + 209 + "'", value.equals(BigInteger.valueOf( 209L ) ) );
        } else {
            value = value.longValue();
            expected = 209L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[70];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[70] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[71];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[71] + "' != '" + 191 + "'", value.equals(BigInteger.valueOf( 191L ) ) );
        } else {
            value = value.longValue();
            expected = 191L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[72];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[72] + "' != '" + 47 + "'", value.equals(BigInteger.valueOf( 47L ) ) );
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[73];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[73] + "' != '" + 249 + "'", value.equals(BigInteger.valueOf( 249L ) ) );
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[74];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[74] + "' != '" + 176 + "'", value.equals(BigInteger.valueOf( 176L ) ) );
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[75];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[75] + "' != '" + 166 + "'", value.equals(BigInteger.valueOf( 166L ) ) );
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[76];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[76] + "' != '" + 213 + "'", value.equals(BigInteger.valueOf( 213L ) ) );
        } else {
            value = value.longValue();
            expected = 213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[77];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[77] + "' != '" + 46 + "'", value.equals(BigInteger.valueOf( 46L ) ) );
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[78];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[78] + "' != '" + 192 + "'", value.equals(BigInteger.valueOf( 192L ) ) );
        } else {
            value = value.longValue();
            expected = 192L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[79];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[79] + "' != '" + 86 + "'", value.equals(BigInteger.valueOf( 86L ) ) );
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[80];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[80] + "' != '" + 32 + "'", value.equals(BigInteger.valueOf( 32L ) ) );
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[81];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[81] + "' != '" + 103 + "'", value.equals(BigInteger.valueOf( 103L ) ) );
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[82];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[82] + "' != '" + 146 + "'", value.equals(BigInteger.valueOf( 146L ) ) );
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[83];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[83] + "' != '" + 252 + "'", value.equals(BigInteger.valueOf( 252L ) ) );
        } else {
            value = value.longValue();
            expected = 252L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[84];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[84] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[85];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[85] + "' != '" + 16 + "'", value.equals(BigInteger.valueOf( 16L ) ) );
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[86];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[86] + "' != '" + 54 + "'", value.equals(BigInteger.valueOf( 54L ) ) );
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[87];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[87] + "' != '" + 161 + "'", value.equals(BigInteger.valueOf( 161L ) ) );
        } else {
            value = value.longValue();
            expected = 161L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[88];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[88] + "' != '" + 60 + "'", value.equals(BigInteger.valueOf( 60L ) ) );
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[89];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[89] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[90];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[90] + "' != '" + 13 + "'", value.equals(BigInteger.valueOf( 13L ) ) );
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[91];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[91] + "' != '" + 191 + "'", value.equals(BigInteger.valueOf( 191L ) ) );
        } else {
            value = value.longValue();
            expected = 191L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[92];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[92] + "' != '" + 116 + "'", value.equals(BigInteger.valueOf( 116L ) ) );
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[93];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[93] + "' != '" + 182 + "'", value.equals(BigInteger.valueOf( 182L ) ) );
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[94];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[94] + "' != '" + 42 + "'", value.equals(BigInteger.valueOf( 42L ) ) );
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[95];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[95] + "' != '" + 191 + "'", value.equals(BigInteger.valueOf( 191L ) ) );
        } else {
            value = value.longValue();
            expected = 191L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[96];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[96] + "' != '" + 213 + "'", value.equals(BigInteger.valueOf( 213L ) ) );
        } else {
            value = value.longValue();
            expected = 213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[97];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[97] + "' != '" + 20 + "'", value.equals(BigInteger.valueOf( 20L ) ) );
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[98];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[98] + "' != '" + 217 + "'", value.equals(BigInteger.valueOf( 217L ) ) );
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[99];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[99] + "' != '" + 8 + "'", value.equals(BigInteger.valueOf( 8L ) ) );
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[100];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[100] + "' != '" + 142 + "'", value.equals(BigInteger.valueOf( 142L ) ) );
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[101];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[101] + "' != '" + 187 + "'", value.equals(BigInteger.valueOf( 187L ) ) );
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[102];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[102] + "' != '" + 238 + "'", value.equals(BigInteger.valueOf( 238L ) ) );
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[103];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[103] + "' != '" + 120 + "'", value.equals(BigInteger.valueOf( 120L ) ) );
        } else {
            value = value.longValue();
            expected = 120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[104];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[104] + "' != '" + 184 + "'", value.equals(BigInteger.valueOf( 184L ) ) );
        } else {
            value = value.longValue();
            expected = 184L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[105];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[105] + "' != '" + 250 + "'", value.equals(BigInteger.valueOf( 250L ) ) );
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[106];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[106] + "' != '" + 31 + "'", value.equals(BigInteger.valueOf( 31L ) ) );
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[107];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[107] + "' != '" + 151 + "'", value.equals(BigInteger.valueOf( 151L ) ) );
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[108];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[108] + "' != '" + 37 + "'", value.equals(BigInteger.valueOf( 37L ) ) );
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[109];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[109] + "' != '" + 51 + "'", value.equals(BigInteger.valueOf( 51L ) ) );
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[110];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[110] + "' != '" + 177 + "'", value.equals(BigInteger.valueOf( 177L ) ) );
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[111];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[111] + "' != '" + 130 + "'", value.equals(BigInteger.valueOf( 130L ) ) );
        } else {
            value = value.longValue();
            expected = 130L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[112];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[112] + "' != '" + 190 + "'", value.equals(BigInteger.valueOf( 190L ) ) );
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[113];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[113] + "' != '" + 155 + "'", value.equals(BigInteger.valueOf( 155L ) ) );
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[114];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[114] + "' != '" + 71 + "'", value.equals(BigInteger.valueOf( 71L ) ) );
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[115];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[115] + "' != '" + 68 + "'", value.equals(BigInteger.valueOf( 68L ) ) );
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[116];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[116] + "' != '" + 56 + "'", value.equals(BigInteger.valueOf( 56L ) ) );
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[117];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[117] + "' != '" + 238 + "'", value.equals(BigInteger.valueOf( 238L ) ) );
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[118];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[118] + "' != '" + 92 + "'", value.equals(BigInteger.valueOf( 92L ) ) );
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[119];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[119] + "' != '" + 130 + "'", value.equals(BigInteger.valueOf( 130L ) ) );
        } else {
            value = value.longValue();
            expected = 130L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[120];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[120] + "' != '" + 37 + "'", value.equals(BigInteger.valueOf( 37L ) ) );
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[121];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[121] + "' != '" + 137 + "'", value.equals(BigInteger.valueOf( 137L ) ) );
        } else {
            value = value.longValue();
            expected = 137L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[122];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[122] + "' != '" + 146 + "'", value.equals(BigInteger.valueOf( 146L ) ) );
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[123];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[123] + "' != '" + 246 + "'", value.equals(BigInteger.valueOf( 246L ) ) );
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[124];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[124] + "' != '" + 114 + "'", value.equals(BigInteger.valueOf( 114L ) ) );
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[125];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[125] + "' != '" + 116 + "'", value.equals(BigInteger.valueOf( 116L ) ) );
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[126];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[126] + "' != '" + 138 + "'", value.equals(BigInteger.valueOf( 138L ) ) );
        } else {
            value = value.longValue();
            expected = 138L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[127];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[127] + "' != '" + 165 + "'", value.equals(BigInteger.valueOf( 165L ) ) );
        } else {
            value = value.longValue();
            expected = 165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[128];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[128] + "' != '" + 217 + "'", value.equals(BigInteger.valueOf( 217L ) ) );
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[129];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[129] + "' != '" + 79 + "'", value.equals(BigInteger.valueOf( 79L ) ) );
        } else {
            value = value.longValue();
            expected = 79L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[130];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[130] + "' != '" + 10 + "'", value.equals(BigInteger.valueOf( 10L ) ) );
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[131];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[131] + "' != '" + 189 + "'", value.equals(BigInteger.valueOf( 189L ) ) );
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[132];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[132] + "' != '" + 128 + "'", value.equals(BigInteger.valueOf( 128L ) ) );
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[133];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[133] + "' != '" + 189 + "'", value.equals(BigInteger.valueOf( 189L ) ) );
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[134];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[134] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[135];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[135] + "' != '" + 240 + "'", value.equals(BigInteger.valueOf( 240L ) ) );
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[136];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[136] + "' != '" + 92 + "'", value.equals(BigInteger.valueOf( 92L ) ) );
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[137];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[137] + "' != '" + 28 + "'", value.equals(BigInteger.valueOf( 28L ) ) );
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[138];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[138] + "' != '" + 126 + "'", value.equals(BigInteger.valueOf( 126L ) ) );
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[139];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[139] + "' != '" + 105 + "'", value.equals(BigInteger.valueOf( 105L ) ) );
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[140];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[140] + "' != '" + 236 + "'", value.equals(BigInteger.valueOf( 236L ) ) );
        } else {
            value = value.longValue();
            expected = 236L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[141];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[141] + "' != '" + 228 + "'", value.equals(BigInteger.valueOf( 228L ) ) );
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[142];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[142] + "' != '" + 194 + "'", value.equals(BigInteger.valueOf( 194L ) ) );
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[143];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[143] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[144];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[144] + "' != '" + 51 + "'", value.equals(BigInteger.valueOf( 51L ) ) );
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[145];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[145] + "' != '" + 61 + "'", value.equals(BigInteger.valueOf( 61L ) ) );
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[146];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[146] + "' != '" + 74 + "'", value.equals(BigInteger.valueOf( 74L ) ) );
        } else {
            value = value.longValue();
            expected = 74L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[147];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[147] + "' != '" + 41 + "'", value.equals(BigInteger.valueOf( 41L ) ) );
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[148];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[148] + "' != '" + 10 + "'", value.equals(BigInteger.valueOf( 10L ) ) );
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[149];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[149] + "' != '" + 239 + "'", value.equals(BigInteger.valueOf( 239L ) ) );
        } else {
            value = value.longValue();
            expected = 239L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[150];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[150] + "' != '" + 133 + "'", value.equals(BigInteger.valueOf( 133L ) ) );
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[151];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[151] + "' != '" + 106 + "'", value.equals(BigInteger.valueOf( 106L ) ) );
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[152];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[152] + "' != '" + 190 + "'", value.equals(BigInteger.valueOf( 190L ) ) );
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[153];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[153] + "' != '" + 30 + "'", value.equals(BigInteger.valueOf( 30L ) ) );
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[154];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[154] + "' != '" + 27 + "'", value.equals(BigInteger.valueOf( 27L ) ) );
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[155];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[155] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[156];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[156] + "' != '" + 240 + "'", value.equals(BigInteger.valueOf( 240L ) ) );
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[157];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[157] + "' != '" + 205 + "'", value.equals(BigInteger.valueOf( 205L ) ) );
        } else {
            value = value.longValue();
            expected = 205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[158];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[158] + "' != '" + 253 + "'", value.equals(BigInteger.valueOf( 253L ) ) );
        } else {
            value = value.longValue();
            expected = 253L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[159];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[159] + "' != '" + 113 + "'", value.equals(BigInteger.valueOf( 113L ) ) );
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[160];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[160] + "' != '" + 25 + "'", value.equals(BigInteger.valueOf( 25L ) ) );
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[161];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[161] + "' != '" + 28 + "'", value.equals(BigInteger.valueOf( 28L ) ) );
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[162];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[162] + "' != '" + 187 + "'", value.equals(BigInteger.valueOf( 187L ) ) );
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[163];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[163] + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[164];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[164] + "' != '" + 101 + "'", value.equals(BigInteger.valueOf( 101L ) ) );
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[165];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[165] + "' != '" + 216 + "'", value.equals(BigInteger.valueOf( 216L ) ) );
        } else {
            value = value.longValue();
            expected = 216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[166];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[166] + "' != '" + 121 + "'", value.equals(BigInteger.valueOf( 121L ) ) );
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[167];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[167] + "' != '" + 41 + "'", value.equals(BigInteger.valueOf( 41L ) ) );
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[168];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[168] + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[169];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[169] + "' != '" + 120 + "'", value.equals(BigInteger.valueOf( 120L ) ) );
        } else {
            value = value.longValue();
            expected = 120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[170];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[170] + "' != '" + 152 + "'", value.equals(BigInteger.valueOf( 152L ) ) );
        } else {
            value = value.longValue();
            expected = 152L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[171];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[171] + "' != '" + 18 + "'", value.equals(BigInteger.valueOf( 18L ) ) );
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[172];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[172] + "' != '" + 116 + "'", value.equals(BigInteger.valueOf( 116L ) ) );
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[173];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[173] + "' != '" + 53 + "'", value.equals(BigInteger.valueOf( 53L ) ) );
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[174];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[174] + "' != '" + 212 + "'", value.equals(BigInteger.valueOf( 212L ) ) );
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[175];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[175] + "' != '" + 100 + "'", value.equals(BigInteger.valueOf( 100L ) ) );
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[176];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[176] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[177];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[177] + "' != '" + 114 + "'", value.equals(BigInteger.valueOf( 114L ) ) );
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[178];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[178] + "' != '" + 198 + "'", value.equals(BigInteger.valueOf( 198L ) ) );
        } else {
            value = value.longValue();
            expected = 198L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[179];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[179] + "' != '" + 200 + "'", value.equals(BigInteger.valueOf( 200L ) ) );
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[180];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[180] + "' != '" + 10 + "'", value.equals(BigInteger.valueOf( 10L ) ) );
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[181];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[181] + "' != '" + 147 + "'", value.equals(BigInteger.valueOf( 147L ) ) );
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[182];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[182] + "' != '" + 25 + "'", value.equals(BigInteger.valueOf( 25L ) ) );
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[183];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[183] + "' != '" + 33 + "'", value.equals(BigInteger.valueOf( 33L ) ) );
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[184];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[184] + "' != '" + 115 + "'", value.equals(BigInteger.valueOf( 115L ) ) );
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[185];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[185] + "' != '" + 208 + "'", value.equals(BigInteger.valueOf( 208L ) ) );
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[186];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[186] + "' != '" + 113 + "'", value.equals(BigInteger.valueOf( 113L ) ) );
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[187];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[187] + "' != '" + 60 + "'", value.equals(BigInteger.valueOf( 60L ) ) );
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[188];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[188] + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[189];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[189] + "' != '" + 183 + "'", value.equals(BigInteger.valueOf( 183L ) ) );
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[190];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[190] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[191];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[191] + "' != '" + 41 + "'", value.equals(BigInteger.valueOf( 41L ) ) );
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[192];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[192] + "' != '" + 217 + "'", value.equals(BigInteger.valueOf( 217L ) ) );
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[193];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[193] + "' != '" + 206 + "'", value.equals(BigInteger.valueOf( 206L ) ) );
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[194];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[194] + "' != '" + 255 + "'", value.equals(BigInteger.valueOf( 255L ) ) );
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[195];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[195] + "' != '" + 211 + "'", value.equals(BigInteger.valueOf( 211L ) ) );
        } else {
            value = value.longValue();
            expected = 211L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[196];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[196] + "' != '" + 225 + "'", value.equals(BigInteger.valueOf( 225L ) ) );
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[197];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[197] + "' != '" + 142 + "'", value.equals(BigInteger.valueOf( 142L ) ) );
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[198];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[198] + "' != '" + 191 + "'", value.equals(BigInteger.valueOf( 191L ) ) );
        } else {
            value = value.longValue();
            expected = 191L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[199];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[199] + "' != '" + 133 + "'", value.equals(BigInteger.valueOf( 133L ) ) );
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[200];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[200] + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[201];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[201] + "' != '" + 15 + "'", value.equals(BigInteger.valueOf( 15L ) ) );
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[202];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[202] + "' != '" + 248 + "'", value.equals(BigInteger.valueOf( 248L ) ) );
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[203];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[203] + "' != '" + 193 + "'", value.equals(BigInteger.valueOf( 193L ) ) );
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[204];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[204] + "' != '" + 66 + "'", value.equals(BigInteger.valueOf( 66L ) ) );
        } else {
            value = value.longValue();
            expected = 66L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[205];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[205] + "' != '" + 191 + "'", value.equals(BigInteger.valueOf( 191L ) ) );
        } else {
            value = value.longValue();
            expected = 191L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[206];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[206] + "' != '" + 244 + "'", value.equals(BigInteger.valueOf( 244L ) ) );
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[207];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[207] + "' != '" + 221 + "'", value.equals(BigInteger.valueOf( 221L ) ) );
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[208];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[208] + "' != '" + 248 + "'", value.equals(BigInteger.valueOf( 248L ) ) );
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[209];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[209] + "' != '" + 199 + "'", value.equals(BigInteger.valueOf( 199L ) ) );
        } else {
            value = value.longValue();
            expected = 199L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[210];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[210] + "' != '" + 241 + "'", value.equals(BigInteger.valueOf( 241L ) ) );
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[211];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[211] + "' != '" + 112 + "'", value.equals(BigInteger.valueOf( 112L ) ) );
        } else {
            value = value.longValue();
            expected = 112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[212];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[212] + "' != '" + 51 + "'", value.equals(BigInteger.valueOf( 51L ) ) );
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[213];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[213] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[214];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[214] + "' != '" + 180 + "'", value.equals(BigInteger.valueOf( 180L ) ) );
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[215];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[215] + "' != '" + 180 + "'", value.equals(BigInteger.valueOf( 180L ) ) );
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[216];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[216] + "' != '" + 125 + "'", value.equals(BigInteger.valueOf( 125L ) ) );
        } else {
            value = value.longValue();
            expected = 125L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[217];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[217] + "' != '" + 97 + "'", value.equals(BigInteger.valueOf( 97L ) ) );
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[218];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[218] + "' != '" + 145 + "'", value.equals(BigInteger.valueOf( 145L ) ) );
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[219];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[219] + "' != '" + 25 + "'", value.equals(BigInteger.valueOf( 25L ) ) );
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[220];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[220] + "' != '" + 72 + "'", value.equals(BigInteger.valueOf( 72L ) ) );
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[221];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[221] + "' != '" + 210 + "'", value.equals(BigInteger.valueOf( 210L ) ) );
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[222];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[222] + "' != '" + 215 + "'", value.equals(BigInteger.valueOf( 215L ) ) );
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[223];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[223] + "' != '" + 208 + "'", value.equals(BigInteger.valueOf( 208L ) ) );
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[224];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[224] + "' != '" + 15 + "'", value.equals(BigInteger.valueOf( 15L ) ) );
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[225];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[225] + "' != '" + 126 + "'", value.equals(BigInteger.valueOf( 126L ) ) );
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[226];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[226] + "' != '" + 56 + "'", value.equals(BigInteger.valueOf( 56L ) ) );
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[227];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[227] + "' != '" + 38 + "'", value.equals(BigInteger.valueOf( 38L ) ) );
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[228];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[228] + "' != '" + 65 + "'", value.equals(BigInteger.valueOf( 65L ) ) );
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[229];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[229] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[230];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[230] + "' != '" + 64 + "'", value.equals(BigInteger.valueOf( 64L ) ) );
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[231];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[231] + "' != '" + 19 + "'", value.equals(BigInteger.valueOf( 19L ) ) );
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[232];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[232] + "' != '" + 74 + "'", value.equals(BigInteger.valueOf( 74L ) ) );
        } else {
            value = value.longValue();
            expected = 74L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[233];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[233] + "' != '" + 223 + "'", value.equals(BigInteger.valueOf( 223L ) ) );
        } else {
            value = value.longValue();
            expected = 223L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[234];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[234] + "' != '" + 111 + "'", value.equals(BigInteger.valueOf( 111L ) ) );
        } else {
            value = value.longValue();
            expected = 111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[235];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[235] + "' != '" + 109 + "'", value.equals(BigInteger.valueOf( 109L ) ) );
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[236];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[236] + "' != '" + 52 + "'", value.equals(BigInteger.valueOf( 52L ) ) );
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[237];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[237] + "' != '" + 43 + "'", value.equals(BigInteger.valueOf( 43L ) ) );
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[238];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[238] + "' != '" + 167 + "'", value.equals(BigInteger.valueOf( 167L ) ) );
        } else {
            value = value.longValue();
            expected = 167L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[239];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[239] + "' != '" + 186 + "'", value.equals(BigInteger.valueOf( 186L ) ) );
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[240];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[240] + "' != '" + 202 + "'", value.equals(BigInteger.valueOf( 202L ) ) );
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[241];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[241] + "' != '" + 111 + "'", value.equals(BigInteger.valueOf( 111L ) ) );
        } else {
            value = value.longValue();
            expected = 111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[242];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[242] + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[243];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[243] + "' != '" + 91 + "'", value.equals(BigInteger.valueOf( 91L ) ) );
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[244];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[244] + "' != '" + 21 + "'", value.equals(BigInteger.valueOf( 21L ) ) );
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[245];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[245] + "' != '" + 236 + "'", value.equals(BigInteger.valueOf( 236L ) ) );
        } else {
            value = value.longValue();
            expected = 236L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[246];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[246] + "' != '" + 234 + "'", value.equals(BigInteger.valueOf( 234L ) ) );
        } else {
            value = value.longValue();
            expected = 234L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[247];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[247] + "' != '" + 196 + "'", value.equals(BigInteger.valueOf( 196L ) ) );
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[248];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[248] + "' != '" + 36 + "'", value.equals(BigInteger.valueOf( 36L ) ) );
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[249];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[249] + "' != '" + 171 + "'", value.equals(BigInteger.valueOf( 171L ) ) );
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[250];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.contents[250] + "' != '" + 147 + "'", value.equals(BigInteger.valueOf( 147L ) ) );
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sequence;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sequence + "' != '" + 259241795 + "'", value.equals(BigInteger.valueOf( 259241795L ) ) );
        } else {
            value = value.longValue();
            expected = 259241795L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
