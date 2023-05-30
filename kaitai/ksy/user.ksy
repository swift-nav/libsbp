# Messages reserved for use by the user.

# Automatically generated from spec/yaml/swiftnav/sbp/user.yaml with generate.py.
# Please do not hand edit!

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
  