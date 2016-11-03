### SBP changes before shipping Piksi Multi

There are a few changes we would like to make in the SBP protocol. These changes
will be much more painful to make after we ship and customers are relying on
the protocol to be largely static, so we'd like to come to a consensus on
these and implement them before shipping Piksi Multi.

These changes attempt to accomplish a few things:
- Make messages more bandwidth efficient
- Make user side logic of using messages more obvious
- Remove state from the protocol, where possible

### 1. Send solution messages at all times, regardless of fix status

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
- Update flags 
   - Describe "fix mode" portion of flags field to be for each individual message only
   - in all messages, 0 corresponds to "invalid"
   - RTK Float and RTK Fixed flags have same numerical value across different messages where relevant
   - No separate flags for simulation mode
   - Only a minor release without a change to MSG_ID can be used to assign a meaning to reserved flags
- Flags detail
    - POS flags:
       - Bits 2-0
         - 000 Invalid
         - 001 RTK Float
         - 010 RTK Fixed
         - 011 SPP
         - 100 Reserved
         - 101 Reserved
         - 110 Reserved
         - 111 Reserved
       - Bits 6-3
         - Reserved
       - Bit 7
         - 0 No RAIM repair
         - 1 RAIM repair
       - Note, we remove MSL vs Ellipsoid height as we have nothing but ellipsoid currently

    - BASELINE flags:
      - Bits: 76543210
      - Bits 2-0:
        - 000 Invalid
        - 001 RTK Float
        - 010 RTK Fixed
        - 011 Reserved
        - 100 Reserved
        - 101 Reserved
        - 110 Reserved
        - 111 Reserved
      - Bits 6-3:
        - Reserved
      - Bit 7:
        - 0 No RAIM Repair
        - 1 RAIM repair

     - VEL flags:
        - Bits: 76543210
        - Bits 2-0:
          - 000 Invalid
          - 001 Measured Doppler Derived
          - 010 Computed Doppler Derived
          - 011 Reserved
          - 100 Reserved
          - 101 Reserved
          - 110 Reserved
          - 111 Reserved
        - Bits 6-3:
          - Reserved
        - Bit 7:
          - 0 No RAIM Repair
          - 1 RAIM repair

    - GPS_TIME flags:
      - Bits: 76543210
      - Bits 2-0:
        - 000 Invalid
        - 001 PVT derived
        - 010 Reserved (will be filled in when RTC comes online and maybe with coarse time)
        - 011 Reserved
        - 100 Reserved
        - 101 Reserved
        - 110 Reserved
        - 111 Reserved
      - Bits 6-3:
        - Reserved
      - Bits 7:
        - 0 No RAIM repair
        - 1 RAIM repair

Heading:
Deprecate for the time being

Dops:
DOPS calculation needs to update when we have RTK solution or RAIM flag to represent the satellites actually used.  When in RTK mode of any kind, DOPS will represent the DOPS from the RTK solution.  If no RTK solution is available (pseudo absolute or baseline), DOPS will be only SPP DOPS.  Flags will follow the position message definition.

Other option:
PVT message

### 2. Observation message updates

Updates to observation message to reduce bandwidth and allow observations to
always be sent regardless of whether they're usable (receiving device filters
them for usability rather than sending device).  Also allows measured doppler to come over the wire.
Message has one more byte per observation than current observation message
We will change max size of observation message to 255 bytes

- Remove week number from header (2 bytes)
- Replace 4 byte obs.sid with 2 bytes, matching the firmware SID representation
  - Satellite ID (1 byte)
    - will be the actual satellite ID value, not value minus 1
  - Signal (Band/Constellation/Etc) Code (1 byte)
- Replace 2 byte lock counter with 1 byte lock timer, conforming to DF402 from RTCM 10403.2
- Add 1 byte of flags for each satellite - need to talk to Estimation and Exafore about what these should be
  - Bit 0: Time fix valid (or code phase valid)
  - Bit 1: Carrier phase valid
  - Bit 2: Half cycle ambiguity resolved
  - Bits 3-7: Reserved
- Have observations be sent out at all times, use flags above to indicate validity
- Add measured doppler field as a Q16.8 layout
  - 16 bit signed part (-32768 to 32767), 1/256 hertz residual
- Deprecate current Tracking State Message as it is no longer needed when we send out observations for all tracked signals with the flags


### 3. sender_id = device_uuid & 0xFFFF

We need to decide where sender_id will come from on Piksi Multi. In deciding
this, we need to keep in mind the following goals:
- sender_id *does not* need to be globally unique amongst all Piksi Multi's
- sender_id *does* need to be unique amongst the Piksi Multi's on a customer's
local network of devices (for instance, point to multi-point ISM radio network,
TCP/IP network, etc)

- Decision is to use the lower 16 bits of the device UUID for serial numbers
- We store the serial number to UUID map in our bringup database
- We work with OPS to put the lower 16 bits of UUID on the physical hardware

### 4. Remove request / response messages where possible

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
- `MSG_M25_FLASH_WRITE_STATUS`a
- `STM_UNIQUE_ID`

The following messages could be part of a device ID message that is
periodically sent:

- `MSG_NAP_DEVICE_DNA_REQ`
- `MSG_NAP_DEVICE_DNA_RESP`
- `MSG_STM_UNIQUE_ID_REQ`
- `MSG_STM_UNIQUE_ID_RESP`

Some items will be exposed through read only settings interface:

- `Device DNA`
- `Buildroot version` 
-  etc


### 5. Replace obs forwarding with general purpose forwarding message

Current there is a convention in the protocol that if the sender_id of a
MSG_OBS is 0, it means it is a forwarded observation from another device. We
propose to replace this with a general purpose forwarding message that wraps
the forwarded message, discarding the preamble and checksum of the forwarded
message. This way, the sender_id of the forwarded message will be preserved and
will remove the need for special handling of sender_id = 0 on obs messages.

The forwarded message will have three fields

- u8 source ID :  Enum for different sources (uart0, uart1, ethernet, cell modem)
- u8 protocol ID : enum for different protocols (SBP, RTCMv3)
- u8[variable length] forwarded msg stream:

### 6. Add UTC time message

Users want UTC time rather than GPS time.  message format is below.  When Leap seconds is hardcoded from library (and not from sky) flags is 1.  When we get leap seconds from sky, we go to flags 2
  - u8     flags
  - u32     TOW [ms]
  - u16    year
  - u8     month
  - u8     day
  - u8    hours
  - u8     minutes
  - u8    seconds
  - s32     ns    (nanoseconds)
    flags define field "time source" in flags: Invalid (0), GNSS (1), GNSS w/valid UTC offset (2), 3-7 Reserved

### 7. Add DGPS status message
- message comes out with each receipt of a complete corrections packet
- u8 flags  (0-3: Source 0: No DGPS 1: SBAS 2: Code Difference 3: RTK 4: PPP, 4-8 reserved)   
- u8 latency (log scale)
- u8 number of GPS satellites from base station
- u8[variable length] Corrections source ID (string)

### 8. Add age of corrections messages that comes out with each solution epoch
Faclitates conversion to NMEA
  - u32 TOW
  - u16 age of corrections (Deci-seconds), 0xFFFF when invalid

### 9. Add fields to MSG_STARTUP
- Cause of start - Power on, software reset, watchdog, hardware reset
- Start type: cold, warm, hot
