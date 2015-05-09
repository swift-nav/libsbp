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

package swiftnav.sbp.navigation;

import org.codehaus.preon.annotation.BoundNumber;
import org.codehaus.preon.buffer.ByteOrder;
import swiftnav.sbp.SBP;



  
/** SBP class for message MSG_DOPS (0x0206).
 *
 * You can have MSG_DOPS inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
  * This dilution of precision (DOP) message describes the effect of
 * navigation satellite geometry on positional measurement
 * precision. */
public class MsgDops extends SBP {

    public static final int TYPE = 0x0206;

    public MsgDops() {
    }

    
    /** * GPS Time of Week */
    @BoundString()
    private int tow;

    
    /** * Geometric Dilution of Precision */
    @BoundString()
    private int gdop;

    
    /** * Position Dilution of Precision */
    @BoundString()
    private int pdop;

    
    /** * Time Dilution of Precision */
    @BoundString()
    private int tdop;

    
    /** * Horizontal Dilution of Precision */
    @BoundString()
    private int hdop;

    
    /** * Vertical Dilution of Precision */
    @BoundString()
    private int vdop;

    

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