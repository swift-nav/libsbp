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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadByIndexResp.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.settings.MsgSettingsReadByIndexResp;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_settings_MsgSettingsReadByIndexRespTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_settings_MsgSettingsReadByIndexRespTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 0,
                    (byte) 116,
                    (byte) 101,
                    (byte) 108,
                    (byte) 101,
                    (byte) 109,
                    (byte) 101,
                    (byte) 116,
                    (byte) 114,
                    (byte) 121,
                    (byte) 95,
                    (byte) 114,
                    (byte) 97,
                    (byte) 100,
                    (byte) 105,
                    (byte) 111,
                    (byte) 0,
                    (byte) 99,
                    (byte) 111,
                    (byte) 110,
                    (byte) 102,
                    (byte) 105,
                    (byte) 103,
                    (byte) 117,
                    (byte) 114,
                    (byte) 97,
                    (byte) 116,
                    (byte) 105,
                    (byte) 111,
                    (byte) 110,
                    (byte) 95,
                    (byte) 115,
                    (byte) 116,
                    (byte) 114,
                    (byte) 105,
                    (byte) 110,
                    (byte) 103,
                    (byte) 0,
                    (byte) 65,
                    (byte) 84,
                    (byte) 38,
                    (byte) 70,
                    (byte) 44,
                    (byte) 65,
                    (byte) 84,
                    (byte) 83,
                    (byte) 49,
                    (byte) 61,
                    (byte) 49,
                    (byte) 49,
                    (byte) 53,
                    (byte) 44,
                    (byte) 65,
                    (byte) 84,
                    (byte) 83,
                    (byte) 50,
                    (byte) 61,
                    (byte) 49,
                    (byte) 50,
                    (byte) 56,
                    (byte) 44,
                    (byte) 65,
                    (byte) 84,
                    (byte) 83,
                    (byte) 53,
                    (byte) 61,
                    (byte) 48,
                    (byte) 44,
                    (byte) 65,
                    (byte) 84,
                    (byte) 38,
                    (byte) 87,
                    (byte) 44,
                    (byte) 65,
                    (byte) 84,
                    (byte) 90,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0xa7, payload);
        MsgSettingsReadByIndexResp msg = new MsgSettingsReadByIndexResp(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.index + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(
                msg.setting,
                "telemetry_radio configuration_string AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ ");

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_settings_MsgSettingsReadByIndexRespTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 1,
                    (byte) 0,
                    (byte) 117,
                    (byte) 97,
                    (byte) 114,
                    (byte) 116,
                    (byte) 95,
                    (byte) 102,
                    (byte) 116,
                    (byte) 100,
                    (byte) 105,
                    (byte) 0,
                    (byte) 109,
                    (byte) 111,
                    (byte) 100,
                    (byte) 101,
                    (byte) 0,
                    (byte) 83,
                    (byte) 66,
                    (byte) 80,
                    (byte) 0,
                    (byte) 101,
                    (byte) 110,
                    (byte) 117,
                    (byte) 109,
                    (byte) 58,
                    (byte) 83,
                    (byte) 66,
                    (byte) 80,
                    (byte) 44,
                    (byte) 78,
                    (byte) 77,
                    (byte) 69,
                    (byte) 65,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0xa7, payload);
        MsgSettingsReadByIndexResp msg = new MsgSettingsReadByIndexResp(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.index + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.setting, "uart_ftdi mode SBP enum:SBP,NMEA ");

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_settings_MsgSettingsReadByIndexRespTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 2,
                    (byte) 0,
                    (byte) 117,
                    (byte) 97,
                    (byte) 114,
                    (byte) 116,
                    (byte) 95,
                    (byte) 102,
                    (byte) 116,
                    (byte) 100,
                    (byte) 105,
                    (byte) 0,
                    (byte) 115,
                    (byte) 98,
                    (byte) 112,
                    (byte) 95,
                    (byte) 109,
                    (byte) 101,
                    (byte) 115,
                    (byte) 115,
                    (byte) 97,
                    (byte) 103,
                    (byte) 101,
                    (byte) 95,
                    (byte) 109,
                    (byte) 97,
                    (byte) 115,
                    (byte) 107,
                    (byte) 0,
                    (byte) 54,
                    (byte) 53,
                    (byte) 53,
                    (byte) 51,
                    (byte) 53,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0xa7, payload);
        MsgSettingsReadByIndexResp msg = new MsgSettingsReadByIndexResp(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.index + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.setting, "uart_ftdi sbp_message_mask 65535 ");

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_settings_MsgSettingsReadByIndexRespTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 3, (byte) 0, (byte) 117, (byte) 97, (byte) 114, (byte) 116, (byte) 95,
                    (byte) 102, (byte) 116, (byte) 100, (byte) 105, (byte) 0, (byte) 98, (byte) 97,
                    (byte) 117, (byte) 100, (byte) 114, (byte) 97, (byte) 116, (byte) 101, (byte) 0,
                    (byte) 49, (byte) 48, (byte) 48, (byte) 48, (byte) 48, (byte) 48, (byte) 48,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0xa7, payload);
        MsgSettingsReadByIndexResp msg = new MsgSettingsReadByIndexResp(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.index + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.setting, "uart_ftdi baudrate 1000000 ");

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_settings_MsgSettingsReadByIndexRespTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 4, (byte) 0, (byte) 117, (byte) 97, (byte) 114, (byte) 116, (byte) 95,
                    (byte) 117, (byte) 97, (byte) 114, (byte) 116, (byte) 97, (byte) 0, (byte) 109,
                    (byte) 111, (byte) 100, (byte) 101, (byte) 0, (byte) 83, (byte) 66, (byte) 80,
                    (byte) 0, (byte) 101, (byte) 110, (byte) 117, (byte) 109, (byte) 58, (byte) 83,
                    (byte) 66, (byte) 80, (byte) 44, (byte) 78, (byte) 77, (byte) 69, (byte) 65,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0xa7, payload);
        MsgSettingsReadByIndexResp msg = new MsgSettingsReadByIndexResp(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.index + "' != '" + 4 + "'", value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.setting, "uart_uarta mode SBP enum:SBP,NMEA ");

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
