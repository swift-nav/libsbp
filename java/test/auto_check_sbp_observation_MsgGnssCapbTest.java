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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGnssCapb.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgGnssCapb;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgGnssCapbTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgGnssCapbTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 176,
                    (byte) 207,
                    (byte) 6,
                    (byte) 0,
                    (byte) 106,
                    (byte) 8,
                    (byte) 26,
                    (byte) 171,
                    (byte) 80,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 81,
                    (byte) 173,
                    (byte) 144,
                    (byte) 46,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 209,
                    (byte) 139,
                    (byte) 93,
                    (byte) 108,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 252,
                    (byte) 204,
                    (byte) 200,
                    (byte) 0,
                    (byte) 205,
                    (byte) 92,
                    (byte) 30,
                    (byte) 49,
                    (byte) 240,
                    (byte) 203,
                    (byte) 21,
                    (byte) 24,
                    (byte) 212,
                    (byte) 93,
                    (byte) 182,
                    (byte) 32,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 105,
                    (byte) 32,
                    (byte) 192,
                    (byte) 27,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 40,
                    (byte) 75,
                    (byte) 250,
                    (byte) 114,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 119,
                    (byte) 147,
                    (byte) 123,
                    (byte) 81,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 85,
                    (byte) 89,
                    (byte) 4,
                    (byte) 2,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 233,
                    (byte) 116,
                    (byte) 137,
                    (byte) 22,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 199,
                    (byte) 109,
                    (byte) 219,
                    (byte) 11,
                    (byte) 221,
                    (byte) 171,
                    (byte) 248,
                    (byte) 82,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 252,
                    (byte) 62,
                    (byte) 221,
                    (byte) 28,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x007b, 0x96, payload);
        MsgGnssCapb msg = new MsgGnssCapb(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.gc.bds_active;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.bds_active + "' != '" + 1929005864 + "'",
                    value.equals(BigInteger.valueOf(1929005864L)));
        } else {
            value = value.longValue();
            expected = 1929005864L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.bds_b2;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.bds_b2 + "' != '" + 33839445 + "'",
                    value.equals(BigInteger.valueOf(33839445L)));
        } else {
            value = value.longValue();
            expected = 33839445L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.bds_b2a;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.bds_b2a + "' != '" + 378107113 + "'",
                    value.equals(BigInteger.valueOf(378107113L)));
        } else {
            value = value.longValue();
            expected = 378107113L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.bds_d2nav;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.bds_d2nav + "' != '" + 1367053175 + "'",
                    value.equals(BigInteger.valueOf(1367053175L)));
        } else {
            value = value.longValue();
            expected = 1367053175L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.gal_active;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.gal_active + "' != '" + 1392028637 + "'",
                    value.equals(BigInteger.valueOf(1392028637L)));
        } else {
            value = value.longValue();
            expected = 1392028637L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.gal_e5;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.gal_e5 + "' != '" + 484261628 + "'",
                    value.equals(BigInteger.valueOf(484261628L)));
        } else {
            value = value.longValue();
            expected = 484261628L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.glo_active;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.glo_active + "' != '" + 13159676 + "'",
                    value.equals(BigInteger.valueOf(13159676L)));
        } else {
            value = value.longValue();
            expected = 13159676L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.glo_l2of;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.glo_l2of + "' != '" + 824073421 + "'",
                    value.equals(BigInteger.valueOf(824073421L)));
        } else {
            value = value.longValue();
            expected = 824073421L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.glo_l3;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.glo_l3 + "' != '" + 404081648 + "'",
                    value.equals(BigInteger.valueOf(404081648L)));
        } else {
            value = value.longValue();
            expected = 404081648L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.gps_active;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.gps_active + "' != '" + 1079028506 + "'",
                    value.equals(BigInteger.valueOf(1079028506L)));
        } else {
            value = value.longValue();
            expected = 1079028506L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.gps_l2c;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.gps_l2c + "' != '" + 781233489 + "'",
                    value.equals(BigInteger.valueOf(781233489L)));
        } else {
            value = value.longValue();
            expected = 781233489L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.gps_l5;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.gps_l5 + "' != '" + 1818069969 + "'",
                    value.equals(BigInteger.valueOf(1818069969L)));
        } else {
            value = value.longValue();
            expected = 1818069969L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.qzss_active;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.qzss_active + "' != '" + 198929863 + "'",
                    value.equals(BigInteger.valueOf(198929863L)));
        } else {
            value = value.longValue();
            expected = 198929863L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.sbas_active;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.sbas_active + "' != '" + 548822484 + "'",
                    value.equals(BigInteger.valueOf(548822484L)));
        } else {
            value = value.longValue();
            expected = 548822484L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gc.sbas_l5;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gc.sbas_l5 + "' != '" + 465576041 + "'",
                    value.equals(BigInteger.valueOf(465576041L)));
        } else {
            value = value.longValue();
            expected = 465576041L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.t_nmct.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.t_nmct.tow + "' != '" + 446384 + "'",
                    value.equals(BigInteger.valueOf(446384L)));
        } else {
            value = value.longValue();
            expected = 446384L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.t_nmct.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.t_nmct.wn + "' != '" + 2154 + "'",
                    value.equals(BigInteger.valueOf(2154L)));
        } else {
            value = value.longValue();
            expected = 2154L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
