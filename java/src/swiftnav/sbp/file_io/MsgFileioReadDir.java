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

package swiftnav.sbp.file_io;

import org.codehaus.preon.annotation.BoundNumber;
import org.codehaus.preon.buffer.ByteOrder;
import swiftnav.sbp.SBP;



  
/** SBP class for message MSG_FILEIO_READ_DIR (0x00A9).
 *
 * You can have MSG_FILEIO_READ_DIR inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
  * The read directory message lists the files in a directory on the
 * device's onboard flash file system.  The offset parameter can be
 * used to skip the first n elements of the file list. Returns a
 * MSG_FILEIO_READ_DIR message containing the directory listings as
 * a NULL delimited list. The listing is chunked over multiple SBP
 * packets and the end of the list is identified by an entry
 * containing just the character 0xFF. If message is invalid, a
 * followup MSG_PRINT message will print "Invalid fileio read
 * message". */
public class MsgFileioReadDir extends SBP {

    public static final int TYPE = 0x00A9;

    public MsgFileioReadDir() {
    }

    
    /**  * The offset to skip the first n elements of the file list */
    @BoundString()
    private int offset;

    
    /** * Name of the directory to list (NULL padded) */
    @BoundString()
    private None dirname;

    

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