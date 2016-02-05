/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 * Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.flash;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_FLASH_PROGRAM (0x00E6).
 *
 * You can have MSG_FLASH_PROGRAM inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The flash program message programs a set of addresses of either
 * the STM or M25 flash. The device replies with either a
 * MSG_FLASH_DONE message containing the return code FLASH_OK (0)
 * on success, or FLASH_INVALID_LEN (2) if the maximum write size
 * is exceeded. Note that the sector-containing addresses must be
 * erased before addresses can be programmed. */

public class MsgFlashProgram extends SBPMessage {
    public static final int TYPE = 0x00E6;

    
    /** Target flags */
    public int target;
    
    /** Starting address offset to program */
    public int[] addr_start;
    
    /** Length of set of addresses to program, counting up from
starting address
 */
    public int addr_len;
    
    /** Data to program addresses with, with length N=addr_len */
    public int[] data;
    

    public MsgFlashProgram (int sender) { super(sender, TYPE); }
    public MsgFlashProgram () { super(TYPE); }
    public MsgFlashProgram (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        target = parser.getU8();
        addr_start = parser.getArrayofU8(3);
        addr_len = parser.getU8();
        data = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(target);
        builder.putArrayofU8(addr_start, 3);
        builder.putU8(addr_len);
        builder.putArrayofU8(data);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("target", target);
        obj.put("addr_start", new JSONArray(addr_start));
        obj.put("addr_len", addr_len);
        obj.put("data", new JSONArray(data));
        return obj;
    }
}