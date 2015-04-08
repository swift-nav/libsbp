#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import pprint

def fmt_repr(obj):
  """
  Return pretty printed string representation of an object.

  """
  items = {k: v for k, v in obj.__dict__.items()}
  return "<%s: {%s}>" % (obj.__class__.__name__, pprint.pformat(items, width=1))

def rejig_values(values):
    new_values = []
    for v in values:
        value, desc = v.iteritems().next()
        new_values.append({
            'value': value,
            'desc': desc
        })
    return new_values

def rejig_bitfields(bfs):
    new_bfs = []
    n_with_values = 0
    for bf in bfs:
        rng, info = bf.iteritems().next()
        if 'values' in info:
            n_with_values += 1
            info['vals'] = rejig_values(info['values'])
            del info['values']
        rng = map(int, str(rng).split('-'))
        if len(rng) == 1:
            lsb = rng[0]
            bf_len = 1
        else:
            lsb, msb = rng
            bf_len = msb + 1 - lsb
        rng = ':'.join(map(str, rng))
        new_bfs.append(dict(info, **{
            'lsb': lsb,
            'range': rng,
            'len': bf_len,
        }))
    return new_bfs, n_with_values
