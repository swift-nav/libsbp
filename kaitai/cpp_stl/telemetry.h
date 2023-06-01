#ifndef TELEMETRY_H_
#define TELEMETRY_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class telemetry_t : public kaitai::kstruct {

public:
    class telemetry_sv_t;
    class msg_tel_sv_t;

    telemetry_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, telemetry_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~telemetry_t();

    class telemetry_sv_t : public kaitai::kstruct {

    public:

        telemetry_sv_t(kaitai::kstream* p__io, telemetry_t::msg_tel_sv_t* p__parent = 0, telemetry_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~telemetry_sv_t();

    private:
        uint8_t m_az;
        int8_t m_el;
        uint8_t m_availability_flags;
        int16_t m_pseudorange_residual;
        int16_t m_phase_residual;
        uint8_t m_outlier_flags;
        uint8_t m_ephemeris_flags;
        uint8_t m_correction_flags;
        gnss_t::gnss_signal_t* m_sid;
        telemetry_t* m__root;
        telemetry_t::msg_tel_sv_t* m__parent;

    public:

        /**
         * Azimuth angle (range 0..179)
         */
        uint8_t az() const { return m_az; }

        /**
         * Elevation angle (range -90..90)
         */
        int8_t el() const { return m_el; }

        /**
         * Observation availability at filter update
         */
        uint8_t availability_flags() const { return m_availability_flags; }

        /**
         * Pseudorange observation residual
         */
        int16_t pseudorange_residual() const { return m_pseudorange_residual; }

        /**
         * Carrier-phase or carrier-phase-derived observation residual
         */
        int16_t phase_residual() const { return m_phase_residual; }

        /**
         * Reports if observation is marked as an outlier and is excluded from
         * the update
         */
        uint8_t outlier_flags() const { return m_outlier_flags; }

        /**
         * Ephemeris metadata
         */
        uint8_t ephemeris_flags() const { return m_ephemeris_flags; }

        /**
         * Reserved
         */
        uint8_t correction_flags() const { return m_correction_flags; }

        /**
         * GNSS signal identifier (16 bit)
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }
        telemetry_t* _root() const { return m__root; }
        telemetry_t::msg_tel_sv_t* _parent() const { return m__parent; }
    };

    /**
     * This message includes telemetry pertinent to satellite signals available
     * to Starling.
     */

    class msg_tel_sv_t : public kaitai::kstruct {

    public:

        msg_tel_sv_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, telemetry_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_tel_sv_t();

    private:
        uint16_t m_wn;
        uint32_t m_tow;
        uint8_t m_n_obs;
        uint8_t m_origin_flags;
        std::vector<telemetry_sv_t*>* m_sv_tel;
        telemetry_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * GPS week number
         */
        uint16_t wn() const { return m_wn; }

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Total number of observations. First nibble is the size of the
         * sequence (n), second nibble is the zero-indexed counter (ith packet
         * of n)
         */
        uint8_t n_obs() const { return m_n_obs; }

        /**
         * Flags to identify the filter type from which the telemetry is
         * reported from
         */
        uint8_t origin_flags() const { return m_origin_flags; }

        /**
         * Array of per-signal telemetry entries
         */
        std::vector<telemetry_sv_t*>* sv_tel() const { return m_sv_tel; }
        telemetry_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

private:
    telemetry_t* m__root;
    kaitai::kstruct* m__parent;

public:
    telemetry_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // TELEMETRY_H_
