/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadByIndexDone.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.settings.MsgSettingsReadByIndexDone;


public class auto_check_sbp_settings_MsgSettingsReadByIndexDoneTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_settings_MsgSettingsReadByIndexDoneTest.test1");
        byte[] payload = new byte[] { };
        SBPMessage sbp = new SBPMessage( 0xd7f6, 0xa6, payload );
        MsgSettingsReadByIndexDone msg = new MsgSettingsReadByIndexDone( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
    }
}