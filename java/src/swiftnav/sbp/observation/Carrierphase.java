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
   * Carrier phase measurement in cycles represented as a 40-bit
 * fixed point number with Q32.8 layout, i.e. 32-bits of whole
 * cycles and 8-bits of fractional cycles. */
public class CarrierPhase{

    public CarrierPhase() {
    }

  
    /** * Carrier phase whole cycles */
    @BoundString()
    private int i;

  
    /** * Carrier phase fractional part */
    @BoundString()
    private int f;

  

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
