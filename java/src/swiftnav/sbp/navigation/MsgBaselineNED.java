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



  
/** SBP class for message MSG_BASELINE_NED (0x0203).
 *
 * You can have MSG_BASELINE_NED inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
  * This message reports the baseline solution in North East Down
 * (NED) coordinates. This baseline is the relative vector distance
 * from the base station to the rover receiver, and NED coordinate
 * system is defined at the local tangent plane centered at the
 * base station position.  The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow). */
public class MsgBaselineNED extends SBP {

    public static final int TYPE = 0x0203;

    public MsgBaselineNED() {
    }

    
    /** * GPS Time of Week */
    @BoundString()
    private int tow;

    
    /** * Baseline North coordinate */
    @BoundString()
    private int n;

    
    /** * Baseline East coordinate */
    @BoundString()
    private int e;

    
    /** * Baseline Down coordinate */
    @BoundString()
    private int d;

    
    /**  * Horizontal position accuracy estimate (not
 * implemented). Defaults to 0. */
    @BoundString()
    private int h_accuracy;

    
    /**  * Vertical position accuracy estimate (not
 * implemented). Defaults to 0. */
    @BoundString()
    private int v_accuracy;

    
    /** * Number of satellites used in solution */
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