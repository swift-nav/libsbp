# Satellite acquisition messages from the device.

# Automatically generated from spec/yaml/swiftnav/sbp/acquisition.yaml with generate.py.
# Please do not hand edit!

meta:
  id: acquisition
  endian: le
  imports: [ gnss ]

types:

  msg_acq_result:
    doc: |
      This message describes the results from an attempted GPS signal
      acquisition search for a satellite PRN over a code phase/carrier
      frequency range. It contains the parameters of the point in the
      acquisition search space with the best carrier-to-noise (CN/0) ratio.
    seq:
      - id: cn0
        doc: |
          CN/0 of best point
        type: f4
      - id: cp
        doc: |
          Code phase of best point
        type: f4
      - id: cf
        doc: |
          Carrier frequency of best point
        type: f4
      - id: sid
        doc: |
          GNSS signal for which acquisition was attempted
        type: gnss::gnss_signal
  
  msg_acq_result_dep_c:
    doc: |
      Deprecated.
    seq:
      - id: cn0
        doc: |
          CN/0 of best point
        type: f4
      - id: cp
        doc: |
          Code phase of best point
        type: f4
      - id: cf
        doc: |
          Carrier frequency of best point
        type: f4
      - id: sid
        doc: |
          GNSS signal for which acquisition was attempted
        type: gnss::gnss_signal_dep
  
  msg_acq_result_dep_b:
    doc: |
      Deprecated.
    seq:
      - id: snr
        doc: |
          SNR of best point. Currently in arbitrary SNR points, but will be in
          units of dB Hz in a later revision of this message.
        type: f4
      - id: cp
        doc: |
          Code phase of best point
        type: f4
      - id: cf
        doc: |
          Carrier frequency of best point
        type: f4
      - id: sid
        doc: |
          GNSS signal for which acquisition was attempted
        type: gnss::gnss_signal_dep
  
  msg_acq_result_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: snr
        doc: |
          SNR of best point. Currently dimensionless, but will have units of
          dB Hz in the revision of this message.
        type: f4
      - id: cp
        doc: |
          Code phase of best point
        type: f4
      - id: cf
        doc: |
          Carrier frequency of best point
        type: f4
      - id: prn
        doc: |
          PRN-1 identifier of the satellite signal for which acquisition was
          attempted
        type: u1
  
  acq_sv_profile:
    doc: |
      Profile for a specific SV for debugging purposes. The message describes
      SV profile during acquisition time. The message is used to debug and
      measure the performance.
    seq:
      - id: job_type
        doc: |
          SV search job type (deep, fallback, etc)
        type: u1
      - id: status
        doc: |
          Acquisition status 1 is Success, 0 is Failure
        type: u1
      - id: cn0
        doc: |
          CN0 value. Only valid if status is '1'
        type: u2
      - id: int_time
        doc: |
          Acquisition integration time
        type: u1
      - id: sid
        doc: |
          GNSS signal for which acquisition was attempted
        type: gnss::gnss_signal
      - id: bin_width
        doc: |
          Acq frequency bin width
        type: u2
      - id: timestamp
        doc: |
          Timestamp of the job complete event
        type: u4
      - id: time_spent
        doc: |
          Time spent to search for sid.code
        type: u4
      - id: cf_min
        doc: |
          Doppler range lowest frequency
        type: s4
      - id: cf_max
        doc: |
          Doppler range highest frequency
        type: s4
      - id: cf
        doc: |
          Doppler value of detected peak. Only valid if status is '1'
        type: s4
      - id: cp
        doc: |
          Codephase of detected peak. Only valid if status is '1'
        type: u4
  
  acq_sv_profile_dep:
    doc: |
      Deprecated.
    seq:
      - id: job_type
        doc: |
          SV search job type (deep, fallback, etc)
        type: u1
      - id: status
        doc: |
          Acquisition status 1 is Success, 0 is Failure
        type: u1
      - id: cn0
        doc: |
          CN0 value. Only valid if status is '1'
        type: u2
      - id: int_time
        doc: |
          Acquisition integration time
        type: u1
      - id: sid
        doc: |
          GNSS signal for which acquisition was attempted
        type: gnss::gnss_signal_dep
      - id: bin_width
        doc: |
          Acq frequency bin width
        type: u2
      - id: timestamp
        doc: |
          Timestamp of the job complete event
        type: u4
      - id: time_spent
        doc: |
          Time spent to search for sid.code
        type: u4
      - id: cf_min
        doc: |
          Doppler range lowest frequency
        type: s4
      - id: cf_max
        doc: |
          Doppler range highest frequency
        type: s4
      - id: cf
        doc: |
          Doppler value of detected peak. Only valid if status is '1'
        type: s4
      - id: cp
        doc: |
          Codephase of detected peak. Only valid if status is '1'
        type: u4
  
  msg_acq_sv_profile:
    doc: |
      The message describes all SV profiles during acquisition time. The
      message is used to debug and measure the performance.
    seq:
      - id: acq_sv_profile
        doc: |
          SV profiles during acquisition time
        type: acq_sv_profile
        repeat: eos
  
  msg_acq_sv_profile_dep:
    doc: |
      Deprecated.
    seq:
      - id: acq_sv_profile
        doc: |
          SV profiles during acquisition time
        type: acq_sv_profile_dep
        repeat: eos
  