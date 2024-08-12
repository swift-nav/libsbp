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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashErase.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.flash.MsgFlashErase;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_flash_MsgFlashEraseTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_flash_MsgFlashEraseTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 74, (byte) 238, (byte) 177, (byte) 118, (byte) 132,
                };
        SBPMessage sbp = new SBPMessage(0x04c3, 0xe2, payload);
        MsgFlashErase msg = new MsgFlashErase(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.sector_num;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sector_num + "' != '" + 2222371310L + "'",
                    value.equals(new BigInteger("2222371310")));
        } else {
            value = value.longValue();
            expected = 2222371310L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.target;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.target + "' != '" + 74 + "'", value.equals(BigInteger.valueOf(74L)));
        } else {
            value = value.longValue();
            expected = 74L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
