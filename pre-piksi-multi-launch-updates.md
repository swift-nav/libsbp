### SBP changes before shipping Piksi Multi

There are a few changes we would like to make in the SBP protocol. These changes
will be much more painful to make after we ship and customers are relying on
the protocol to be largely static, so we'd like to come to a consensus on
these and implement them before shipping Piksi Multi.

These changes attempt to accomplish a few things:
- Make messages more bandwidth efficient
- Make user side logic of using messages more obvious
- Remove state from the protocol, where possible

### 1. Replace obs forwarding with general purpose forwarding message

Current there is a convention in the protocol that if the sender_id of a
MSG_OBS is 0, it means it is a forwarded observation from another device. We
propose to replace this with a general purpose forwarding message that wraps
the forwarded message, discarding the preamble and checksum of the forwarded
message. This way, the sender_id of the forwarded message will be preserved and
will remove the need for special handling of sender_id = 0 on obs messages.

### 2. sender_id = device_uuid & 0xFFFF

We need to decide where sender_id will come from on Piksi Multi. In deciding
this, we need to keep in mind the following goals:
- sender_id *does not* need to be globally unique amongst all Piksi Multi's
- sender_id *does* need to be unique amongst the Piksi Multi's on a customer's
local network of devices (for instance, point to multi-point ISM radio network,
TCP/IP network, etc)

### 3. Remove request / response messages where possible

The following request response messages are not used in Piksi Multi and can be
deprecated:

- `MSG_BOOTLOADER_HANDSHAKE_REQ`
- `MSG_BOOTLOADER_HANDSHAKE_RESP`
- `MSG_FLASH_READ_REQ`
- `MSG_FLASH_READ_RESP`
- `MSG_FLASH_PROGRAM`
- `MSG_FLASH_ERASE`
- `MSG_FLASH_DONE`
- `MSG_STM_FLASH_LOCK_SECTOR`
- `MSG_STM_FLASH_UNLOCK_SECTOR`
- `MSG_M25_FLASH_WRITE_STATUS`

The following messages could be part of a device ID message that is
periodically sent:

- `MSG_NAP_DEVICE_DNA_REQ`
- `MSG_NAP_DEVICE_DNA_RESP`
- `MSG_STM_UNIQUE_ID_REQ`
- `MSG_STM_UNIQUE_ID_RESP`

### 4. Observation message updates

Updates to observation message to reduce bandwidth and allow observations to
always be sent regardless of whether they're usable (receiving device filters
them for usability rather than sending device).

- Remove week number (2 bytes)
- Replace 4 byte obs.sid with 2 bytes, matching the firmware SID representation
  - Satellite ID (1 byte)
    - Should we make this actual satellite ID value, not value minus 1?
  - Signal (Band/Constellation/Etc) Code (1 byte)
- Replace 2 byte lock counter with 1 byte, conforming to DF402 from RTCM 10403.2
- Add 1 byte of flags for each satellite - need to talk to Estimation and Exafore about what these should be
  - Bit 0: Time fix valid (or code phase valid)
  - Bit 1: Carrier phase valid
  - Bit 2: Half cycle ambiguity resolved
  - Bits 3-7: Reserved
- Have observations be sent out at all times, use flags to indicate validity

### 5. Send solution messages at all times, regardless of fix status

- Affects the following messages:
  - GPS time
  - DOPS (to add)
  - Pos ECEF
  - Pos LLH
  - Baseline ECEF
  - Baseline NED
  - Vel ECEF
  - Vel NED
  - Baseline heading 
- Have flags be consistent across all solution messages (except for GPS time)
  - 0 = Fix not available or invalid
  - 1 = GPS SPS Mode, fix valid
  - 2 = Differential GPS, SPS Mode, fix valid
  - 3 = GPS PPS Mode, fix valid
  - 4 = Real Time Kinematic. System used in RTK mode with fixed integers
  - 5 = Float RTK. Satellite system used in RTK mode, floating integers
  - 6 = Estimated (dead reckoning) Mode
  - 7 = Manual Input Mode
  - 8 = Simulator Mode 
- GPS time: 3 bit time fix field, rest of flag bits reserved:
  - 0: none
  - 1: coarse
  - 2: fine
  - 3 - 255: reserved

### 6. Add UTC time message

Users want UTC time rather than GPS time.

### 7. Add DGPS status message

- u8 flags  (0-3: Source 0: No DGPS 1: SBAS 2: Code Difference 3: RTK 4: PPP, 4-8 reserved)   
- u8[6] Station ID
- u16 age_of_corrections (deci-seconds)  0.1 seconds
- u8 number of GPS satellites from base station
- u8[3] reserved

### 8. Add NAV complete message

Sent after rest of solution messages to indicate all solution message for epoch
have been sent.

### 9. Add fields to MSG_STARTUP
- Cause of start - Power on, software reset, watchdog, hardware reset
- Start type: cold, warm, hot
