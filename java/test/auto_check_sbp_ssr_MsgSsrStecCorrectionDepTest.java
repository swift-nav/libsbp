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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrectionDep.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.ssr.MsgSsrStecCorrectionDep;


public class auto_check_sbp_ssr_MsgSsrStecCorrectionDepTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrStecCorrectionDepTest.test1");
        byte[] payload = new byte[] {(byte)158,(byte)228,(byte)114,(byte)117,(byte)50,(byte)158,(byte)156,(byte)42,(byte)119,(byte)156,(byte)157,(byte)112,(byte)47,(byte)60,(byte)132,(byte)40,(byte)70,(byte)87,(byte)235,(byte)83,(byte)177,(byte)198,(byte)3,(byte)14,(byte)8,(byte)70,(byte)12,(byte)44,(byte)53,(byte)181,(byte)90,(byte)174,(byte)247,(byte)150,(byte)58,(byte)172,(byte)247,(byte)179,(byte)119,(byte)176,(byte)125,(byte)4,(byte)177,(byte)229,(byte)113,(byte)14,(byte)77,(byte)153,(byte)185,(byte)23,(byte)53,(byte)222,(byte)187,(byte)146,(byte)250,(byte)91,(byte)212,(byte)215,(byte)14,(byte)107,(byte)250,(byte)94,(byte)107,(byte)33,(byte)91,(byte)234,(byte)0,(byte)213,(byte)139,(byte)95,(byte)179,(byte)50,(byte)21,(byte)74,(byte)174,(byte)169,(byte)61,(byte)86,(byte)91,(byte)142,(byte)51,(byte)108,(byte)9,(byte)38,(byte)225,(byte)146,(byte)101,(byte)73,(byte)139,(byte)56,(byte)117,(byte)82,(byte)37,(byte)213,(byte)108,(byte)205,(byte)93,(byte)18,(byte)19,(byte)195,(byte)33,(byte)202,(byte)87,(byte)206,(byte)178,(byte)125,(byte)188,(byte)119,(byte)56,(byte)69,(byte)150,(byte)150,(byte)76,(byte)3,(byte)131,(byte)18,(byte)73,(byte)208,(byte)72,(byte)232,(byte)8,(byte)250,(byte)203,(byte)178,(byte)170,(byte)163,(byte)252,(byte)86,(byte)49,(byte)247,(byte)178,(byte)166,(byte)56,(byte)31,(byte)10,(byte)119,(byte)213,(byte)241,(byte)212,(byte)164,(byte)1,(byte)162,(byte)42,(byte)18,(byte)124,(byte)169,(byte)121,(byte)158,(byte)26,(byte)56,(byte)23,(byte)142,(byte)125,(byte)40,(byte)120,(byte)67,(byte)45,(byte)126,(byte)235,(byte)110,(byte)23,(byte)12,(byte)241,(byte)88,(byte)69,(byte)239,(byte)252,(byte)57,(byte)93,(byte)44,(byte)201,(byte)216,(byte)173,(byte)242,(byte)178,(byte)17,(byte)5,(byte)223,(byte)169,(byte)192,(byte)3,(byte)77,(byte)107,(byte)2,(byte)144,(byte)233,(byte)14,(byte)88,(byte)32,(byte)209,(byte)1,(byte)17,(byte)123,(byte)155,(byte)41,(byte)183,(byte)244,(byte)158,(byte)82,(byte)53,(byte)103,(byte)14,(byte)202,(byte)185,(byte)35,(byte)181,(byte)21,(byte)118,(byte)254,(byte)250,(byte)50,(byte)184,(byte)50,(byte)31,(byte)45,(byte)56,(byte)163,(byte)177,(byte)126,(byte)217,(byte)79,(byte)171,(byte)239,(byte)237,(byte)188,(byte)238,(byte)112,(byte)201,(byte)118,(byte)141,(byte)18,(byte)163,(byte)103,(byte)35,(byte)63,(byte)21,(byte)82,(byte)129,(byte)18,(byte)117,(byte)85,(byte)190,(byte)79,(byte)210,(byte)215, };
        SBPMessage sbp = new SBPMessage( 0x97cc, 0x5fb, payload );
        MsgSsrStecCorrectionDep msg = new MsgSsrStecCorrectionDep( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.iod_atmo;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.iod_atmo + "' != '" + 60 + "'", value.equals(BigInteger.valueOf( 60L ) ) );
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.num_msgs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.num_msgs + "' != '" + 157 + "'", value.equals(BigInteger.valueOf( 157L ) ) );
        } else {
            value = value.longValue();
            expected = 157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.seq_num;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.seq_num + "' != '" + 112 + "'", value.equals(BigInteger.valueOf( 112L ) ) );
        } else {
            value = value.longValue();
            expected = 112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.tile_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.tile_id + "' != '" + 30066 + "'", value.equals(BigInteger.valueOf( 30066L ) ) );
        } else {
            value = value.longValue();
            expected = 30066L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.tile_set_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.tile_set_id + "' != '" + 58526 + "'", value.equals(BigInteger.valueOf( 58526L ) ) );
        } else {
            value = value.longValue();
            expected = 58526L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.time.tow + "' != '" + 714907186 + "'", value.equals(BigInteger.valueOf( 714907186L ) ) );
        } else {
            value = value.longValue();
            expected = 714907186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.time.wn + "' != '" + 40055 + "'", value.equals(BigInteger.valueOf( 40055L ) ) );
        } else {
            value = value.longValue();
            expected = 40055L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.update_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.header.update_interval + "' != '" + 47 + "'", value.equals(BigInteger.valueOf( 47L ) ) );
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].stec_coeff[0] + "' != '" + -5289 + "'", value.equals(BigInteger.valueOf( -5289L ) ) );
        } else {
            value = value.longValue();
            expected = -5289L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].stec_coeff[1] + "' != '" + -20141 + "'", value.equals(BigInteger.valueOf( -20141L ) ) );
        } else {
            value = value.longValue();
            expected = -20141L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].stec_coeff[2] + "' != '" + 966 + "'", value.equals(BigInteger.valueOf( 966L ) ) );
        } else {
            value = value.longValue();
            expected = 966L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].stec_coeff[3] + "' != '" + 2062 + "'", value.equals(BigInteger.valueOf( 2062L ) ) );
        } else {
            value = value.longValue();
            expected = 2062L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].stec_quality_indicator + "' != '" + 70 + "'", value.equals(BigInteger.valueOf( 70L ) ) );
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].sv_id.constellation + "' != '" + 40 + "'", value.equals(BigInteger.valueOf( 40L ) ) );
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[0].sv_id.satId + "' != '" + 132 + "'", value.equals(BigInteger.valueOf( 132L ) ) );
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].stec_coeff[0] + "' != '" + -19147 + "'", value.equals(BigInteger.valueOf( -19147L ) ) );
        } else {
            value = value.longValue();
            expected = -19147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].stec_coeff[1] + "' != '" + -20902 + "'", value.equals(BigInteger.valueOf( -20902L ) ) );
        } else {
            value = value.longValue();
            expected = -20902L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].stec_coeff[2] + "' != '" + -26889 + "'", value.equals(BigInteger.valueOf( -26889L ) ) );
        } else {
            value = value.longValue();
            expected = -26889L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].stec_coeff[3] + "' != '" + -21446 + "'", value.equals(BigInteger.valueOf( -21446L ) ) );
        } else {
            value = value.longValue();
            expected = -21446L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].stec_quality_indicator + "' != '" + 44 + "'", value.equals(BigInteger.valueOf( 44L ) ) );
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].sv_id.constellation + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[1].sv_id.satId + "' != '" + 70 + "'", value.equals(BigInteger.valueOf( 70L ) ) );
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].stec_coeff[0] + "' != '" + 32176 + "'", value.equals(BigInteger.valueOf( 32176L ) ) );
        } else {
            value = value.longValue();
            expected = 32176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].stec_coeff[1] + "' != '" + -20220 + "'", value.equals(BigInteger.valueOf( -20220L ) ) );
        } else {
            value = value.longValue();
            expected = -20220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].stec_coeff[2] + "' != '" + 29157 + "'", value.equals(BigInteger.valueOf( 29157L ) ) );
        } else {
            value = value.longValue();
            expected = 29157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].stec_coeff[3] + "' != '" + 19726 + "'", value.equals(BigInteger.valueOf( 19726L ) ) );
        } else {
            value = value.longValue();
            expected = 19726L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].stec_quality_indicator + "' != '" + 119 + "'", value.equals(BigInteger.valueOf( 119L ) ) );
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].sv_id.constellation + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[2].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[2].sv_id.satId + "' != '" + 247 + "'", value.equals(BigInteger.valueOf( 247L ) ) );
        } else {
            value = value.longValue();
            expected = 247L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].stec_coeff[0] + "' != '" + -8651 + "'", value.equals(BigInteger.valueOf( -8651L ) ) );
        } else {
            value = value.longValue();
            expected = -8651L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].stec_coeff[1] + "' != '" + -27973 + "'", value.equals(BigInteger.valueOf( -27973L ) ) );
        } else {
            value = value.longValue();
            expected = -27973L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].stec_coeff[2] + "' != '" + 23546 + "'", value.equals(BigInteger.valueOf( 23546L ) ) );
        } else {
            value = value.longValue();
            expected = 23546L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].stec_coeff[3] + "' != '" + -10284 + "'", value.equals(BigInteger.valueOf( -10284L ) ) );
        } else {
            value = value.longValue();
            expected = -10284L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].stec_quality_indicator + "' != '" + 23 + "'", value.equals(BigInteger.valueOf( 23L ) ) );
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].sv_id.constellation + "' != '" + 185 + "'", value.equals(BigInteger.valueOf( 185L ) ) );
        } else {
            value = value.longValue();
            expected = 185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[3].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[3].sv_id.satId + "' != '" + 153 + "'", value.equals(BigInteger.valueOf( 153L ) ) );
        } else {
            value = value.longValue();
            expected = 153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].stec_coeff[0] + "' != '" + 27486 + "'", value.equals(BigInteger.valueOf( 27486L ) ) );
        } else {
            value = value.longValue();
            expected = 27486L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].stec_coeff[1] + "' != '" + 23329 + "'", value.equals(BigInteger.valueOf( 23329L ) ) );
        } else {
            value = value.longValue();
            expected = 23329L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].stec_coeff[2] + "' != '" + 234 + "'", value.equals(BigInteger.valueOf( 234L ) ) );
        } else {
            value = value.longValue();
            expected = 234L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].stec_coeff[3] + "' != '" + -29739 + "'", value.equals(BigInteger.valueOf( -29739L ) ) );
        } else {
            value = value.longValue();
            expected = -29739L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].stec_quality_indicator + "' != '" + 250 + "'", value.equals(BigInteger.valueOf( 250L ) ) );
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].sv_id.constellation + "' != '" + 107 + "'", value.equals(BigInteger.valueOf( 107L ) ) );
        } else {
            value = value.longValue();
            expected = 107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[4].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[4].sv_id.satId + "' != '" + 14 + "'", value.equals(BigInteger.valueOf( 14L ) ) );
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].stec_coeff[0] + "' != '" + 18965 + "'", value.equals(BigInteger.valueOf( 18965L ) ) );
        } else {
            value = value.longValue();
            expected = 18965L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].stec_coeff[1] + "' != '" + -22098 + "'", value.equals(BigInteger.valueOf( -22098L ) ) );
        } else {
            value = value.longValue();
            expected = -22098L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].stec_coeff[2] + "' != '" + 22077 + "'", value.equals(BigInteger.valueOf( 22077L ) ) );
        } else {
            value = value.longValue();
            expected = 22077L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].stec_coeff[3] + "' != '" + -29093 + "'", value.equals(BigInteger.valueOf( -29093L ) ) );
        } else {
            value = value.longValue();
            expected = -29093L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].stec_quality_indicator + "' != '" + 50 + "'", value.equals(BigInteger.valueOf( 50L ) ) );
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].sv_id.constellation + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[5].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[5].sv_id.satId + "' != '" + 95 + "'", value.equals(BigInteger.valueOf( 95L ) ) );
        } else {
            value = value.longValue();
            expected = 95L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].stec_coeff[0] + "' != '" + -7898 + "'", value.equals(BigInteger.valueOf( -7898L ) ) );
        } else {
            value = value.longValue();
            expected = -7898L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].stec_coeff[1] + "' != '" + 26002 + "'", value.equals(BigInteger.valueOf( 26002L ) ) );
        } else {
            value = value.longValue();
            expected = 26002L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].stec_coeff[2] + "' != '" + -29879 + "'", value.equals(BigInteger.valueOf( -29879L ) ) );
        } else {
            value = value.longValue();
            expected = -29879L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].stec_coeff[3] + "' != '" + 30008 + "'", value.equals(BigInteger.valueOf( 30008L ) ) );
        } else {
            value = value.longValue();
            expected = 30008L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].stec_quality_indicator + "' != '" + 9 + "'", value.equals(BigInteger.valueOf( 9L ) ) );
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].sv_id.constellation + "' != '" + 108 + "'", value.equals(BigInteger.valueOf( 108L ) ) );
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[6].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[6].sv_id.satId + "' != '" + 51 + "'", value.equals(BigInteger.valueOf( 51L ) ) );
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].stec_coeff[0] + "' != '" + -12948 + "'", value.equals(BigInteger.valueOf( -12948L ) ) );
        } else {
            value = value.longValue();
            expected = -12948L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].stec_coeff[1] + "' != '" + 4701 + "'", value.equals(BigInteger.valueOf( 4701L ) ) );
        } else {
            value = value.longValue();
            expected = 4701L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].stec_coeff[2] + "' != '" + -15597 + "'", value.equals(BigInteger.valueOf( -15597L ) ) );
        } else {
            value = value.longValue();
            expected = -15597L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].stec_coeff[3] + "' != '" + -13791 + "'", value.equals(BigInteger.valueOf( -13791L ) ) );
        } else {
            value = value.longValue();
            expected = -13791L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].stec_quality_indicator + "' != '" + 213 + "'", value.equals(BigInteger.valueOf( 213L ) ) );
        } else {
            value = value.longValue();
            expected = 213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].sv_id.constellation + "' != '" + 37 + "'", value.equals(BigInteger.valueOf( 37L ) ) );
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[7].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[7].sv_id.satId + "' != '" + 82 + "'", value.equals(BigInteger.valueOf( 82L ) ) );
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].stec_coeff[0] + "' != '" + -17283 + "'", value.equals(BigInteger.valueOf( -17283L ) ) );
        } else {
            value = value.longValue();
            expected = -17283L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].stec_coeff[1] + "' != '" + 14455 + "'", value.equals(BigInteger.valueOf( 14455L ) ) );
        } else {
            value = value.longValue();
            expected = 14455L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].stec_coeff[2] + "' != '" + -27067 + "'", value.equals(BigInteger.valueOf( -27067L ) ) );
        } else {
            value = value.longValue();
            expected = -27067L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].stec_coeff[3] + "' != '" + 19606 + "'", value.equals(BigInteger.valueOf( 19606L ) ) );
        } else {
            value = value.longValue();
            expected = 19606L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].stec_quality_indicator + "' != '" + 178 + "'", value.equals(BigInteger.valueOf( 178L ) ) );
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].sv_id.constellation + "' != '" + 206 + "'", value.equals(BigInteger.valueOf( 206L ) ) );
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[8].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[8].sv_id.satId + "' != '" + 87 + "'", value.equals(BigInteger.valueOf( 87L ) ) );
        } else {
            value = value.longValue();
            expected = 87L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].stec_coeff[0] + "' != '" + -12215 + "'", value.equals(BigInteger.valueOf( -12215L ) ) );
        } else {
            value = value.longValue();
            expected = -12215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].stec_coeff[1] + "' != '" + -6072 + "'", value.equals(BigInteger.valueOf( -6072L ) ) );
        } else {
            value = value.longValue();
            expected = -6072L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].stec_coeff[2] + "' != '" + -1528 + "'", value.equals(BigInteger.valueOf( -1528L ) ) );
        } else {
            value = value.longValue();
            expected = -1528L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].stec_coeff[3] + "' != '" + -19765 + "'", value.equals(BigInteger.valueOf( -19765L ) ) );
        } else {
            value = value.longValue();
            expected = -19765L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].stec_quality_indicator + "' != '" + 18 + "'", value.equals(BigInteger.valueOf( 18L ) ) );
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].sv_id.constellation + "' != '" + 131 + "'", value.equals(BigInteger.valueOf( 131L ) ) );
        } else {
            value = value.longValue();
            expected = 131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[9].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[9].sv_id.satId + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].stec_coeff[0] + "' != '" + 12630 + "'", value.equals(BigInteger.valueOf( 12630L ) ) );
        } else {
            value = value.longValue();
            expected = 12630L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].stec_coeff[1] + "' != '" + -19721 + "'", value.equals(BigInteger.valueOf( -19721L ) ) );
        } else {
            value = value.longValue();
            expected = -19721L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].stec_coeff[2] + "' != '" + 14502 + "'", value.equals(BigInteger.valueOf( 14502L ) ) );
        } else {
            value = value.longValue();
            expected = 14502L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].stec_coeff[3] + "' != '" + 2591 + "'", value.equals(BigInteger.valueOf( 2591L ) ) );
        } else {
            value = value.longValue();
            expected = 2591L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].stec_quality_indicator + "' != '" + 252 + "'", value.equals(BigInteger.valueOf( 252L ) ) );
        } else {
            value = value.longValue();
            expected = 252L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].sv_id.constellation + "' != '" + 163 + "'", value.equals(BigInteger.valueOf( 163L ) ) );
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[10].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[10].sv_id.satId + "' != '" + 170 + "'", value.equals(BigInteger.valueOf( 170L ) ) );
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].stec_coeff[0] + "' != '" + -23340 + "'", value.equals(BigInteger.valueOf( -23340L ) ) );
        } else {
            value = value.longValue();
            expected = -23340L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].stec_coeff[1] + "' != '" + -24063 + "'", value.equals(BigInteger.valueOf( -24063L ) ) );
        } else {
            value = value.longValue();
            expected = -24063L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].stec_coeff[2] + "' != '" + 4650 + "'", value.equals(BigInteger.valueOf( 4650L ) ) );
        } else {
            value = value.longValue();
            expected = 4650L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].stec_coeff[3] + "' != '" + -22148 + "'", value.equals(BigInteger.valueOf( -22148L ) ) );
        } else {
            value = value.longValue();
            expected = -22148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].stec_quality_indicator + "' != '" + 241 + "'", value.equals(BigInteger.valueOf( 241L ) ) );
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].sv_id.constellation + "' != '" + 213 + "'", value.equals(BigInteger.valueOf( 213L ) ) );
        } else {
            value = value.longValue();
            expected = 213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[11].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[11].sv_id.satId + "' != '" + 119 + "'", value.equals(BigInteger.valueOf( 119L ) ) );
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].stec_coeff[0] + "' != '" + 5944 + "'", value.equals(BigInteger.valueOf( 5944L ) ) );
        } else {
            value = value.longValue();
            expected = 5944L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].stec_coeff[1] + "' != '" + 32142 + "'", value.equals(BigInteger.valueOf( 32142L ) ) );
        } else {
            value = value.longValue();
            expected = 32142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].stec_coeff[2] + "' != '" + 30760 + "'", value.equals(BigInteger.valueOf( 30760L ) ) );
        } else {
            value = value.longValue();
            expected = 30760L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].stec_coeff[3] + "' != '" + 11587 + "'", value.equals(BigInteger.valueOf( 11587L ) ) );
        } else {
            value = value.longValue();
            expected = 11587L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].stec_quality_indicator + "' != '" + 26 + "'", value.equals(BigInteger.valueOf( 26L ) ) );
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].sv_id.constellation + "' != '" + 158 + "'", value.equals(BigInteger.valueOf( 158L ) ) );
        } else {
            value = value.longValue();
            expected = 158L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[12].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[12].sv_id.satId + "' != '" + 121 + "'", value.equals(BigInteger.valueOf( 121L ) ) );
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].stec_coeff[0] + "' != '" + 3095 + "'", value.equals(BigInteger.valueOf( 3095L ) ) );
        } else {
            value = value.longValue();
            expected = 3095L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].stec_coeff[1] + "' != '" + 22769 + "'", value.equals(BigInteger.valueOf( 22769L ) ) );
        } else {
            value = value.longValue();
            expected = 22769L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].stec_coeff[2] + "' != '" + -4283 + "'", value.equals(BigInteger.valueOf( -4283L ) ) );
        } else {
            value = value.longValue();
            expected = -4283L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].stec_coeff[3] + "' != '" + 14844 + "'", value.equals(BigInteger.valueOf( 14844L ) ) );
        } else {
            value = value.longValue();
            expected = 14844L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].stec_quality_indicator + "' != '" + 110 + "'", value.equals(BigInteger.valueOf( 110L ) ) );
        } else {
            value = value.longValue();
            expected = 110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].sv_id.constellation + "' != '" + 235 + "'", value.equals(BigInteger.valueOf( 235L ) ) );
        } else {
            value = value.longValue();
            expected = 235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[13].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[13].sv_id.satId + "' != '" + 126 + "'", value.equals(BigInteger.valueOf( 126L ) ) );
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].stec_coeff[0] + "' != '" + -21032 + "'", value.equals(BigInteger.valueOf( -21032L ) ) );
        } else {
            value = value.longValue();
            expected = -21032L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].stec_coeff[1] + "' != '" + -19726 + "'", value.equals(BigInteger.valueOf( -19726L ) ) );
        } else {
            value = value.longValue();
            expected = -19726L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].stec_coeff[2] + "' != '" + 1297 + "'", value.equals(BigInteger.valueOf( 1297L ) ) );
        } else {
            value = value.longValue();
            expected = 1297L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].stec_coeff[3] + "' != '" + -22049 + "'", value.equals(BigInteger.valueOf( -22049L ) ) );
        } else {
            value = value.longValue();
            expected = -22049L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].stec_quality_indicator + "' != '" + 201 + "'", value.equals(BigInteger.valueOf( 201L ) ) );
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].sv_id.constellation + "' != '" + 44 + "'", value.equals(BigInteger.valueOf( 44L ) ) );
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[14].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[14].sv_id.satId + "' != '" + 93 + "'", value.equals(BigInteger.valueOf( 93L ) ) );
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].stec_coeff[0] + "' != '" + 619 + "'", value.equals(BigInteger.valueOf( 619L ) ) );
        } else {
            value = value.longValue();
            expected = 619L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].stec_coeff[1] + "' != '" + -5744 + "'", value.equals(BigInteger.valueOf( -5744L ) ) );
        } else {
            value = value.longValue();
            expected = -5744L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].stec_coeff[2] + "' != '" + 22542 + "'", value.equals(BigInteger.valueOf( 22542L ) ) );
        } else {
            value = value.longValue();
            expected = 22542L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].stec_coeff[3] + "' != '" + -12000 + "'", value.equals(BigInteger.valueOf( -12000L ) ) );
        } else {
            value = value.longValue();
            expected = -12000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].stec_quality_indicator + "' != '" + 77 + "'", value.equals(BigInteger.valueOf( 77L ) ) );
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].sv_id.constellation + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[15].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[15].sv_id.satId + "' != '" + 192 + "'", value.equals(BigInteger.valueOf( 192L ) ) );
        } else {
            value = value.longValue();
            expected = 192L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].stec_coeff[0] + "' != '" + 10651 + "'", value.equals(BigInteger.valueOf( 10651L ) ) );
        } else {
            value = value.longValue();
            expected = 10651L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].stec_coeff[1] + "' != '" + -2889 + "'", value.equals(BigInteger.valueOf( -2889L ) ) );
        } else {
            value = value.longValue();
            expected = -2889L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].stec_coeff[2] + "' != '" + 21150 + "'", value.equals(BigInteger.valueOf( 21150L ) ) );
        } else {
            value = value.longValue();
            expected = 21150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].stec_coeff[3] + "' != '" + 26421 + "'", value.equals(BigInteger.valueOf( 26421L ) ) );
        } else {
            value = value.longValue();
            expected = 26421L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].stec_quality_indicator + "' != '" + 123 + "'", value.equals(BigInteger.valueOf( 123L ) ) );
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].sv_id.constellation + "' != '" + 17 + "'", value.equals(BigInteger.valueOf( 17L ) ) );
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[16].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[16].sv_id.satId + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].stec_coeff[0] + "' != '" + -19165 + "'", value.equals(BigInteger.valueOf( -19165L ) ) );
        } else {
            value = value.longValue();
            expected = -19165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].stec_coeff[1] + "' != '" + 30229 + "'", value.equals(BigInteger.valueOf( 30229L ) ) );
        } else {
            value = value.longValue();
            expected = 30229L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].stec_coeff[2] + "' != '" + -1282 + "'", value.equals(BigInteger.valueOf( -1282L ) ) );
        } else {
            value = value.longValue();
            expected = -1282L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].stec_coeff[3] + "' != '" + -18382 + "'", value.equals(BigInteger.valueOf( -18382L ) ) );
        } else {
            value = value.longValue();
            expected = -18382L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].stec_quality_indicator + "' != '" + 185 + "'", value.equals(BigInteger.valueOf( 185L ) ) );
        } else {
            value = value.longValue();
            expected = 185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].sv_id.constellation + "' != '" + 202 + "'", value.equals(BigInteger.valueOf( 202L ) ) );
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[17].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[17].sv_id.satId + "' != '" + 14 + "'", value.equals(BigInteger.valueOf( 14L ) ) );
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].stec_coeff[0] + "' != '" + -23752 + "'", value.equals(BigInteger.valueOf( -23752L ) ) );
        } else {
            value = value.longValue();
            expected = -23752L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].stec_coeff[1] + "' != '" + 32433 + "'", value.equals(BigInteger.valueOf( 32433L ) ) );
        } else {
            value = value.longValue();
            expected = 32433L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].stec_coeff[2] + "' != '" + 20441 + "'", value.equals(BigInteger.valueOf( 20441L ) ) );
        } else {
            value = value.longValue();
            expected = 20441L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].stec_coeff[3] + "' != '" + -4181 + "'", value.equals(BigInteger.valueOf( -4181L ) ) );
        } else {
            value = value.longValue();
            expected = -4181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].stec_quality_indicator + "' != '" + 45 + "'", value.equals(BigInteger.valueOf( 45L ) ) );
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].sv_id.constellation + "' != '" + 31 + "'", value.equals(BigInteger.valueOf( 31L ) ) );
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[18].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[18].sv_id.satId + "' != '" + 50 + "'", value.equals(BigInteger.valueOf( 50L ) ) );
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].stec_coeff[0] + "' != '" + -13968 + "'", value.equals(BigInteger.valueOf( -13968L ) ) );
        } else {
            value = value.longValue();
            expected = -13968L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].stec_coeff[1] + "' != '" + -29322 + "'", value.equals(BigInteger.valueOf( -29322L ) ) );
        } else {
            value = value.longValue();
            expected = -29322L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].stec_coeff[2] + "' != '" + -23790 + "'", value.equals(BigInteger.valueOf( -23790L ) ) );
        } else {
            value = value.longValue();
            expected = -23790L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].stec_coeff[3] + "' != '" + 9063 + "'", value.equals(BigInteger.valueOf( 9063L ) ) );
        } else {
            value = value.longValue();
            expected = 9063L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].stec_quality_indicator + "' != '" + 238 + "'", value.equals(BigInteger.valueOf( 238L ) ) );
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].sv_id.constellation + "' != '" + 188 + "'", value.equals(BigInteger.valueOf( 188L ) ) );
        } else {
            value = value.longValue();
            expected = 188L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[19].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[19].sv_id.satId + "' != '" + 237 + "'", value.equals(BigInteger.valueOf( 237L ) ) );
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].stec_coeff[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].stec_coeff[0] + "' != '" + 4737 + "'", value.equals(BigInteger.valueOf( 4737L ) ) );
        } else {
            value = value.longValue();
            expected = 4737L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].stec_coeff[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].stec_coeff[1] + "' != '" + 21877 + "'", value.equals(BigInteger.valueOf( 21877L ) ) );
        } else {
            value = value.longValue();
            expected = 21877L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].stec_coeff[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].stec_coeff[2] + "' != '" + 20414 + "'", value.equals(BigInteger.valueOf( 20414L ) ) );
        } else {
            value = value.longValue();
            expected = 20414L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].stec_coeff[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].stec_coeff[3] + "' != '" + -10286 + "'", value.equals(BigInteger.valueOf( -10286L ) ) );
        } else {
            value = value.longValue();
            expected = -10286L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].stec_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].stec_quality_indicator + "' != '" + 82 + "'", value.equals(BigInteger.valueOf( 82L ) ) );
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].sv_id.constellation + "' != '" + 21 + "'", value.equals(BigInteger.valueOf( 21L ) ) );
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[20].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stec_sat_list[20].sv_id.satId + "' != '" + 63 + "'", value.equals(BigInteger.valueOf( 63L ) ) );
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
