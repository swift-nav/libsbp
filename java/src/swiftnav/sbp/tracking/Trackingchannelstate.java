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

package swiftnav.sbp.tracking;

import org.codehaus.preon.annotation.BoundNumber;
import org.codehaus.preon.buffer.ByteOrder;
import swiftnav.sbp.SBP;


  
/**
   * Tracking channel state for a specific satellite PRN and measured
 * signal power. */
public class TrackingChannelState{

    public TrackingChannelState() {
    }

  
    /** * Status of tracking channel */
    @BoundString()
    private int state;

  
    /** * PRN-1 being tracked */
    @BoundString()
    private int prn;

  
    /** * Carrier-to-noise density */
    @BoundString()
    private float cn0;

  

    /** Given a binary payload d, update the appropriate payload
     *  fields of the message.
    */
    public void fromBinary() {
      return;
    }

    /** Produce a framed/packed SBP message.
     */
    public int toBinary() {
        return 0;
    }

    public String toString() {
        return "Foo!";
    }
}
