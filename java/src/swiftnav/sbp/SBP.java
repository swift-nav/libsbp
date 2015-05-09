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

package swiftnav.sbp;

import java.io.*;

public class SBP {

    private final int type;

    private final byte[] data;

    private int sender;

    protected SBP(int type, int len) {
        this.type = type;
        this.data = new byte[len];
    }

    protected SBP(int type, byte[] data) {
        this.type = type;
        this.data = data;
    }

    public String toString() {
        String s = "foo!";
        return s;
    }
}
