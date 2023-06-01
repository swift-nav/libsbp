#ifndef TRACKING_H_
#define TRACKING_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class tracking_t : public kaitai::kstruct {

public:
    class msg_tracking_state_detailed_dep_t;
    class tracking_channel_state_dep_b_t;
    class tracking_channel_state_t;
    class msg_tracking_state_t;
    class tracking_channel_state_dep_a_t;
    class msg_tracking_iq_dep_a_t;
    class tracking_channel_correlation_dep_t;
    class msg_tracking_state_dep_a_t;
    class msg_measurement_state_t;
    class tracking_channel_correlation_t;
    class msg_tracking_iq_t;
    class msg_tracking_state_detailed_dep_a_t;
    class msg_tracking_state_dep_b_t;
    class measurement_state_t;
    class msg_tracking_iq_dep_b_t;

    tracking_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, tracking_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~tracking_t();

    /**
     * Deprecated.
     */

    class msg_tracking_state_detailed_dep_t : public kaitai::kstruct {

    public:

        msg_tracking_state_detailed_dep_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_tracking_state_detailed_dep_t();

    private:
        uint64_t m_recv_time;
        gnss_t::gps_time_dep_t* m_tot;
        uint32_t m_p;
        uint16_t m_p_std;
        gnss_t::carrier_phase_t* m_l;
        uint8_t m_cn0;
        uint16_t m_lock;
        gnss_t::gnss_signal_dep_t* m_sid;
        int32_t m_doppler;
        uint16_t m_doppler_std;
        uint32_t m_uptime;
        int16_t m_clock_offset;
        int16_t m_clock_drift;
        uint16_t m_corr_spacing;
        int8_t m_acceleration;
        uint8_t m_sync_flags;
        uint8_t m_tow_flags;
        uint8_t m_track_flags;
        uint8_t m_nav_flags;
        uint8_t m_pset_flags;
        uint8_t m_misc_flags;
        tracking_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Receiver clock time.
         */
        uint64_t recv_time() const { return m_recv_time; }

        /**
         * Time of transmission of signal from satellite. TOW only valid when
         * TOW status is decoded or propagated. WN only valid when week number
         * valid flag is set.
         */
        gnss_t::gps_time_dep_t* tot() const { return m_tot; }

        /**
         * Pseudorange observation. Valid only when pseudorange valid flag is
         * set.
         */
        uint32_t p() const { return m_p; }

        /**
         * Pseudorange observation standard deviation. Valid only when
         * pseudorange valid flag is set.
         */
        uint16_t p_std() const { return m_p_std; }

        /**
         * Carrier phase observation with typical sign convention. Valid only
         * when PLL pessimistic lock is achieved.
         */
        gnss_t::carrier_phase_t* l() const { return m_l; }

        /**
         * Carrier-to-Noise density
         */
        uint8_t cn0() const { return m_cn0; }

        /**
         * Lock time. It is encoded according to DF402 from the RTCM 10403.2
         * Amendment 2 specification. Valid values range from 0 to 15.
         */
        uint16_t lock() const { return m_lock; }

        /**
         * GNSS signal identifier.
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }

        /**
         * Carrier Doppler frequency.
         */
        int32_t doppler() const { return m_doppler; }

        /**
         * Carrier Doppler frequency standard deviation.
         */
        uint16_t doppler_std() const { return m_doppler_std; }

        /**
         * Number of seconds of continuous tracking. Specifies how much time
         * signal is in continuous track.
         */
        uint32_t uptime() const { return m_uptime; }

        /**
         * TCXO clock offset. Valid only when valid clock valid flag is set.
         */
        int16_t clock_offset() const { return m_clock_offset; }

        /**
         * TCXO clock drift. Valid only when valid clock valid flag is set.
         */
        int16_t clock_drift() const { return m_clock_drift; }

        /**
         * Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
         */
        uint16_t corr_spacing() const { return m_corr_spacing; }

        /**
         * Acceleration. Valid only when acceleration valid flag is set.
         */
        int8_t acceleration() const { return m_acceleration; }

        /**
         * Synchronization status flags.
         */
        uint8_t sync_flags() const { return m_sync_flags; }

        /**
         * TOW status flags.
         */
        uint8_t tow_flags() const { return m_tow_flags; }

        /**
         * Tracking loop status flags.
         */
        uint8_t track_flags() const { return m_track_flags; }

        /**
         * Navigation data status flags.
         */
        uint8_t nav_flags() const { return m_nav_flags; }

        /**
         * Parameters sets flags.
         */
        uint8_t pset_flags() const { return m_pset_flags; }

        /**
         * Miscellaneous flags.
         */
        uint8_t misc_flags() const { return m_misc_flags; }
        tracking_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class tracking_channel_state_dep_b_t : public kaitai::kstruct {

    public:

        tracking_channel_state_dep_b_t(kaitai::kstream* p__io, tracking_t::msg_tracking_state_dep_b_t* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~tracking_channel_state_dep_b_t();

    private:
        uint8_t m_state;
        gnss_t::gnss_signal_dep_t* m_sid;
        float m_cn0;
        tracking_t* m__root;
        tracking_t::msg_tracking_state_dep_b_t* m__parent;

    public:

        /**
         * Status of tracking channel
         */
        uint8_t state() const { return m_state; }

        /**
         * GNSS signal being tracked
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }

        /**
         * Carrier-to-noise density
         */
        float cn0() const { return m_cn0; }
        tracking_t* _root() const { return m__root; }
        tracking_t::msg_tracking_state_dep_b_t* _parent() const { return m__parent; }
    };

    /**
     * Tracking channel state for a specific satellite signal and measured
     * signal power.
     */

    class tracking_channel_state_t : public kaitai::kstruct {

    public:

        tracking_channel_state_t(kaitai::kstream* p__io, tracking_t::msg_tracking_state_t* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~tracking_channel_state_t();

    private:
        gnss_t::gnss_signal_t* m_sid;
        uint8_t m_fcn;
        uint8_t m_cn0;
        tracking_t* m__root;
        tracking_t::msg_tracking_state_t* m__parent;

    public:

        /**
         * GNSS signal being tracked
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Frequency channel number (GLONASS only)
         */
        uint8_t fcn() const { return m_fcn; }

        /**
         * Carrier-to-Noise density.  Zero implies invalid cn0.
         */
        uint8_t cn0() const { return m_cn0; }
        tracking_t* _root() const { return m__root; }
        tracking_t::msg_tracking_state_t* _parent() const { return m__parent; }
    };

    /**
     * The tracking message returns a variable-length array of tracking channel
     * states. It reports status and carrier-to-noise density measurements for
     * all tracked satellites.
     */

    class msg_tracking_state_t : public kaitai::kstruct {

    public:

        msg_tracking_state_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_tracking_state_t();

    private:
        std::vector<tracking_channel_state_t*>* m_states;
        tracking_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Signal tracking channel state
         */
        std::vector<tracking_channel_state_t*>* states() const { return m_states; }
        tracking_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class tracking_channel_state_dep_a_t : public kaitai::kstruct {

    public:

        tracking_channel_state_dep_a_t(kaitai::kstream* p__io, tracking_t::msg_tracking_state_dep_a_t* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~tracking_channel_state_dep_a_t();

    private:
        uint8_t m_state;
        uint8_t m_prn;
        float m_cn0;
        tracking_t* m__root;
        tracking_t::msg_tracking_state_dep_a_t* m__parent;

    public:

        /**
         * Status of tracking channel
         */
        uint8_t state() const { return m_state; }

        /**
         * PRN-1 being tracked
         */
        uint8_t prn() const { return m_prn; }

        /**
         * Carrier-to-noise density
         */
        float cn0() const { return m_cn0; }
        tracking_t* _root() const { return m__root; }
        tracking_t::msg_tracking_state_dep_a_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_tracking_iq_dep_a_t : public kaitai::kstruct {

    public:

        msg_tracking_iq_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_tracking_iq_dep_a_t();

    private:
        uint8_t m_channel;
        gnss_t::gnss_signal_dep_t* m_sid;
        std::vector<uint64_t>* m_corrs;
        tracking_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Tracking channel of origin
         */
        uint8_t channel() const { return m_channel; }

        /**
         * GNSS signal identifier
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }

        /**
         * Early, Prompt and Late correlations
         */
        std::vector<uint64_t>* corrs() const { return m_corrs; }
        tracking_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Structure containing in-phase and quadrature correlation components.
     */

    class tracking_channel_correlation_dep_t : public kaitai::kstruct {

    public:

        tracking_channel_correlation_dep_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~tracking_channel_correlation_dep_t();

    private:
        int32_t m_i;
        int32_t m_q;
        tracking_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * In-phase correlation
         */
        int32_t i() const { return m_i; }

        /**
         * Quadrature correlation
         */
        int32_t q() const { return m_q; }
        tracking_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_tracking_state_dep_a_t : public kaitai::kstruct {

    public:

        msg_tracking_state_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_tracking_state_dep_a_t();

    private:
        std::vector<tracking_channel_state_dep_a_t*>* m_states;
        tracking_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Satellite tracking channel state
         */
        std::vector<tracking_channel_state_dep_a_t*>* states() const { return m_states; }
        tracking_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The tracking message returns a variable-length array of tracking channel
     * states. It reports status and carrier-to-noise density measurements for
     * all tracked satellites.
     */

    class msg_measurement_state_t : public kaitai::kstruct {

    public:

        msg_measurement_state_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_measurement_state_t();

    private:
        std::vector<measurement_state_t*>* m_states;
        tracking_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * ME signal tracking channel state
         */
        std::vector<measurement_state_t*>* states() const { return m_states; }
        tracking_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Structure containing in-phase and quadrature correlation components.
     */

    class tracking_channel_correlation_t : public kaitai::kstruct {

    public:

        tracking_channel_correlation_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~tracking_channel_correlation_t();

    private:
        int16_t m_i;
        int16_t m_q;
        tracking_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * In-phase correlation
         */
        int16_t i() const { return m_i; }

        /**
         * Quadrature correlation
         */
        int16_t q() const { return m_q; }
        tracking_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * When enabled, a tracking channel can output the correlations at each
     * update interval.
     */

    class msg_tracking_iq_t : public kaitai::kstruct {

    public:

        msg_tracking_iq_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_tracking_iq_t();

    private:
        uint8_t m_channel;
        gnss_t::gnss_signal_t* m_sid;
        std::vector<uint64_t>* m_corrs;
        tracking_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Tracking channel of origin
         */
        uint8_t channel() const { return m_channel; }

        /**
         * GNSS signal identifier
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Early, Prompt and Late correlations
         */
        std::vector<uint64_t>* corrs() const { return m_corrs; }
        tracking_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The tracking message returns a set tracking channel parameters for a
     * single tracking channel useful for debugging issues.
     */

    class msg_tracking_state_detailed_dep_a_t : public kaitai::kstruct {

    public:

        msg_tracking_state_detailed_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_tracking_state_detailed_dep_a_t();

    private:
        uint64_t m_recv_time;
        gnss_t::gps_time_t* m_tot;
        uint32_t m_p;
        uint16_t m_p_std;
        gnss_t::carrier_phase_t* m_l;
        uint8_t m_cn0;
        uint16_t m_lock;
        gnss_t::gnss_signal_t* m_sid;
        int32_t m_doppler;
        uint16_t m_doppler_std;
        uint32_t m_uptime;
        int16_t m_clock_offset;
        int16_t m_clock_drift;
        uint16_t m_corr_spacing;
        int8_t m_acceleration;
        uint8_t m_sync_flags;
        uint8_t m_tow_flags;
        uint8_t m_track_flags;
        uint8_t m_nav_flags;
        uint8_t m_pset_flags;
        uint8_t m_misc_flags;
        tracking_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Receiver clock time.
         */
        uint64_t recv_time() const { return m_recv_time; }

        /**
         * Time of transmission of signal from satellite. TOW only valid when
         * TOW status is decoded or propagated. WN only valid when week number
         * valid flag is set.
         */
        gnss_t::gps_time_t* tot() const { return m_tot; }

        /**
         * Pseudorange observation. Valid only when pseudorange valid flag is
         * set.
         */
        uint32_t p() const { return m_p; }

        /**
         * Pseudorange observation standard deviation. Valid only when
         * pseudorange valid flag is set.
         */
        uint16_t p_std() const { return m_p_std; }

        /**
         * Carrier phase observation with typical sign convention. Valid only
         * when PLL pessimistic lock is achieved.
         */
        gnss_t::carrier_phase_t* l() const { return m_l; }

        /**
         * Carrier-to-Noise density
         */
        uint8_t cn0() const { return m_cn0; }

        /**
         * Lock time. It is encoded according to DF402 from the RTCM 10403.2
         * Amendment 2 specification. Valid values range from 0 to 15.
         */
        uint16_t lock() const { return m_lock; }

        /**
         * GNSS signal identifier.
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Carrier Doppler frequency.
         */
        int32_t doppler() const { return m_doppler; }

        /**
         * Carrier Doppler frequency standard deviation.
         */
        uint16_t doppler_std() const { return m_doppler_std; }

        /**
         * Number of seconds of continuous tracking. Specifies how much time
         * signal is in continuous track.
         */
        uint32_t uptime() const { return m_uptime; }

        /**
         * TCXO clock offset. Valid only when valid clock valid flag is set.
         */
        int16_t clock_offset() const { return m_clock_offset; }

        /**
         * TCXO clock drift. Valid only when valid clock valid flag is set.
         */
        int16_t clock_drift() const { return m_clock_drift; }

        /**
         * Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
         */
        uint16_t corr_spacing() const { return m_corr_spacing; }

        /**
         * Acceleration. Valid only when acceleration valid flag is set.
         */
        int8_t acceleration() const { return m_acceleration; }

        /**
         * Synchronization status flags.
         */
        uint8_t sync_flags() const { return m_sync_flags; }

        /**
         * TOW status flags.
         */
        uint8_t tow_flags() const { return m_tow_flags; }

        /**
         * Tracking loop status flags.
         */
        uint8_t track_flags() const { return m_track_flags; }

        /**
         * Navigation data status flags.
         */
        uint8_t nav_flags() const { return m_nav_flags; }

        /**
         * Parameters sets flags.
         */
        uint8_t pset_flags() const { return m_pset_flags; }

        /**
         * Miscellaneous flags.
         */
        uint8_t misc_flags() const { return m_misc_flags; }
        tracking_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_tracking_state_dep_b_t : public kaitai::kstruct {

    public:

        msg_tracking_state_dep_b_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_tracking_state_dep_b_t();

    private:
        std::vector<tracking_channel_state_dep_b_t*>* m_states;
        tracking_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Signal tracking channel state
         */
        std::vector<tracking_channel_state_dep_b_t*>* states() const { return m_states; }
        tracking_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Measurement Engine tracking channel state for a specific satellite
     * signal and measured signal power. The mesid field for Glonass can either
     * carry the FCN as 100 + FCN where FCN is in [-7, +6] or the Slot ID (from
     * 1 to 28).
     */

    class measurement_state_t : public kaitai::kstruct {

    public:

        measurement_state_t(kaitai::kstream* p__io, tracking_t::msg_measurement_state_t* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~measurement_state_t();

    private:
        gnss_t::gnss_signal_t* m_mesid;
        uint8_t m_cn0;
        tracking_t* m__root;
        tracking_t::msg_measurement_state_t* m__parent;

    public:

        /**
         * Measurement Engine GNSS signal being tracked (carries either Glonass
         * FCN or SLOT)
         */
        gnss_t::gnss_signal_t* mesid() const { return m_mesid; }

        /**
         * Carrier-to-Noise density.  Zero implies invalid cn0.
         */
        uint8_t cn0() const { return m_cn0; }
        tracking_t* _root() const { return m__root; }
        tracking_t::msg_measurement_state_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_tracking_iq_dep_b_t : public kaitai::kstruct {

    public:

        msg_tracking_iq_dep_b_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, tracking_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_tracking_iq_dep_b_t();

    private:
        uint8_t m_channel;
        gnss_t::gnss_signal_t* m_sid;
        std::vector<uint64_t>* m_corrs;
        tracking_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Tracking channel of origin
         */
        uint8_t channel() const { return m_channel; }

        /**
         * GNSS signal identifier
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Early, Prompt and Late correlations
         */
        std::vector<uint64_t>* corrs() const { return m_corrs; }
        tracking_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

private:
    tracking_t* m__root;
    kaitai::kstruct* m__parent;

public:
    tracking_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // TRACKING_H_
