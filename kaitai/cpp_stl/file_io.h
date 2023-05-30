#ifndef FILE_IO_H_
#define FILE_IO_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class file_io_t : public kaitai::kstruct {

public:
    class msg_fileio_write_req_t;
    class msg_fileio_config_resp_t;
    class msg_fileio_remove_t;
    class msg_fileio_config_req_t;
    class msg_fileio_read_dir_req_t;
    class msg_fileio_write_resp_t;
    class msg_fileio_read_dir_resp_t;
    class msg_fileio_read_req_t;
    class msg_fileio_read_resp_t;

    file_io_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, file_io_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~file_io_t();

    /**
     * The file write message writes a certain length (up to 255 bytes) of data
     * to a file at a given offset. Returns a copy of the original
     * MSG_FILEIO_WRITE_RESP message to check integrity of the write. The
     * sequence number in the request will be returned in the response. If
     * message is invalid, a followup MSG_PRINT message will print "Invalid
     * fileio write message". A device will only process this message when it
     * is received from sender ID 0x42.
     */

    class msg_fileio_write_req_t : public kaitai::kstruct {

    public:

        msg_fileio_write_req_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, file_io_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_fileio_write_req_t();

    private:
        uint32_t m_sequence;
        uint32_t m_offset;
        std::string m_filename;
        std::vector<uint8_t>* m_data;
        file_io_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Write sequence number
         */
        uint32_t sequence() const { return m_sequence; }

        /**
         * Offset into the file at which to start writing in bytes
         */
        uint32_t offset() const { return m_offset; }

        /**
         * Name of the file to write to
         */
        std::string filename() const { return m_filename; }

        /**
         * Variable-length array of data to write
         */
        std::vector<uint8_t>* data() const { return m_data; }
        file_io_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The advice on the optimal configuration for a FileIO transfer.  Newer
     * version of FileIO can support greater throughput by supporting a large
     * window of FileIO data that can be in-flight during read or write
     * operations.
     */

    class msg_fileio_config_resp_t : public kaitai::kstruct {

    public:

        msg_fileio_config_resp_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, file_io_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_fileio_config_resp_t();

    private:
        uint32_t m_sequence;
        uint32_t m_window_size;
        uint32_t m_batch_size;
        uint32_t m_fileio_version;
        file_io_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Advice sequence number
         */
        uint32_t sequence() const { return m_sequence; }

        /**
         * The number of SBP packets in the data in-flight window
         */
        uint32_t window_size() const { return m_window_size; }

        /**
         * The number of SBP packets sent in one PDU
         */
        uint32_t batch_size() const { return m_batch_size; }

        /**
         * The version of FileIO that is supported
         */
        uint32_t fileio_version() const { return m_fileio_version; }
        file_io_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The file remove message deletes a file from the file system. If the
     * message is invalid, a followup MSG_PRINT message will print "Invalid
     * fileio remove message". A device will only process this message when it
     * is received from sender ID 0x42.
     */

    class msg_fileio_remove_t : public kaitai::kstruct {

    public:

        msg_fileio_remove_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, file_io_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_fileio_remove_t();

    private:
        std::string m_filename;
        file_io_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Name of the file to delete
         */
        std::string filename() const { return m_filename; }
        file_io_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Requests advice on the optimal configuration for a FileIO transfer.
     * Newer version of FileIO can support greater throughput by supporting a
     * large window of FileIO data that can be in-flight during read or write
     * operations.
     */

    class msg_fileio_config_req_t : public kaitai::kstruct {

    public:

        msg_fileio_config_req_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, file_io_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_fileio_config_req_t();

    private:
        uint32_t m_sequence;
        file_io_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Advice sequence number
         */
        uint32_t sequence() const { return m_sequence; }
        file_io_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The read directory message lists the files in a directory on the
     * device's onboard flash file system.  The offset parameter can be used to
     * skip the first n elements of the file list. Returns a
     * MSG_FILEIO_READ_DIR_RESP message containing the directory listings as a
     * NULL delimited list. The listing is chunked over multiple SBP packets.
     * The sequence number in the request will be returned in the response.  If
     * message is invalid, a followup MSG_PRINT message will print "Invalid
     * fileio read message". A device will only respond to this message when it
     * is received from sender ID 0x42.
     */

    class msg_fileio_read_dir_req_t : public kaitai::kstruct {

    public:

        msg_fileio_read_dir_req_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, file_io_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_fileio_read_dir_req_t();

    private:
        uint32_t m_sequence;
        uint32_t m_offset;
        std::string m_dirname;
        file_io_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Read sequence number
         */
        uint32_t sequence() const { return m_sequence; }

        /**
         * The offset to skip the first n elements of the file list
         */
        uint32_t offset() const { return m_offset; }

        /**
         * Name of the directory to list
         */
        std::string dirname() const { return m_dirname; }
        file_io_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The file write message writes a certain length (up to 255 bytes) of data
     * to a file at a given offset. The message is a copy of the original
     * MSG_FILEIO_WRITE_REQ message to check integrity of the write. The
     * sequence number in the response is preserved from the request.
     */

    class msg_fileio_write_resp_t : public kaitai::kstruct {

    public:

        msg_fileio_write_resp_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, file_io_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_fileio_write_resp_t();

    private:
        uint32_t m_sequence;
        file_io_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Write sequence number
         */
        uint32_t sequence() const { return m_sequence; }
        file_io_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The read directory message lists the files in a directory on the
     * device's onboard flash file system. Message contains the directory
     * listings as a NULL delimited list. The listing is chunked over multiple
     * SBP packets and the end of the list is identified by an packet with no
     * entries. The sequence number in the response is preserved from the
     * request.
     */

    class msg_fileio_read_dir_resp_t : public kaitai::kstruct {

    public:

        msg_fileio_read_dir_resp_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, file_io_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_fileio_read_dir_resp_t();

    private:
        uint32_t m_sequence;
        std::vector<uint8_t>* m_contents;
        file_io_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Read sequence number
         */
        uint32_t sequence() const { return m_sequence; }

        /**
         * Contents of read directory
         */
        std::vector<uint8_t>* contents() const { return m_contents; }
        file_io_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The file read message reads a certain length (up to 255 bytes) from a
     * given offset into a file, and returns the data in a MSG_FILEIO_READ_RESP
     * message where the message length field indicates how many bytes were
     * successfully read. The sequence number in the request will be returned
     * in the response. If the message is invalid, a followup MSG_PRINT message
     * will print "Invalid fileio read message". A device will only respond to
     * this message when it is received from sender ID 0x42.
     */

    class msg_fileio_read_req_t : public kaitai::kstruct {

    public:

        msg_fileio_read_req_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, file_io_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_fileio_read_req_t();

    private:
        uint32_t m_sequence;
        uint32_t m_offset;
        uint8_t m_chunk_size;
        std::string m_filename;
        file_io_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Read sequence number
         */
        uint32_t sequence() const { return m_sequence; }

        /**
         * File offset
         */
        uint32_t offset() const { return m_offset; }

        /**
         * Chunk size to read
         */
        uint8_t chunk_size() const { return m_chunk_size; }

        /**
         * Name of the file to read from
         */
        std::string filename() const { return m_filename; }
        file_io_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The file read message reads a certain length (up to 255 bytes) from a
     * given offset into a file, and returns the data in a message where the
     * message length field indicates how many bytes were successfully read.
     * The sequence number in the response is preserved from the request.
     */

    class msg_fileio_read_resp_t : public kaitai::kstruct {

    public:

        msg_fileio_read_resp_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, file_io_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_fileio_read_resp_t();

    private:
        uint32_t m_sequence;
        std::vector<uint8_t>* m_contents;
        file_io_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Read sequence number
         */
        uint32_t sequence() const { return m_sequence; }

        /**
         * Contents of read file
         */
        std::vector<uint8_t>* contents() const { return m_contents; }
        file_io_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

private:
    file_io_t* m__root;
    kaitai::kstruct* m__parent;

public:
    file_io_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // FILE_IO_H_
