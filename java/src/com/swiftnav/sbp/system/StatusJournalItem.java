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
package com.swiftnav.sbp.system;

// This file was auto-generated from yaml/swiftnav/sbp/system.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import org.json.JSONObject;

public class StatusJournalItem extends SBPStruct {

    /** Milliseconds since system startup */
    public long uptime;

    public SubSystemReport report;

    public StatusJournalItem() {}

    @Override
    public StatusJournalItem parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        uptime = parser.getU32();
        report = new SubSystemReport().parse(parser);
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU32(uptime);
        report.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("uptime", uptime);
        obj.put("report", report.toJSON());
        return obj;
    }
}
