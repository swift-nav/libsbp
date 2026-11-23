# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from .utils import PYTHON_ROOT
import sbp.sbp2json
import os
import pytest

TEST_DATA = os.path.join(PYTHON_ROOT, "..", "test_data", "benchmark.sbp")


def get_message_count(unbuffered):
    msg_count = 0
    def counter(args, res):
        nonlocal msg_count
        msg_count += 1

    sbp.sbp2json.dump = counter

    # anonymous object to emulate parsed arguments
    args = type('',(object,),{
        'file': open(TEST_DATA, "rb"),
        'include': [],
        'unbuffered': unbuffered
    })()

    sbp.sbp2json.sbp_main(args)

    return msg_count


# make sure that we parse exactly 150000 SBP messages from TEST_DATA
# when running sbp2json without the --unbuffered flag
@pytest.mark.slow
def test_sbp2json_buffered():
    msg_count = get_message_count(False)
    assert msg_count == 150000


# make sure that we parse exactly 150000 SBP messages from TEST_DATA
# when running sbp2json with the --unbuffered flag
@pytest.mark.slow
def test_sbp2json_unbuffered():
    msg_count = get_message_count(True)
    assert msg_count == 150000


def _heartbeat(sender, flags):
    payload = flags.to_bytes(4, 'little')
    return sbp.msg.SBP(0xFFFF, sender, len(payload), payload).to_binary()


# A message cut short by a dropped connection, followed by complete messages.
# Both parsers must skip the broken message and still find every complete one.
@pytest.mark.parametrize("iter_fn", [
    sbp.sbp2json.iter_messages_buffered,
    sbp.sbp2json.iter_messages_unbuffered,
])
def test_sbp2json_resync_after_truncated_message(iter_fn):
    import io
    truncated = bytes([0x55, 0x02, 0x02, 0x42, 0x00, 50, 1, 2, 3, 4])
    senders = list(range(0x100, 0x10A))
    stream = truncated + b''.join(_heartbeat(s, 0x12) for s in senders)

    msgs = list(iter_fn(io.BytesIO(stream)))

    assert [sender for _, sender, _, _, _ in msgs] == senders
