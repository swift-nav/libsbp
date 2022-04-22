/* Copyright (C) 2015-2021 Swift Navigation Inc.
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

/**
 * SBP class for message MSG_STATUS_JOURNAL (0xFFFD).
 *
 * <p>You can have MSG_STATUS_JOURNAL inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>The status journal message contains up to 30 past status reports (see MSG_STATUS_REPORT) and
 * functions as a error/event storage for telemetry purposes.
 */
public class MsgStatusJournal extends SBPMessage {
    public static final int TYPE = 0xFFFD;

    /** Identity of reporting system */
    public int reporting_system;

    /** SBP protocol version */
    public int sbp_version;

    /** Increments on each status report sent */
    public long sequence;

    /** Status journal */
    public StatusJournalItem[] status;

    public MsgStatusJournal(int sender) {
        super(sender, TYPE);
    }

    public MsgStatusJournal() {
        super(TYPE);
    }

    public MsgStatusJournal(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        reporting_system = parser.getU16();
        sbp_version = parser.getU16();
        sequence = parser.getU32();
        status = parser.getArray(StatusJournalItem.class);
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(reporting_system);
        builder.putU16(sbp_version);
        builder.putU32(sequence);
        builder.putArray(status);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("reporting_system", reporting_system);
        obj.put("sbp_version", sbp_version);
        obj.put("sequence", sequence);
        obj.put("status", SBPStruct.toJSONArray(status));
        return obj;
    }
}
