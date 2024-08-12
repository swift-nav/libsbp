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
# Satellite observation messages from the device. The SBP sender ID of 0 indicates
# remote observations from a GNSS base station, correction network, or Skylark,
# Swift's cloud GNSS correction product.
#
# Automatically generated from spec/yaml/swiftnav/sbp/observation.yaml with generate.py.
# Do not modify by hand!

meta:
  id: observation
  endian: le
  imports: [ gnss ]

types:

  observation_header:
    doc: |
      Header of a GNSS observation message.
    seq:
      - id: t
        doc: |
          GNSS time of this observation
        type: gnss::gps_time
      - id: n_obs
        doc: |
          Total number of observations. First nibble is the size of the
          sequence (n), second nibble is the zero-indexed counter (ith packet
          of n)
        type: u1
  
  doppler:
    doc: |
      Doppler measurement in Hz represented as a 24-bit fixed point number
      with Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of
      fractional doppler. This doppler is defined as positive for approaching
      satellites.
    seq:
      - id: i
        doc: |
          Doppler whole Hz
        type: s2
      - id: f
        doc: |
          Doppler fractional part
        type: u1
  
  packed_obs_content:
    doc: |
      Pseudorange and carrier phase observation for a satellite being tracked.
      The observations are interoperable with 3rd party receivers and conform
      with typical RTCM 3.1 message GPS/GLO observations.

      Carrier phase observations are not guaranteed to be aligned to the RINEX
      3 or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are
      currently performed.
    seq:
      - id: p
        doc: |
          Pseudorange observation
        type: u4
      - id: l
        doc: |
          Carrier phase observation with typical sign convention.
        type: gnss::carrier_phase
      - id: d
        doc: |
          Doppler observation with typical sign convention.
        type: doppler
      - id: cn0
        doc: |
          Carrier-to-Noise density.  Zero implies invalid cn0.
        type: u1
      - id: lock
        doc: |
          Lock timer. This value gives an indication of the time for which a
          signal has maintained continuous phase lock. Whenever a signal has
          lost and regained lock, this value is reset to zero. It is encoded
          according to DF402 from the RTCM 10403.2 Amendment 2 specification.
          Valid values range from 0 to 15 and the most significant nibble is
          reserved for future use.
        type: u1
      - id: flags
        doc: |
          Measurement status flags. A bit field of flags providing the status
          of this observation.  If this field is 0 it means only the Cn0
          estimate for the signal is valid.
        type: u1
      - id: sid
        doc: |
          GNSS signal identifier (16 bit)
        type: gnss::gnss_signal
  
  packed_osr_content:
    doc: |
      Pseudorange and carrier phase network corrections for a satellite
      signal.
    seq:
      - id: p
        doc: |
          Pseudorange observation
        type: u4
      - id: l
        doc: |
          Carrier phase observation with typical sign convention.
        type: gnss::carrier_phase
      - id: lock
        doc: |
          Lock timer. This value gives an indication of the time for which a
          signal has maintained continuous phase lock. Whenever a signal has
          lost and regained lock, this value is reset to zero. It is encoded
          according to DF402 from the RTCM 10403.2 Amendment 2 specification.
          Valid values range from 0 to 15 and the most significant nibble is
          reserved for future use.
        type: u1
      - id: flags
        doc: |
          Correction flags.
        type: u1
      - id: sid
        doc: |
          GNSS signal identifier (16 bit)
        type: gnss::gnss_signal
      - id: iono_std
        doc: |
          Slant ionospheric correction standard deviation
        type: u2
      - id: tropo_std
        doc: |
          Slant tropospheric correction standard deviation
        type: u2
      - id: range_std
        doc: |
          Orbit/clock/bias correction projected on range standard deviation
        type: u2
  
  msg_obs:
    doc: |
      The GPS observations message reports all the raw pseudorange and carrier
      phase observations for the satellites being tracked by the device.
      Carrier phase observation here is represented as a 40-bit fixed point
      number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
      fractional cycles). The observations are be interoperable with 3rd party
      receivers and conform with typical RTCMv3 GNSS observations.
    seq:
      - id: header
        doc: |
          Header of a GPS observation message
        type: observation_header
      - id: obs
        doc: |
          Pseudorange and carrier phase observation for a satellite being
          tracked.
        type: packed_obs_content
        repeat: eos
  
  msg_base_pos_llh:
    doc: |
      The base station position message is the position reported by the base
      station itself. It is used for pseudo-absolute RTK positioning, and is
      required to be a high-accuracy surveyed location of the base station.
      Any error here will result in an error in the pseudo-absolute position
      output.
    seq:
      - id: lat
        doc: |
          Latitude
        type: f8
      - id: lon
        doc: |
          Longitude
        type: f8
      - id: height
        doc: |
          Height
        type: f8
  
  msg_base_pos_ecef:
    doc: |
      The base station position message is the position reported by the base
      station itself in absolute Earth Centered Earth Fixed coordinates. It is
      used for pseudo-absolute RTK positioning, and is required to be a high-
      accuracy surveyed location of the base station. Any error here will
      result in an error in the pseudo-absolute position output.
    seq:
      - id: x
        doc: |
          ECEF X coordinate
        type: f8
      - id: y
        doc: |
          ECEF Y coordinate
        type: f8
      - id: z
        doc: |
          ECEF Z coordinate
        type: f8
  
  ephemeris_common_content:
    seq:
      - id: sid
        doc: |
          GNSS signal identifier (16 bit)
        type: gnss::gnss_signal
      - id: toe
        doc: |
          Time of Ephemerides
        type: gnss::gps_time_sec
      - id: ura
        doc: |
          User Range Accuracy
        type: f4
      - id: fit_interval
        doc: |
          Curve fit interval
        type: u4
      - id: valid
        doc: |
          Status of ephemeris, 1 = valid, 0 = invalid
        type: u1
      - id: health_bits
        doc: |
          Satellite health status.
          GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
          SBAS: 0 = valid, non-zero = invalid
          GLO: 0 = valid, non-zero = invalid
        type: u1
  
  ephemeris_common_content_dep_b:
    seq:
      - id: sid
        doc: |
          GNSS signal identifier (16 bit)
        type: gnss::gnss_signal
      - id: toe
        doc: |
          Time of Ephemerides
        type: gnss::gps_time_sec
      - id: ura
        doc: |
          User Range Accuracy
        type: f8
      - id: fit_interval
        doc: |
          Curve fit interval
        type: u4
      - id: valid
        doc: |
          Status of ephemeris, 1 = valid, 0 = invalid
        type: u1
      - id: health_bits
        doc: |
          Satellite health status.
          GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
          Others: 0 = valid, non-zero = invalid
        type: u1
  
  ephemeris_common_content_dep_a:
    seq:
      - id: sid
        doc: |
          GNSS signal identifier
        type: gnss::gnss_signal_dep
      - id: toe
        doc: |
          Time of Ephemerides
        type: gnss::gps_time_dep
      - id: ura
        doc: |
          User Range Accuracy
        type: f8
      - id: fit_interval
        doc: |
          Curve fit interval
        type: u4
      - id: valid
        doc: |
          Status of ephemeris, 1 = valid, 0 = invalid
        type: u1
      - id: health_bits
        doc: |
          Satellite health status.
          GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
          SBAS: 0 = valid, non-zero = invalid
          GLO: 0 = valid, non-zero = invalid
        type: u1
  
  msg_ephemeris_gps_dep_e:
    doc: |
      Deprecated.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content_dep_a
      - id: tgd
        doc: |
          Group delay differential between L1 and L2
        type: f8
      - id: c_rs
        doc: |
          Amplitude of the sine harmonic correction term to the orbit radius
        type: f8
      - id: c_rc
        doc: |
          Amplitude of the cosine harmonic correction term to the orbit radius
        type: f8
      - id: c_uc
        doc: |
          Amplitude of the cosine harmonic correction term to the argument of
          latitude
        type: f8
      - id: c_us
        doc: |
          Amplitude of the sine harmonic correction term to the argument of
          latitude
        type: f8
      - id: c_ic
        doc: |
          Amplitude of the cosine harmonic correction term to the angle of
          inclination
        type: f8
      - id: c_is
        doc: |
          Amplitude of the sine harmonic correction term to the angle of
          inclination
        type: f8
      - id: dn
        doc: |
          Mean motion difference
        type: f8
      - id: m0
        doc: |
          Mean anomaly at reference time
        type: f8
      - id: ecc
        doc: |
          Eccentricity of satellite orbit
        type: f8
      - id: sqrta
        doc: |
          Square root of the semi-major axis of orbit
        type: f8
      - id: omega0
        doc: |
          Longitude of ascending node of orbit plane at weekly epoch
        type: f8
      - id: omegadot
        doc: |
          Rate of right ascension
        type: f8
      - id: w
        doc: |
          Argument of perigee
        type: f8
      - id: inc
        doc: |
          Inclination
        type: f8
      - id: inc_dot
        doc: |
          Inclination first derivative
        type: f8
      - id: af0
        doc: |
          Polynomial clock correction coefficient (clock bias)
        type: f8
      - id: af1
        doc: |
          Polynomial clock correction coefficient (clock drift)
        type: f8
      - id: af2
        doc: |
          Polynomial clock correction coefficient (rate of clock drift)
        type: f8
      - id: toc
        doc: |
          Clock reference
        type: gnss::gps_time_dep
      - id: iode
        doc: |
          Issue of ephemeris data
        type: u1
      - id: iodc
        doc: |
          Issue of clock data
        type: u2
  
  msg_ephemeris_gps_dep_f:
    doc: |
      Deprecated.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content_dep_b
      - id: tgd
        doc: |
          Group delay differential between L1 and L2
        type: f8
      - id: c_rs
        doc: |
          Amplitude of the sine harmonic correction term to the orbit radius
        type: f8
      - id: c_rc
        doc: |
          Amplitude of the cosine harmonic correction term to the orbit radius
        type: f8
      - id: c_uc
        doc: |
          Amplitude of the cosine harmonic correction term to the argument of
          latitude
        type: f8
      - id: c_us
        doc: |
          Amplitude of the sine harmonic correction term to the argument of
          latitude
        type: f8
      - id: c_ic
        doc: |
          Amplitude of the cosine harmonic correction term to the angle of
          inclination
        type: f8
      - id: c_is
        doc: |
          Amplitude of the sine harmonic correction term to the angle of
          inclination
        type: f8
      - id: dn
        doc: |
          Mean motion difference
        type: f8
      - id: m0
        doc: |
          Mean anomaly at reference time
        type: f8
      - id: ecc
        doc: |
          Eccentricity of satellite orbit
        type: f8
      - id: sqrta
        doc: |
          Square root of the semi-major axis of orbit
        type: f8
      - id: omega0
        doc: |
          Longitude of ascending node of orbit plane at weekly epoch
        type: f8
      - id: omegadot
        doc: |
          Rate of right ascension
        type: f8
      - id: w
        doc: |
          Argument of perigee
        type: f8
      - id: inc
        doc: |
          Inclination
        type: f8
      - id: inc_dot
        doc: |
          Inclination first derivative
        type: f8
      - id: af0
        doc: |
          Polynomial clock correction coefficient (clock bias)
        type: f8
      - id: af1
        doc: |
          Polynomial clock correction coefficient (clock drift)
        type: f8
      - id: af2
        doc: |
          Polynomial clock correction coefficient (rate of clock drift)
        type: f8
      - id: toc
        doc: |
          Clock reference
        type: gnss::gps_time_sec
      - id: iode
        doc: |
          Issue of ephemeris data
        type: u1
      - id: iodc
        doc: |
          Issue of clock data
        type: u2
  
  msg_ephemeris_gps:
    doc: |
      The ephemeris message returns a set of satellite orbit parameters that
      is used to calculate GPS satellite position, velocity, and clock offset.
      Please see the Navstar GPS Space Segment/Navigation user interfaces
      (ICD-GPS-200, Table 20-III) for more details.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content
      - id: tgd
        doc: |
          Group delay differential between L1 and L2
        type: f4
      - id: c_rs
        doc: |
          Amplitude of the sine harmonic correction term to the orbit radius
        type: f4
      - id: c_rc
        doc: |
          Amplitude of the cosine harmonic correction term to the orbit radius
        type: f4
      - id: c_uc
        doc: |
          Amplitude of the cosine harmonic correction term to the argument of
          latitude
        type: f4
      - id: c_us
        doc: |
          Amplitude of the sine harmonic correction term to the argument of
          latitude
        type: f4
      - id: c_ic
        doc: |
          Amplitude of the cosine harmonic correction term to the angle of
          inclination
        type: f4
      - id: c_is
        doc: |
          Amplitude of the sine harmonic correction term to the angle of
          inclination
        type: f4
      - id: dn
        doc: |
          Mean motion difference
        type: f8
      - id: m0
        doc: |
          Mean anomaly at reference time
        type: f8
      - id: ecc
        doc: |
          Eccentricity of satellite orbit
        type: f8
      - id: sqrta
        doc: |
          Square root of the semi-major axis of orbit
        type: f8
      - id: omega0
        doc: |
          Longitude of ascending node of orbit plane at weekly epoch
        type: f8
      - id: omegadot
        doc: |
          Rate of right ascension
        type: f8
      - id: w
        doc: |
          Argument of perigee
        type: f8
      - id: inc
        doc: |
          Inclination
        type: f8
      - id: inc_dot
        doc: |
          Inclination first derivative
        type: f8
      - id: af0
        doc: |
          Polynomial clock correction coefficient (clock bias)
        type: f4
      - id: af1
        doc: |
          Polynomial clock correction coefficient (clock drift)
        type: f4
      - id: af2
        doc: |
          Polynomial clock correction coefficient (rate of clock drift)
        type: f4
      - id: toc
        doc: |
          Clock reference
        type: gnss::gps_time_sec
      - id: iode
        doc: |
          Issue of ephemeris data
        type: u1
      - id: iodc
        doc: |
          Issue of clock data
        type: u2
  
  msg_ephemeris_qzss:
    doc: |
      The ephemeris message returns a set of satellite orbit parameters that
      is used to calculate QZSS satellite position, velocity, and clock
      offset.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content
      - id: tgd
        doc: |
          Group delay differential between L1 and L2
        type: f4
      - id: c_rs
        doc: |
          Amplitude of the sine harmonic correction term to the orbit radius
        type: f4
      - id: c_rc
        doc: |
          Amplitude of the cosine harmonic correction term to the orbit radius
        type: f4
      - id: c_uc
        doc: |
          Amplitude of the cosine harmonic correction term to the argument of
          latitude
        type: f4
      - id: c_us
        doc: |
          Amplitude of the sine harmonic correction term to the argument of
          latitude
        type: f4
      - id: c_ic
        doc: |
          Amplitude of the cosine harmonic correction term to the angle of
          inclination
        type: f4
      - id: c_is
        doc: |
          Amplitude of the sine harmonic correction term to the angle of
          inclination
        type: f4
      - id: dn
        doc: |
          Mean motion difference
        type: f8
      - id: m0
        doc: |
          Mean anomaly at reference time
        type: f8
      - id: ecc
        doc: |
          Eccentricity of satellite orbit
        type: f8
      - id: sqrta
        doc: |
          Square root of the semi-major axis of orbit
        type: f8
      - id: omega0
        doc: |
          Longitude of ascending node of orbit plane at weekly epoch
        type: f8
      - id: omegadot
        doc: |
          Rate of right ascension
        type: f8
      - id: w
        doc: |
          Argument of perigee
        type: f8
      - id: inc
        doc: |
          Inclination
        type: f8
      - id: inc_dot
        doc: |
          Inclination first derivative
        type: f8
      - id: af0
        doc: |
          Polynomial clock correction coefficient (clock bias)
        type: f4
      - id: af1
        doc: |
          Polynomial clock correction coefficient (clock drift)
        type: f4
      - id: af2
        doc: |
          Polynomial clock correction coefficient (rate of clock drift)
        type: f4
      - id: toc
        doc: |
          Clock reference
        type: gnss::gps_time_sec
      - id: iode
        doc: |
          Issue of ephemeris data
        type: u1
      - id: iodc
        doc: |
          Issue of clock data
        type: u2
  
  msg_ephemeris_bds:
    doc: |
      The ephemeris message returns a set of satellite orbit parameters that
      is used to calculate BDS satellite position, velocity, and clock offset.
      Please see the BeiDou Navigation Satellite System SIS-ICD Version 2.1,
      Table 5-9 for more details.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content
      - id: tgd1
        doc: |
          Group delay differential for B1
        type: f4
      - id: tgd2
        doc: |
          Group delay differential for B2
        type: f4
      - id: c_rs
        doc: |
          Amplitude of the sine harmonic correction term to the orbit radius
        type: f4
      - id: c_rc
        doc: |
          Amplitude of the cosine harmonic correction term to the orbit radius
        type: f4
      - id: c_uc
        doc: |
          Amplitude of the cosine harmonic correction term to the argument of
          latitude
        type: f4
      - id: c_us
        doc: |
          Amplitude of the sine harmonic correction term to the argument of
          latitude
        type: f4
      - id: c_ic
        doc: |
          Amplitude of the cosine harmonic correction term to the angle of
          inclination
        type: f4
      - id: c_is
        doc: |
          Amplitude of the sine harmonic correction term to the angle of
          inclination
        type: f4
      - id: dn
        doc: |
          Mean motion difference
        type: f8
      - id: m0
        doc: |
          Mean anomaly at reference time
        type: f8
      - id: ecc
        doc: |
          Eccentricity of satellite orbit
        type: f8
      - id: sqrta
        doc: |
          Square root of the semi-major axis of orbit
        type: f8
      - id: omega0
        doc: |
          Longitude of ascending node of orbit plane at weekly epoch
        type: f8
      - id: omegadot
        doc: |
          Rate of right ascension
        type: f8
      - id: w
        doc: |
          Argument of perigee
        type: f8
      - id: inc
        doc: |
          Inclination
        type: f8
      - id: inc_dot
        doc: |
          Inclination first derivative
        type: f8
      - id: af0
        doc: |
          Polynomial clock correction coefficient (clock bias)
        type: f8
      - id: af1
        doc: |
          Polynomial clock correction coefficient (clock drift)
        type: f4
      - id: af2
        doc: |
          Polynomial clock correction coefficient (rate of clock drift)
        type: f4
      - id: toc
        doc: |
          Clock reference
        type: gnss::gps_time_sec
      - id: iode
        doc: |
          Issue of ephemeris data
          Calculated from the navigation data parameter t_oe per RTCM/CSNO
          recommendation: IODE = mod (t_oe / 720, 240)
        type: u1
      - id: iodc
        doc: |
          Issue of clock data
          Calculated from the navigation data parameter t_oe per RTCM/CSNO
          recommendation: IODE = mod (t_oc / 720, 240)
        type: u2
  
  msg_ephemeris_gal_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content
      - id: bgd_e1e5a
        doc: |
          E1-E5a Broadcast Group Delay
        type: f4
      - id: bgd_e1e5b
        doc: |
          E1-E5b Broadcast Group Delay
        type: f4
      - id: c_rs
        doc: |
          Amplitude of the sine harmonic correction term to the orbit radius
        type: f4
      - id: c_rc
        doc: |
          Amplitude of the cosine harmonic correction term to the orbit radius
        type: f4
      - id: c_uc
        doc: |
          Amplitude of the cosine harmonic correction term to the argument of
          latitude
        type: f4
      - id: c_us
        doc: |
          Amplitude of the sine harmonic correction term to the argument of
          latitude
        type: f4
      - id: c_ic
        doc: |
          Amplitude of the cosine harmonic correction term to the angle of
          inclination
        type: f4
      - id: c_is
        doc: |
          Amplitude of the sine harmonic correction term to the angle of
          inclination
        type: f4
      - id: dn
        doc: |
          Mean motion difference
        type: f8
      - id: m0
        doc: |
          Mean anomaly at reference time
        type: f8
      - id: ecc
        doc: |
          Eccentricity of satellite orbit
        type: f8
      - id: sqrta
        doc: |
          Square root of the semi-major axis of orbit
        type: f8
      - id: omega0
        doc: |
          Longitude of ascending node of orbit plane at weekly epoch
        type: f8
      - id: omegadot
        doc: |
          Rate of right ascension
        type: f8
      - id: w
        doc: |
          Argument of perigee
        type: f8
      - id: inc
        doc: |
          Inclination
        type: f8
      - id: inc_dot
        doc: |
          Inclination first derivative
        type: f8
      - id: af0
        doc: |
          Polynomial clock correction coefficient (clock bias)
        type: f8
      - id: af1
        doc: |
          Polynomial clock correction coefficient (clock drift)
        type: f8
      - id: af2
        doc: |
          Polynomial clock correction coefficient (rate of clock drift)
        type: f4
      - id: toc
        doc: |
          Clock reference
        type: gnss::gps_time_sec
      - id: iode
        doc: |
          Issue of data (IODnav)
        type: u2
      - id: iodc
        doc: |
          Issue of data (IODnav). Always equal to iode
        type: u2
  
  msg_ephemeris_gal:
    doc: |
      The ephemeris message returns a set of satellite orbit parameters that
      is used to calculate Galileo satellite position, velocity, and clock
      offset. Please see the Signal In Space ICD OS SIS ICD, Issue 1.3,
      December 2016 for more details.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content
      - id: bgd_e1e5a
        doc: |
          E1-E5a Broadcast Group Delay
        type: f4
      - id: bgd_e1e5b
        doc: |
          E1-E5b Broadcast Group Delay
        type: f4
      - id: c_rs
        doc: |
          Amplitude of the sine harmonic correction term to the orbit radius
        type: f4
      - id: c_rc
        doc: |
          Amplitude of the cosine harmonic correction term to the orbit radius
        type: f4
      - id: c_uc
        doc: |
          Amplitude of the cosine harmonic correction term to the argument of
          latitude
        type: f4
      - id: c_us
        doc: |
          Amplitude of the sine harmonic correction term to the argument of
          latitude
        type: f4
      - id: c_ic
        doc: |
          Amplitude of the cosine harmonic correction term to the angle of
          inclination
        type: f4
      - id: c_is
        doc: |
          Amplitude of the sine harmonic correction term to the angle of
          inclination
        type: f4
      - id: dn
        doc: |
          Mean motion difference
        type: f8
      - id: m0
        doc: |
          Mean anomaly at reference time
        type: f8
      - id: ecc
        doc: |
          Eccentricity of satellite orbit
        type: f8
      - id: sqrta
        doc: |
          Square root of the semi-major axis of orbit
        type: f8
      - id: omega0
        doc: |
          Longitude of ascending node of orbit plane at weekly epoch
        type: f8
      - id: omegadot
        doc: |
          Rate of right ascension
        type: f8
      - id: w
        doc: |
          Argument of perigee
        type: f8
      - id: inc
        doc: |
          Inclination
        type: f8
      - id: inc_dot
        doc: |
          Inclination first derivative
        type: f8
      - id: af0
        doc: |
          Polynomial clock correction coefficient (clock bias)
        type: f8
      - id: af1
        doc: |
          Polynomial clock correction coefficient (clock drift)
        type: f8
      - id: af2
        doc: |
          Polynomial clock correction coefficient (rate of clock drift)
        type: f4
      - id: toc
        doc: |
          Clock reference
        type: gnss::gps_time_sec
      - id: iode
        doc: |
          Issue of data (IODnav)
        type: u2
      - id: iodc
        doc: |
          Issue of data (IODnav). Always equal to iode
        type: u2
      - id: source
        doc: |
          0=I/NAV, 1=F/NAV
        type: u1
  
  msg_ephemeris_sbas_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content_dep_a
      - id: pos
        doc: |
          Position of the GEO at time toe
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: vel
        doc: |
          Velocity of the GEO at time toe
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: acc
        doc: |
          Acceleration of the GEO at time toe
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: a_gf0
        doc: |
          Time offset of the GEO clock w.r.t. SBAS Network Time
        type: f8
      - id: a_gf1
        doc: |
          Drift of the GEO clock w.r.t. SBAS Network Time
        type: f8
  
  msg_ephemeris_glo_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content_dep_a
      - id: gamma
        doc: |
          Relative deviation of predicted carrier frequency from nominal
        type: f8
      - id: tau
        doc: |
          Correction to the SV time
        type: f8
      - id: pos
        doc: |
          Position of the SV at tb in PZ-90.02 coordinates system
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: vel
        doc: |
          Velocity vector of the SV at tb in PZ-90.02 coordinates system
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: acc
        doc: |
          Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
        type: f8
        repeat: expr
        repeat-expr: 3
  
  msg_ephemeris_sbas_dep_b:
    doc: |
      Deprecated.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content_dep_b
      - id: pos
        doc: |
          Position of the GEO at time toe
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: vel
        doc: |
          Velocity of the GEO at time toe
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: acc
        doc: |
          Acceleration of the GEO at time toe
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: a_gf0
        doc: |
          Time offset of the GEO clock w.r.t. SBAS Network Time
        type: f8
      - id: a_gf1
        doc: |
          Drift of the GEO clock w.r.t. SBAS Network Time
        type: f8
  
  msg_ephemeris_sbas:
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content
      - id: pos
        doc: |
          Position of the GEO at time toe
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: vel
        doc: |
          Velocity of the GEO at time toe
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: acc
        doc: |
          Acceleration of the GEO at time toe
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: a_gf0
        doc: |
          Time offset of the GEO clock w.r.t. SBAS Network Time
        type: f4
      - id: a_gf1
        doc: |
          Drift of the GEO clock w.r.t. SBAS Network Time
        type: f4
  
  msg_ephemeris_glo_dep_b:
    doc: |
      Deprecated.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content_dep_b
      - id: gamma
        doc: |
          Relative deviation of predicted carrier frequency from nominal
        type: f8
      - id: tau
        doc: |
          Correction to the SV time
        type: f8
      - id: pos
        doc: |
          Position of the SV at tb in PZ-90.02 coordinates system
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: vel
        doc: |
          Velocity vector of the SV at tb in PZ-90.02 coordinates system
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: acc
        doc: |
          Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
        type: f8
        repeat: expr
        repeat-expr: 3
  
  msg_ephemeris_glo_dep_c:
    doc: |
      The ephemeris message returns a set of satellite orbit parameters that
      is used to calculate GLO satellite position, velocity, and clock offset.
      Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
      immediate information (ephemeris parameters)" for more details.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content_dep_b
      - id: gamma
        doc: |
          Relative deviation of predicted carrier frequency from nominal
        type: f8
      - id: tau
        doc: |
          Correction to the SV time
        type: f8
      - id: d_tau
        doc: |
          Equipment delay between L1 and L2
        type: f8
      - id: pos
        doc: |
          Position of the SV at tb in PZ-90.02 coordinates system
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: vel
        doc: |
          Velocity vector of the SV at tb in PZ-90.02 coordinates system
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: acc
        doc: |
          Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: fcn
        doc: |
          Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
        type: u1
  
  msg_ephemeris_glo_dep_d:
    doc: |
      This observation message has been deprecated in favor of ephemeris
      message using floats for size reduction.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content_dep_b
      - id: gamma
        doc: |
          Relative deviation of predicted carrier frequency from nominal
        type: f8
      - id: tau
        doc: |
          Correction to the SV time
        type: f8
      - id: d_tau
        doc: |
          Equipment delay between L1 and L2
        type: f8
      - id: pos
        doc: |
          Position of the SV at tb in PZ-90.02 coordinates system
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: vel
        doc: |
          Velocity vector of the SV at tb in PZ-90.02 coordinates system
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: acc
        doc: |
          Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: fcn
        doc: |
          Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
        type: u1
      - id: iod
        doc: |
          Issue of data. Equal to the 7 bits of the immediate data word t_b
        type: u1
  
  msg_ephemeris_glo:
    doc: |
      The ephemeris message returns a set of satellite orbit parameters that
      is used to calculate GLO satellite position, velocity, and clock offset.
      Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
      immediate information (ephemeris parameters)" for more details.
    seq:
      - id: common
        doc: |
          Values common for all ephemeris types
        type: ephemeris_common_content
      - id: gamma
        doc: |
          Relative deviation of predicted carrier frequency from nominal
        type: f4
      - id: tau
        doc: |
          Correction to the SV time
        type: f4
      - id: d_tau
        doc: |
          Equipment delay between L1 and L2
        type: f4
      - id: pos
        doc: |
          Position of the SV at tb in PZ-90.02 coordinates system
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: vel
        doc: |
          Velocity vector of the SV at tb in PZ-90.02 coordinates system
        type: f8
        repeat: expr
        repeat-expr: 3
      - id: acc
        doc: |
          Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: fcn
        doc: |
          Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
        type: u1
      - id: iod
        doc: |
          Issue of data. Equal to the 7 bits of the immediate data word t_b
        type: u1
  
  msg_ephemeris_dep_d:
    doc: |
      Deprecated.
    seq:
      - id: tgd
        doc: |
          Group delay differential between L1 and L2
        type: f8
      - id: c_rs
        doc: |
          Amplitude of the sine harmonic correction term to the orbit radius
        type: f8
      - id: c_rc
        doc: |
          Amplitude of the cosine harmonic correction term to the orbit radius
        type: f8
      - id: c_uc
        doc: |
          Amplitude of the cosine harmonic correction term to the argument of
          latitude
        type: f8
      - id: c_us
        doc: |
          Amplitude of the sine harmonic correction term to the argument of
          latitude
        type: f8
      - id: c_ic
        doc: |
          Amplitude of the cosine harmonic correction term to the angle of
          inclination
        type: f8
      - id: c_is
        doc: |
          Amplitude of the sine harmonic correction term to the angle of
          inclination
        type: f8
      - id: dn
        doc: |
          Mean motion difference
        type: f8
      - id: m0
        doc: |
          Mean anomaly at reference time
        type: f8
      - id: ecc
        doc: |
          Eccentricity of satellite orbit
        type: f8
      - id: sqrta
        doc: |
          Square root of the semi-major axis of orbit
        type: f8
      - id: omega0
        doc: |
          Longitude of ascending node of orbit plane at weekly epoch
        type: f8
      - id: omegadot
        doc: |
          Rate of right ascension
        type: f8
      - id: w
        doc: |
          Argument of perigee
        type: f8
      - id: inc
        doc: |
          Inclination
        type: f8
      - id: inc_dot
        doc: |
          Inclination first derivative
        type: f8
      - id: af0
        doc: |
          Polynomial clock correction coefficient (clock bias)
        type: f8
      - id: af1
        doc: |
          Polynomial clock correction coefficient (clock drift)
        type: f8
      - id: af2
        doc: |
          Polynomial clock correction coefficient (rate of clock drift)
        type: f8
      - id: toe_tow
        doc: |
          Time of week
        type: f8
      - id: toe_wn
        doc: |
          Week number
        type: u2
      - id: toc_tow
        doc: |
          Clock reference time of week
        type: f8
      - id: toc_wn
        doc: |
          Clock reference week number
        type: u2
      - id: valid
        doc: |
          Is valid?
        type: u1
      - id: healthy
        doc: |
          Satellite is healthy?
        type: u1
      - id: sid
        doc: |
          GNSS signal identifier
        type: gnss::gnss_signal_dep
      - id: iode
        doc: |
          Issue of ephemeris data
        type: u1
      - id: iodc
        doc: |
          Issue of clock data
        type: u2
      - id: reserved
        doc: |
          Reserved field
        type: u4
  
  msg_ephemeris_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: tgd
        doc: |
          Group delay differential between L1 and L2
        type: f8
      - id: c_rs
        doc: |
          Amplitude of the sine harmonic correction term to the orbit radius
        type: f8
      - id: c_rc
        doc: |
          Amplitude of the cosine harmonic correction term to the orbit radius
        type: f8
      - id: c_uc
        doc: |
          Amplitude of the cosine harmonic correction term to the argument of
          latitude
        type: f8
      - id: c_us
        doc: |
          Amplitude of the sine harmonic correction term to the argument of
          latitude
        type: f8
      - id: c_ic
        doc: |
          Amplitude of the cosine harmonic correction term to the angle of
          inclination
        type: f8
      - id: c_is
        doc: |
          Amplitude of the sine harmonic correction term to the angle of
          inclination
        type: f8
      - id: dn
        doc: |
          Mean motion difference
        type: f8
      - id: m0
        doc: |
          Mean anomaly at reference time
        type: f8
      - id: ecc
        doc: |
          Eccentricity of satellite orbit
        type: f8
      - id: sqrta
        doc: |
          Square root of the semi-major axis of orbit
        type: f8
      - id: omega0
        doc: |
          Longitude of ascending node of orbit plane at weekly epoch
        type: f8
      - id: omegadot
        doc: |
          Rate of right ascension
        type: f8
      - id: w
        doc: |
          Argument of perigee
        type: f8
      - id: inc
        doc: |
          Inclination
        type: f8
      - id: inc_dot
        doc: |
          Inclination first derivative
        type: f8
      - id: af0
        doc: |
          Polynomial clock correction coefficient (clock bias)
        type: f8
      - id: af1
        doc: |
          Polynomial clock correction coefficient (clock drift)
        type: f8
      - id: af2
        doc: |
          Polynomial clock correction coefficient (rate of clock drift)
        type: f8
      - id: toe_tow
        doc: |
          Time of week
        type: f8
      - id: toe_wn
        doc: |
          Week number
        type: u2
      - id: toc_tow
        doc: |
          Clock reference time of week
        type: f8
      - id: toc_wn
        doc: |
          Clock reference week number
        type: u2
      - id: valid
        doc: |
          Is valid?
        type: u1
      - id: healthy
        doc: |
          Satellite is healthy?
        type: u1
      - id: prn
        doc: |
          PRN being tracked
        type: u1
  
  msg_ephemeris_dep_b:
    doc: |
      Deprecated.
    seq:
      - id: tgd
        doc: |
          Group delay differential between L1 and L2
        type: f8
      - id: c_rs
        doc: |
          Amplitude of the sine harmonic correction term to the orbit radius
        type: f8
      - id: c_rc
        doc: |
          Amplitude of the cosine harmonic correction term to the orbit radius
        type: f8
      - id: c_uc
        doc: |
          Amplitude of the cosine harmonic correction term to the argument of
          latitude
        type: f8
      - id: c_us
        doc: |
          Amplitude of the sine harmonic correction term to the argument of
          latitude
        type: f8
      - id: c_ic
        doc: |
          Amplitude of the cosine harmonic correction term to the angle of
          inclination
        type: f8
      - id: c_is
        doc: |
          Amplitude of the sine harmonic correction term to the angle of
          inclination
        type: f8
      - id: dn
        doc: |
          Mean motion difference
        type: f8
      - id: m0
        doc: |
          Mean anomaly at reference time
        type: f8
      - id: ecc
        doc: |
          Eccentricity of satellite orbit
        type: f8
      - id: sqrta
        doc: |
          Square root of the semi-major axis of orbit
        type: f8
      - id: omega0
        doc: |
          Longitude of ascending node of orbit plane at weekly epoch
        type: f8
      - id: omegadot
        doc: |
          Rate of right ascension
        type: f8
      - id: w
        doc: |
          Argument of perigee
        type: f8
      - id: inc
        doc: |
          Inclination
        type: f8
      - id: inc_dot
        doc: |
          Inclination first derivative
        type: f8
      - id: af0
        doc: |
          Polynomial clock correction coefficient (clock bias)
        type: f8
      - id: af1
        doc: |
          Polynomial clock correction coefficient (clock drift)
        type: f8
      - id: af2
        doc: |
          Polynomial clock correction coefficient (rate of clock drift)
        type: f8
      - id: toe_tow
        doc: |
          Time of week
        type: f8
      - id: toe_wn
        doc: |
          Week number
        type: u2
      - id: toc_tow
        doc: |
          Clock reference time of week
        type: f8
      - id: toc_wn
        doc: |
          Clock reference week number
        type: u2
      - id: valid
        doc: |
          Is valid?
        type: u1
      - id: healthy
        doc: |
          Satellite is healthy?
        type: u1
      - id: prn
        doc: |
          PRN being tracked
        type: u1
      - id: iode
        doc: |
          Issue of ephemeris data
        type: u1
  
  msg_ephemeris_dep_c:
    doc: |
      Deprecated.
    seq:
      - id: tgd
        doc: |
          Group delay differential between L1 and L2
        type: f8
      - id: c_rs
        doc: |
          Amplitude of the sine harmonic correction term to the orbit radius
        type: f8
      - id: c_rc
        doc: |
          Amplitude of the cosine harmonic correction term to the orbit radius
        type: f8
      - id: c_uc
        doc: |
          Amplitude of the cosine harmonic correction term to the argument of
          latitude
        type: f8
      - id: c_us
        doc: |
          Amplitude of the sine harmonic correction term to the argument of
          latitude
        type: f8
      - id: c_ic
        doc: |
          Amplitude of the cosine harmonic correction term to the angle of
          inclination
        type: f8
      - id: c_is
        doc: |
          Amplitude of the sine harmonic correction term to the angle of
          inclination
        type: f8
      - id: dn
        doc: |
          Mean motion difference
        type: f8
      - id: m0
        doc: |
          Mean anomaly at reference time
        type: f8
      - id: ecc
        doc: |
          Eccentricity of satellite orbit
        type: f8
      - id: sqrta
        doc: |
          Square root of the semi-major axis of orbit
        type: f8
      - id: omega0
        doc: |
          Longitude of ascending node of orbit plane at weekly epoch
        type: f8
      - id: omegadot
        doc: |
          Rate of right ascension
        type: f8
      - id: w
        doc: |
          Argument of perigee
        type: f8
      - id: inc
        doc: |
          Inclination
        type: f8
      - id: inc_dot
        doc: |
          Inclination first derivative
        type: f8
      - id: af0
        doc: |
          Polynomial clock correction coefficient (clock bias)
        type: f8
      - id: af1
        doc: |
          Polynomial clock correction coefficient (clock drift)
        type: f8
      - id: af2
        doc: |
          Polynomial clock correction coefficient (rate of clock drift)
        type: f8
      - id: toe_tow
        doc: |
          Time of week
        type: f8
      - id: toe_wn
        doc: |
          Week number
        type: u2
      - id: toc_tow
        doc: |
          Clock reference time of week
        type: f8
      - id: toc_wn
        doc: |
          Clock reference week number
        type: u2
      - id: valid
        doc: |
          Is valid?
        type: u1
      - id: healthy
        doc: |
          Satellite is healthy?
        type: u1
      - id: sid
        doc: |
          GNSS signal identifier
        type: gnss::gnss_signal_dep
      - id: iode
        doc: |
          Issue of ephemeris data
        type: u1
      - id: iodc
        doc: |
          Issue of clock data
        type: u2
      - id: reserved
        doc: |
          Reserved field
        type: u4
  
  observation_header_dep:
    doc: |
      Header of a GPS observation message.
    seq:
      - id: t
        doc: |
          GPS time of this observation
        type: gnss::gps_time_dep
      - id: n_obs
        doc: |
          Total number of observations. First nibble is the size of the
          sequence (n), second nibble is the zero-indexed counter (ith packet
          of n)
        type: u1
  
  carrier_phase_dep_a:
    doc: |
      Carrier phase measurement in cycles represented as a 40-bit fixed point
      number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
      fractional cycles. This has the opposite sign convention than a typical
      GPS receiver and the phase has the opposite sign as the pseudorange.
    seq:
      - id: i
        doc: |
          Carrier phase whole cycles
        type: s4
      - id: f
        doc: |
          Carrier phase fractional part
        type: u1
  
  packed_obs_content_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: p
        doc: |
          Pseudorange observation
        type: u4
      - id: l
        doc: |
          Carrier phase observation with opposite sign from typical convention
        type: carrier_phase_dep_a
      - id: cn0
        doc: |
          Carrier-to-Noise density
        type: u1
      - id: lock
        doc: |
          Lock indicator. This value changes whenever a satellite signal has
          lost and regained lock, indicating that the carrier phase ambiguity
          may have changed.
        type: u2
      - id: prn
        doc: |
          PRN-1 identifier of the satellite signal
        type: u1
  
  packed_obs_content_dep_b:
    doc: |
      Pseudorange and carrier phase observation for a satellite being tracked.
      Pseudoranges are referenced to a nominal pseudorange.
    seq:
      - id: p
        doc: |
          Pseudorange observation
        type: u4
      - id: l
        doc: |
          Carrier phase observation with opposite sign from typical
          convention.
        type: carrier_phase_dep_a
      - id: cn0
        doc: |
          Carrier-to-Noise density
        type: u1
      - id: lock
        doc: |
          Lock indicator. This value changes whenever a satellite signal has
          lost and regained lock, indicating that the carrier phase ambiguity
          may have changed.
        type: u2
      - id: sid
        doc: |
          GNSS signal identifier
        type: gnss::gnss_signal_dep
  
  packed_obs_content_dep_c:
    doc: |
      Pseudorange and carrier phase observation for a satellite being tracked.
      The observations are be interoperable with 3rd party receivers and
      conform with typical RTCMv3 GNSS observations.
    seq:
      - id: p
        doc: |
          Pseudorange observation
        type: u4
      - id: l
        doc: |
          Carrier phase observation with typical sign convention.
        type: gnss::carrier_phase
      - id: cn0
        doc: |
          Carrier-to-Noise density
        type: u1
      - id: lock
        doc: |
          Lock indicator. This value changes whenever a satellite signal has
          lost and regained lock, indicating that the carrier phase ambiguity
          may have changed.
        type: u2
      - id: sid
        doc: |
          GNSS signal identifier
        type: gnss::gnss_signal_dep
  
  msg_obs_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: header
        doc: |
          Header of a GPS observation message
        type: observation_header_dep
      - id: obs
        doc: |
          Pseudorange and carrier phase observation for a satellite being
          tracked.
        type: packed_obs_content_dep_a
        repeat: eos
  
  msg_obs_dep_b:
    doc: |
      Deprecated.
    seq:
      - id: header
        doc: |
          Header of a GPS observation message
        type: observation_header_dep
      - id: obs
        doc: |
          Pseudorange and carrier phase observation for a satellite being
          tracked.
        type: packed_obs_content_dep_b
        repeat: eos
  
  msg_obs_dep_c:
    doc: |
      Deprecated.
    seq:
      - id: header
        doc: |
          Header of a GPS observation message
        type: observation_header_dep
      - id: obs
        doc: |
          Pseudorange and carrier phase observation for a satellite being
          tracked.
        type: packed_obs_content_dep_c
        repeat: eos
  
  msg_iono:
    doc: |
      The ionospheric parameters which allow the "L1 only" or "L2 only" user
      to utilize the ionospheric model for computation of the ionospheric
      delay. Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
    seq:
      - id: t_nmct
        doc: |
          Navigation Message Correction Table Validity Time
        type: gnss::gps_time_sec
      - id: a0
        type: f8
      - id: a1
        type: f8
      - id: a2
        type: f8
      - id: a3
        type: f8
      - id: b0
        type: f8
      - id: b1
        type: f8
      - id: b2
        type: f8
      - id: b3
        type: f8
  
  msg_sv_configuration_gps_dep:
    doc: |
      Deprecated.
    seq:
      - id: t_nmct
        doc: |
          Navigation Message Correction Table Validity Time
        type: gnss::gps_time_sec
      - id: l2c_mask
        doc: |
          L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
        type: u4
  
  gnss_capb:
    seq:
      - id: gps_active
        doc: |
          GPS SV active mask
        type: u8
      - id: gps_l2c
        doc: |
          GPS L2C active mask
        type: u8
      - id: gps_l5
        doc: |
          GPS L5 active mask
        type: u8
      - id: glo_active
        doc: |
          GLO active mask
        type: u4
      - id: glo_l2of
        doc: |
          GLO L2OF active mask
        type: u4
      - id: glo_l3
        doc: |
          GLO L3 active mask
        type: u4
      - id: sbas_active
        doc: |
          SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
          https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
        type: u8
      - id: sbas_l5
        doc: |
          SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
          https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
        type: u8
      - id: bds_active
        doc: |
          BDS active mask
        type: u8
      - id: bds_d2nav
        doc: |
          BDS D2NAV active mask
        type: u8
      - id: bds_b2
        doc: |
          BDS B2 active mask
        type: u8
      - id: bds_b2a
        doc: |
          BDS B2A active mask
        type: u8
      - id: qzss_active
        doc: |
          QZSS active mask
        type: u4
      - id: gal_active
        doc: |
          GAL active mask
        type: u8
      - id: gal_e5
        doc: |
          GAL E5 active mask
        type: u8
  
  msg_gnss_capb:
    doc: |
      Bit masks of signal capabilities for each GNSS satellite PRN.
      Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
    seq:
      - id: t_nmct
        doc: |
          Navigation Message Correction Table Validity Time
        type: gnss::gps_time_sec
      - id: gc
        doc: |
          GNSS capabilities masks
        type: gnss_capb
  
  msg_group_delay_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: t_op
        doc: |
          Data Predict Time of Week
        type: gnss::gps_time_dep
      - id: prn
        doc: |
          Satellite number
        type: u1
      - id: valid
        doc: |
          bit-field indicating validity of the values, LSB indicating tgd
          validity etc. 1 = value is valid, 0 = value is not valid.
        type: u1
      - id: tgd
        type: s2
      - id: isc_l1ca
        type: s2
      - id: isc_l2c
        type: s2
  
  msg_group_delay_dep_b:
    doc: |
      Deprecated.
    seq:
      - id: t_op
        doc: |
          Data Predict Time of Week
        type: gnss::gps_time_sec
      - id: sid
        doc: |
          GNSS signal identifier
        type: gnss::gnss_signal_dep
      - id: valid
        doc: |
          bit-field indicating validity of the values, LSB indicating tgd
          validity etc. 1 = value is valid, 0 = value is not valid.
        type: u1
      - id: tgd
        type: s2
      - id: isc_l1ca
        type: s2
      - id: isc_l2c
        type: s2
  
  msg_group_delay:
    doc: |
      Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
    seq:
      - id: t_op
        doc: |
          Data Predict Time of Week
        type: gnss::gps_time_sec
      - id: sid
        doc: |
          GNSS signal identifier
        type: gnss::gnss_signal
      - id: valid
        doc: |
          bit-field indicating validity of the values, LSB indicating tgd
          validity etc. 1 = value is valid, 0 = value is not valid.
        type: u1
      - id: tgd
        type: s2
      - id: isc_l1ca
        type: s2
      - id: isc_l2c
        type: s2
  
  almanac_common_content:
    seq:
      - id: sid
        doc: |
          GNSS signal identifier
        type: gnss::gnss_signal
      - id: toa
        doc: |
          Reference time of almanac
        type: gnss::gps_time_sec
      - id: ura
        doc: |
          User Range Accuracy
        type: f8
      - id: fit_interval
        doc: |
          Curve fit interval
        type: u4
      - id: valid
        doc: |
          Status of almanac, 1 = valid, 0 = invalid
        type: u1
      - id: health_bits
        doc: |
          Satellite health status for GPS:
            - bits 5-7: NAV data health status. See IS-GPS-200H
              Table 20-VII: NAV Data Health Indications.
            - bits 0-4: Signal health status. See IS-GPS-200H
              Table 20-VIII. Codes for Health of SV Signal
              Components.
          Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
          details):
            - bit 0: C(n), "unhealthy" flag that is transmitted within
              non-immediate data and indicates overall constellation status
              at the moment of almanac uploading.
              '0' indicates malfunction of n-satellite.
              '1' indicates that n-satellite is operational.
            - bit 1: Bn(ln), '0' indicates the satellite is operational
              and suitable for navigation.
        type: u1
  
  almanac_common_content_dep:
    seq:
      - id: sid
        doc: |
          GNSS signal identifier
        type: gnss::gnss_signal_dep
      - id: toa
        doc: |
          Reference time of almanac
        type: gnss::gps_time_sec
      - id: ura
        doc: |
          User Range Accuracy
        type: f8
      - id: fit_interval
        doc: |
          Curve fit interval
        type: u4
      - id: valid
        doc: |
          Status of almanac, 1 = valid, 0 = invalid
        type: u1
      - id: health_bits
        doc: |
          Satellite health status for GPS:
            - bits 5-7: NAV data health status. See IS-GPS-200H
              Table 20-VII: NAV Data Health Indications.
            - bits 0-4: Signal health status. See IS-GPS-200H
              Table 20-VIII. Codes for Health of SV Signal
              Components.
          Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
          details):
            - bit 0: C(n), "unhealthy" flag that is transmitted within
              non-immediate data and indicates overall constellation status
              at the moment of almanac uploading.
              '0' indicates malfunction of n-satellite.
              '1' indicates that n-satellite is operational.
            - bit 1: Bn(ln), '0' indicates the satellite is operational
              and suitable for navigation.
        type: u1
  
  msg_almanac_gps_dep:
    doc: |
      Deprecated.
    seq:
      - id: common
        doc: |
          Values common for all almanac types
        type: almanac_common_content_dep
      - id: m0
        doc: |
          Mean anomaly at reference time
        type: f8
      - id: ecc
        doc: |
          Eccentricity of satellite orbit
        type: f8
      - id: sqrta
        doc: |
          Square root of the semi-major axis of orbit
        type: f8
      - id: omega0
        doc: |
          Longitude of ascending node of orbit plane at weekly epoch
        type: f8
      - id: omegadot
        doc: |
          Rate of right ascension
        type: f8
      - id: w
        doc: |
          Argument of perigee
        type: f8
      - id: inc
        doc: |
          Inclination
        type: f8
      - id: af0
        doc: |
          Polynomial clock correction coefficient (clock bias)
        type: f8
      - id: af1
        doc: |
          Polynomial clock correction coefficient (clock drift)
        type: f8
  
  msg_almanac_gps:
    doc: |
      The almanac message returns a set of satellite orbit parameters. Almanac
      data is not very precise and is considered valid for up to several
      months. Please see the Navstar GPS Space Segment/Navigation user
      interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
      details.
    seq:
      - id: common
        doc: |
          Values common for all almanac types
        type: almanac_common_content
      - id: m0
        doc: |
          Mean anomaly at reference time
        type: f8
      - id: ecc
        doc: |
          Eccentricity of satellite orbit
        type: f8
      - id: sqrta
        doc: |
          Square root of the semi-major axis of orbit
        type: f8
      - id: omega0
        doc: |
          Longitude of ascending node of orbit plane at weekly epoch
        type: f8
      - id: omegadot
        doc: |
          Rate of right ascension
        type: f8
      - id: w
        doc: |
          Argument of perigee
        type: f8
      - id: inc
        doc: |
          Inclination
        type: f8
      - id: af0
        doc: |
          Polynomial clock correction coefficient (clock bias)
        type: f8
      - id: af1
        doc: |
          Polynomial clock correction coefficient (clock drift)
        type: f8
  
  msg_almanac_glo_dep:
    doc: |
      Deprecated.
    seq:
      - id: common
        doc: |
          Values common for all almanac types
        type: almanac_common_content_dep
      - id: lambda_na
        doc: |
          Longitude of the first ascending node of the orbit in PZ-90.02
          coordinate system
        type: f8
      - id: t_lambda_na
        doc: |
          Time of the first ascending node passage
        type: f8
      - id: i
        doc: |
          Value of inclination at instant of t_lambda
        type: f8
      - id: t
        doc: |
          Value of Draconian period at instant of t_lambda
        type: f8
      - id: t_dot
        doc: |
          Rate of change of the Draconian period
        type: f8
      - id: epsilon
        doc: |
          Eccentricity at instant of t_lambda
        type: f8
      - id: omega
        doc: |
          Argument of perigee at instant of t_lambda
        type: f8
  
  msg_almanac_glo:
    doc: |
      The almanac message returns a set of satellite orbit parameters. Almanac
      data is not very precise and is considered valid for up to several
      months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
      information and almanac" for details.
    seq:
      - id: common
        doc: |
          Values common for all almanac types
        type: almanac_common_content
      - id: lambda_na
        doc: |
          Longitude of the first ascending node of the orbit in PZ-90.02
          coordinate system
        type: f8
      - id: t_lambda_na
        doc: |
          Time of the first ascending node passage
        type: f8
      - id: i
        doc: |
          Value of inclination at instant of t_lambda
        type: f8
      - id: t
        doc: |
          Value of Draconian period at instant of t_lambda
        type: f8
      - id: t_dot
        doc: |
          Rate of change of the Draconian period
        type: f8
      - id: epsilon
        doc: |
          Eccentricity at instant of t_lambda
        type: f8
      - id: omega
        doc: |
          Argument of perigee at instant of t_lambda
        type: f8
  
  msg_glo_biases:
    doc: |
      The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS
      integer ambiguity resolution for baselines with mixed receiver types
      (e.g. receiver of different manufacturers).
    seq:
      - id: mask
        doc: |
          GLONASS FDMA signals mask
        type: u1
      - id: l1ca_bias
        doc: |
          GLONASS L1 C/A Code-Phase Bias
        type: s2
      - id: l1p_bias
        doc: |
          GLONASS L1 P Code-Phase Bias
        type: s2
      - id: l2ca_bias
        doc: |
          GLONASS L2 C/A Code-Phase Bias
        type: s2
      - id: l2p_bias
        doc: |
          GLONASS L2 P Code-Phase Bias
        type: s2
  
  sv_az_el:
    doc: |
      Satellite azimuth and elevation.
    seq:
      - id: sid
        doc: |
          GNSS signal identifier
        type: gnss::gnss_signal
      - id: az
        doc: |
          Azimuth angle (range 0..179)
        type: u1
      - id: el
        doc: |
          Elevation angle (range -90..90)
        type: s1
  
  msg_sv_az_el:
    doc: |
      Azimuth and elevation angles of all the visible satellites that the
      device does have ephemeris or almanac for.
    seq:
      - id: azel
        doc: |
          Azimuth and elevation per satellite
        type: sv_az_el
        repeat: eos
  
  msg_osr:
    doc: |
      The OSR message contains network corrections in an observation-like
      format.
    seq:
      - id: header
        doc: |
          Header of a GPS observation message
        type: observation_header
      - id: obs
        doc: |
          Network correction for a satellite signal.
        type: packed_osr_content
        repeat: eos
  