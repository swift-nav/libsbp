#!/bin/bash


#PYTHONPATH=python python -c "import sys; import json; from sbp.navigation import MsgVelCog; sys.stdout.buffer.write(MsgVelCog(**json.loads(sys.stdin.read())).to_binary())" <<EOF
#  {"msg_type": 540, "sender": 35027, "tow": 326825520, "cog": 0, "sog": 0, "vel_d": 0, "cog_accuracy": 0, "sog_accuracy": 0, "vel_d_accuracy": 0, "flags": 0}
#EOF

PYTHONPATH=python python -c "import sys; import json; from sbp.navigation import MsgVelCog; sys.stdout.buffer.write(MsgVelCog(**json.loads(sys.stdin.read())).to_binary())" <<EOF
  {"msg_type": 540, "sender": 35027, "tow": 326825520, "cog": 1000, "sog": 2000, "vel_d": 3000, "cog_accuracy": 4000, "sog_accuracy": 5000, "vel_d_accuracy": 6000, "flags": 62}
EOF

PYTHONPATH=python python -c "import sys; import json; from sbp.navigation import MsgVelCog; sys.stdout.buffer.write(MsgVelCog(**json.loads(sys.stdin.read())).to_binary())" <<EOF
  {"msg_type": 540, "sender": 35027, "tow": 326825520, "cog": 123, "sog": 456, "vel_d": -1000, "cog_accuracy": 180000000, "sog_accuracy": 100, "vel_d_accuracy": 100, "flags": 0}
EOF
