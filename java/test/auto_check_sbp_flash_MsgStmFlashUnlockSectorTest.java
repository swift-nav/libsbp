/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.test;

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/flash/test_MsgStmFlashUnlockSector.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.flash.MsgStmFlashUnlockSector;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_flash_MsgStmFlashUnlockSectorTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_flash_MsgStmFlashUnlockSectorTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 31, (byte) 16, (byte) 231, (byte) 49,
                };
        SBPMessage sbp = new SBPMessage(0x04c3, 0xe4, payload);
        MsgStmFlashUnlockSector msg = new MsgStmFlashUnlockSector(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.sector;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sector + "' != '" + 837226527 + "'",
                    value.equals(BigInteger.valueOf(837226527L)));
        } else {
            value = value.longValue();
            expected = 837226527L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
