# Messages for using device's onboard flash filesystem functionality. This allows
# data to be stored persistently in the device's program flash with wear-levelling
# using a simple filesystem interface. The file system interface (CFS) defines an
# abstract API for reading directories and for reading and writing files.  Note
# that some of these messages share the same message type ID for both the host
# request and the device response.

# Automatically generated from spec/yaml/swiftnav/sbp/file_io.yaml with generate.py.
# Please do not hand edit!

meta:
  id: file_io
  endian: le
  imports: [  ]

types:

  msg_fileio_read_req:
    doc: |
      The file read message reads a certain length (up to 255 bytes) from a
      given offset into a file, and returns the data in a MSG_FILEIO_READ_RESP
      message where the message length field indicates how many bytes were
      successfully read. The sequence number in the request will be returned
      in the response. If the message is invalid, a followup MSG_PRINT message
      will print "Invalid fileio read message". A device will only respond to
      this message when it is received from sender ID 0x42.
    seq:
      - id: sequence
        doc: |
          Read sequence number
        type: u4
      - id: offset
        doc: |
          File offset
        type: u4
      - id: chunk_size
        doc: |
          Chunk size to read
        type: u1
      - id: filename
        doc: |
          Name of the file to read from
        type: str
        encoding: ascii
        size-eos: true
  
  msg_fileio_read_resp:
    doc: |
      The file read message reads a certain length (up to 255 bytes) from a
      given offset into a file, and returns the data in a message where the
      message length field indicates how many bytes were successfully read.
      The sequence number in the response is preserved from the request.
    seq:
      - id: sequence
        doc: |
          Read sequence number
        type: u4
      - id: contents
        doc: |
          Contents of read file
        type: u1
        repeat: eos
  
  msg_fileio_read_dir_req:
    doc: |
      The read directory message lists the files in a directory on the
      device's onboard flash file system.  The offset parameter can be used to
      skip the first n elements of the file list. Returns a
      MSG_FILEIO_READ_DIR_RESP message containing the directory listings as a
      NULL delimited list. The listing is chunked over multiple SBP packets.
      The sequence number in the request will be returned in the response.  If
      message is invalid, a followup MSG_PRINT message will print "Invalid
      fileio read message". A device will only respond to this message when it
      is received from sender ID 0x42.
    seq:
      - id: sequence
        doc: |
          Read sequence number
        type: u4
      - id: offset
        doc: |
          The offset to skip the first n elements of the file list
        type: u4
      - id: dirname
        doc: |
          Name of the directory to list
        type: str
        encoding: ascii
        size-eos: true
  
  msg_fileio_read_dir_resp:
    doc: |
      The read directory message lists the files in a directory on the
      device's onboard flash file system. Message contains the directory
      listings as a NULL delimited list. The listing is chunked over multiple
      SBP packets and the end of the list is identified by an packet with no
      entries. The sequence number in the response is preserved from the
      request.
    seq:
      - id: sequence
        doc: |
          Read sequence number
        type: u4
      - id: contents
        doc: |
          Contents of read directory
        type: u1
        repeat: eos
  
  msg_fileio_remove:
    doc: |
      The file remove message deletes a file from the file system. If the
      message is invalid, a followup MSG_PRINT message will print "Invalid
      fileio remove message". A device will only process this message when it
      is received from sender ID 0x42.
    seq:
      - id: filename
        doc: |
          Name of the file to delete
        type: str
        encoding: ascii
        size-eos: true
  
  msg_fileio_write_req:
    doc: |
      The file write message writes a certain length (up to 255 bytes) of data
      to a file at a given offset. Returns a copy of the original
      MSG_FILEIO_WRITE_RESP message to check integrity of the write. The
      sequence number in the request will be returned in the response. If
      message is invalid, a followup MSG_PRINT message will print "Invalid
      fileio write message". A device will only process this message when it
      is received from sender ID 0x42.
    seq:
      - id: sequence
        doc: |
          Write sequence number
        type: u4
      - id: offset
        doc: |
          Offset into the file at which to start writing in bytes
        type: u4
      - id: filename
        doc: |
          Name of the file to write to
        type: str
        encoding: ascii
        size-eos: true
      - id: data
        doc: |
          Variable-length array of data to write
        type: u1
        repeat: eos
  
  msg_fileio_write_resp:
    doc: |
      The file write message writes a certain length (up to 255 bytes) of data
      to a file at a given offset. The message is a copy of the original
      MSG_FILEIO_WRITE_REQ message to check integrity of the write. The
      sequence number in the response is preserved from the request.
    seq:
      - id: sequence
        doc: |
          Write sequence number
        type: u4
  
  msg_fileio_config_req:
    doc: |
      Requests advice on the optimal configuration for a FileIO transfer.
      Newer version of FileIO can support greater throughput by supporting a
      large window of FileIO data that can be in-flight during read or write
      operations.
    seq:
      - id: sequence
        doc: |
          Advice sequence number
        type: u4
  
  msg_fileio_config_resp:
    doc: |
      The advice on the optimal configuration for a FileIO transfer.  Newer
      version of FileIO can support greater throughput by supporting a large
      window of FileIO data that can be in-flight during read or write
      operations.
    seq:
      - id: sequence
        doc: |
          Advice sequence number
        type: u4
      - id: window_size
        doc: |
          The number of SBP packets in the data in-flight window
        type: u4
      - id: batch_size
        doc: |
          The number of SBP packets sent in one PDU
        type: u4
      - id: fileio_version
        doc: |
          The version of FileIO that is supported
        type: u4
  