# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Messages reserved for use by the user.
#
# Automatically generated from spec/yaml/swiftnav/sbp/user.yaml with generate.py.
# Do not modify by hand!

meta:
  id: user
  endian: le
  imports: [  ]

types:

  msg_user_data:
    doc: |
      This message can contain any application specific user data up to a
      maximum length of 255 bytes per message.
    seq:
      - id: contents
        doc: |
          User data payload
        type: u1
        repeat: eos
  
