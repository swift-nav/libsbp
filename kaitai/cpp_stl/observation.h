#ifndef OBSERVATION_H_
#define OBSERVATION_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class observation_t : public kaitai::kstruct {

public:
    class msg_sv_az_el_t;
    class gnss_capb_t;
    class msg_group_delay_dep_b_t;
    class observation_header_dep_t;
    class almanac_common_content_dep_t;
    class ephemeris_common_content_dep_a_t;
    class ephemeris_common_content_t;
    class packed_obs_content_dep_c_t;
    class msg_ephemeris_glo_dep_d_t;
    class msg_obs_dep_a_t;
    class msg_ephemeris_dep_b_t;
    class msg_obs_t;
    class doppler_t;
    class msg_almanac_glo_dep_t;
    class msg_almanac_gps_dep_t;
    class sv_az_el_t;
    class msg_glo_biases_t;
    class msg_ephemeris_sbas_dep_b_t;
    class msg_ephemeris_gps_dep_e_t;
    class msg_gnss_capb_t;
    class msg_almanac_gps_t;
    class msg_ephemeris_qzss_t;
    class msg_group_delay_dep_a_t;
    class msg_ephemeris_dep_c_t;
    class carrier_phase_dep_a_t;
    class msg_ephemeris_gal_t;
    class packed_osr_content_t;
    class msg_ephemeris_bds_t;
    class msg_ephemeris_gps_dep_f_t;
    class observation_header_t;
    class msg_ephemeris_sbas_dep_a_t;
    class packed_obs_content_t;
    class msg_base_pos_ecef_t;
    class msg_ephemeris_glo_dep_a_t;
    class msg_group_delay_t;
    class msg_almanac_glo_t;
    class msg_ephemeris_gal_dep_a_t;
    class msg_obs_dep_b_t;
    class packed_obs_content_dep_a_t;
    class msg_ephemeris_glo_t;
    class msg_iono_t;
    class msg_ephemeris_dep_d_t;
    class msg_ephemeris_gps_t;
    class msg_base_pos_llh_t;
    class almanac_common_content_t;
    class msg_osr_t;
    class msg_ephemeris_glo_dep_c_t;
    class msg_ephemeris_glo_dep_b_t;
    class msg_sv_configuration_gps_dep_t;
    class msg_ephemeris_sbas_t;
    class packed_obs_content_dep_b_t;
    class msg_obs_dep_c_t;
    class msg_ephemeris_dep_a_t;
    class ephemeris_common_content_dep_b_t;

    observation_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, observation_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~observation_t();

    /**
     * Azimuth and elevation angles of all the visible satellites that the
     * device does have ephemeris or almanac for.
     */

    class msg_sv_az_el_t : public kaitai::kstruct {

    public:

        msg_sv_az_el_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_sv_az_el_t();

    private:
        std::vector<sv_az_el_t*>* m_azel;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Azimuth and elevation per satellite
         */
        std::vector<sv_az_el_t*>* azel() const { return m_azel; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    class gnss_capb_t : public kaitai::kstruct {

    public:

        gnss_capb_t(kaitai::kstream* p__io, observation_t::msg_gnss_capb_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~gnss_capb_t();

    private:
        uint64_t m_gps_active;
        uint64_t m_gps_l2c;
        uint64_t m_gps_l5;
        uint32_t m_glo_active;
        uint32_t m_glo_l2of;
        uint32_t m_glo_l3;
        uint64_t m_sbas_active;
        uint64_t m_sbas_l5;
        uint64_t m_bds_active;
        uint64_t m_bds_d2nav;
        uint64_t m_bds_b2;
        uint64_t m_bds_b2a;
        uint32_t m_qzss_active;
        uint64_t m_gal_active;
        uint64_t m_gal_e5;
        observation_t* m__root;
        observation_t::msg_gnss_capb_t* m__parent;

    public:

        /**
         * GPS SV active mask
         */
        uint64_t gps_active() const { return m_gps_active; }

        /**
         * GPS L2C active mask
         */
        uint64_t gps_l2c() const { return m_gps_l2c; }

        /**
         * GPS L5 active mask
         */
        uint64_t gps_l5() const { return m_gps_l5; }

        /**
         * GLO active mask
         */
        uint32_t glo_active() const { return m_glo_active; }

        /**
         * GLO L2OF active mask
         */
        uint32_t glo_l2of() const { return m_glo_l2of; }

        /**
         * GLO L3 active mask
         */
        uint32_t glo_l3() const { return m_glo_l3; }

        /**
         * SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
         * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
         */
        uint64_t sbas_active() const { return m_sbas_active; }

        /**
         * SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
         * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
         */
        uint64_t sbas_l5() const { return m_sbas_l5; }

        /**
         * BDS active mask
         */
        uint64_t bds_active() const { return m_bds_active; }

        /**
         * BDS D2NAV active mask
         */
        uint64_t bds_d2nav() const { return m_bds_d2nav; }

        /**
         * BDS B2 active mask
         */
        uint64_t bds_b2() const { return m_bds_b2; }

        /**
         * BDS B2A active mask
         */
        uint64_t bds_b2a() const { return m_bds_b2a; }

        /**
         * QZSS active mask
         */
        uint32_t qzss_active() const { return m_qzss_active; }

        /**
         * GAL active mask
         */
        uint64_t gal_active() const { return m_gal_active; }

        /**
         * GAL E5 active mask
         */
        uint64_t gal_e5() const { return m_gal_e5; }
        observation_t* _root() const { return m__root; }
        observation_t::msg_gnss_capb_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_group_delay_dep_b_t : public kaitai::kstruct {

    public:

        msg_group_delay_dep_b_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_group_delay_dep_b_t();

    private:
        gnss_t::gps_time_sec_t* m_t_op;
        gnss_t::gnss_signal_dep_t* m_sid;
        uint8_t m_valid;
        int16_t m_tgd;
        int16_t m_isc_l1ca;
        int16_t m_isc_l2c;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Data Predict Time of Week
         */
        gnss_t::gps_time_sec_t* t_op() const { return m_t_op; }

        /**
         * GNSS signal identifier
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }

        /**
         * bit-field indicating validity of the values, LSB indicating tgd
         * validity etc. 1 = value is valid, 0 = value is not valid.
         */
        uint8_t valid() const { return m_valid; }
        int16_t tgd() const { return m_tgd; }
        int16_t isc_l1ca() const { return m_isc_l1ca; }
        int16_t isc_l2c() const { return m_isc_l2c; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Header of a GPS observation message.
     */

    class observation_header_dep_t : public kaitai::kstruct {

    public:

        observation_header_dep_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~observation_header_dep_t();

    private:
        gnss_t::gps_time_dep_t* m_t;
        uint8_t m_n_obs;
        observation_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * GPS time of this observation
         */
        gnss_t::gps_time_dep_t* t() const { return m_t; }

        /**
         * Total number of observations. First nibble is the size of the
         * sequence (n), second nibble is the zero-indexed counter (ith packet
         * of n)
         */
        uint8_t n_obs() const { return m_n_obs; }
        observation_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class almanac_common_content_dep_t : public kaitai::kstruct {

    public:

        almanac_common_content_dep_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~almanac_common_content_dep_t();

    private:
        gnss_t::gnss_signal_dep_t* m_sid;
        gnss_t::gps_time_sec_t* m_toa;
        double m_ura;
        uint32_t m_fit_interval;
        uint8_t m_valid;
        uint8_t m_health_bits;
        observation_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * GNSS signal identifier
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }

        /**
         * Reference time of almanac
         */
        gnss_t::gps_time_sec_t* toa() const { return m_toa; }

        /**
         * User Range Accuracy
         */
        double ura() const { return m_ura; }

        /**
         * Curve fit interval
         */
        uint32_t fit_interval() const { return m_fit_interval; }

        /**
         * Status of almanac, 1 = valid, 0 = invalid
         */
        uint8_t valid() const { return m_valid; }

        /**
         * Satellite health status for GPS:
         *   - bits 5-7: NAV data health status. See IS-GPS-200H
         *     Table 20-VII: NAV Data Health Indications.
         *   - bits 0-4: Signal health status. See IS-GPS-200H
         *     Table 20-VIII. Codes for Health of SV Signal
         *     Components.
         * Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
         * details):
         *   - bit 0: C(n), "unhealthy" flag that is transmitted within
         *     non-immediate data and indicates overall constellation status
         *     at the moment of almanac uploading.
         *     '0' indicates malfunction of n-satellite.
         *     '1' indicates that n-satellite is operational.
         *   - bit 1: Bn(ln), '0' indicates the satellite is operational
         *     and suitable for navigation.
         */
        uint8_t health_bits() const { return m_health_bits; }
        observation_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class ephemeris_common_content_dep_a_t : public kaitai::kstruct {

    public:

        ephemeris_common_content_dep_a_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~ephemeris_common_content_dep_a_t();

    private:
        gnss_t::gnss_signal_dep_t* m_sid;
        gnss_t::gps_time_dep_t* m_toe;
        double m_ura;
        uint32_t m_fit_interval;
        uint8_t m_valid;
        uint8_t m_health_bits;
        observation_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * GNSS signal identifier
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }

        /**
         * Time of Ephemerides
         */
        gnss_t::gps_time_dep_t* toe() const { return m_toe; }

        /**
         * User Range Accuracy
         */
        double ura() const { return m_ura; }

        /**
         * Curve fit interval
         */
        uint32_t fit_interval() const { return m_fit_interval; }

        /**
         * Status of ephemeris, 1 = valid, 0 = invalid
         */
        uint8_t valid() const { return m_valid; }

        /**
         * Satellite health status.
         * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
         * SBAS: 0 = valid, non-zero = invalid
         * GLO: 0 = valid, non-zero = invalid
         */
        uint8_t health_bits() const { return m_health_bits; }
        observation_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class ephemeris_common_content_t : public kaitai::kstruct {

    public:

        ephemeris_common_content_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~ephemeris_common_content_t();

    private:
        gnss_t::gnss_signal_t* m_sid;
        gnss_t::gps_time_sec_t* m_toe;
        float m_ura;
        uint32_t m_fit_interval;
        uint8_t m_valid;
        uint8_t m_health_bits;
        observation_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * GNSS signal identifier (16 bit)
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Time of Ephemerides
         */
        gnss_t::gps_time_sec_t* toe() const { return m_toe; }

        /**
         * User Range Accuracy
         */
        float ura() const { return m_ura; }

        /**
         * Curve fit interval
         */
        uint32_t fit_interval() const { return m_fit_interval; }

        /**
         * Status of ephemeris, 1 = valid, 0 = invalid
         */
        uint8_t valid() const { return m_valid; }

        /**
         * Satellite health status.
         * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
         * SBAS: 0 = valid, non-zero = invalid
         * GLO: 0 = valid, non-zero = invalid
         */
        uint8_t health_bits() const { return m_health_bits; }
        observation_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * Pseudorange and carrier phase observation for a satellite being tracked.
     * The observations are be interoperable with 3rd party receivers and
     * conform with typical RTCMv3 GNSS observations.
     */

    class packed_obs_content_dep_c_t : public kaitai::kstruct {

    public:

        packed_obs_content_dep_c_t(kaitai::kstream* p__io, observation_t::msg_obs_dep_c_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~packed_obs_content_dep_c_t();

    private:
        uint32_t m_p;
        gnss_t::carrier_phase_t* m_l;
        uint8_t m_cn0;
        uint16_t m_lock;
        gnss_t::gnss_signal_dep_t* m_sid;
        observation_t* m__root;
        observation_t::msg_obs_dep_c_t* m__parent;

    public:

        /**
         * Pseudorange observation
         */
        uint32_t p() const { return m_p; }

        /**
         * Carrier phase observation with typical sign convention.
         */
        gnss_t::carrier_phase_t* l() const { return m_l; }

        /**
         * Carrier-to-Noise density
         */
        uint8_t cn0() const { return m_cn0; }

        /**
         * Lock indicator. This value changes whenever a satellite signal has
         * lost and regained lock, indicating that the carrier phase ambiguity
         * may have changed.
         */
        uint16_t lock() const { return m_lock; }

        /**
         * GNSS signal identifier
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }
        observation_t* _root() const { return m__root; }
        observation_t::msg_obs_dep_c_t* _parent() const { return m__parent; }
    };

    /**
     * This observation message has been deprecated in favor of ephemeris
     * message using floats for size reduction.
     */

    class msg_ephemeris_glo_dep_d_t : public kaitai::kstruct {

    public:

        msg_ephemeris_glo_dep_d_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_glo_dep_d_t();

    private:
        ephemeris_common_content_dep_b_t* m_common;
        double m_gamma;
        double m_tau;
        double m_d_tau;
        std::vector<double>* m_pos;
        std::vector<double>* m_vel;
        std::vector<double>* m_acc;
        uint8_t m_fcn;
        uint8_t m_iod;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_dep_b_t* common() const { return m_common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        double gamma() const { return m_gamma; }

        /**
         * Correction to the SV time
         */
        double tau() const { return m_tau; }

        /**
         * Equipment delay between L1 and L2
         */
        double d_tau() const { return m_d_tau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        std::vector<double>* pos() const { return m_pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        std::vector<double>* vel() const { return m_vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        std::vector<double>* acc() const { return m_acc; }

        /**
         * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
         */
        uint8_t fcn() const { return m_fcn; }

        /**
         * Issue of data. Equal to the 7 bits of the immediate data word t_b
         */
        uint8_t iod() const { return m_iod; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_obs_dep_a_t : public kaitai::kstruct {

    public:

        msg_obs_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_obs_dep_a_t();

    private:
        observation_header_dep_t* m_header;
        std::vector<packed_obs_content_dep_a_t*>* m_obs;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Header of a GPS observation message
         */
        observation_header_dep_t* header() const { return m_header; }

        /**
         * Pseudorange and carrier phase observation for a satellite being
         * tracked.
         */
        std::vector<packed_obs_content_dep_a_t*>* obs() const { return m_obs; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ephemeris_dep_b_t : public kaitai::kstruct {

    public:

        msg_ephemeris_dep_b_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_dep_b_t();

    private:
        double m_tgd;
        double m_c_rs;
        double m_c_rc;
        double m_c_uc;
        double m_c_us;
        double m_c_ic;
        double m_c_is;
        double m_dn;
        double m_m0;
        double m_ecc;
        double m_sqrta;
        double m_omega0;
        double m_omegadot;
        double m_w;
        double m_inc;
        double m_inc_dot;
        double m_af0;
        double m_af1;
        double m_af2;
        double m_toe_tow;
        uint16_t m_toe_wn;
        double m_toc_tow;
        uint16_t m_toc_wn;
        uint8_t m_valid;
        uint8_t m_healthy;
        uint8_t m_prn;
        uint8_t m_iode;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Group delay differential between L1 and L2
         */
        double tgd() const { return m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        double c_rs() const { return m_c_rs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        double c_rc() const { return m_c_rc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        double c_uc() const { return m_c_uc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        double c_us() const { return m_c_us; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        double c_ic() const { return m_c_ic; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        double c_is() const { return m_c_is; }

        /**
         * Mean motion difference
         */
        double dn() const { return m_dn; }

        /**
         * Mean anomaly at reference time
         */
        double m0() const { return m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        double ecc() const { return m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        double sqrta() const { return m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        double omega0() const { return m_omega0; }

        /**
         * Rate of right ascension
         */
        double omegadot() const { return m_omegadot; }

        /**
         * Argument of perigee
         */
        double w() const { return m_w; }

        /**
         * Inclination
         */
        double inc() const { return m_inc; }

        /**
         * Inclination first derivative
         */
        double inc_dot() const { return m_inc_dot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        double af0() const { return m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        double af1() const { return m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        double af2() const { return m_af2; }

        /**
         * Time of week
         */
        double toe_tow() const { return m_toe_tow; }

        /**
         * Week number
         */
        uint16_t toe_wn() const { return m_toe_wn; }

        /**
         * Clock reference time of week
         */
        double toc_tow() const { return m_toc_tow; }

        /**
         * Clock reference week number
         */
        uint16_t toc_wn() const { return m_toc_wn; }

        /**
         * Is valid?
         */
        uint8_t valid() const { return m_valid; }

        /**
         * Satellite is healthy?
         */
        uint8_t healthy() const { return m_healthy; }

        /**
         * PRN being tracked
         */
        uint8_t prn() const { return m_prn; }

        /**
         * Issue of ephemeris data
         */
        uint8_t iode() const { return m_iode; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The GPS observations message reports all the raw pseudorange and carrier
     * phase observations for the satellites being tracked by the device.
     * Carrier phase observation here is represented as a 40-bit fixed point
     * number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
     * fractional cycles). The observations are be interoperable with 3rd party
     * receivers and conform with typical RTCMv3 GNSS observations.
     */

    class msg_obs_t : public kaitai::kstruct {

    public:

        msg_obs_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_obs_t();

    private:
        observation_header_t* m_header;
        std::vector<packed_obs_content_t*>* m_obs;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Header of a GPS observation message
         */
        observation_header_t* header() const { return m_header; }

        /**
         * Pseudorange and carrier phase observation for a satellite being
         * tracked.
         */
        std::vector<packed_obs_content_t*>* obs() const { return m_obs; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Doppler measurement in Hz represented as a 24-bit fixed point number
     * with Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of
     * fractional doppler. This doppler is defined as positive for approaching
     * satellites.
     */

    class doppler_t : public kaitai::kstruct {

    public:

        doppler_t(kaitai::kstream* p__io, observation_t::packed_obs_content_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~doppler_t();

    private:
        int16_t m_i;
        uint8_t m_f;
        observation_t* m__root;
        observation_t::packed_obs_content_t* m__parent;

    public:

        /**
         * Doppler whole Hz
         */
        int16_t i() const { return m_i; }

        /**
         * Doppler fractional part
         */
        uint8_t f() const { return m_f; }
        observation_t* _root() const { return m__root; }
        observation_t::packed_obs_content_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_almanac_glo_dep_t : public kaitai::kstruct {

    public:

        msg_almanac_glo_dep_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_almanac_glo_dep_t();

    private:
        almanac_common_content_dep_t* m_common;
        double m_lambda_na;
        double m_t_lambda_na;
        double m_i;
        double m_t;
        double m_t_dot;
        double m_epsilon;
        double m_omega;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all almanac types
         */
        almanac_common_content_dep_t* common() const { return m_common; }

        /**
         * Longitude of the first ascending node of the orbit in PZ-90.02
         * coordinate system
         */
        double lambda_na() const { return m_lambda_na; }

        /**
         * Time of the first ascending node passage
         */
        double t_lambda_na() const { return m_t_lambda_na; }

        /**
         * Value of inclination at instant of t_lambda
         */
        double i() const { return m_i; }

        /**
         * Value of Draconian period at instant of t_lambda
         */
        double t() const { return m_t; }

        /**
         * Rate of change of the Draconian period
         */
        double t_dot() const { return m_t_dot; }

        /**
         * Eccentricity at instant of t_lambda
         */
        double epsilon() const { return m_epsilon; }

        /**
         * Argument of perigee at instant of t_lambda
         */
        double omega() const { return m_omega; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_almanac_gps_dep_t : public kaitai::kstruct {

    public:

        msg_almanac_gps_dep_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_almanac_gps_dep_t();

    private:
        almanac_common_content_dep_t* m_common;
        double m_m0;
        double m_ecc;
        double m_sqrta;
        double m_omega0;
        double m_omegadot;
        double m_w;
        double m_inc;
        double m_af0;
        double m_af1;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all almanac types
         */
        almanac_common_content_dep_t* common() const { return m_common; }

        /**
         * Mean anomaly at reference time
         */
        double m0() const { return m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        double ecc() const { return m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        double sqrta() const { return m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        double omega0() const { return m_omega0; }

        /**
         * Rate of right ascension
         */
        double omegadot() const { return m_omegadot; }

        /**
         * Argument of perigee
         */
        double w() const { return m_w; }

        /**
         * Inclination
         */
        double inc() const { return m_inc; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        double af0() const { return m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        double af1() const { return m_af1; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Satellite azimuth and elevation.
     */

    class sv_az_el_t : public kaitai::kstruct {

    public:

        sv_az_el_t(kaitai::kstream* p__io, observation_t::msg_sv_az_el_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sv_az_el_t();

    private:
        gnss_t::gnss_signal_t* m_sid;
        uint8_t m_az;
        int8_t m_el;
        observation_t* m__root;
        observation_t::msg_sv_az_el_t* m__parent;

    public:

        /**
         * GNSS signal identifier
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Azimuth angle (range 0..179)
         */
        uint8_t az() const { return m_az; }

        /**
         * Elevation angle (range -90..90)
         */
        int8_t el() const { return m_el; }
        observation_t* _root() const { return m__root; }
        observation_t::msg_sv_az_el_t* _parent() const { return m__parent; }
    };

    /**
     * The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS
     * integer ambiguity resolution for baselines with mixed receiver types
     * (e.g. receiver of different manufacturers).
     */

    class msg_glo_biases_t : public kaitai::kstruct {

    public:

        msg_glo_biases_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_glo_biases_t();

    private:
        uint8_t m_mask;
        int16_t m_l1ca_bias;
        int16_t m_l1p_bias;
        int16_t m_l2ca_bias;
        int16_t m_l2p_bias;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * GLONASS FDMA signals mask
         */
        uint8_t mask() const { return m_mask; }

        /**
         * GLONASS L1 C/A Code-Phase Bias
         */
        int16_t l1ca_bias() const { return m_l1ca_bias; }

        /**
         * GLONASS L1 P Code-Phase Bias
         */
        int16_t l1p_bias() const { return m_l1p_bias; }

        /**
         * GLONASS L2 C/A Code-Phase Bias
         */
        int16_t l2ca_bias() const { return m_l2ca_bias; }

        /**
         * GLONASS L2 P Code-Phase Bias
         */
        int16_t l2p_bias() const { return m_l2p_bias; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ephemeris_sbas_dep_b_t : public kaitai::kstruct {

    public:

        msg_ephemeris_sbas_dep_b_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_sbas_dep_b_t();

    private:
        ephemeris_common_content_dep_b_t* m_common;
        std::vector<double>* m_pos;
        std::vector<double>* m_vel;
        std::vector<double>* m_acc;
        double m_a_gf0;
        double m_a_gf1;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_dep_b_t* common() const { return m_common; }

        /**
         * Position of the GEO at time toe
         */
        std::vector<double>* pos() const { return m_pos; }

        /**
         * Velocity of the GEO at time toe
         */
        std::vector<double>* vel() const { return m_vel; }

        /**
         * Acceleration of the GEO at time toe
         */
        std::vector<double>* acc() const { return m_acc; }

        /**
         * Time offset of the GEO clock w.r.t. SBAS Network Time
         */
        double a_gf0() const { return m_a_gf0; }

        /**
         * Drift of the GEO clock w.r.t. SBAS Network Time
         */
        double a_gf1() const { return m_a_gf1; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ephemeris_gps_dep_e_t : public kaitai::kstruct {

    public:

        msg_ephemeris_gps_dep_e_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_gps_dep_e_t();

    private:
        ephemeris_common_content_dep_a_t* m_common;
        double m_tgd;
        double m_c_rs;
        double m_c_rc;
        double m_c_uc;
        double m_c_us;
        double m_c_ic;
        double m_c_is;
        double m_dn;
        double m_m0;
        double m_ecc;
        double m_sqrta;
        double m_omega0;
        double m_omegadot;
        double m_w;
        double m_inc;
        double m_inc_dot;
        double m_af0;
        double m_af1;
        double m_af2;
        gnss_t::gps_time_dep_t* m_toc;
        uint8_t m_iode;
        uint16_t m_iodc;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_dep_a_t* common() const { return m_common; }

        /**
         * Group delay differential between L1 and L2
         */
        double tgd() const { return m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        double c_rs() const { return m_c_rs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        double c_rc() const { return m_c_rc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        double c_uc() const { return m_c_uc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        double c_us() const { return m_c_us; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        double c_ic() const { return m_c_ic; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        double c_is() const { return m_c_is; }

        /**
         * Mean motion difference
         */
        double dn() const { return m_dn; }

        /**
         * Mean anomaly at reference time
         */
        double m0() const { return m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        double ecc() const { return m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        double sqrta() const { return m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        double omega0() const { return m_omega0; }

        /**
         * Rate of right ascension
         */
        double omegadot() const { return m_omegadot; }

        /**
         * Argument of perigee
         */
        double w() const { return m_w; }

        /**
         * Inclination
         */
        double inc() const { return m_inc; }

        /**
         * Inclination first derivative
         */
        double inc_dot() const { return m_inc_dot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        double af0() const { return m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        double af1() const { return m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        double af2() const { return m_af2; }

        /**
         * Clock reference
         */
        gnss_t::gps_time_dep_t* toc() const { return m_toc; }

        /**
         * Issue of ephemeris data
         */
        uint8_t iode() const { return m_iode; }

        /**
         * Issue of clock data
         */
        uint16_t iodc() const { return m_iodc; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Bit masks of signal capabilities for each GNSS satellite PRN.
     * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
     */

    class msg_gnss_capb_t : public kaitai::kstruct {

    public:

        msg_gnss_capb_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_gnss_capb_t();

    private:
        gnss_t::gps_time_sec_t* m_t_nmct;
        gnss_capb_t* m_gc;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Navigation Message Correction Table Validity Time
         */
        gnss_t::gps_time_sec_t* t_nmct() const { return m_t_nmct; }

        /**
         * GNSS capabilities masks
         */
        gnss_capb_t* gc() const { return m_gc; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The almanac message returns a set of satellite orbit parameters. Almanac
     * data is not very precise and is considered valid for up to several
     * months. Please see the Navstar GPS Space Segment/Navigation user
     * interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
     * details.
     */

    class msg_almanac_gps_t : public kaitai::kstruct {

    public:

        msg_almanac_gps_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_almanac_gps_t();

    private:
        almanac_common_content_t* m_common;
        double m_m0;
        double m_ecc;
        double m_sqrta;
        double m_omega0;
        double m_omegadot;
        double m_w;
        double m_inc;
        double m_af0;
        double m_af1;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all almanac types
         */
        almanac_common_content_t* common() const { return m_common; }

        /**
         * Mean anomaly at reference time
         */
        double m0() const { return m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        double ecc() const { return m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        double sqrta() const { return m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        double omega0() const { return m_omega0; }

        /**
         * Rate of right ascension
         */
        double omegadot() const { return m_omegadot; }

        /**
         * Argument of perigee
         */
        double w() const { return m_w; }

        /**
         * Inclination
         */
        double inc() const { return m_inc; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        double af0() const { return m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        double af1() const { return m_af1; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate QZSS satellite position, velocity, and clock
     * offset.
     */

    class msg_ephemeris_qzss_t : public kaitai::kstruct {

    public:

        msg_ephemeris_qzss_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_qzss_t();

    private:
        ephemeris_common_content_t* m_common;
        float m_tgd;
        float m_c_rs;
        float m_c_rc;
        float m_c_uc;
        float m_c_us;
        float m_c_ic;
        float m_c_is;
        double m_dn;
        double m_m0;
        double m_ecc;
        double m_sqrta;
        double m_omega0;
        double m_omegadot;
        double m_w;
        double m_inc;
        double m_inc_dot;
        float m_af0;
        float m_af1;
        float m_af2;
        gnss_t::gps_time_sec_t* m_toc;
        uint8_t m_iode;
        uint16_t m_iodc;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_t* common() const { return m_common; }

        /**
         * Group delay differential between L1 and L2
         */
        float tgd() const { return m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        float c_rs() const { return m_c_rs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        float c_rc() const { return m_c_rc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        float c_uc() const { return m_c_uc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        float c_us() const { return m_c_us; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        float c_ic() const { return m_c_ic; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        float c_is() const { return m_c_is; }

        /**
         * Mean motion difference
         */
        double dn() const { return m_dn; }

        /**
         * Mean anomaly at reference time
         */
        double m0() const { return m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        double ecc() const { return m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        double sqrta() const { return m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        double omega0() const { return m_omega0; }

        /**
         * Rate of right ascension
         */
        double omegadot() const { return m_omegadot; }

        /**
         * Argument of perigee
         */
        double w() const { return m_w; }

        /**
         * Inclination
         */
        double inc() const { return m_inc; }

        /**
         * Inclination first derivative
         */
        double inc_dot() const { return m_inc_dot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        float af0() const { return m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        float af1() const { return m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        float af2() const { return m_af2; }

        /**
         * Clock reference
         */
        gnss_t::gps_time_sec_t* toc() const { return m_toc; }

        /**
         * Issue of ephemeris data
         */
        uint8_t iode() const { return m_iode; }

        /**
         * Issue of clock data
         */
        uint16_t iodc() const { return m_iodc; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_group_delay_dep_a_t : public kaitai::kstruct {

    public:

        msg_group_delay_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_group_delay_dep_a_t();

    private:
        gnss_t::gps_time_dep_t* m_t_op;
        uint8_t m_prn;
        uint8_t m_valid;
        int16_t m_tgd;
        int16_t m_isc_l1ca;
        int16_t m_isc_l2c;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Data Predict Time of Week
         */
        gnss_t::gps_time_dep_t* t_op() const { return m_t_op; }

        /**
         * Satellite number
         */
        uint8_t prn() const { return m_prn; }

        /**
         * bit-field indicating validity of the values, LSB indicating tgd
         * validity etc. 1 = value is valid, 0 = value is not valid.
         */
        uint8_t valid() const { return m_valid; }
        int16_t tgd() const { return m_tgd; }
        int16_t isc_l1ca() const { return m_isc_l1ca; }
        int16_t isc_l2c() const { return m_isc_l2c; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ephemeris_dep_c_t : public kaitai::kstruct {

    public:

        msg_ephemeris_dep_c_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_dep_c_t();

    private:
        double m_tgd;
        double m_c_rs;
        double m_c_rc;
        double m_c_uc;
        double m_c_us;
        double m_c_ic;
        double m_c_is;
        double m_dn;
        double m_m0;
        double m_ecc;
        double m_sqrta;
        double m_omega0;
        double m_omegadot;
        double m_w;
        double m_inc;
        double m_inc_dot;
        double m_af0;
        double m_af1;
        double m_af2;
        double m_toe_tow;
        uint16_t m_toe_wn;
        double m_toc_tow;
        uint16_t m_toc_wn;
        uint8_t m_valid;
        uint8_t m_healthy;
        gnss_t::gnss_signal_dep_t* m_sid;
        uint8_t m_iode;
        uint16_t m_iodc;
        uint32_t m_reserved;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Group delay differential between L1 and L2
         */
        double tgd() const { return m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        double c_rs() const { return m_c_rs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        double c_rc() const { return m_c_rc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        double c_uc() const { return m_c_uc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        double c_us() const { return m_c_us; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        double c_ic() const { return m_c_ic; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        double c_is() const { return m_c_is; }

        /**
         * Mean motion difference
         */
        double dn() const { return m_dn; }

        /**
         * Mean anomaly at reference time
         */
        double m0() const { return m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        double ecc() const { return m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        double sqrta() const { return m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        double omega0() const { return m_omega0; }

        /**
         * Rate of right ascension
         */
        double omegadot() const { return m_omegadot; }

        /**
         * Argument of perigee
         */
        double w() const { return m_w; }

        /**
         * Inclination
         */
        double inc() const { return m_inc; }

        /**
         * Inclination first derivative
         */
        double inc_dot() const { return m_inc_dot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        double af0() const { return m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        double af1() const { return m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        double af2() const { return m_af2; }

        /**
         * Time of week
         */
        double toe_tow() const { return m_toe_tow; }

        /**
         * Week number
         */
        uint16_t toe_wn() const { return m_toe_wn; }

        /**
         * Clock reference time of week
         */
        double toc_tow() const { return m_toc_tow; }

        /**
         * Clock reference week number
         */
        uint16_t toc_wn() const { return m_toc_wn; }

        /**
         * Is valid?
         */
        uint8_t valid() const { return m_valid; }

        /**
         * Satellite is healthy?
         */
        uint8_t healthy() const { return m_healthy; }

        /**
         * GNSS signal identifier
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }

        /**
         * Issue of ephemeris data
         */
        uint8_t iode() const { return m_iode; }

        /**
         * Issue of clock data
         */
        uint16_t iodc() const { return m_iodc; }

        /**
         * Reserved field
         */
        uint32_t reserved() const { return m_reserved; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Carrier phase measurement in cycles represented as a 40-bit fixed point
     * number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
     * fractional cycles. This has the opposite sign convention than a typical
     * GPS receiver and the phase has the opposite sign as the pseudorange.
     */

    class carrier_phase_dep_a_t : public kaitai::kstruct {

    public:

        carrier_phase_dep_a_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~carrier_phase_dep_a_t();

    private:
        int32_t m_i;
        uint8_t m_f;
        observation_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Carrier phase whole cycles
         */
        int32_t i() const { return m_i; }

        /**
         * Carrier phase fractional part
         */
        uint8_t f() const { return m_f; }
        observation_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate Galileo satellite position, velocity, and clock
     * offset. Please see the Signal In Space ICD OS SIS ICD, Issue 1.3,
     * December 2016 for more details.
     */

    class msg_ephemeris_gal_t : public kaitai::kstruct {

    public:

        msg_ephemeris_gal_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_gal_t();

    private:
        ephemeris_common_content_t* m_common;
        float m_bgd_e1e5a;
        float m_bgd_e1e5b;
        float m_c_rs;
        float m_c_rc;
        float m_c_uc;
        float m_c_us;
        float m_c_ic;
        float m_c_is;
        double m_dn;
        double m_m0;
        double m_ecc;
        double m_sqrta;
        double m_omega0;
        double m_omegadot;
        double m_w;
        double m_inc;
        double m_inc_dot;
        double m_af0;
        double m_af1;
        float m_af2;
        gnss_t::gps_time_sec_t* m_toc;
        uint16_t m_iode;
        uint16_t m_iodc;
        uint8_t m_source;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_t* common() const { return m_common; }

        /**
         * E1-E5a Broadcast Group Delay
         */
        float bgd_e1e5a() const { return m_bgd_e1e5a; }

        /**
         * E1-E5b Broadcast Group Delay
         */
        float bgd_e1e5b() const { return m_bgd_e1e5b; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        float c_rs() const { return m_c_rs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        float c_rc() const { return m_c_rc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        float c_uc() const { return m_c_uc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        float c_us() const { return m_c_us; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        float c_ic() const { return m_c_ic; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        float c_is() const { return m_c_is; }

        /**
         * Mean motion difference
         */
        double dn() const { return m_dn; }

        /**
         * Mean anomaly at reference time
         */
        double m0() const { return m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        double ecc() const { return m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        double sqrta() const { return m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        double omega0() const { return m_omega0; }

        /**
         * Rate of right ascension
         */
        double omegadot() const { return m_omegadot; }

        /**
         * Argument of perigee
         */
        double w() const { return m_w; }

        /**
         * Inclination
         */
        double inc() const { return m_inc; }

        /**
         * Inclination first derivative
         */
        double inc_dot() const { return m_inc_dot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        double af0() const { return m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        double af1() const { return m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        float af2() const { return m_af2; }

        /**
         * Clock reference
         */
        gnss_t::gps_time_sec_t* toc() const { return m_toc; }

        /**
         * Issue of data (IODnav)
         */
        uint16_t iode() const { return m_iode; }

        /**
         * Issue of data (IODnav). Always equal to iode
         */
        uint16_t iodc() const { return m_iodc; }

        /**
         * 0=I/NAV, 1=F/NAV
         */
        uint8_t source() const { return m_source; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Pseudorange and carrier phase network corrections for a satellite
     * signal.
     */

    class packed_osr_content_t : public kaitai::kstruct {

    public:

        packed_osr_content_t(kaitai::kstream* p__io, observation_t::msg_osr_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~packed_osr_content_t();

    private:
        uint32_t m_p;
        gnss_t::carrier_phase_t* m_l;
        uint8_t m_lock;
        uint8_t m_flags;
        gnss_t::gnss_signal_t* m_sid;
        uint16_t m_iono_std;
        uint16_t m_tropo_std;
        uint16_t m_range_std;
        observation_t* m__root;
        observation_t::msg_osr_t* m__parent;

    public:

        /**
         * Pseudorange observation
         */
        uint32_t p() const { return m_p; }

        /**
         * Carrier phase observation with typical sign convention.
         */
        gnss_t::carrier_phase_t* l() const { return m_l; }

        /**
         * Lock timer. This value gives an indication of the time for which a
         * signal has maintained continuous phase lock. Whenever a signal has
         * lost and regained lock, this value is reset to zero. It is encoded
         * according to DF402 from the RTCM 10403.2 Amendment 2 specification.
         * Valid values range from 0 to 15 and the most significant nibble is
         * reserved for future use.
         */
        uint8_t lock() const { return m_lock; }

        /**
         * Correction flags.
         */
        uint8_t flags() const { return m_flags; }

        /**
         * GNSS signal identifier (16 bit)
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Slant ionospheric correction standard deviation
         */
        uint16_t iono_std() const { return m_iono_std; }

        /**
         * Slant tropospheric correction standard deviation
         */
        uint16_t tropo_std() const { return m_tropo_std; }

        /**
         * Orbit/clock/bias correction projected on range standard deviation
         */
        uint16_t range_std() const { return m_range_std; }
        observation_t* _root() const { return m__root; }
        observation_t::msg_osr_t* _parent() const { return m__parent; }
    };

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate BDS satellite position, velocity, and clock offset.
     * Please see the BeiDou Navigation Satellite System SIS-ICD Version 2.1,
     * Table 5-9 for more details.
     */

    class msg_ephemeris_bds_t : public kaitai::kstruct {

    public:

        msg_ephemeris_bds_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_bds_t();

    private:
        ephemeris_common_content_t* m_common;
        float m_tgd1;
        float m_tgd2;
        float m_c_rs;
        float m_c_rc;
        float m_c_uc;
        float m_c_us;
        float m_c_ic;
        float m_c_is;
        double m_dn;
        double m_m0;
        double m_ecc;
        double m_sqrta;
        double m_omega0;
        double m_omegadot;
        double m_w;
        double m_inc;
        double m_inc_dot;
        double m_af0;
        float m_af1;
        float m_af2;
        gnss_t::gps_time_sec_t* m_toc;
        uint8_t m_iode;
        uint16_t m_iodc;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_t* common() const { return m_common; }

        /**
         * Group delay differential for B1
         */
        float tgd1() const { return m_tgd1; }

        /**
         * Group delay differential for B2
         */
        float tgd2() const { return m_tgd2; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        float c_rs() const { return m_c_rs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        float c_rc() const { return m_c_rc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        float c_uc() const { return m_c_uc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        float c_us() const { return m_c_us; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        float c_ic() const { return m_c_ic; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        float c_is() const { return m_c_is; }

        /**
         * Mean motion difference
         */
        double dn() const { return m_dn; }

        /**
         * Mean anomaly at reference time
         */
        double m0() const { return m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        double ecc() const { return m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        double sqrta() const { return m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        double omega0() const { return m_omega0; }

        /**
         * Rate of right ascension
         */
        double omegadot() const { return m_omegadot; }

        /**
         * Argument of perigee
         */
        double w() const { return m_w; }

        /**
         * Inclination
         */
        double inc() const { return m_inc; }

        /**
         * Inclination first derivative
         */
        double inc_dot() const { return m_inc_dot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        double af0() const { return m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        float af1() const { return m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        float af2() const { return m_af2; }

        /**
         * Clock reference
         */
        gnss_t::gps_time_sec_t* toc() const { return m_toc; }

        /**
         * Issue of ephemeris data
         * Calculated from the navigation data parameter t_oe per RTCM/CSNO
         * recommendation: IODE = mod (t_oe / 720, 240)
         */
        uint8_t iode() const { return m_iode; }

        /**
         * Issue of clock data
         * Calculated from the navigation data parameter t_oe per RTCM/CSNO
         * recommendation: IODE = mod (t_oc / 720, 240)
         */
        uint16_t iodc() const { return m_iodc; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ephemeris_gps_dep_f_t : public kaitai::kstruct {

    public:

        msg_ephemeris_gps_dep_f_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_gps_dep_f_t();

    private:
        ephemeris_common_content_dep_b_t* m_common;
        double m_tgd;
        double m_c_rs;
        double m_c_rc;
        double m_c_uc;
        double m_c_us;
        double m_c_ic;
        double m_c_is;
        double m_dn;
        double m_m0;
        double m_ecc;
        double m_sqrta;
        double m_omega0;
        double m_omegadot;
        double m_w;
        double m_inc;
        double m_inc_dot;
        double m_af0;
        double m_af1;
        double m_af2;
        gnss_t::gps_time_sec_t* m_toc;
        uint8_t m_iode;
        uint16_t m_iodc;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_dep_b_t* common() const { return m_common; }

        /**
         * Group delay differential between L1 and L2
         */
        double tgd() const { return m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        double c_rs() const { return m_c_rs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        double c_rc() const { return m_c_rc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        double c_uc() const { return m_c_uc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        double c_us() const { return m_c_us; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        double c_ic() const { return m_c_ic; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        double c_is() const { return m_c_is; }

        /**
         * Mean motion difference
         */
        double dn() const { return m_dn; }

        /**
         * Mean anomaly at reference time
         */
        double m0() const { return m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        double ecc() const { return m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        double sqrta() const { return m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        double omega0() const { return m_omega0; }

        /**
         * Rate of right ascension
         */
        double omegadot() const { return m_omegadot; }

        /**
         * Argument of perigee
         */
        double w() const { return m_w; }

        /**
         * Inclination
         */
        double inc() const { return m_inc; }

        /**
         * Inclination first derivative
         */
        double inc_dot() const { return m_inc_dot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        double af0() const { return m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        double af1() const { return m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        double af2() const { return m_af2; }

        /**
         * Clock reference
         */
        gnss_t::gps_time_sec_t* toc() const { return m_toc; }

        /**
         * Issue of ephemeris data
         */
        uint8_t iode() const { return m_iode; }

        /**
         * Issue of clock data
         */
        uint16_t iodc() const { return m_iodc; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Header of a GNSS observation message.
     */

    class observation_header_t : public kaitai::kstruct {

    public:

        observation_header_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~observation_header_t();

    private:
        gnss_t::gps_time_t* m_t;
        uint8_t m_n_obs;
        observation_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * GNSS time of this observation
         */
        gnss_t::gps_time_t* t() const { return m_t; }

        /**
         * Total number of observations. First nibble is the size of the
         * sequence (n), second nibble is the zero-indexed counter (ith packet
         * of n)
         */
        uint8_t n_obs() const { return m_n_obs; }
        observation_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ephemeris_sbas_dep_a_t : public kaitai::kstruct {

    public:

        msg_ephemeris_sbas_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_sbas_dep_a_t();

    private:
        ephemeris_common_content_dep_a_t* m_common;
        std::vector<double>* m_pos;
        std::vector<double>* m_vel;
        std::vector<double>* m_acc;
        double m_a_gf0;
        double m_a_gf1;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_dep_a_t* common() const { return m_common; }

        /**
         * Position of the GEO at time toe
         */
        std::vector<double>* pos() const { return m_pos; }

        /**
         * Velocity of the GEO at time toe
         */
        std::vector<double>* vel() const { return m_vel; }

        /**
         * Acceleration of the GEO at time toe
         */
        std::vector<double>* acc() const { return m_acc; }

        /**
         * Time offset of the GEO clock w.r.t. SBAS Network Time
         */
        double a_gf0() const { return m_a_gf0; }

        /**
         * Drift of the GEO clock w.r.t. SBAS Network Time
         */
        double a_gf1() const { return m_a_gf1; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Pseudorange and carrier phase observation for a satellite being tracked.
     * The observations are interoperable with 3rd party receivers and conform
     * with typical RTCM 3.1 message GPS/GLO observations.
     * 
     * Carrier phase observations are not guaranteed to be aligned to the RINEX
     * 3 or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are
     * currently performed.
     */

    class packed_obs_content_t : public kaitai::kstruct {

    public:

        packed_obs_content_t(kaitai::kstream* p__io, observation_t::msg_obs_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~packed_obs_content_t();

    private:
        uint32_t m_p;
        gnss_t::carrier_phase_t* m_l;
        doppler_t* m_d;
        uint8_t m_cn0;
        uint8_t m_lock;
        uint8_t m_flags;
        gnss_t::gnss_signal_t* m_sid;
        observation_t* m__root;
        observation_t::msg_obs_t* m__parent;

    public:

        /**
         * Pseudorange observation
         */
        uint32_t p() const { return m_p; }

        /**
         * Carrier phase observation with typical sign convention.
         */
        gnss_t::carrier_phase_t* l() const { return m_l; }

        /**
         * Doppler observation with typical sign convention.
         */
        doppler_t* d() const { return m_d; }

        /**
         * Carrier-to-Noise density.  Zero implies invalid cn0.
         */
        uint8_t cn0() const { return m_cn0; }

        /**
         * Lock timer. This value gives an indication of the time for which a
         * signal has maintained continuous phase lock. Whenever a signal has
         * lost and regained lock, this value is reset to zero. It is encoded
         * according to DF402 from the RTCM 10403.2 Amendment 2 specification.
         * Valid values range from 0 to 15 and the most significant nibble is
         * reserved for future use.
         */
        uint8_t lock() const { return m_lock; }

        /**
         * Measurement status flags. A bit field of flags providing the status
         * of this observation.  If this field is 0 it means only the Cn0
         * estimate for the signal is valid.
         */
        uint8_t flags() const { return m_flags; }

        /**
         * GNSS signal identifier (16 bit)
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }
        observation_t* _root() const { return m__root; }
        observation_t::msg_obs_t* _parent() const { return m__parent; }
    };

    /**
     * The base station position message is the position reported by the base
     * station itself in absolute Earth Centered Earth Fixed coordinates. It is
     * used for pseudo-absolute RTK positioning, and is required to be a high-
     * accuracy surveyed location of the base station. Any error here will
     * result in an error in the pseudo-absolute position output.
     */

    class msg_base_pos_ecef_t : public kaitai::kstruct {

    public:

        msg_base_pos_ecef_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_base_pos_ecef_t();

    private:
        double m_x;
        double m_y;
        double m_z;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * ECEF X coordinate
         */
        double x() const { return m_x; }

        /**
         * ECEF Y coordinate
         */
        double y() const { return m_y; }

        /**
         * ECEF Z coordinate
         */
        double z() const { return m_z; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ephemeris_glo_dep_a_t : public kaitai::kstruct {

    public:

        msg_ephemeris_glo_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_glo_dep_a_t();

    private:
        ephemeris_common_content_dep_a_t* m_common;
        double m_gamma;
        double m_tau;
        std::vector<double>* m_pos;
        std::vector<double>* m_vel;
        std::vector<double>* m_acc;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_dep_a_t* common() const { return m_common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        double gamma() const { return m_gamma; }

        /**
         * Correction to the SV time
         */
        double tau() const { return m_tau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        std::vector<double>* pos() const { return m_pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        std::vector<double>* vel() const { return m_vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        std::vector<double>* acc() const { return m_acc; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
     */

    class msg_group_delay_t : public kaitai::kstruct {

    public:

        msg_group_delay_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_group_delay_t();

    private:
        gnss_t::gps_time_sec_t* m_t_op;
        gnss_t::gnss_signal_t* m_sid;
        uint8_t m_valid;
        int16_t m_tgd;
        int16_t m_isc_l1ca;
        int16_t m_isc_l2c;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Data Predict Time of Week
         */
        gnss_t::gps_time_sec_t* t_op() const { return m_t_op; }

        /**
         * GNSS signal identifier
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * bit-field indicating validity of the values, LSB indicating tgd
         * validity etc. 1 = value is valid, 0 = value is not valid.
         */
        uint8_t valid() const { return m_valid; }
        int16_t tgd() const { return m_tgd; }
        int16_t isc_l1ca() const { return m_isc_l1ca; }
        int16_t isc_l2c() const { return m_isc_l2c; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The almanac message returns a set of satellite orbit parameters. Almanac
     * data is not very precise and is considered valid for up to several
     * months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
     * information and almanac" for details.
     */

    class msg_almanac_glo_t : public kaitai::kstruct {

    public:

        msg_almanac_glo_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_almanac_glo_t();

    private:
        almanac_common_content_t* m_common;
        double m_lambda_na;
        double m_t_lambda_na;
        double m_i;
        double m_t;
        double m_t_dot;
        double m_epsilon;
        double m_omega;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all almanac types
         */
        almanac_common_content_t* common() const { return m_common; }

        /**
         * Longitude of the first ascending node of the orbit in PZ-90.02
         * coordinate system
         */
        double lambda_na() const { return m_lambda_na; }

        /**
         * Time of the first ascending node passage
         */
        double t_lambda_na() const { return m_t_lambda_na; }

        /**
         * Value of inclination at instant of t_lambda
         */
        double i() const { return m_i; }

        /**
         * Value of Draconian period at instant of t_lambda
         */
        double t() const { return m_t; }

        /**
         * Rate of change of the Draconian period
         */
        double t_dot() const { return m_t_dot; }

        /**
         * Eccentricity at instant of t_lambda
         */
        double epsilon() const { return m_epsilon; }

        /**
         * Argument of perigee at instant of t_lambda
         */
        double omega() const { return m_omega; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ephemeris_gal_dep_a_t : public kaitai::kstruct {

    public:

        msg_ephemeris_gal_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_gal_dep_a_t();

    private:
        ephemeris_common_content_t* m_common;
        float m_bgd_e1e5a;
        float m_bgd_e1e5b;
        float m_c_rs;
        float m_c_rc;
        float m_c_uc;
        float m_c_us;
        float m_c_ic;
        float m_c_is;
        double m_dn;
        double m_m0;
        double m_ecc;
        double m_sqrta;
        double m_omega0;
        double m_omegadot;
        double m_w;
        double m_inc;
        double m_inc_dot;
        double m_af0;
        double m_af1;
        float m_af2;
        gnss_t::gps_time_sec_t* m_toc;
        uint16_t m_iode;
        uint16_t m_iodc;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_t* common() const { return m_common; }

        /**
         * E1-E5a Broadcast Group Delay
         */
        float bgd_e1e5a() const { return m_bgd_e1e5a; }

        /**
         * E1-E5b Broadcast Group Delay
         */
        float bgd_e1e5b() const { return m_bgd_e1e5b; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        float c_rs() const { return m_c_rs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        float c_rc() const { return m_c_rc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        float c_uc() const { return m_c_uc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        float c_us() const { return m_c_us; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        float c_ic() const { return m_c_ic; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        float c_is() const { return m_c_is; }

        /**
         * Mean motion difference
         */
        double dn() const { return m_dn; }

        /**
         * Mean anomaly at reference time
         */
        double m0() const { return m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        double ecc() const { return m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        double sqrta() const { return m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        double omega0() const { return m_omega0; }

        /**
         * Rate of right ascension
         */
        double omegadot() const { return m_omegadot; }

        /**
         * Argument of perigee
         */
        double w() const { return m_w; }

        /**
         * Inclination
         */
        double inc() const { return m_inc; }

        /**
         * Inclination first derivative
         */
        double inc_dot() const { return m_inc_dot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        double af0() const { return m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        double af1() const { return m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        float af2() const { return m_af2; }

        /**
         * Clock reference
         */
        gnss_t::gps_time_sec_t* toc() const { return m_toc; }

        /**
         * Issue of data (IODnav)
         */
        uint16_t iode() const { return m_iode; }

        /**
         * Issue of data (IODnav). Always equal to iode
         */
        uint16_t iodc() const { return m_iodc; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_obs_dep_b_t : public kaitai::kstruct {

    public:

        msg_obs_dep_b_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_obs_dep_b_t();

    private:
        observation_header_dep_t* m_header;
        std::vector<packed_obs_content_dep_b_t*>* m_obs;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Header of a GPS observation message
         */
        observation_header_dep_t* header() const { return m_header; }

        /**
         * Pseudorange and carrier phase observation for a satellite being
         * tracked.
         */
        std::vector<packed_obs_content_dep_b_t*>* obs() const { return m_obs; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class packed_obs_content_dep_a_t : public kaitai::kstruct {

    public:

        packed_obs_content_dep_a_t(kaitai::kstream* p__io, observation_t::msg_obs_dep_a_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~packed_obs_content_dep_a_t();

    private:
        uint32_t m_p;
        carrier_phase_dep_a_t* m_l;
        uint8_t m_cn0;
        uint16_t m_lock;
        uint8_t m_prn;
        observation_t* m__root;
        observation_t::msg_obs_dep_a_t* m__parent;

    public:

        /**
         * Pseudorange observation
         */
        uint32_t p() const { return m_p; }

        /**
         * Carrier phase observation with opposite sign from typical convention
         */
        carrier_phase_dep_a_t* l() const { return m_l; }

        /**
         * Carrier-to-Noise density
         */
        uint8_t cn0() const { return m_cn0; }

        /**
         * Lock indicator. This value changes whenever a satellite signal has
         * lost and regained lock, indicating that the carrier phase ambiguity
         * may have changed.
         */
        uint16_t lock() const { return m_lock; }

        /**
         * PRN-1 identifier of the satellite signal
         */
        uint8_t prn() const { return m_prn; }
        observation_t* _root() const { return m__root; }
        observation_t::msg_obs_dep_a_t* _parent() const { return m__parent; }
    };

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate GLO satellite position, velocity, and clock offset.
     * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
     * immediate information (ephemeris parameters)" for more details.
     */

    class msg_ephemeris_glo_t : public kaitai::kstruct {

    public:

        msg_ephemeris_glo_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_glo_t();

    private:
        ephemeris_common_content_t* m_common;
        float m_gamma;
        float m_tau;
        float m_d_tau;
        std::vector<double>* m_pos;
        std::vector<double>* m_vel;
        std::vector<float>* m_acc;
        uint8_t m_fcn;
        uint8_t m_iod;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_t* common() const { return m_common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        float gamma() const { return m_gamma; }

        /**
         * Correction to the SV time
         */
        float tau() const { return m_tau; }

        /**
         * Equipment delay between L1 and L2
         */
        float d_tau() const { return m_d_tau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        std::vector<double>* pos() const { return m_pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        std::vector<double>* vel() const { return m_vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        std::vector<float>* acc() const { return m_acc; }

        /**
         * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
         */
        uint8_t fcn() const { return m_fcn; }

        /**
         * Issue of data. Equal to the 7 bits of the immediate data word t_b
         */
        uint8_t iod() const { return m_iod; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The ionospheric parameters which allow the "L1 only" or "L2 only" user
     * to utilize the ionospheric model for computation of the ionospheric
     * delay. Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
     */

    class msg_iono_t : public kaitai::kstruct {

    public:

        msg_iono_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_iono_t();

    private:
        gnss_t::gps_time_sec_t* m_t_nmct;
        double m_a0;
        double m_a1;
        double m_a2;
        double m_a3;
        double m_b0;
        double m_b1;
        double m_b2;
        double m_b3;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Navigation Message Correction Table Validity Time
         */
        gnss_t::gps_time_sec_t* t_nmct() const { return m_t_nmct; }
        double a0() const { return m_a0; }
        double a1() const { return m_a1; }
        double a2() const { return m_a2; }
        double a3() const { return m_a3; }
        double b0() const { return m_b0; }
        double b1() const { return m_b1; }
        double b2() const { return m_b2; }
        double b3() const { return m_b3; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ephemeris_dep_d_t : public kaitai::kstruct {

    public:

        msg_ephemeris_dep_d_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_dep_d_t();

    private:
        double m_tgd;
        double m_c_rs;
        double m_c_rc;
        double m_c_uc;
        double m_c_us;
        double m_c_ic;
        double m_c_is;
        double m_dn;
        double m_m0;
        double m_ecc;
        double m_sqrta;
        double m_omega0;
        double m_omegadot;
        double m_w;
        double m_inc;
        double m_inc_dot;
        double m_af0;
        double m_af1;
        double m_af2;
        double m_toe_tow;
        uint16_t m_toe_wn;
        double m_toc_tow;
        uint16_t m_toc_wn;
        uint8_t m_valid;
        uint8_t m_healthy;
        gnss_t::gnss_signal_dep_t* m_sid;
        uint8_t m_iode;
        uint16_t m_iodc;
        uint32_t m_reserved;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Group delay differential between L1 and L2
         */
        double tgd() const { return m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        double c_rs() const { return m_c_rs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        double c_rc() const { return m_c_rc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        double c_uc() const { return m_c_uc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        double c_us() const { return m_c_us; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        double c_ic() const { return m_c_ic; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        double c_is() const { return m_c_is; }

        /**
         * Mean motion difference
         */
        double dn() const { return m_dn; }

        /**
         * Mean anomaly at reference time
         */
        double m0() const { return m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        double ecc() const { return m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        double sqrta() const { return m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        double omega0() const { return m_omega0; }

        /**
         * Rate of right ascension
         */
        double omegadot() const { return m_omegadot; }

        /**
         * Argument of perigee
         */
        double w() const { return m_w; }

        /**
         * Inclination
         */
        double inc() const { return m_inc; }

        /**
         * Inclination first derivative
         */
        double inc_dot() const { return m_inc_dot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        double af0() const { return m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        double af1() const { return m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        double af2() const { return m_af2; }

        /**
         * Time of week
         */
        double toe_tow() const { return m_toe_tow; }

        /**
         * Week number
         */
        uint16_t toe_wn() const { return m_toe_wn; }

        /**
         * Clock reference time of week
         */
        double toc_tow() const { return m_toc_tow; }

        /**
         * Clock reference week number
         */
        uint16_t toc_wn() const { return m_toc_wn; }

        /**
         * Is valid?
         */
        uint8_t valid() const { return m_valid; }

        /**
         * Satellite is healthy?
         */
        uint8_t healthy() const { return m_healthy; }

        /**
         * GNSS signal identifier
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }

        /**
         * Issue of ephemeris data
         */
        uint8_t iode() const { return m_iode; }

        /**
         * Issue of clock data
         */
        uint16_t iodc() const { return m_iodc; }

        /**
         * Reserved field
         */
        uint32_t reserved() const { return m_reserved; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate GPS satellite position, velocity, and clock offset.
     * Please see the Navstar GPS Space Segment/Navigation user interfaces
     * (ICD-GPS-200, Table 20-III) for more details.
     */

    class msg_ephemeris_gps_t : public kaitai::kstruct {

    public:

        msg_ephemeris_gps_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_gps_t();

    private:
        ephemeris_common_content_t* m_common;
        float m_tgd;
        float m_c_rs;
        float m_c_rc;
        float m_c_uc;
        float m_c_us;
        float m_c_ic;
        float m_c_is;
        double m_dn;
        double m_m0;
        double m_ecc;
        double m_sqrta;
        double m_omega0;
        double m_omegadot;
        double m_w;
        double m_inc;
        double m_inc_dot;
        float m_af0;
        float m_af1;
        float m_af2;
        gnss_t::gps_time_sec_t* m_toc;
        uint8_t m_iode;
        uint16_t m_iodc;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_t* common() const { return m_common; }

        /**
         * Group delay differential between L1 and L2
         */
        float tgd() const { return m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        float c_rs() const { return m_c_rs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        float c_rc() const { return m_c_rc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        float c_uc() const { return m_c_uc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        float c_us() const { return m_c_us; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        float c_ic() const { return m_c_ic; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        float c_is() const { return m_c_is; }

        /**
         * Mean motion difference
         */
        double dn() const { return m_dn; }

        /**
         * Mean anomaly at reference time
         */
        double m0() const { return m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        double ecc() const { return m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        double sqrta() const { return m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        double omega0() const { return m_omega0; }

        /**
         * Rate of right ascension
         */
        double omegadot() const { return m_omegadot; }

        /**
         * Argument of perigee
         */
        double w() const { return m_w; }

        /**
         * Inclination
         */
        double inc() const { return m_inc; }

        /**
         * Inclination first derivative
         */
        double inc_dot() const { return m_inc_dot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        float af0() const { return m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        float af1() const { return m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        float af2() const { return m_af2; }

        /**
         * Clock reference
         */
        gnss_t::gps_time_sec_t* toc() const { return m_toc; }

        /**
         * Issue of ephemeris data
         */
        uint8_t iode() const { return m_iode; }

        /**
         * Issue of clock data
         */
        uint16_t iodc() const { return m_iodc; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The base station position message is the position reported by the base
     * station itself. It is used for pseudo-absolute RTK positioning, and is
     * required to be a high-accuracy surveyed location of the base station.
     * Any error here will result in an error in the pseudo-absolute position
     * output.
     */

    class msg_base_pos_llh_t : public kaitai::kstruct {

    public:

        msg_base_pos_llh_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_base_pos_llh_t();

    private:
        double m_lat;
        double m_lon;
        double m_height;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Latitude
         */
        double lat() const { return m_lat; }

        /**
         * Longitude
         */
        double lon() const { return m_lon; }

        /**
         * Height
         */
        double height() const { return m_height; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    class almanac_common_content_t : public kaitai::kstruct {

    public:

        almanac_common_content_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~almanac_common_content_t();

    private:
        gnss_t::gnss_signal_t* m_sid;
        gnss_t::gps_time_sec_t* m_toa;
        double m_ura;
        uint32_t m_fit_interval;
        uint8_t m_valid;
        uint8_t m_health_bits;
        observation_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * GNSS signal identifier
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Reference time of almanac
         */
        gnss_t::gps_time_sec_t* toa() const { return m_toa; }

        /**
         * User Range Accuracy
         */
        double ura() const { return m_ura; }

        /**
         * Curve fit interval
         */
        uint32_t fit_interval() const { return m_fit_interval; }

        /**
         * Status of almanac, 1 = valid, 0 = invalid
         */
        uint8_t valid() const { return m_valid; }

        /**
         * Satellite health status for GPS:
         *   - bits 5-7: NAV data health status. See IS-GPS-200H
         *     Table 20-VII: NAV Data Health Indications.
         *   - bits 0-4: Signal health status. See IS-GPS-200H
         *     Table 20-VIII. Codes for Health of SV Signal
         *     Components.
         * Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
         * details):
         *   - bit 0: C(n), "unhealthy" flag that is transmitted within
         *     non-immediate data and indicates overall constellation status
         *     at the moment of almanac uploading.
         *     '0' indicates malfunction of n-satellite.
         *     '1' indicates that n-satellite is operational.
         *   - bit 1: Bn(ln), '0' indicates the satellite is operational
         *     and suitable for navigation.
         */
        uint8_t health_bits() const { return m_health_bits; }
        observation_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * The OSR message contains network corrections in an observation-like
     * format.
     */

    class msg_osr_t : public kaitai::kstruct {

    public:

        msg_osr_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_osr_t();

    private:
        observation_header_t* m_header;
        std::vector<packed_osr_content_t*>* m_obs;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Header of a GPS observation message
         */
        observation_header_t* header() const { return m_header; }

        /**
         * Network correction for a satellite signal.
         */
        std::vector<packed_osr_content_t*>* obs() const { return m_obs; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The ephemeris message returns a set of satellite orbit parameters that
     * is used to calculate GLO satellite position, velocity, and clock offset.
     * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
     * immediate information (ephemeris parameters)" for more details.
     */

    class msg_ephemeris_glo_dep_c_t : public kaitai::kstruct {

    public:

        msg_ephemeris_glo_dep_c_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_glo_dep_c_t();

    private:
        ephemeris_common_content_dep_b_t* m_common;
        double m_gamma;
        double m_tau;
        double m_d_tau;
        std::vector<double>* m_pos;
        std::vector<double>* m_vel;
        std::vector<double>* m_acc;
        uint8_t m_fcn;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_dep_b_t* common() const { return m_common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        double gamma() const { return m_gamma; }

        /**
         * Correction to the SV time
         */
        double tau() const { return m_tau; }

        /**
         * Equipment delay between L1 and L2
         */
        double d_tau() const { return m_d_tau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        std::vector<double>* pos() const { return m_pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        std::vector<double>* vel() const { return m_vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        std::vector<double>* acc() const { return m_acc; }

        /**
         * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
         */
        uint8_t fcn() const { return m_fcn; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ephemeris_glo_dep_b_t : public kaitai::kstruct {

    public:

        msg_ephemeris_glo_dep_b_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_glo_dep_b_t();

    private:
        ephemeris_common_content_dep_b_t* m_common;
        double m_gamma;
        double m_tau;
        std::vector<double>* m_pos;
        std::vector<double>* m_vel;
        std::vector<double>* m_acc;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_dep_b_t* common() const { return m_common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        double gamma() const { return m_gamma; }

        /**
         * Correction to the SV time
         */
        double tau() const { return m_tau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        std::vector<double>* pos() const { return m_pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        std::vector<double>* vel() const { return m_vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        std::vector<double>* acc() const { return m_acc; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_sv_configuration_gps_dep_t : public kaitai::kstruct {

    public:

        msg_sv_configuration_gps_dep_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_sv_configuration_gps_dep_t();

    private:
        gnss_t::gps_time_sec_t* m_t_nmct;
        uint32_t m_l2c_mask;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Navigation Message Correction Table Validity Time
         */
        gnss_t::gps_time_sec_t* t_nmct() const { return m_t_nmct; }

        /**
         * L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
         */
        uint32_t l2c_mask() const { return m_l2c_mask; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    class msg_ephemeris_sbas_t : public kaitai::kstruct {

    public:

        msg_ephemeris_sbas_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_sbas_t();

    private:
        ephemeris_common_content_t* m_common;
        std::vector<double>* m_pos;
        std::vector<float>* m_vel;
        std::vector<float>* m_acc;
        float m_a_gf0;
        float m_a_gf1;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Values common for all ephemeris types
         */
        ephemeris_common_content_t* common() const { return m_common; }

        /**
         * Position of the GEO at time toe
         */
        std::vector<double>* pos() const { return m_pos; }

        /**
         * Velocity of the GEO at time toe
         */
        std::vector<float>* vel() const { return m_vel; }

        /**
         * Acceleration of the GEO at time toe
         */
        std::vector<float>* acc() const { return m_acc; }

        /**
         * Time offset of the GEO clock w.r.t. SBAS Network Time
         */
        float a_gf0() const { return m_a_gf0; }

        /**
         * Drift of the GEO clock w.r.t. SBAS Network Time
         */
        float a_gf1() const { return m_a_gf1; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Pseudorange and carrier phase observation for a satellite being tracked.
     * Pseudoranges are referenced to a nominal pseudorange.
     */

    class packed_obs_content_dep_b_t : public kaitai::kstruct {

    public:

        packed_obs_content_dep_b_t(kaitai::kstream* p__io, observation_t::msg_obs_dep_b_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~packed_obs_content_dep_b_t();

    private:
        uint32_t m_p;
        carrier_phase_dep_a_t* m_l;
        uint8_t m_cn0;
        uint16_t m_lock;
        gnss_t::gnss_signal_dep_t* m_sid;
        observation_t* m__root;
        observation_t::msg_obs_dep_b_t* m__parent;

    public:

        /**
         * Pseudorange observation
         */
        uint32_t p() const { return m_p; }

        /**
         * Carrier phase observation with opposite sign from typical
         * convention.
         */
        carrier_phase_dep_a_t* l() const { return m_l; }

        /**
         * Carrier-to-Noise density
         */
        uint8_t cn0() const { return m_cn0; }

        /**
         * Lock indicator. This value changes whenever a satellite signal has
         * lost and regained lock, indicating that the carrier phase ambiguity
         * may have changed.
         */
        uint16_t lock() const { return m_lock; }

        /**
         * GNSS signal identifier
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }
        observation_t* _root() const { return m__root; }
        observation_t::msg_obs_dep_b_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_obs_dep_c_t : public kaitai::kstruct {

    public:

        msg_obs_dep_c_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_obs_dep_c_t();

    private:
        observation_header_dep_t* m_header;
        std::vector<packed_obs_content_dep_c_t*>* m_obs;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Header of a GPS observation message
         */
        observation_header_dep_t* header() const { return m_header; }

        /**
         * Pseudorange and carrier phase observation for a satellite being
         * tracked.
         */
        std::vector<packed_obs_content_dep_c_t*>* obs() const { return m_obs; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ephemeris_dep_a_t : public kaitai::kstruct {

    public:

        msg_ephemeris_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ephemeris_dep_a_t();

    private:
        double m_tgd;
        double m_c_rs;
        double m_c_rc;
        double m_c_uc;
        double m_c_us;
        double m_c_ic;
        double m_c_is;
        double m_dn;
        double m_m0;
        double m_ecc;
        double m_sqrta;
        double m_omega0;
        double m_omegadot;
        double m_w;
        double m_inc;
        double m_inc_dot;
        double m_af0;
        double m_af1;
        double m_af2;
        double m_toe_tow;
        uint16_t m_toe_wn;
        double m_toc_tow;
        uint16_t m_toc_wn;
        uint8_t m_valid;
        uint8_t m_healthy;
        uint8_t m_prn;
        observation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Group delay differential between L1 and L2
         */
        double tgd() const { return m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        double c_rs() const { return m_c_rs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        double c_rc() const { return m_c_rc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        double c_uc() const { return m_c_uc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        double c_us() const { return m_c_us; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        double c_ic() const { return m_c_ic; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        double c_is() const { return m_c_is; }

        /**
         * Mean motion difference
         */
        double dn() const { return m_dn; }

        /**
         * Mean anomaly at reference time
         */
        double m0() const { return m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        double ecc() const { return m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        double sqrta() const { return m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        double omega0() const { return m_omega0; }

        /**
         * Rate of right ascension
         */
        double omegadot() const { return m_omegadot; }

        /**
         * Argument of perigee
         */
        double w() const { return m_w; }

        /**
         * Inclination
         */
        double inc() const { return m_inc; }

        /**
         * Inclination first derivative
         */
        double inc_dot() const { return m_inc_dot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        double af0() const { return m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        double af1() const { return m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        double af2() const { return m_af2; }

        /**
         * Time of week
         */
        double toe_tow() const { return m_toe_tow; }

        /**
         * Week number
         */
        uint16_t toe_wn() const { return m_toe_wn; }

        /**
         * Clock reference time of week
         */
        double toc_tow() const { return m_toc_tow; }

        /**
         * Clock reference week number
         */
        uint16_t toc_wn() const { return m_toc_wn; }

        /**
         * Is valid?
         */
        uint8_t valid() const { return m_valid; }

        /**
         * Satellite is healthy?
         */
        uint8_t healthy() const { return m_healthy; }

        /**
         * PRN being tracked
         */
        uint8_t prn() const { return m_prn; }
        observation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    class ephemeris_common_content_dep_b_t : public kaitai::kstruct {

    public:

        ephemeris_common_content_dep_b_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, observation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~ephemeris_common_content_dep_b_t();

    private:
        gnss_t::gnss_signal_t* m_sid;
        gnss_t::gps_time_sec_t* m_toe;
        double m_ura;
        uint32_t m_fit_interval;
        uint8_t m_valid;
        uint8_t m_health_bits;
        observation_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * GNSS signal identifier (16 bit)
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Time of Ephemerides
         */
        gnss_t::gps_time_sec_t* toe() const { return m_toe; }

        /**
         * User Range Accuracy
         */
        double ura() const { return m_ura; }

        /**
         * Curve fit interval
         */
        uint32_t fit_interval() const { return m_fit_interval; }

        /**
         * Status of ephemeris, 1 = valid, 0 = invalid
         */
        uint8_t valid() const { return m_valid; }

        /**
         * Satellite health status.
         * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
         * Others: 0 = valid, non-zero = invalid
         */
        uint8_t health_bits() const { return m_health_bits; }
        observation_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

private:
    observation_t* m__root;
    kaitai::kstruct* m__parent;

public:
    observation_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // OBSERVATION_H_
