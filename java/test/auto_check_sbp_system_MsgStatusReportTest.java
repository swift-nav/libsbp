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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusReport.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.system.MsgStatusReport;


public class auto_check_sbp_system_MsgStatusReportTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_system_MsgStatusReportTest.test1");
        byte[] payload = new byte[] {(byte)82,(byte)253,(byte)177,(byte)95,(byte)3,(byte)60,(byte)143,(byte)90,(byte)233,(byte)21,(byte)208,(byte)98,(byte)247,(byte)203,(byte)221,(byte)198,(byte)156,(byte)207,(byte)217,(byte)238,(byte)162,(byte)136,(byte)154,(byte)11,(byte)114,(byte)236,(byte)134,(byte)235,(byte)12,(byte)133,(byte)9,(byte)30,(byte)175,(byte)145,(byte)26,(byte)114,(byte)215,(byte)20,(byte)146,(byte)249,(byte)54,(byte)54,(byte)133,(byte)193,(byte)106,(byte)186,(byte)210,(byte)183,(byte)0,(byte)129,(byte)5,(byte)248,(byte)225,(byte)149,(byte)135,(byte)127,(byte)2,(byte)26,(byte)88,(byte)92,(byte)10,(byte)103,(byte)73,(byte)3,(byte)103,(byte)68,(byte)76,(byte)184,(byte)33,(byte)206,(byte)194,(byte)163,(byte)123,(byte)30,(byte)151,(byte)176,(byte)149,(byte)172,(byte)184,(byte)231,(byte)118,(byte)230,(byte)200,(byte)168,(byte)100,(byte)109,(byte)10,(byte)233,(byte)4,(byte)60,(byte)247,(byte)82,(byte)215,(byte)166,(byte)28,(byte)138,(byte)110,(byte)45,(byte)98,(byte)218,(byte)244,(byte)179,(byte)126,(byte)107,(byte)92,(byte)124,(byte)94,(byte)157,(byte)42,(byte)187,(byte)124,(byte)6,(byte)97,(byte)247,(byte)160,(byte)188,(byte)110,(byte)120,(byte)254,(byte)214,(byte)110,(byte)51,(byte)240,(byte)164,(byte)147,(byte)18,(byte)74,(byte)178,(byte)67,(byte)4,(byte)27,(byte)73,(byte)190,(byte)64,(byte)179,(byte)146,(byte)125,(byte)153,(byte)192,(byte)46,(byte)202,(byte)66,(byte)248,(byte)46,(byte)40,(byte)161,(byte)173,(byte)242,(byte)214,(byte)3,(byte)11,(byte)1,(byte)118,(byte)70,(byte)162,(byte)61,(byte)178,(byte)27,(byte)156,(byte)40,(byte)191,(byte)113,(byte)230,(byte)200,(byte)72,(byte)8,(byte)215,(byte)245,(byte)78,(byte)59,(byte)222,(byte)250,(byte)115,(byte)32,(byte)33,(byte)30,(byte)211,(byte)170,(byte)145,(byte)92,(byte)157,(byte)75,(byte)24,(byte)169,(byte)6,(byte)55,(byte)62,(byte)8,(byte)107,(byte)82,(byte)140,(byte)49,(byte)179,(byte)122,(byte)90,(byte)71,(byte)28,(byte)88,(byte)103,(byte)51,(byte)177,(byte)72,(byte)93,(byte)39,(byte)148,(byte)11,(byte)202,(byte)42,(byte)34,(byte)92,(byte)204,(byte)102,(byte)29,(byte)98,(byte)249,(byte)91,(byte)134,(byte)95,(byte)23,(byte)248,(byte)192,(byte)20,(byte)83,(byte)195,(byte)95,(byte)180,(byte)54,(byte)36,(byte)186,(byte)75,(byte)64,(byte)20,(byte)157,(byte)133,(byte)12,(byte)149,(byte)28,(byte)14,(byte)185,(byte)129,(byte)101,(byte)239,(byte)74,(byte)248,(byte)245,(byte)30,(byte)228,(byte)88,(byte)142,(byte)212,(byte)53,(byte)224, };
        SBPMessage sbp = new SBPMessage( 0x5406, 0xfffe, payload );
        MsgStatusReport msg = new MsgStatusReport( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.reporting_system;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.reporting_system + "' != '" + 64850 + "'", value.equals(BigInteger.valueOf( 64850L ) ) );
        } else {
            value = value.longValue();
            expected = 64850L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sbp_version;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sbp_version + "' != '" + 24497 + "'", value.equals(BigInteger.valueOf( 24497L ) ) );
        } else {
            value = value.longValue();
            expected = 24497L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sequence;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sequence + "' != '" + 1519336451 + "'", value.equals(BigInteger.valueOf( 1519336451L ) ) );
        } else {
            value = value.longValue();
            expected = 1519336451L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[0].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[0].component + "' != '" + 52215 + "'", value.equals(BigInteger.valueOf( 52215L ) ) );
        } else {
            value = value.longValue();
            expected = 52215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[0].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[0].generic + "' != '" + 221 + "'", value.equals(BigInteger.valueOf( 221L ) ) );
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[0].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[0].specific + "' != '" + 198 + "'", value.equals(BigInteger.valueOf( 198L ) ) );
        } else {
            value = value.longValue();
            expected = 198L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[1].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[1].component + "' != '" + 53148 + "'", value.equals(BigInteger.valueOf( 53148L ) ) );
        } else {
            value = value.longValue();
            expected = 53148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[1].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[1].generic + "' != '" + 217 + "'", value.equals(BigInteger.valueOf( 217L ) ) );
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[1].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[1].specific + "' != '" + 238 + "'", value.equals(BigInteger.valueOf( 238L ) ) );
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[2].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[2].component + "' != '" + 34978 + "'", value.equals(BigInteger.valueOf( 34978L ) ) );
        } else {
            value = value.longValue();
            expected = 34978L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[2].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[2].generic + "' != '" + 154 + "'", value.equals(BigInteger.valueOf( 154L ) ) );
        } else {
            value = value.longValue();
            expected = 154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[2].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[2].specific + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[3].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[3].component + "' != '" + 60530 + "'", value.equals(BigInteger.valueOf( 60530L ) ) );
        } else {
            value = value.longValue();
            expected = 60530L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[3].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[3].generic + "' != '" + 134 + "'", value.equals(BigInteger.valueOf( 134L ) ) );
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[3].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[3].specific + "' != '" + 235 + "'", value.equals(BigInteger.valueOf( 235L ) ) );
        } else {
            value = value.longValue();
            expected = 235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[4].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[4].component + "' != '" + 34060 + "'", value.equals(BigInteger.valueOf( 34060L ) ) );
        } else {
            value = value.longValue();
            expected = 34060L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[4].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[4].generic + "' != '" + 9 + "'", value.equals(BigInteger.valueOf( 9L ) ) );
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[4].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[4].specific + "' != '" + 30 + "'", value.equals(BigInteger.valueOf( 30L ) ) );
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[5].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[5].component + "' != '" + 37295 + "'", value.equals(BigInteger.valueOf( 37295L ) ) );
        } else {
            value = value.longValue();
            expected = 37295L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[5].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[5].generic + "' != '" + 26 + "'", value.equals(BigInteger.valueOf( 26L ) ) );
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[5].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[5].specific + "' != '" + 114 + "'", value.equals(BigInteger.valueOf( 114L ) ) );
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[6].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[6].component + "' != '" + 5335 + "'", value.equals(BigInteger.valueOf( 5335L ) ) );
        } else {
            value = value.longValue();
            expected = 5335L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[6].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[6].generic + "' != '" + 146 + "'", value.equals(BigInteger.valueOf( 146L ) ) );
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[6].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[6].specific + "' != '" + 249 + "'", value.equals(BigInteger.valueOf( 249L ) ) );
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[7].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[7].component + "' != '" + 13878 + "'", value.equals(BigInteger.valueOf( 13878L ) ) );
        } else {
            value = value.longValue();
            expected = 13878L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[7].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[7].generic + "' != '" + 133 + "'", value.equals(BigInteger.valueOf( 133L ) ) );
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[7].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[7].specific + "' != '" + 193 + "'", value.equals(BigInteger.valueOf( 193L ) ) );
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[8].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[8].component + "' != '" + 47722 + "'", value.equals(BigInteger.valueOf( 47722L ) ) );
        } else {
            value = value.longValue();
            expected = 47722L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[8].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[8].generic + "' != '" + 210 + "'", value.equals(BigInteger.valueOf( 210L ) ) );
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[8].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[8].specific + "' != '" + 183 + "'", value.equals(BigInteger.valueOf( 183L ) ) );
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[9].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[9].component + "' != '" + 33024 + "'", value.equals(BigInteger.valueOf( 33024L ) ) );
        } else {
            value = value.longValue();
            expected = 33024L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[9].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[9].generic + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[9].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[9].specific + "' != '" + 248 + "'", value.equals(BigInteger.valueOf( 248L ) ) );
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[10].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[10].component + "' != '" + 38369 + "'", value.equals(BigInteger.valueOf( 38369L ) ) );
        } else {
            value = value.longValue();
            expected = 38369L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[10].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[10].generic + "' != '" + 135 + "'", value.equals(BigInteger.valueOf( 135L ) ) );
        } else {
            value = value.longValue();
            expected = 135L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[10].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[10].specific + "' != '" + 127 + "'", value.equals(BigInteger.valueOf( 127L ) ) );
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[11].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[11].component + "' != '" + 6658 + "'", value.equals(BigInteger.valueOf( 6658L ) ) );
        } else {
            value = value.longValue();
            expected = 6658L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[11].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[11].generic + "' != '" + 88 + "'", value.equals(BigInteger.valueOf( 88L ) ) );
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[11].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[11].specific + "' != '" + 92 + "'", value.equals(BigInteger.valueOf( 92L ) ) );
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[12].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[12].component + "' != '" + 26378 + "'", value.equals(BigInteger.valueOf( 26378L ) ) );
        } else {
            value = value.longValue();
            expected = 26378L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[12].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[12].generic + "' != '" + 73 + "'", value.equals(BigInteger.valueOf( 73L ) ) );
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[12].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[12].specific + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[13].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[13].component + "' != '" + 17511 + "'", value.equals(BigInteger.valueOf( 17511L ) ) );
        } else {
            value = value.longValue();
            expected = 17511L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[13].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[13].generic + "' != '" + 76 + "'", value.equals(BigInteger.valueOf( 76L ) ) );
        } else {
            value = value.longValue();
            expected = 76L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[13].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[13].specific + "' != '" + 184 + "'", value.equals(BigInteger.valueOf( 184L ) ) );
        } else {
            value = value.longValue();
            expected = 184L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[14].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[14].component + "' != '" + 52769 + "'", value.equals(BigInteger.valueOf( 52769L ) ) );
        } else {
            value = value.longValue();
            expected = 52769L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[14].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[14].generic + "' != '" + 194 + "'", value.equals(BigInteger.valueOf( 194L ) ) );
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[14].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[14].specific + "' != '" + 163 + "'", value.equals(BigInteger.valueOf( 163L ) ) );
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[15].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[15].component + "' != '" + 7803 + "'", value.equals(BigInteger.valueOf( 7803L ) ) );
        } else {
            value = value.longValue();
            expected = 7803L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[15].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[15].generic + "' != '" + 151 + "'", value.equals(BigInteger.valueOf( 151L ) ) );
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[15].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[15].specific + "' != '" + 176 + "'", value.equals(BigInteger.valueOf( 176L ) ) );
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[16].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[16].component + "' != '" + 44181 + "'", value.equals(BigInteger.valueOf( 44181L ) ) );
        } else {
            value = value.longValue();
            expected = 44181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[16].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[16].generic + "' != '" + 184 + "'", value.equals(BigInteger.valueOf( 184L ) ) );
        } else {
            value = value.longValue();
            expected = 184L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[16].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[16].specific + "' != '" + 231 + "'", value.equals(BigInteger.valueOf( 231L ) ) );
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[17].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[17].component + "' != '" + 58998 + "'", value.equals(BigInteger.valueOf( 58998L ) ) );
        } else {
            value = value.longValue();
            expected = 58998L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[17].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[17].generic + "' != '" + 200 + "'", value.equals(BigInteger.valueOf( 200L ) ) );
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[17].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[17].specific + "' != '" + 168 + "'", value.equals(BigInteger.valueOf( 168L ) ) );
        } else {
            value = value.longValue();
            expected = 168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[18].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[18].component + "' != '" + 28004 + "'", value.equals(BigInteger.valueOf( 28004L ) ) );
        } else {
            value = value.longValue();
            expected = 28004L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[18].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[18].generic + "' != '" + 10 + "'", value.equals(BigInteger.valueOf( 10L ) ) );
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[18].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[18].specific + "' != '" + 233 + "'", value.equals(BigInteger.valueOf( 233L ) ) );
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[19].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[19].component + "' != '" + 15364 + "'", value.equals(BigInteger.valueOf( 15364L ) ) );
        } else {
            value = value.longValue();
            expected = 15364L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[19].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[19].generic + "' != '" + 247 + "'", value.equals(BigInteger.valueOf( 247L ) ) );
        } else {
            value = value.longValue();
            expected = 247L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[19].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[19].specific + "' != '" + 82 + "'", value.equals(BigInteger.valueOf( 82L ) ) );
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[20].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[20].component + "' != '" + 42711 + "'", value.equals(BigInteger.valueOf( 42711L ) ) );
        } else {
            value = value.longValue();
            expected = 42711L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[20].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[20].generic + "' != '" + 28 + "'", value.equals(BigInteger.valueOf( 28L ) ) );
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[20].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[20].specific + "' != '" + 138 + "'", value.equals(BigInteger.valueOf( 138L ) ) );
        } else {
            value = value.longValue();
            expected = 138L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[21].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[21].component + "' != '" + 11630 + "'", value.equals(BigInteger.valueOf( 11630L ) ) );
        } else {
            value = value.longValue();
            expected = 11630L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[21].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[21].generic + "' != '" + 98 + "'", value.equals(BigInteger.valueOf( 98L ) ) );
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[21].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[21].specific + "' != '" + 218 + "'", value.equals(BigInteger.valueOf( 218L ) ) );
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[22].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[22].component + "' != '" + 46068 + "'", value.equals(BigInteger.valueOf( 46068L ) ) );
        } else {
            value = value.longValue();
            expected = 46068L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[22].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[22].generic + "' != '" + 126 + "'", value.equals(BigInteger.valueOf( 126L ) ) );
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[22].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[22].specific + "' != '" + 107 + "'", value.equals(BigInteger.valueOf( 107L ) ) );
        } else {
            value = value.longValue();
            expected = 107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[23].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[23].component + "' != '" + 31836 + "'", value.equals(BigInteger.valueOf( 31836L ) ) );
        } else {
            value = value.longValue();
            expected = 31836L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[23].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[23].generic + "' != '" + 94 + "'", value.equals(BigInteger.valueOf( 94L ) ) );
        } else {
            value = value.longValue();
            expected = 94L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[23].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[23].specific + "' != '" + 157 + "'", value.equals(BigInteger.valueOf( 157L ) ) );
        } else {
            value = value.longValue();
            expected = 157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[24].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[24].component + "' != '" + 47914 + "'", value.equals(BigInteger.valueOf( 47914L ) ) );
        } else {
            value = value.longValue();
            expected = 47914L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[24].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[24].generic + "' != '" + 124 + "'", value.equals(BigInteger.valueOf( 124L ) ) );
        } else {
            value = value.longValue();
            expected = 124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[24].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[24].specific + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[25].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[25].component + "' != '" + 63329 + "'", value.equals(BigInteger.valueOf( 63329L ) ) );
        } else {
            value = value.longValue();
            expected = 63329L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[25].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[25].generic + "' != '" + 160 + "'", value.equals(BigInteger.valueOf( 160L ) ) );
        } else {
            value = value.longValue();
            expected = 160L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[25].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[25].specific + "' != '" + 188 + "'", value.equals(BigInteger.valueOf( 188L ) ) );
        } else {
            value = value.longValue();
            expected = 188L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[26].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[26].component + "' != '" + 30830 + "'", value.equals(BigInteger.valueOf( 30830L ) ) );
        } else {
            value = value.longValue();
            expected = 30830L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[26].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[26].generic + "' != '" + 254 + "'", value.equals(BigInteger.valueOf( 254L ) ) );
        } else {
            value = value.longValue();
            expected = 254L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[26].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[26].specific + "' != '" + 214 + "'", value.equals(BigInteger.valueOf( 214L ) ) );
        } else {
            value = value.longValue();
            expected = 214L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[27].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[27].component + "' != '" + 13166 + "'", value.equals(BigInteger.valueOf( 13166L ) ) );
        } else {
            value = value.longValue();
            expected = 13166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[27].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[27].generic + "' != '" + 240 + "'", value.equals(BigInteger.valueOf( 240L ) ) );
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[27].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[27].specific + "' != '" + 164 + "'", value.equals(BigInteger.valueOf( 164L ) ) );
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[28].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[28].component + "' != '" + 4755 + "'", value.equals(BigInteger.valueOf( 4755L ) ) );
        } else {
            value = value.longValue();
            expected = 4755L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[28].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[28].generic + "' != '" + 74 + "'", value.equals(BigInteger.valueOf( 74L ) ) );
        } else {
            value = value.longValue();
            expected = 74L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[28].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[28].specific + "' != '" + 178 + "'", value.equals(BigInteger.valueOf( 178L ) ) );
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[29].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[29].component + "' != '" + 1091 + "'", value.equals(BigInteger.valueOf( 1091L ) ) );
        } else {
            value = value.longValue();
            expected = 1091L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[29].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[29].generic + "' != '" + 27 + "'", value.equals(BigInteger.valueOf( 27L ) ) );
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[29].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[29].specific + "' != '" + 73 + "'", value.equals(BigInteger.valueOf( 73L ) ) );
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[30].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[30].component + "' != '" + 16574 + "'", value.equals(BigInteger.valueOf( 16574L ) ) );
        } else {
            value = value.longValue();
            expected = 16574L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[30].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[30].generic + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[30].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[30].specific + "' != '" + 146 + "'", value.equals(BigInteger.valueOf( 146L ) ) );
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[31].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[31].component + "' != '" + 39293 + "'", value.equals(BigInteger.valueOf( 39293L ) ) );
        } else {
            value = value.longValue();
            expected = 39293L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[31].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[31].generic + "' != '" + 192 + "'", value.equals(BigInteger.valueOf( 192L ) ) );
        } else {
            value = value.longValue();
            expected = 192L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[31].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[31].specific + "' != '" + 46 + "'", value.equals(BigInteger.valueOf( 46L ) ) );
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[32].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[32].component + "' != '" + 17098 + "'", value.equals(BigInteger.valueOf( 17098L ) ) );
        } else {
            value = value.longValue();
            expected = 17098L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[32].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[32].generic + "' != '" + 248 + "'", value.equals(BigInteger.valueOf( 248L ) ) );
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[32].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[32].specific + "' != '" + 46 + "'", value.equals(BigInteger.valueOf( 46L ) ) );
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[33].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[33].component + "' != '" + 41256 + "'", value.equals(BigInteger.valueOf( 41256L ) ) );
        } else {
            value = value.longValue();
            expected = 41256L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[33].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[33].generic + "' != '" + 173 + "'", value.equals(BigInteger.valueOf( 173L ) ) );
        } else {
            value = value.longValue();
            expected = 173L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[33].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[33].specific + "' != '" + 242 + "'", value.equals(BigInteger.valueOf( 242L ) ) );
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[34].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[34].component + "' != '" + 982 + "'", value.equals(BigInteger.valueOf( 982L ) ) );
        } else {
            value = value.longValue();
            expected = 982L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[34].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[34].generic + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[34].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[34].specific + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[35].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[35].component + "' != '" + 18038 + "'", value.equals(BigInteger.valueOf( 18038L ) ) );
        } else {
            value = value.longValue();
            expected = 18038L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[35].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[35].generic + "' != '" + 162 + "'", value.equals(BigInteger.valueOf( 162L ) ) );
        } else {
            value = value.longValue();
            expected = 162L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[35].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[35].specific + "' != '" + 61 + "'", value.equals(BigInteger.valueOf( 61L ) ) );
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[36].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[36].component + "' != '" + 7090 + "'", value.equals(BigInteger.valueOf( 7090L ) ) );
        } else {
            value = value.longValue();
            expected = 7090L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[36].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[36].generic + "' != '" + 156 + "'", value.equals(BigInteger.valueOf( 156L ) ) );
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[36].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[36].specific + "' != '" + 40 + "'", value.equals(BigInteger.valueOf( 40L ) ) );
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[37].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[37].component + "' != '" + 29119 + "'", value.equals(BigInteger.valueOf( 29119L ) ) );
        } else {
            value = value.longValue();
            expected = 29119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[37].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[37].generic + "' != '" + 230 + "'", value.equals(BigInteger.valueOf( 230L ) ) );
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[37].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[37].specific + "' != '" + 200 + "'", value.equals(BigInteger.valueOf( 200L ) ) );
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[38].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[38].component + "' != '" + 2120 + "'", value.equals(BigInteger.valueOf( 2120L ) ) );
        } else {
            value = value.longValue();
            expected = 2120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[38].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[38].generic + "' != '" + 215 + "'", value.equals(BigInteger.valueOf( 215L ) ) );
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[38].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[38].specific + "' != '" + 245 + "'", value.equals(BigInteger.valueOf( 245L ) ) );
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[39].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[39].component + "' != '" + 15182 + "'", value.equals(BigInteger.valueOf( 15182L ) ) );
        } else {
            value = value.longValue();
            expected = 15182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[39].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[39].generic + "' != '" + 222 + "'", value.equals(BigInteger.valueOf( 222L ) ) );
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[39].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[39].specific + "' != '" + 250 + "'", value.equals(BigInteger.valueOf( 250L ) ) );
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[40].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[40].component + "' != '" + 8307 + "'", value.equals(BigInteger.valueOf( 8307L ) ) );
        } else {
            value = value.longValue();
            expected = 8307L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[40].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[40].generic + "' != '" + 33 + "'", value.equals(BigInteger.valueOf( 33L ) ) );
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[40].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[40].specific + "' != '" + 30 + "'", value.equals(BigInteger.valueOf( 30L ) ) );
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[41].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[41].component + "' != '" + 43731 + "'", value.equals(BigInteger.valueOf( 43731L ) ) );
        } else {
            value = value.longValue();
            expected = 43731L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[41].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[41].generic + "' != '" + 145 + "'", value.equals(BigInteger.valueOf( 145L ) ) );
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[41].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[41].specific + "' != '" + 92 + "'", value.equals(BigInteger.valueOf( 92L ) ) );
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[42].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[42].component + "' != '" + 19357 + "'", value.equals(BigInteger.valueOf( 19357L ) ) );
        } else {
            value = value.longValue();
            expected = 19357L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[42].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[42].generic + "' != '" + 24 + "'", value.equals(BigInteger.valueOf( 24L ) ) );
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[42].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[42].specific + "' != '" + 169 + "'", value.equals(BigInteger.valueOf( 169L ) ) );
        } else {
            value = value.longValue();
            expected = 169L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[43].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[43].component + "' != '" + 14086 + "'", value.equals(BigInteger.valueOf( 14086L ) ) );
        } else {
            value = value.longValue();
            expected = 14086L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[43].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[43].generic + "' != '" + 62 + "'", value.equals(BigInteger.valueOf( 62L ) ) );
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[43].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[43].specific + "' != '" + 8 + "'", value.equals(BigInteger.valueOf( 8L ) ) );
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[44].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[44].component + "' != '" + 21099 + "'", value.equals(BigInteger.valueOf( 21099L ) ) );
        } else {
            value = value.longValue();
            expected = 21099L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[44].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[44].generic + "' != '" + 140 + "'", value.equals(BigInteger.valueOf( 140L ) ) );
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[44].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[44].specific + "' != '" + 49 + "'", value.equals(BigInteger.valueOf( 49L ) ) );
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[45].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[45].component + "' != '" + 31411 + "'", value.equals(BigInteger.valueOf( 31411L ) ) );
        } else {
            value = value.longValue();
            expected = 31411L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[45].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[45].generic + "' != '" + 90 + "'", value.equals(BigInteger.valueOf( 90L ) ) );
        } else {
            value = value.longValue();
            expected = 90L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[45].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[45].specific + "' != '" + 71 + "'", value.equals(BigInteger.valueOf( 71L ) ) );
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[46].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[46].component + "' != '" + 22556 + "'", value.equals(BigInteger.valueOf( 22556L ) ) );
        } else {
            value = value.longValue();
            expected = 22556L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[46].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[46].generic + "' != '" + 103 + "'", value.equals(BigInteger.valueOf( 103L ) ) );
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[46].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[46].specific + "' != '" + 51 + "'", value.equals(BigInteger.valueOf( 51L ) ) );
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[47].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[47].component + "' != '" + 18609 + "'", value.equals(BigInteger.valueOf( 18609L ) ) );
        } else {
            value = value.longValue();
            expected = 18609L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[47].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[47].generic + "' != '" + 93 + "'", value.equals(BigInteger.valueOf( 93L ) ) );
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[47].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[47].specific + "' != '" + 39 + "'", value.equals(BigInteger.valueOf( 39L ) ) );
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[48].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[48].component + "' != '" + 2964 + "'", value.equals(BigInteger.valueOf( 2964L ) ) );
        } else {
            value = value.longValue();
            expected = 2964L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[48].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[48].generic + "' != '" + 202 + "'", value.equals(BigInteger.valueOf( 202L ) ) );
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[48].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[48].specific + "' != '" + 42 + "'", value.equals(BigInteger.valueOf( 42L ) ) );
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[49].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[49].component + "' != '" + 23586 + "'", value.equals(BigInteger.valueOf( 23586L ) ) );
        } else {
            value = value.longValue();
            expected = 23586L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[49].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[49].generic + "' != '" + 204 + "'", value.equals(BigInteger.valueOf( 204L ) ) );
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[49].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[49].specific + "' != '" + 102 + "'", value.equals(BigInteger.valueOf( 102L ) ) );
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[50].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[50].component + "' != '" + 25117 + "'", value.equals(BigInteger.valueOf( 25117L ) ) );
        } else {
            value = value.longValue();
            expected = 25117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[50].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[50].generic + "' != '" + 249 + "'", value.equals(BigInteger.valueOf( 249L ) ) );
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[50].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[50].specific + "' != '" + 91 + "'", value.equals(BigInteger.valueOf( 91L ) ) );
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[51].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[51].component + "' != '" + 24454 + "'", value.equals(BigInteger.valueOf( 24454L ) ) );
        } else {
            value = value.longValue();
            expected = 24454L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[51].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[51].generic + "' != '" + 23 + "'", value.equals(BigInteger.valueOf( 23L ) ) );
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[51].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[51].specific + "' != '" + 248 + "'", value.equals(BigInteger.valueOf( 248L ) ) );
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[52].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[52].component + "' != '" + 5312 + "'", value.equals(BigInteger.valueOf( 5312L ) ) );
        } else {
            value = value.longValue();
            expected = 5312L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[52].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[52].generic + "' != '" + 83 + "'", value.equals(BigInteger.valueOf( 83L ) ) );
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[52].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[52].specific + "' != '" + 195 + "'", value.equals(BigInteger.valueOf( 195L ) ) );
        } else {
            value = value.longValue();
            expected = 195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[53].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[53].component + "' != '" + 46175 + "'", value.equals(BigInteger.valueOf( 46175L ) ) );
        } else {
            value = value.longValue();
            expected = 46175L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[53].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[53].generic + "' != '" + 54 + "'", value.equals(BigInteger.valueOf( 54L ) ) );
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[53].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[53].specific + "' != '" + 36 + "'", value.equals(BigInteger.valueOf( 36L ) ) );
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[54].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[54].component + "' != '" + 19386 + "'", value.equals(BigInteger.valueOf( 19386L ) ) );
        } else {
            value = value.longValue();
            expected = 19386L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[54].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[54].generic + "' != '" + 64 + "'", value.equals(BigInteger.valueOf( 64L ) ) );
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[54].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[54].specific + "' != '" + 20 + "'", value.equals(BigInteger.valueOf( 20L ) ) );
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[55].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[55].component + "' != '" + 34205 + "'", value.equals(BigInteger.valueOf( 34205L ) ) );
        } else {
            value = value.longValue();
            expected = 34205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[55].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[55].generic + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[55].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[55].specific + "' != '" + 149 + "'", value.equals(BigInteger.valueOf( 149L ) ) );
        } else {
            value = value.longValue();
            expected = 149L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[56].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[56].component + "' != '" + 3612 + "'", value.equals(BigInteger.valueOf( 3612L ) ) );
        } else {
            value = value.longValue();
            expected = 3612L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[56].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[56].generic + "' != '" + 185 + "'", value.equals(BigInteger.valueOf( 185L ) ) );
        } else {
            value = value.longValue();
            expected = 185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[56].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[56].specific + "' != '" + 129 + "'", value.equals(BigInteger.valueOf( 129L ) ) );
        } else {
            value = value.longValue();
            expected = 129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[57].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[57].component + "' != '" + 61285 + "'", value.equals(BigInteger.valueOf( 61285L ) ) );
        } else {
            value = value.longValue();
            expected = 61285L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[57].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[57].generic + "' != '" + 74 + "'", value.equals(BigInteger.valueOf( 74L ) ) );
        } else {
            value = value.longValue();
            expected = 74L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[57].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[57].specific + "' != '" + 248 + "'", value.equals(BigInteger.valueOf( 248L ) ) );
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[58].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[58].component + "' != '" + 7925 + "'", value.equals(BigInteger.valueOf( 7925L ) ) );
        } else {
            value = value.longValue();
            expected = 7925L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[58].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[58].generic + "' != '" + 228 + "'", value.equals(BigInteger.valueOf( 228L ) ) );
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[58].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[58].specific + "' != '" + 88 + "'", value.equals(BigInteger.valueOf( 88L ) ) );
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[59].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[59].component + "' != '" + 54414 + "'", value.equals(BigInteger.valueOf( 54414L ) ) );
        } else {
            value = value.longValue();
            expected = 54414L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[59].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[59].generic + "' != '" + 53 + "'", value.equals(BigInteger.valueOf( 53L ) ) );
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.status[59].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.status[59].specific + "' != '" + 224 + "'", value.equals(BigInteger.valueOf( 224L ) ) );
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uptime;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.uptime + "' != '" + 1657804265 + "'", value.equals(BigInteger.valueOf( 1657804265L ) ) );
        } else {
            value = value.longValue();
            expected = 1657804265L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
