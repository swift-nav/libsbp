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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioRemove.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.file_io.MsgFileioRemove;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_file_io_MsgFileioRemoveTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_file_io_MsgFileioRemoveTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 47, (byte) 112, (byte) 97, (byte) 116, (byte) 104, (byte) 47, (byte) 116,
                    (byte) 111, (byte) 47, (byte) 102, (byte) 105, (byte) 108, (byte) 101, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x04c3, 0xac, payload);
        MsgFileioRemove msg = new MsgFileioRemove(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.filename, "/path/to/file ");

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
