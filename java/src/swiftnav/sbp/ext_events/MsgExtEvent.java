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

package swiftnav.sbp.ext_events;

import org.codehaus.preon.annotation.BoundNumber;
import org.codehaus.preon.buffer.ByteOrder;
import swiftnav.sbp.SBP;



  
/** SBP class for message MSG_EXT_EVENT (0x0101).
 *
 * You can have MSG_EXT_EVENT inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
  * Reports detection of an external event, the GPS time it occurred,
 * which pin it was and whether it was rising or falling. */
public class MsgExtEvent extends SBP {

    public static final int TYPE = 0x0101;

    public MsgExtEvent() {
    }

    
    /** * GPS week number */
    @BoundString()
    private int wn;

    
    /** * GPS time of week rounded to the nearest millisecond */
    @BoundString()
    private int tow;

    
    /**  * Nanosecond residual of millisecond-rounded TOW (ranges
 * from -500000 to 500000) */
    @BoundString()
    private int ns;

    
    /** * Flags */
    @BoundString()
    private int flags;

    
    /** * Pin number.  0..9 = DEBUG0..9. */
    @BoundString()
    private int pin;

    

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