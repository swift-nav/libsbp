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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrectionDepA.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.ssr.MsgSsrStecCorrectionDepA;


public class auto_check_sbp_ssr_MsgSsrStecCorrectionDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrStecCorrectionDepATest.test1");
        byte[] payload = new byte[] {(byte)70,(byte)81,(byte)196,(byte)232,(byte)185,(byte)43,(byte)147,(byte)123,(byte)39,(byte)4,(byte)126,(byte)19,(byte)111,(byte)97,(byte)248,(byte)130,(byte)217,(byte)217,(byte)106,(byte)58,(byte)12,(byte)65,(byte)230,(byte)171,(byte)81,(byte)95,(byte)86,(byte)16,(byte)39,(byte)84,(byte)228,(byte)208,(byte)201,(byte)81,(byte)219,(byte)99,(byte)203,(byte)61,(byte)182,(byte)66,(byte)125,(byte)203,(byte)3,(byte)193,(byte)44,(byte)100,(byte)220,(byte)125,(byte)60,(byte)21,(byte)93,(byte)218,(byte)247,(byte)158,(byte)207,(byte)93,(byte)129,(byte)134,(byte)14,(byte)209,(byte)48,(byte)14,(byte)215,(byte)153,(byte)148,(byte)147,(byte)72,(byte)225,(byte)180,(byte)236,(byte)205,(byte)201,(byte)33,(byte)3,(byte)246,(byte)204,(byte)19,(byte)3,(byte)98,(byte)4,(byte)194,(byte)191,(byte)246,(byte)76,(byte)219,(byte)31,(byte)191,(byte)113,(byte)79,(byte)177,(byte)15,(byte)251,(byte)33,(byte)19,(byte)96,(byte)54,(byte)58,(byte)146,(byte)210,(byte)100,(byte)249,(byte)72,(byte)21,(byte)161,(byte)211,(byte)198,(byte)21,(byte)238,(byte)111,(byte)107,(byte)36,(byte)227,(byte)225,(byte)213,(byte)3,(byte)71,(byte)243,(byte)63,(byte)65,(byte)236,(byte)92,(byte)77,(byte)0,(byte)169,(byte)15,(byte)182,(byte)5,(byte)240,(byte)180,(byte)9,(byte)122,(byte)86,(byte)232,(byte)6,(byte)103,(byte)104,(byte)254,(byte)189,(byte)81,(byte)110,(byte)2,(byte)49,(byte)202,(byte)84,(byte)216,(byte)55,(byte)50,(byte)181,(byte)5,(byte)123,(byte)80,(byte)49,(byte)244,(byte)224,(byte)188,(byte)125,(byte)164,(byte)230,(byte)56,(byte)66,(byte)124,(byte)168,(byte)59,(byte)139,(byte)106,(byte)118,(byte)51,(byte)187,(byte)216,(byte)191,(byte)158,(byte)77,(byte)92,(byte)58,(byte)253,(byte)132,(byte)150,(byte)165,(byte)9,(byte)154,(byte)189,(byte)218,(byte)61,(byte)209,(byte)1,(byte)82,(byte)181,(byte)196,(byte)23,(byte)53,(byte)182,(byte)112,(byte)192,(byte)206,(byte)167,(byte)157,(byte)244,(byte)35,(byte)1,(byte)189,(byte)217,(byte)61,(byte)88,(byte)97,(byte)201,(byte)201,(byte)74,(byte)251,(byte)217,(byte)14,(byte)104,(byte)184,(byte)54,(byte)52,(byte)74,(byte)238,(byte)10,(byte)129,(byte)22,(byte)178,(byte)226,(byte)109,(byte)88,(byte)157,(byte)30,(byte)196,(byte)175,(byte)26,(byte)76,(byte)34,(byte)116,(byte)220,(byte)154,(byte)232,(byte)12,(byte)179,(byte)244,(byte)15,(byte)155,(byte)196,(byte)202,(byte)72,(byte)70,(byte)115,(byte)10,(byte)214,(byte)114,(byte)39,(byte)245,(byte)28,(byte)237,(byte)68, };
        SBPMessage sbp = new SBPMessage( 0x0727, 0x5eb, payload );
        MsgSsrStecCorrectionDepA msg = new MsgSsrStecCorrectionDepA( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.iod_atmo;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.iod_atmo + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.num_msgs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.num_msgs + "' != '" + 147 + "'", value.equals(BigInteger.valueOf( 147L ) ) );
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.seq_num;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.seq_num + "' != '" + 123 + "'", value.equals(BigInteger.valueOf( 123L ) ) );
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.time.tow + "' != '" + 3905179974L + "'", value.equals( new BigInteger( "3905179974" ) ) );
        } else {
            value = value.longValue();
            expected = 3905179974L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.time.wn + "' != '" + 11193 + "'", value.equals(BigInteger.valueOf( 11193L ) ) );
        } else {
            value = value.longValue();
            expected = 11193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.update_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.update_interval + "' != '" + 39 + "'", value.equals(BigInteger.valueOf( 39L ) ) );
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].stec_coeff[0] + "' != '" + -1951 + "'", value.equals(BigInteger.valueOf( -1951L ) ) );
        } else {
            value = value.longValue();
            expected = -1951L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].stec_coeff[1] + "' != '" + -9854 + "'", value.equals(BigInteger.valueOf( -9854L ) ) );
        } else {
            value = value.longValue();
            expected = -9854L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].stec_coeff[2] + "' != '" + 27353 + "'", value.equals(BigInteger.valueOf( 27353L ) ) );
        } else {
            value = value.longValue();
            expected = 27353L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].stec_coeff[3] + "' != '" + 3130 + "'", value.equals(BigInteger.valueOf( 3130L ) ) );
        } else {
            value = value.longValue();
            expected = 3130L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].stec_quality_indicator + "' != '" + 111 + "'", value.equals(BigInteger.valueOf( 111L ) ) );
        } else {
            value = value.longValue();
            expected = 111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].sv_id.constellation + "' != '" + 19 + "'", value.equals(BigInteger.valueOf( 19L ) ) );
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].sv_id.satId + "' != '" + 126 + "'", value.equals(BigInteger.valueOf( 126L ) ) );
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].stec_coeff[0] + "' != '" + 24401 + "'", value.equals(BigInteger.valueOf( 24401L ) ) );
        } else {
            value = value.longValue();
            expected = 24401L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].stec_coeff[1] + "' != '" + 4182 + "'", value.equals(BigInteger.valueOf( 4182L ) ) );
        } else {
            value = value.longValue();
            expected = 4182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].stec_coeff[2] + "' != '" + 21543 + "'", value.equals(BigInteger.valueOf( 21543L ) ) );
        } else {
            value = value.longValue();
            expected = 21543L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].stec_coeff[3] + "' != '" + -12060 + "'", value.equals(BigInteger.valueOf( -12060L ) ) );
        } else {
            value = value.longValue();
            expected = -12060L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].stec_quality_indicator + "' != '" + 171 + "'", value.equals(BigInteger.valueOf( 171L ) ) );
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].sv_id.constellation + "' != '" + 230 + "'", value.equals(BigInteger.valueOf( 230L ) ) );
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].sv_id.satId + "' != '" + 65 + "'", value.equals(BigInteger.valueOf( 65L ) ) );
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].stec_coeff[0] + "' != '" + -13469 + "'", value.equals(BigInteger.valueOf( -13469L ) ) );
        } else {
            value = value.longValue();
            expected = -13469L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].stec_coeff[1] + "' != '" + -18883 + "'", value.equals(BigInteger.valueOf( -18883L ) ) );
        } else {
            value = value.longValue();
            expected = -18883L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].stec_coeff[2] + "' != '" + 32066 + "'", value.equals(BigInteger.valueOf( 32066L ) ) );
        } else {
            value = value.longValue();
            expected = 32066L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].stec_coeff[3] + "' != '" + 971 + "'", value.equals(BigInteger.valueOf( 971L ) ) );
        } else {
            value = value.longValue();
            expected = 971L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].stec_quality_indicator + "' != '" + 219 + "'", value.equals(BigInteger.valueOf( 219L ) ) );
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].sv_id.constellation + "' != '" + 81 + "'", value.equals(BigInteger.valueOf( 81L ) ) );
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].sv_id.satId + "' != '" + 201 + "'", value.equals(BigInteger.valueOf( 201L ) ) );
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].stec_coeff[0] + "' != '" + 32220 + "'", value.equals(BigInteger.valueOf( 32220L ) ) );
        } else {
            value = value.longValue();
            expected = 32220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].stec_coeff[1] + "' != '" + 5436 + "'", value.equals(BigInteger.valueOf( 5436L ) ) );
        } else {
            value = value.longValue();
            expected = 5436L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].stec_coeff[2] + "' != '" + -9635 + "'", value.equals(BigInteger.valueOf( -9635L ) ) );
        } else {
            value = value.longValue();
            expected = -9635L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].stec_coeff[3] + "' != '" + -24841 + "'", value.equals(BigInteger.valueOf( -24841L ) ) );
        } else {
            value = value.longValue();
            expected = -24841L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].stec_quality_indicator + "' != '" + 100 + "'", value.equals(BigInteger.valueOf( 100L ) ) );
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].sv_id.constellation + "' != '" + 44 + "'", value.equals(BigInteger.valueOf( 44L ) ) );
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].sv_id.satId + "' != '" + 193 + "'", value.equals(BigInteger.valueOf( 193L ) ) );
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].stec_coeff[0] + "' != '" + 3718 + "'", value.equals(BigInteger.valueOf( 3718L ) ) );
        } else {
            value = value.longValue();
            expected = 3718L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].stec_coeff[1] + "' != '" + 12497 + "'", value.equals(BigInteger.valueOf( 12497L ) ) );
        } else {
            value = value.longValue();
            expected = 12497L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].stec_coeff[2] + "' != '" + -10482 + "'", value.equals(BigInteger.valueOf( -10482L ) ) );
        } else {
            value = value.longValue();
            expected = -10482L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].stec_coeff[3] + "' != '" + -27495 + "'", value.equals(BigInteger.valueOf( -27495L ) ) );
        } else {
            value = value.longValue();
            expected = -27495L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].stec_quality_indicator + "' != '" + 129 + "'", value.equals(BigInteger.valueOf( 129L ) ) );
        } else {
            value = value.longValue();
            expected = 129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].sv_id.constellation + "' != '" + 93 + "'", value.equals(BigInteger.valueOf( 93L ) ) );
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].sv_id.satId + "' != '" + 207 + "'", value.equals(BigInteger.valueOf( 207L ) ) );
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].stec_coeff[0] + "' != '" + -4940 + "'", value.equals(BigInteger.valueOf( -4940L ) ) );
        } else {
            value = value.longValue();
            expected = -4940L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].stec_coeff[1] + "' != '" + -13875 + "'", value.equals(BigInteger.valueOf( -13875L ) ) );
        } else {
            value = value.longValue();
            expected = -13875L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].stec_coeff[2] + "' != '" + 801 + "'", value.equals(BigInteger.valueOf( 801L ) ) );
        } else {
            value = value.longValue();
            expected = 801L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].stec_coeff[3] + "' != '" + -13066 + "'", value.equals(BigInteger.valueOf( -13066L ) ) );
        } else {
            value = value.longValue();
            expected = -13066L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].stec_quality_indicator + "' != '" + 225 + "'", value.equals(BigInteger.valueOf( 225L ) ) );
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].sv_id.constellation + "' != '" + 72 + "'", value.equals(BigInteger.valueOf( 72L ) ) );
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].sv_id.satId + "' != '" + 147 + "'", value.equals(BigInteger.valueOf( 147L ) ) );
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].stec_coeff[0] + "' != '" + -15868 + "'", value.equals(BigInteger.valueOf( -15868L ) ) );
        } else {
            value = value.longValue();
            expected = -15868L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].stec_coeff[1] + "' != '" + -2369 + "'", value.equals(BigInteger.valueOf( -2369L ) ) );
        } else {
            value = value.longValue();
            expected = -2369L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].stec_coeff[2] + "' != '" + -9396 + "'", value.equals(BigInteger.valueOf( -9396L ) ) );
        } else {
            value = value.longValue();
            expected = -9396L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].stec_coeff[3] + "' != '" + -16609 + "'", value.equals(BigInteger.valueOf( -16609L ) ) );
        } else {
            value = value.longValue();
            expected = -16609L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].stec_quality_indicator + "' != '" + 98 + "'", value.equals(BigInteger.valueOf( 98L ) ) );
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].sv_id.constellation + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].sv_id.satId + "' != '" + 19 + "'", value.equals(BigInteger.valueOf( 19L ) ) );
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].stec_coeff[0] + "' != '" + -1265 + "'", value.equals(BigInteger.valueOf( -1265L ) ) );
        } else {
            value = value.longValue();
            expected = -1265L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].stec_coeff[1] + "' != '" + 4897 + "'", value.equals(BigInteger.valueOf( 4897L ) ) );
        } else {
            value = value.longValue();
            expected = 4897L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].stec_coeff[2] + "' != '" + 13920 + "'", value.equals(BigInteger.valueOf( 13920L ) ) );
        } else {
            value = value.longValue();
            expected = 13920L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].stec_coeff[3] + "' != '" + -28102 + "'", value.equals(BigInteger.valueOf( -28102L ) ) );
        } else {
            value = value.longValue();
            expected = -28102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].stec_quality_indicator + "' != '" + 177 + "'", value.equals(BigInteger.valueOf( 177L ) ) );
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].sv_id.constellation + "' != '" + 79 + "'", value.equals(BigInteger.valueOf( 79L ) ) );
        } else {
            value = value.longValue();
            expected = 79L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].sv_id.satId + "' != '" + 113 + "'", value.equals(BigInteger.valueOf( 113L ) ) );
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].stec_coeff[0] + "' != '" + 5448 + "'", value.equals(BigInteger.valueOf( 5448L ) ) );
        } else {
            value = value.longValue();
            expected = 5448L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].stec_coeff[1] + "' != '" + -11359 + "'", value.equals(BigInteger.valueOf( -11359L ) ) );
        } else {
            value = value.longValue();
            expected = -11359L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].stec_coeff[2] + "' != '" + 5574 + "'", value.equals(BigInteger.valueOf( 5574L ) ) );
        } else {
            value = value.longValue();
            expected = 5574L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].stec_coeff[3] + "' != '" + 28654 + "'", value.equals(BigInteger.valueOf( 28654L ) ) );
        } else {
            value = value.longValue();
            expected = 28654L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].stec_quality_indicator + "' != '" + 249 + "'", value.equals(BigInteger.valueOf( 249L ) ) );
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].sv_id.constellation + "' != '" + 100 + "'", value.equals(BigInteger.valueOf( 100L ) ) );
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].sv_id.satId + "' != '" + 210 + "'", value.equals(BigInteger.valueOf( 210L ) ) );
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].stec_coeff[0] + "' != '" + -10783 + "'", value.equals(BigInteger.valueOf( -10783L ) ) );
        } else {
            value = value.longValue();
            expected = -10783L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].stec_coeff[1] + "' != '" + 18179 + "'", value.equals(BigInteger.valueOf( 18179L ) ) );
        } else {
            value = value.longValue();
            expected = 18179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].stec_coeff[2] + "' != '" + 16371 + "'", value.equals(BigInteger.valueOf( 16371L ) ) );
        } else {
            value = value.longValue();
            expected = 16371L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].stec_coeff[3] + "' != '" + -5055 + "'", value.equals(BigInteger.valueOf( -5055L ) ) );
        } else {
            value = value.longValue();
            expected = -5055L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].stec_quality_indicator + "' != '" + 227 + "'", value.equals(BigInteger.valueOf( 227L ) ) );
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].sv_id.constellation + "' != '" + 36 + "'", value.equals(BigInteger.valueOf( 36L ) ) );
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].sv_id.satId + "' != '" + 107 + "'", value.equals(BigInteger.valueOf( 107L ) ) );
        } else {
            value = value.longValue();
            expected = 107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].stec_coeff[0] + "' != '" + 4009 + "'", value.equals(BigInteger.valueOf( 4009L ) ) );
        } else {
            value = value.longValue();
            expected = 4009L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].stec_coeff[1] + "' != '" + 1462 + "'", value.equals(BigInteger.valueOf( 1462L ) ) );
        } else {
            value = value.longValue();
            expected = 1462L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].stec_coeff[2] + "' != '" + -19216 + "'", value.equals(BigInteger.valueOf( -19216L ) ) );
        } else {
            value = value.longValue();
            expected = -19216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].stec_coeff[3] + "' != '" + 31241 + "'", value.equals(BigInteger.valueOf( 31241L ) ) );
        } else {
            value = value.longValue();
            expected = 31241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].stec_quality_indicator + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].sv_id.constellation + "' != '" + 77 + "'", value.equals(BigInteger.valueOf( 77L ) ) );
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].sv_id.satId + "' != '" + 92 + "'", value.equals(BigInteger.valueOf( 92L ) ) );
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].stec_coeff[0] + "' != '" + 26727 + "'", value.equals(BigInteger.valueOf( 26727L ) ) );
        } else {
            value = value.longValue();
            expected = 26727L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].stec_coeff[1] + "' != '" + -16898 + "'", value.equals(BigInteger.valueOf( -16898L ) ) );
        } else {
            value = value.longValue();
            expected = -16898L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].stec_coeff[2] + "' != '" + 28241 + "'", value.equals(BigInteger.valueOf( 28241L ) ) );
        } else {
            value = value.longValue();
            expected = 28241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].stec_coeff[3] + "' != '" + 12546 + "'", value.equals(BigInteger.valueOf( 12546L ) ) );
        } else {
            value = value.longValue();
            expected = 12546L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].stec_quality_indicator + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].sv_id.constellation + "' != '" + 232 + "'", value.equals(BigInteger.valueOf( 232L ) ) );
        } else {
            value = value.longValue();
            expected = 232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].sv_id.satId + "' != '" + 86 + "'", value.equals(BigInteger.valueOf( 86L ) ) );
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].stec_coeff[0] + "' != '" + 12855 + "'", value.equals(BigInteger.valueOf( 12855L ) ) );
        } else {
            value = value.longValue();
            expected = 12855L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].stec_coeff[1] + "' != '" + 1461 + "'", value.equals(BigInteger.valueOf( 1461L ) ) );
        } else {
            value = value.longValue();
            expected = 1461L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].stec_coeff[2] + "' != '" + 20603 + "'", value.equals(BigInteger.valueOf( 20603L ) ) );
        } else {
            value = value.longValue();
            expected = 20603L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].stec_coeff[3] + "' != '" + -3023 + "'", value.equals(BigInteger.valueOf( -3023L ) ) );
        } else {
            value = value.longValue();
            expected = -3023L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].stec_quality_indicator + "' != '" + 216 + "'", value.equals(BigInteger.valueOf( 216L ) ) );
        } else {
            value = value.longValue();
            expected = 216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].sv_id.constellation + "' != '" + 84 + "'", value.equals(BigInteger.valueOf( 84L ) ) );
        } else {
            value = value.longValue();
            expected = 84L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].sv_id.satId + "' != '" + 202 + "'", value.equals(BigInteger.valueOf( 202L ) ) );
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].stec_coeff[0] + "' != '" + -6492 + "'", value.equals(BigInteger.valueOf( -6492L ) ) );
        } else {
            value = value.longValue();
            expected = -6492L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].stec_coeff[1] + "' != '" + 16952 + "'", value.equals(BigInteger.valueOf( 16952L ) ) );
        } else {
            value = value.longValue();
            expected = 16952L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].stec_coeff[2] + "' != '" + -22404 + "'", value.equals(BigInteger.valueOf( -22404L ) ) );
        } else {
            value = value.longValue();
            expected = -22404L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].stec_coeff[3] + "' != '" + -29893 + "'", value.equals(BigInteger.valueOf( -29893L ) ) );
        } else {
            value = value.longValue();
            expected = -29893L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].stec_quality_indicator + "' != '" + 125 + "'", value.equals(BigInteger.valueOf( 125L ) ) );
        } else {
            value = value.longValue();
            expected = 125L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].sv_id.constellation + "' != '" + 188 + "'", value.equals(BigInteger.valueOf( 188L ) ) );
        } else {
            value = value.longValue();
            expected = 188L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].sv_id.satId + "' != '" + 224 + "'", value.equals(BigInteger.valueOf( 224L ) ) );
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].stec_coeff[0] + "' != '" + -10053 + "'", value.equals(BigInteger.valueOf( -10053L ) ) );
        } else {
            value = value.longValue();
            expected = -10053L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].stec_coeff[1] + "' != '" + -24897 + "'", value.equals(BigInteger.valueOf( -24897L ) ) );
        } else {
            value = value.longValue();
            expected = -24897L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].stec_coeff[2] + "' != '" + 23629 + "'", value.equals(BigInteger.valueOf( 23629L ) ) );
        } else {
            value = value.longValue();
            expected = 23629L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].stec_coeff[3] + "' != '" + -710 + "'", value.equals(BigInteger.valueOf( -710L ) ) );
        } else {
            value = value.longValue();
            expected = -710L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].stec_quality_indicator + "' != '" + 51 + "'", value.equals(BigInteger.valueOf( 51L ) ) );
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].sv_id.constellation + "' != '" + 118 + "'", value.equals(BigInteger.valueOf( 118L ) ) );
        } else {
            value = value.longValue();
            expected = 118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].sv_id.satId + "' != '" + 106 + "'", value.equals(BigInteger.valueOf( 106L ) ) );
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].stec_coeff[0] + "' != '" + -26103 + "'", value.equals(BigInteger.valueOf( -26103L ) ) );
        } else {
            value = value.longValue();
            expected = -26103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].stec_coeff[1] + "' != '" + -9539 + "'", value.equals(BigInteger.valueOf( -9539L ) ) );
        } else {
            value = value.longValue();
            expected = -9539L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].stec_coeff[2] + "' != '" + -11971 + "'", value.equals(BigInteger.valueOf( -11971L ) ) );
        } else {
            value = value.longValue();
            expected = -11971L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].stec_coeff[3] + "' != '" + 20993 + "'", value.equals(BigInteger.valueOf( 20993L ) ) );
        } else {
            value = value.longValue();
            expected = 20993L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].stec_quality_indicator + "' != '" + 165 + "'", value.equals(BigInteger.valueOf( 165L ) ) );
        } else {
            value = value.longValue();
            expected = 165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].sv_id.constellation + "' != '" + 150 + "'", value.equals(BigInteger.valueOf( 150L ) ) );
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].sv_id.satId + "' != '" + 132 + "'", value.equals(BigInteger.valueOf( 132L ) ) );
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].stec_coeff[0] + "' != '" + -18891 + "'", value.equals(BigInteger.valueOf( -18891L ) ) );
        } else {
            value = value.longValue();
            expected = -18891L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].stec_coeff[1] + "' != '" + -16272 + "'", value.equals(BigInteger.valueOf( -16272L ) ) );
        } else {
            value = value.longValue();
            expected = -16272L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].stec_coeff[2] + "' != '" + -22578 + "'", value.equals(BigInteger.valueOf( -22578L ) ) );
        } else {
            value = value.longValue();
            expected = -22578L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].stec_coeff[3] + "' != '" + -2915 + "'", value.equals(BigInteger.valueOf( -2915L ) ) );
        } else {
            value = value.longValue();
            expected = -2915L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].stec_quality_indicator + "' != '" + 23 + "'", value.equals(BigInteger.valueOf( 23L ) ) );
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].sv_id.constellation + "' != '" + 196 + "'", value.equals(BigInteger.valueOf( 196L ) ) );
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].sv_id.satId + "' != '" + 181 + "'", value.equals(BigInteger.valueOf( 181L ) ) );
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].stec_coeff[0] + "' != '" + 15833 + "'", value.equals(BigInteger.valueOf( 15833L ) ) );
        } else {
            value = value.longValue();
            expected = 15833L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].stec_coeff[1] + "' != '" + 24920 + "'", value.equals(BigInteger.valueOf( 24920L ) ) );
        } else {
            value = value.longValue();
            expected = 24920L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].stec_coeff[2] + "' != '" + -13879 + "'", value.equals(BigInteger.valueOf( -13879L ) ) );
        } else {
            value = value.longValue();
            expected = -13879L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].stec_coeff[3] + "' != '" + -1206 + "'", value.equals(BigInteger.valueOf( -1206L ) ) );
        } else {
            value = value.longValue();
            expected = -1206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].stec_quality_indicator + "' != '" + 189 + "'", value.equals(BigInteger.valueOf( 189L ) ) );
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].sv_id.constellation + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].sv_id.satId + "' != '" + 35 + "'", value.equals(BigInteger.valueOf( 35L ) ) );
        } else {
            value = value.longValue();
            expected = 35L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].stec_coeff[0] + "' != '" + 14008 + "'", value.equals(BigInteger.valueOf( 14008L ) ) );
        } else {
            value = value.longValue();
            expected = 14008L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].stec_coeff[1] + "' != '" + 18996 + "'", value.equals(BigInteger.valueOf( 18996L ) ) );
        } else {
            value = value.longValue();
            expected = 18996L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].stec_coeff[2] + "' != '" + 2798 + "'", value.equals(BigInteger.valueOf( 2798L ) ) );
        } else {
            value = value.longValue();
            expected = 2798L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].stec_coeff[3] + "' != '" + 5761 + "'", value.equals(BigInteger.valueOf( 5761L ) ) );
        } else {
            value = value.longValue();
            expected = 5761L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].stec_quality_indicator + "' != '" + 104 + "'", value.equals(BigInteger.valueOf( 104L ) ) );
        } else {
            value = value.longValue();
            expected = 104L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].sv_id.constellation + "' != '" + 14 + "'", value.equals(BigInteger.valueOf( 14L ) ) );
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].sv_id.satId + "' != '" + 217 + "'", value.equals(BigInteger.valueOf( 217L ) ) );
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].stec_coeff[0] + "' != '" + -25256 + "'", value.equals(BigInteger.valueOf( -25256L ) ) );
        } else {
            value = value.longValue();
            expected = -25256L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].stec_coeff[1] + "' != '" + -15330 + "'", value.equals(BigInteger.valueOf( -15330L ) ) );
        } else {
            value = value.longValue();
            expected = -15330L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].stec_coeff[2] + "' != '" + 6831 + "'", value.equals(BigInteger.valueOf( 6831L ) ) );
        } else {
            value = value.longValue();
            expected = 6831L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].stec_coeff[3] + "' != '" + 8780 + "'", value.equals(BigInteger.valueOf( 8780L ) ) );
        } else {
            value = value.longValue();
            expected = 8780L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].stec_quality_indicator + "' != '" + 109 + "'", value.equals(BigInteger.valueOf( 109L ) ) );
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].sv_id.constellation + "' != '" + 226 + "'", value.equals(BigInteger.valueOf( 226L ) ) );
        } else {
            value = value.longValue();
            expected = 226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].sv_id.satId + "' != '" + 178 + "'", value.equals(BigInteger.valueOf( 178L ) ) );
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].stec_coeff[0] + "' != '" + 3304 + "'", value.equals(BigInteger.valueOf( 3304L ) ) );
        } else {
            value = value.longValue();
            expected = 3304L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].stec_coeff[1] + "' != '" + -2893 + "'", value.equals(BigInteger.valueOf( -2893L ) ) );
        } else {
            value = value.longValue();
            expected = -2893L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].stec_coeff[2] + "' != '" + -25841 + "'", value.equals(BigInteger.valueOf( -25841L ) ) );
        } else {
            value = value.longValue();
            expected = -25841L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].stec_coeff[3] + "' != '" + -13628 + "'", value.equals(BigInteger.valueOf( -13628L ) ) );
        } else {
            value = value.longValue();
            expected = -13628L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].stec_quality_indicator + "' != '" + 154 + "'", value.equals(BigInteger.valueOf( 154L ) ) );
        } else {
            value = value.longValue();
            expected = 154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].sv_id.constellation + "' != '" + 220 + "'", value.equals(BigInteger.valueOf( 220L ) ) );
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].sv_id.satId + "' != '" + 116 + "'", value.equals(BigInteger.valueOf( 116L ) ) );
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[21].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[21].stec_coeff[0] + "' != '" + -10742 + "'", value.equals(BigInteger.valueOf( -10742L ) ) );
        } else {
            value = value.longValue();
            expected = -10742L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[21].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[21].stec_coeff[1] + "' != '" + 10098 + "'", value.equals(BigInteger.valueOf( 10098L ) ) );
        } else {
            value = value.longValue();
            expected = 10098L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[21].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[21].stec_coeff[2] + "' != '" + 7413 + "'", value.equals(BigInteger.valueOf( 7413L ) ) );
        } else {
            value = value.longValue();
            expected = 7413L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[21].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[21].stec_coeff[3] + "' != '" + 17645 + "'", value.equals(BigInteger.valueOf( 17645L ) ) );
        } else {
            value = value.longValue();
            expected = 17645L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[21].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[21].stec_quality_indicator + "' != '" + 115 + "'", value.equals(BigInteger.valueOf( 115L ) ) );
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[21].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[21].sv_id.constellation + "' != '" + 70 + "'", value.equals(BigInteger.valueOf( 70L ) ) );
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[21].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[21].sv_id.satId + "' != '" + 72 + "'", value.equals(BigInteger.valueOf( 72L ) ) );
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
