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

package swiftnav.sbp.observation;

import org.codehaus.preon.annotation.BoundNumber;
import org.codehaus.preon.buffer.ByteOrder;
import swiftnav.sbp.SBP;


  
/**
  * Header of a GPS observation message. */
public class ObservationHeader{

    public ObservationHeader() {
    }

  
    /** * GPS time of this observation */
    @BoundString()
    private None t;

  
    /**  * Total number of observations. First nibble is the size
 * of the sequence (n), second nibble is the zero-indexed
 * counter (ith packet of n) */
    @BoundString()
    private int n_obs;

  

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
