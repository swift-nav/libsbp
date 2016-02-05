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


/** SBP class for message MSG_FLASH_READ_RESP (0x00E1).
 *
 * You can have MSG_FLASH_READ_RESP inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The flash read message reads a set of addresses of either the
 * STM or M25 onboard flash. The device replies with a
 * MSG_FLASH_READ_RESP message containing either the read data on
 * success or a MSG_FLASH_DONE message containing the return code
 * FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
 * FLASH_INVALID_ADDR (3) if the address is outside of the allowed
 * range. */

public class MsgFlashReadResp extends SBPMessage {
    public static final int TYPE = 0x00E1;

    
    /** Target flags */
    public int target;
    
    /** Starting address offset to read from */
    public int[] addr_start;
    
    /** Length of set of addresses to read, counting up from
starting address
 */
    public int addr_len;
    

    public MsgFlashReadResp (int sender) { super(sender, TYPE); }
    public MsgFlashReadResp () { super(TYPE); }
    public MsgFlashReadResp (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        target = parser.getU8();
        addr_start = parser.getArrayofU8(3);
        addr_len = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(target);
        builder.putArrayofU8(addr_start, 3);
        builder.putU8(addr_len);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("target", target);
        obj.put("addr_start", new JSONArray(addr_start));
        obj.put("addr_len", addr_len);
        return obj;
    }
}