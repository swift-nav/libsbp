#ifndef SIGNING_H_
#define SIGNING_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class signing_t : public kaitai::kstruct {

public:
    class msg_certificate_chain_dep_t;
    class msg_ed25519_signature_dep_b_t;
    class msg_ed25519_certificate_dep_t;
    class utc_time_t;
    class ecdsa_signature_t;
    class msg_ed25519_signature_dep_a_t;
    class msg_certificate_chain_t;
    class msg_ecdsa_certificate_t;
    class msg_ecdsa_signature_dep_b_t;
    class msg_ecdsa_signature_t;
    class msg_ecdsa_signature_dep_a_t;

    signing_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, signing_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~signing_t();

    /**
     * Deprecated.
     */

    class msg_certificate_chain_dep_t : public kaitai::kstruct {

    public:

        msg_certificate_chain_dep_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, signing_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_certificate_chain_dep_t();

    private:
        std::vector<uint8_t>* m_root_certificate;
        std::vector<uint8_t>* m_intermediate_certificate;
        std::vector<uint8_t>* m_corrections_certificate;
        utc_time_t* m_expiration;
        std::vector<uint8_t>* m_signature;
        signing_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * SHA-1 fingerprint of the root certificate
         */
        std::vector<uint8_t>* root_certificate() const { return m_root_certificate; }

        /**
         * SHA-1 fingerprint of the intermediate certificate
         */
        std::vector<uint8_t>* intermediate_certificate() const { return m_intermediate_certificate; }

        /**
         * SHA-1 fingerprint of the corrections certificate
         */
        std::vector<uint8_t>* corrections_certificate() const { return m_corrections_certificate; }

        /**
         * The certificate chain comprised of three fingerprints: root
         * certificate, intermediate certificate and corrections certificate.
         */
        utc_time_t* expiration() const { return m_expiration; }

        /**
         * An ECDSA signature (created by the root certificate) over the
         * concatenation of the SBP payload bytes preceding this field. That
         * is, the concatenation of `root_certificate`,
         * `intermediate_certificate`, `corrections_certificate` and
         * `expiration`.  This certificate chain (allow list) can also be
         * validated by fetching it from `http(s)://certs.swiftnav.com/chain`.
         */
        std::vector<uint8_t>* signature() const { return m_signature; }
        signing_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ed25519_signature_dep_b_t : public kaitai::kstruct {

    public:

        msg_ed25519_signature_dep_b_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, signing_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ed25519_signature_dep_b_t();

    private:
        uint8_t m_stream_counter;
        uint8_t m_on_demand_counter;
        std::vector<uint8_t>* m_signature;
        std::vector<uint8_t>* m_fingerprint;
        std::vector<uint32_t>* m_signed_messages;
        signing_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Signature message counter. Zero indexed and incremented with each
         * signature message.  The counter will not increment if this message
         * was in response to an on demand request.  The counter will roll over
         * after 256 messages. Upon connection, the value of the counter may
         * not initially be zero.
         */
        uint8_t stream_counter() const { return m_stream_counter; }

        /**
         * On demand message counter. Zero indexed and incremented with each
         * signature message sent in response to an on demand message. The
         * counter will roll over after 256 messages.  Upon connection, the
         * value of the counter may not initially be zero.
         */
        uint8_t on_demand_counter() const { return m_on_demand_counter; }

        /**
         * ED25519 signature for messages.
         */
        std::vector<uint8_t>* signature() const { return m_signature; }

        /**
         * SHA-1 fingerprint of the associated certificate.
         */
        std::vector<uint8_t>* fingerprint() const { return m_fingerprint; }

        /**
         * CRCs of signed messages.
         */
        std::vector<uint32_t>* signed_messages() const { return m_signed_messages; }
        signing_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ed25519_certificate_dep_t : public kaitai::kstruct {

    public:

        msg_ed25519_certificate_dep_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, signing_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ed25519_certificate_dep_t();

    private:
        uint8_t m_n_msg;
        std::vector<uint8_t>* m_fingerprint;
        std::vector<uint8_t>* m_certificate_bytes;
        signing_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Total number messages that make up the certificate. First nibble is
         * the size of the sequence (n), second nibble is the zero-indexed
         * counter (ith packet of n)
         */
        uint8_t n_msg() const { return m_n_msg; }

        /**
         * SHA-1 fingerprint of the associated certificate.
         */
        std::vector<uint8_t>* fingerprint() const { return m_fingerprint; }

        /**
         * ED25519 certificate bytes.
         */
        std::vector<uint8_t>* certificate_bytes() const { return m_certificate_bytes; }
        signing_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    class utc_time_t : public kaitai::kstruct {

    public:

        utc_time_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, signing_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~utc_time_t();

    private:
        uint16_t m_year;
        uint8_t m_month;
        uint8_t m_day;
        uint8_t m_hours;
        uint8_t m_minutes;
        uint8_t m_seconds;
        uint32_t m_ns;
        signing_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Year
         */
        uint16_t year() const { return m_year; }

        /**
         * Month (range 1 .. 12)
         */
        uint8_t month() const { return m_month; }

        /**
         * days in the month (range 1-31)
         */
        uint8_t day() const { return m_day; }

        /**
         * hours of day (range 0-23)
         */
        uint8_t hours() const { return m_hours; }

        /**
         * minutes of hour (range 0-59)
         */
        uint8_t minutes() const { return m_minutes; }

        /**
         * seconds of minute (range 0-60) rounded down
         */
        uint8_t seconds() const { return m_seconds; }

        /**
         * nanoseconds of second (range 0-999999999)
         */
        uint32_t ns() const { return m_ns; }
        signing_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class ecdsa_signature_t : public kaitai::kstruct {

    public:

        ecdsa_signature_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, signing_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~ecdsa_signature_t();

    private:
        uint8_t m_len;
        std::vector<uint8_t>* m_data;
        signing_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Number of bytes to use of the signature field.  The DER encoded
         * signature has a maximum size of 72 bytes but can vary between 70 and
         * 72 bytes in length.
         */
        uint8_t len() const { return m_len; }

        /**
         * DER encoded ECDSA signature for the messages using SHA-256 as the
         * digest algorithm.
         */
        std::vector<uint8_t>* data() const { return m_data; }
        signing_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ed25519_signature_dep_a_t : public kaitai::kstruct {

    public:

        msg_ed25519_signature_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, signing_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ed25519_signature_dep_a_t();

    private:
        std::vector<uint8_t>* m_signature;
        std::vector<uint8_t>* m_fingerprint;
        std::vector<uint32_t>* m_signed_messages;
        signing_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * ED25519 signature for messages.
         */
        std::vector<uint8_t>* signature() const { return m_signature; }

        /**
         * SHA-1 fingerprint of the associated certificate.
         */
        std::vector<uint8_t>* fingerprint() const { return m_fingerprint; }

        /**
         * CRCs of signed messages.
         */
        std::vector<uint32_t>* signed_messages() const { return m_signed_messages; }
        signing_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    class msg_certificate_chain_t : public kaitai::kstruct {

    public:

        msg_certificate_chain_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, signing_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_certificate_chain_t();

    private:
        std::vector<uint8_t>* m_root_certificate;
        std::vector<uint8_t>* m_intermediate_certificate;
        std::vector<uint8_t>* m_corrections_certificate;
        utc_time_t* m_expiration;
        ecdsa_signature_t* m_signature;
        signing_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * SHA-1 fingerprint of the root certificate
         */
        std::vector<uint8_t>* root_certificate() const { return m_root_certificate; }

        /**
         * SHA-1 fingerprint of the intermediate certificate
         */
        std::vector<uint8_t>* intermediate_certificate() const { return m_intermediate_certificate; }

        /**
         * SHA-1 fingerprint of the corrections certificate
         */
        std::vector<uint8_t>* corrections_certificate() const { return m_corrections_certificate; }

        /**
         * The time after which the signature given is no longer valid.
         * Implementors should consult a time source (such as GNSS) to check if
         * the current time is later than the expiration time, if the condition
         * is true, signatures in the stream should not be considered valid.
         */
        utc_time_t* expiration() const { return m_expiration; }

        /**
         * Signature (created by the root certificate) over the concatenation
         * of the SBP payload bytes preceding this field. That is, the
         * concatenation of `root_certificate`, `intermediate_certificate`,
         * `corrections_certificate` and `expiration`.  This certificate chain
         * (allow list) can also be validated by fetching it from
         * `http(s)://certs.swiftnav.com/chain`.
         */
        ecdsa_signature_t* signature() const { return m_signature; }
        signing_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
     */

    class msg_ecdsa_certificate_t : public kaitai::kstruct {

    public:

        msg_ecdsa_certificate_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, signing_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ecdsa_certificate_t();

    private:
        uint8_t m_n_msg;
        std::vector<uint8_t>* m_certificate_id;
        uint8_t m_flags;
        std::vector<uint8_t>* m_certificate_bytes;
        signing_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Total number messages that make up the certificate. The first nibble
         * (mask 0xF0 or left shifted by 4 bits) is the size of the sequence
         * (n), second nibble (mask 0x0F) is the zero-indexed counter (ith
         * packet of n).
         */
        uint8_t n_msg() const { return m_n_msg; }

        /**
         * The last 4 bytes of the certificate's SHA-1 fingerprint
         */
        std::vector<uint8_t>* certificate_id() const { return m_certificate_id; }
        uint8_t flags() const { return m_flags; }

        /**
         * DER encoded x.509 ECDSA certificate bytes
         */
        std::vector<uint8_t>* certificate_bytes() const { return m_certificate_bytes; }
        signing_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ecdsa_signature_dep_b_t : public kaitai::kstruct {

    public:

        msg_ecdsa_signature_dep_b_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, signing_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ecdsa_signature_dep_b_t();

    private:
        uint8_t m_flags;
        uint8_t m_stream_counter;
        uint8_t m_on_demand_counter;
        std::vector<uint8_t>* m_certificate_id;
        uint8_t m_n_signature_bytes;
        std::vector<uint8_t>* m_signature;
        std::vector<uint8_t>* m_signed_messages;
        signing_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Describes the format of the `signed\_messages` field below.
         */
        uint8_t flags() const { return m_flags; }

        /**
         * Signature message counter. Zero indexed and incremented with each
         * signature message.  The counter will not increment if this message
         * was in response to an on demand request.  The counter will roll over
         * after 256 messages. Upon connection, the value of the counter may
         * not initially be zero.
         */
        uint8_t stream_counter() const { return m_stream_counter; }

        /**
         * On demand message counter. Zero indexed and incremented with each
         * signature message sent in response to an on demand message. The
         * counter will roll over after 256 messages.  Upon connection, the
         * value of the counter may not initially be zero.
         */
        uint8_t on_demand_counter() const { return m_on_demand_counter; }

        /**
         * The last 4 bytes of the certificate's SHA-1 fingerprint
         */
        std::vector<uint8_t>* certificate_id() const { return m_certificate_id; }

        /**
         * Number of bytes to use of the signature field.  The DER encoded
         * signature has a maximum size of 72 bytes but can vary between 70 and
         * 72 bytes in length.
         */
        uint8_t n_signature_bytes() const { return m_n_signature_bytes; }

        /**
         * DER encoded ECDSA signature for the messages using SHA-256 as the
         * digest algorithm.
         */
        std::vector<uint8_t>* signature() const { return m_signature; }

        /**
         * CRCs of the messages covered by this signature.  For Skylark, which
         * delivers SBP messages wrapped in Swift's proprietary RTCM message,
         * these are the 24-bit CRCs from the RTCM message framing. For SBP
         * only streams, this will be 16-bit CRCs from the SBP framing.  See
         * the `flags` field to determine the type of CRCs covered.
         */
        std::vector<uint8_t>* signed_messages() const { return m_signed_messages; }
        signing_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * An ECDSA-256 signature using SHA-256 as the message digest algorithm.
     */

    class msg_ecdsa_signature_t : public kaitai::kstruct {

    public:

        msg_ecdsa_signature_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, signing_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ecdsa_signature_t();

    private:
        uint8_t m_flags;
        uint8_t m_stream_counter;
        uint8_t m_on_demand_counter;
        std::vector<uint8_t>* m_certificate_id;
        ecdsa_signature_t* m_signature;
        std::vector<uint8_t>* m_signed_messages;
        signing_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Describes the format of the `signed\_messages` field below.
         */
        uint8_t flags() const { return m_flags; }

        /**
         * Signature message counter. Zero indexed and incremented with each
         * signature message.  The counter will not increment if this message
         * was in response to an on demand request.  The counter will roll over
         * after 256 messages. Upon connection, the value of the counter may
         * not initially be zero.
         */
        uint8_t stream_counter() const { return m_stream_counter; }

        /**
         * On demand message counter. Zero indexed and incremented with each
         * signature message sent in response to an on demand message. The
         * counter will roll over after 256 messages.  Upon connection, the
         * value of the counter may not initially be zero.
         */
        uint8_t on_demand_counter() const { return m_on_demand_counter; }

        /**
         * The last 4 bytes of the certificate's SHA-1 fingerprint
         */
        std::vector<uint8_t>* certificate_id() const { return m_certificate_id; }

        /**
         * Signature over the frames of this message group.
         */
        ecdsa_signature_t* signature() const { return m_signature; }

        /**
         * CRCs of the messages covered by this signature.  For Skylark, which
         * delivers SBP messages wrapped in Swift's proprietary RTCM message,
         * these are the 24-bit CRCs from the RTCM message framing. For SBP
         * only streams, this will be 16-bit CRCs from the SBP framing.  See
         * the `flags` field to determine the type of CRCs covered.
         */
        std::vector<uint8_t>* signed_messages() const { return m_signed_messages; }
        signing_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ecdsa_signature_dep_a_t : public kaitai::kstruct {

    public:

        msg_ecdsa_signature_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, signing_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ecdsa_signature_dep_a_t();

    private:
        uint8_t m_flags;
        uint8_t m_stream_counter;
        uint8_t m_on_demand_counter;
        std::vector<uint8_t>* m_certificate_id;
        std::vector<uint8_t>* m_signature;
        std::vector<uint8_t>* m_signed_messages;
        signing_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Describes the format of the `signed\_messages` field below.
         */
        uint8_t flags() const { return m_flags; }

        /**
         * Signature message counter. Zero indexed and incremented with each
         * signature message.  The counter will not increment if this message
         * was in response to an on demand request.  The counter will roll over
         * after 256 messages. Upon connection, the value of the counter may
         * not initially be zero.
         */
        uint8_t stream_counter() const { return m_stream_counter; }

        /**
         * On demand message counter. Zero indexed and incremented with each
         * signature message sent in response to an on demand message. The
         * counter will roll over after 256 messages.  Upon connection, the
         * value of the counter may not initially be zero.
         */
        uint8_t on_demand_counter() const { return m_on_demand_counter; }

        /**
         * The last 4 bytes of the certificate's SHA-1 fingerprint
         */
        std::vector<uint8_t>* certificate_id() const { return m_certificate_id; }

        /**
         * ECDSA signature for the messages using SHA-256 as the digest
         * algorithm.
         */
        std::vector<uint8_t>* signature() const { return m_signature; }

        /**
         * CRCs of the messages covered by this signature.  For Skylark, which
         * delivers SBP messages wrapped in Swift's proprietary RTCM message,
         * these are the 24-bit CRCs from the RTCM message framing. For SBP
         * only streams, this will be 16-bit CRCs from the SBP framing.  See
         * the `flags` field to determine the type of CRCs covered.
         */
        std::vector<uint8_t>* signed_messages() const { return m_signed_messages; }
        signing_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

private:
    signing_t* m__root;
    kaitai::kstruct* m__parent;

public:
    signing_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // SIGNING_H_
