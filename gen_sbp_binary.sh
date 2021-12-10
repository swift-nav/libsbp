#!/bin/bash

PYTHONPATH=python python -c "import sys; import json; from sbp.navigation import MsgVelCog; sys.stdout.buffer.write(MsgVelCog(**json.loads(sys.stdin.read())).to_binary())" <<EOF
  {"msg_type": 540, "sender": 35027, "tow": 326825520, "cog": 45123, "sog": 123, "vel_d": 456, "cog_accuracy": 789, "sog_accuracy": 42, "vel_d_accuracy": 24, "flags": 63}
EOF
