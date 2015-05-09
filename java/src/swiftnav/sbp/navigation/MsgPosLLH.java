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



  
/** SBP class for message MSG_POS_LLH (0x0201).
 *
 * You can have MSG_POS_LLH inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
  * This position solution message reports the absolute geodetic
 * coordinates and the status (single point vs pseudo-absolute RTK)
 * of the position solution. If the rover receiver knows the
 * surveyed position of the base station and has an RTK solution,
 * this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full
 * GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow). */
public class MsgPosLLH extends SBP {

    public static final int TYPE = 0x0201;

    public MsgPosLLH() {
    }

    
    /** * GPS Time of Week */
    @BoundString()
    private int tow;

    
    /** * Latitude */
    @BoundString()
    private double lat;

    
    /** * Longitude */
    @BoundString()
    private double lon;

    
    /** * Height */
    @BoundString()
    private double height;

    
    /**  * Horizontal position accuracy estimate (not
 * implemented). Defaults to 0. */
    @BoundString()
    private int h_accuracy;

    
    /**  * Vertical position accuracy estimate (not
 * implemented). Defaults to 0. */
    @BoundString()
    private int v_accuracy;

    
    /** * Number of satellites used in solution. */
    @BoundString()
    private int n_sats;

    
    /** * Status flags */
    @BoundString()
    private int flags;

    

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