/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package swiftnav.sbp.flash;

import org.codehaus.preon.annotation.BoundNumber;
import org.codehaus.preon.buffer.ByteOrder;
import swiftnav.sbp.SBP;



  
/** SBP class for message MSG_M25_FLASH_WRITE_STATUS (0x00F3).
 *
 * You can have MSG_M25_FLASH_WRITE_STATUS inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
  * The flash status message writes to the 8-bit M25 flash status
 * register. The device replies with a MSG_FLASH_DONE message. */
public class MsgM25FlashWriteStatus extends SBP {

    public static final int TYPE = 0x00F3;

    public MsgM25FlashWriteStatus() {
    }

    
    /** * Byte to write to the M25 flash status register */
    @BoundString()
    private None status;

    

    /** Given a binary payload d, update the appropriate payload
     *  fields of the message. */
    public void fromBinary() {

    }

    /** Produce a framed/packed SBP message. */
    public int toBinary() {
        return 0;
    }

    /** Given a JSON-encoded string s, build a message object. */
    public void fromJSON(String s) {

    }

    public void toJSONDict() {
    }

    public String toString() {
        return "Foo!";
    }
}