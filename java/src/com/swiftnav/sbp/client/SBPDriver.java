/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.client;

import java.io.IOException;

/** Abstract interface for SBP stream drivers. */
public interface SBPDriver {
    /** Read bytes from the SBP link .
     * This function must read the number of bytes specified from the link
     * and may block if necessary.  If the link is no longer available an
     * IOException must be thrown.
     */
    byte[] read(int len) throws IOException;
    /** Write bytes to the SBP link.
     * This function must write all the data bytes to the link.  If this is
     * not possible because the link is no longer available an IOException must
     * be thrown.
     */
    void write(byte[] data) throws IOException;
}
