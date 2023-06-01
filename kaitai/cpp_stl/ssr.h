#ifndef SSR_H_
#define SSR_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class ssr_t : public kaitai::kstruct {

public:
    class grid_definition_header_dep_a_t;
    class stec_residual_no_std_t;
    class tropospheric_delay_correction_no_std_t;
    class msg_ssr_stec_correction_dep_t;
    class stec_sat_element_integrity_t;
    class msg_ssr_orbit_clock_dep_a_t;
    class msg_ssr_stec_correction_t;
    class msg_ssr_orbit_clock_t;
    class bounds_header_t;
    class msg_ssr_gridded_correction_t;
    class stec_residual_t;
    class code_phase_biases_sat_sig_t;
    class satellite_apc_t;
    class gridded_correction_header_t;
    class stec_sat_element_t;
    class stec_header_dep_a_t;
    class stec_header_t;
    class msg_ssr_stec_correction_dep_a_t;
    class gridded_correction_header_dep_a_t;
    class msg_ssr_orbit_clock_bounds_t;
    class msg_ssr_gridded_correction_bounds_t;
    class msg_ssr_grid_definition_dep_a_t;
    class code_biases_content_t;
    class msg_ssr_satellite_apc_t;
    class phase_biases_content_t;
    class msg_ssr_tile_definition_dep_a_t;
    class orbit_clock_bound_t;
    class msg_ssr_gridded_correction_dep_a_t;
    class msg_ssr_orbit_clock_bounds_degradation_t;
    class msg_ssr_gridded_correction_no_std_dep_a_t;
    class msg_ssr_code_phase_biases_bounds_t;
    class msg_ssr_code_biases_t;
    class msg_ssr_tile_definition_t;
    class orbit_clock_bound_degradation_t;
    class msg_ssr_satellite_apc_dep_t;
    class tropospheric_delay_correction_t;
    class msg_ssr_tile_definition_dep_b_t;
    class msg_ssr_phase_biases_t;

    ssr_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, ssr_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~ssr_t();

    /**
     * Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes
     * an RLE encoded validity list.
     */

    class grid_definition_header_dep_a_t : public kaitai::kstruct {

    public:

        grid_definition_header_dep_a_t(kaitai::kstream* p__io, ssr_t::msg_ssr_grid_definition_dep_a_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~grid_definition_header_dep_a_t();

    private:
        uint8_t m_region_size_inverse;
        uint16_t m_area_width;
        uint16_t m_lat_nw_corner_enc;
        uint16_t m_lon_nw_corner_enc;
        uint8_t m_num_msgs;
        uint8_t m_seq_num;
        ssr_t* m__root;
        ssr_t::msg_ssr_grid_definition_dep_a_t* m__parent;

    public:

        /**
         * region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
         */
        uint8_t region_size_inverse() const { return m_region_size_inverse; }

        /**
         * grid height (deg) = grid width (deg) = area_width / region_size 0 is
         * an invalid value.
         */
        uint16_t area_width() const { return m_area_width; }

        /**
         * North-West corner latitude (deg) = region_size * lat_nw_corner_enc -
         * 90
         */
        uint16_t lat_nw_corner_enc() const { return m_lat_nw_corner_enc; }

        /**
         * North-West corner longitude (deg) = region_size * lon_nw_corner_enc
         * - 180
         */
        uint16_t lon_nw_corner_enc() const { return m_lon_nw_corner_enc; }

        /**
         * Number of messages in the dataset
         */
        uint8_t num_msgs() const { return m_num_msgs; }

        /**
         * Position of this message in the dataset
         */
        uint8_t seq_num() const { return m_seq_num; }
        ssr_t* _root() const { return m__root; }
        ssr_t::msg_ssr_grid_definition_dep_a_t* _parent() const { return m__parent; }
    };

    /**
     * STEC residual for the given satellite at the grid point.
     */

    class stec_residual_no_std_t : public kaitai::kstruct {

    public:

        stec_residual_no_std_t(kaitai::kstream* p__io, ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~stec_residual_no_std_t();

    private:
        gnss_t::sv_id_t* m_sv_id;
        int16_t m_residual;
        ssr_t* m__root;
        ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t* m__parent;

    public:

        /**
         * space vehicle identifier
         */
        gnss_t::sv_id_t* sv_id() const { return m_sv_id; }

        /**
         * STEC residual
         */
        int16_t residual() const { return m_residual; }
        ssr_t* _root() const { return m__root; }
        ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t* _parent() const { return m__parent; }
    };

    /**
     * Troposphere vertical delays at the grid point.
     */

    class tropospheric_delay_correction_no_std_t : public kaitai::kstruct {

    public:

        tropospheric_delay_correction_no_std_t(kaitai::kstream* p__io, ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~tropospheric_delay_correction_no_std_t();

    private:
        int16_t m_hydro;
        int8_t m_wet;
        ssr_t* m__root;
        ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t* m__parent;

    public:

        /**
         * Hydrostatic vertical delay
         */
        int16_t hydro() const { return m_hydro; }

        /**
         * Wet vertical delay
         */
        int8_t wet() const { return m_wet; }
        ssr_t* _root() const { return m__root; }
        ssr_t::msg_ssr_gridded_correction_no_std_dep_a_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ssr_stec_correction_dep_t : public kaitai::kstruct {

    public:

        msg_ssr_stec_correction_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_stec_correction_dep_t();

    private:
        stec_header_t* m_header;
        std::vector<stec_sat_element_t*>* m_stec_sat_list;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Header of a STEC polynomial coefficient message.
         */
        stec_header_t* header() const { return m_header; }

        /**
         * Array of STEC polynomial coefficients for each space vehicle.
         */
        std::vector<stec_sat_element_t*>* stec_sat_list() const { return m_stec_sat_list; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * STEC polynomial and bounds for the given satellite.
     */

    class stec_sat_element_integrity_t : public kaitai::kstruct {

    public:

        stec_sat_element_integrity_t(kaitai::kstream* p__io, ssr_t::msg_ssr_gridded_correction_bounds_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~stec_sat_element_integrity_t();

    private:
        stec_residual_t* m_stec_residual;
        uint8_t m_stec_bound_mu;
        uint8_t m_stec_bound_sig;
        uint8_t m_stec_bound_mu_dot;
        uint8_t m_stec_bound_sig_dot;
        ssr_t* m__root;
        ssr_t::msg_ssr_gridded_correction_bounds_t* m__parent;

    public:

        /**
         * STEC residuals (mean, stddev)
         */
        stec_residual_t* stec_residual() const { return m_stec_residual; }

        /**
         * Error Bound Mean. See Note 1.
         */
        uint8_t stec_bound_mu() const { return m_stec_bound_mu; }

        /**
         * Error Bound StDev. See Note 1.
         */
        uint8_t stec_bound_sig() const { return m_stec_bound_sig; }

        /**
         * Error Bound Mean First derivative.
         */
        uint8_t stec_bound_mu_dot() const { return m_stec_bound_mu_dot; }

        /**
         * Error Bound StDev First derivative.
         */
        uint8_t stec_bound_sig_dot() const { return m_stec_bound_sig_dot; }
        ssr_t* _root() const { return m__root; }
        ssr_t::msg_ssr_gridded_correction_bounds_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ssr_orbit_clock_dep_a_t : public kaitai::kstruct {

    public:

        msg_ssr_orbit_clock_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_orbit_clock_dep_a_t();

    private:
        gnss_t::gps_time_sec_t* m_time;
        gnss_t::gnss_signal_t* m_sid;
        uint8_t m_update_interval;
        uint8_t m_iod_ssr;
        uint8_t m_iod;
        int32_t m_radial;
        int32_t m_along;
        int32_t m_cross;
        int32_t m_dot_radial;
        int32_t m_dot_along;
        int32_t m_dot_cross;
        int32_t m_c0;
        int32_t m_c1;
        int32_t m_c2;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GNSS reference time of the correction
         */
        gnss_t::gps_time_sec_t* time() const { return m_time; }

        /**
         * GNSS signal identifier (16 bit)
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        uint8_t update_interval() const { return m_update_interval; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        uint8_t iod_ssr() const { return m_iod_ssr; }

        /**
         * Issue of broadcast ephemeris data
         */
        uint8_t iod() const { return m_iod; }

        /**
         * Orbit radial delta correction
         */
        int32_t radial() const { return m_radial; }

        /**
         * Orbit along delta correction
         */
        int32_t along() const { return m_along; }

        /**
         * Orbit along delta correction
         */
        int32_t cross() const { return m_cross; }

        /**
         * Velocity of orbit radial delta correction
         */
        int32_t dot_radial() const { return m_dot_radial; }

        /**
         * Velocity of orbit along delta correction
         */
        int32_t dot_along() const { return m_dot_along; }

        /**
         * Velocity of orbit cross delta correction
         */
        int32_t dot_cross() const { return m_dot_cross; }

        /**
         * C0 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        int32_t c0() const { return m_c0; }

        /**
         * C1 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        int32_t c1() const { return m_c1; }

        /**
         * C2 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        int32_t c2() const { return m_c2; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    class msg_ssr_stec_correction_t : public kaitai::kstruct {

    public:

        msg_ssr_stec_correction_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_stec_correction_t();

    private:
        bounds_header_t* m_header;
        uint8_t m_ssr_iod_atmo;
        uint16_t m_tile_set_id;
        uint16_t m_tile_id;
        uint8_t m_n_sats;
        std::vector<stec_sat_element_t*>* m_stec_sat_list;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Header of a STEC correction with bounds message.
         */
        bounds_header_t* header() const { return m_header; }

        /**
         * IOD of the SSR atmospheric correction
         */
        uint8_t ssr_iod_atmo() const { return m_ssr_iod_atmo; }

        /**
         * Tile set ID
         */
        uint16_t tile_set_id() const { return m_tile_set_id; }

        /**
         * Tile ID
         */
        uint16_t tile_id() const { return m_tile_id; }

        /**
         * Number of satellites.
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Array of STEC polynomial coefficients for each space vehicle.
         */
        std::vector<stec_sat_element_t*>* stec_sat_list() const { return m_stec_sat_list; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The precise orbit and clock correction message is to be applied as a
     * delta correction to broadcast ephemeris and is an equivalent to the 1060
     * /1066 RTCM message types.
     */

    class msg_ssr_orbit_clock_t : public kaitai::kstruct {

    public:

        msg_ssr_orbit_clock_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_orbit_clock_t();

    private:
        gnss_t::gps_time_sec_t* m_time;
        gnss_t::gnss_signal_t* m_sid;
        uint8_t m_update_interval;
        uint8_t m_iod_ssr;
        uint32_t m_iod;
        int32_t m_radial;
        int32_t m_along;
        int32_t m_cross;
        int32_t m_dot_radial;
        int32_t m_dot_along;
        int32_t m_dot_cross;
        int32_t m_c0;
        int32_t m_c1;
        int32_t m_c2;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GNSS reference time of the correction
         */
        gnss_t::gps_time_sec_t* time() const { return m_time; }

        /**
         * GNSS signal identifier (16 bit)
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        uint8_t update_interval() const { return m_update_interval; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        uint8_t iod_ssr() const { return m_iod_ssr; }

        /**
         * Issue of broadcast ephemeris data or IODCRC (Beidou)
         */
        uint32_t iod() const { return m_iod; }

        /**
         * Orbit radial delta correction
         */
        int32_t radial() const { return m_radial; }

        /**
         * Orbit along delta correction
         */
        int32_t along() const { return m_along; }

        /**
         * Orbit along delta correction
         */
        int32_t cross() const { return m_cross; }

        /**
         * Velocity of orbit radial delta correction
         */
        int32_t dot_radial() const { return m_dot_radial; }

        /**
         * Velocity of orbit along delta correction
         */
        int32_t dot_along() const { return m_dot_along; }

        /**
         * Velocity of orbit cross delta correction
         */
        int32_t dot_cross() const { return m_dot_cross; }

        /**
         * C0 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        int32_t c0() const { return m_c0; }

        /**
         * C1 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        int32_t c1() const { return m_c1; }

        /**
         * C2 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        int32_t c2() const { return m_c2; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    class bounds_header_t : public kaitai::kstruct {

    public:

        bounds_header_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~bounds_header_t();

    private:
        gnss_t::gps_time_sec_t* m_time;
        uint8_t m_num_msgs;
        uint8_t m_seq_num;
        uint8_t m_update_interval;
        uint8_t m_sol_id;
        ssr_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * GNSS reference time of the bound
         */
        gnss_t::gps_time_sec_t* time() const { return m_time; }

        /**
         * Number of messages in the dataset
         */
        uint8_t num_msgs() const { return m_num_msgs; }

        /**
         * Position of this message in the dataset
         */
        uint8_t seq_num() const { return m_seq_num; }

        /**
         * Update interval between consecutive bounds. Similar to RTCM DF391.
         */
        uint8_t update_interval() const { return m_update_interval; }

        /**
         * SSR Solution ID.
         */
        uint8_t sol_id() const { return m_sol_id; }
        ssr_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * STEC residuals are per space vehicle, troposphere is not.
     * 
     * It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
     */

    class msg_ssr_gridded_correction_t : public kaitai::kstruct {

    public:

        msg_ssr_gridded_correction_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_gridded_correction_t();

    private:
        gridded_correction_header_t* m_header;
        uint16_t m_index;
        tropospheric_delay_correction_t* m_tropo_delay_correction;
        std::vector<stec_residual_t*>* m_stec_residuals;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Header of a gridded correction message
         */
        gridded_correction_header_t* header() const { return m_header; }

        /**
         * Index of the grid point.
         */
        uint16_t index() const { return m_index; }

        /**
         * Wet and hydrostatic vertical delays (mean, stddev).
         */
        tropospheric_delay_correction_t* tropo_delay_correction() const { return m_tropo_delay_correction; }

        /**
         * STEC residuals for each satellite (mean, stddev).
         */
        std::vector<stec_residual_t*>* stec_residuals() const { return m_stec_residuals; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * STEC residual (mean and standard deviation) for the given satellite at
     * the grid point.
     */

    class stec_residual_t : public kaitai::kstruct {

    public:

        stec_residual_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~stec_residual_t();

    private:
        gnss_t::sv_id_t* m_sv_id;
        int16_t m_residual;
        uint8_t m_stddev;
        ssr_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * space vehicle identifier
         */
        gnss_t::sv_id_t* sv_id() const { return m_sv_id; }

        /**
         * STEC residual
         */
        int16_t residual() const { return m_residual; }

        /**
         * Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
         * value/16) - 1) * 10
         */
        uint8_t stddev() const { return m_stddev; }
        ssr_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class code_phase_biases_sat_sig_t : public kaitai::kstruct {

    public:

        code_phase_biases_sat_sig_t(kaitai::kstream* p__io, ssr_t::msg_ssr_code_phase_biases_bounds_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~code_phase_biases_sat_sig_t();

    private:
        uint8_t m_sat_id;
        uint8_t m_signal_id;
        uint8_t m_code_bias_bound_mu;
        uint8_t m_code_bias_bound_sig;
        uint8_t m_phase_bias_bound_mu;
        uint8_t m_phase_bias_bound_sig;
        ssr_t* m__root;
        ssr_t::msg_ssr_code_phase_biases_bounds_t* m__parent;

    public:

        /**
         * Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
         * or DF488 (BDS) depending on the constellation.
         */
        uint8_t sat_id() const { return m_sat_id; }

        /**
         * Signal and Tracking Mode Identifier. Similar to either RTCM DF380
         * (GPS), DF382 (Galileo) or DF467 (BDS) depending on the
         * constellation.
         */
        uint8_t signal_id() const { return m_signal_id; }

        /**
         * Code Bias Mean. Range: 0-1.275 m
         */
        uint8_t code_bias_bound_mu() const { return m_code_bias_bound_mu; }

        /**
         * Code Bias Standard Deviation. Range: 0-1.275 m
         */
        uint8_t code_bias_bound_sig() const { return m_code_bias_bound_sig; }

        /**
         * Phase Bias Mean. Range: 0-1.275 m
         */
        uint8_t phase_bias_bound_mu() const { return m_phase_bias_bound_mu; }

        /**
         * Phase Bias Standard Deviation. Range: 0-1.275 m
         */
        uint8_t phase_bias_bound_sig() const { return m_phase_bias_bound_sig; }
        ssr_t* _root() const { return m__root; }
        ssr_t::msg_ssr_code_phase_biases_bounds_t* _parent() const { return m__parent; }
    };

    /**
     * Contains phase center offset and elevation variation corrections for one
     * signal on a satellite.
     */

    class satellite_apc_t : public kaitai::kstruct {

    public:

        satellite_apc_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~satellite_apc_t();

    private:
        gnss_t::gnss_signal_t* m_sid;
        uint8_t m_sat_info;
        uint16_t m_svn;
        std::vector<int16_t>* m_pco;
        std::vector<int8_t>* m_pcv;
        ssr_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * GNSS signal identifier (16 bit)
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Additional satellite information
         */
        uint8_t sat_info() const { return m_sat_info; }

        /**
         * Satellite Code, as defined by IGS. Typically the space vehicle
         * number.
         */
        uint16_t svn() const { return m_svn; }

        /**
         * Mean phase center offset, X Y and Z axes. See IGS ANTEX file format
         * description for coordinate system definition.
         */
        std::vector<int16_t>* pco() const { return m_pco; }

        /**
         * Elevation dependent phase center variations. First element is 0
         * degrees separation from the Z axis, subsequent elements represent
         * elevation variations in 1 degree increments.
         */
        std::vector<int8_t>* pcv() const { return m_pcv; }
        ssr_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * The LPP message contains nested variable length arrays which are not
     * supported in SBP, so each grid point will be identified by the index.
     */

    class gridded_correction_header_t : public kaitai::kstruct {

    public:

        gridded_correction_header_t(kaitai::kstream* p__io, ssr_t::msg_ssr_gridded_correction_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~gridded_correction_header_t();

    private:
        uint16_t m_tile_set_id;
        uint16_t m_tile_id;
        gnss_t::gps_time_sec_t* m_time;
        uint16_t m_num_msgs;
        uint16_t m_seq_num;
        uint8_t m_update_interval;
        uint8_t m_iod_atmo;
        uint8_t m_tropo_quality_indicator;
        ssr_t* m__root;
        ssr_t::msg_ssr_gridded_correction_t* m__parent;

    public:

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        uint16_t tile_set_id() const { return m_tile_set_id; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        uint16_t tile_id() const { return m_tile_id; }

        /**
         * GNSS reference time of the correction
         */
        gnss_t::gps_time_sec_t* time() const { return m_time; }

        /**
         * Number of messages in the dataset
         */
        uint16_t num_msgs() const { return m_num_msgs; }

        /**
         * Position of this message in the dataset
         */
        uint16_t seq_num() const { return m_seq_num; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        uint8_t update_interval() const { return m_update_interval; }

        /**
         * IOD of the SSR atmospheric correction
         */
        uint8_t iod_atmo() const { return m_iod_atmo; }

        /**
         * Quality of the troposphere data. Encoded following RTCM DF389
         * specification in units of m.
         */
        uint8_t tropo_quality_indicator() const { return m_tropo_quality_indicator; }
        ssr_t* _root() const { return m__root; }
        ssr_t::msg_ssr_gridded_correction_t* _parent() const { return m__parent; }
    };

    /**
     * STEC polynomial for the given satellite.
     */

    class stec_sat_element_t : public kaitai::kstruct {

    public:

        stec_sat_element_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~stec_sat_element_t();

    private:
        gnss_t::sv_id_t* m_sv_id;
        uint8_t m_stec_quality_indicator;
        std::vector<int16_t>* m_stec_coeff;
        ssr_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Unique space vehicle identifier
         */
        gnss_t::sv_id_t* sv_id() const { return m_sv_id; }

        /**
         * Quality of the STEC data. Encoded following RTCM DF389 specification
         * but in units of TECU instead of m.
         */
        uint8_t stec_quality_indicator() const { return m_stec_quality_indicator; }

        /**
         * Coefficients of the STEC polynomial in the order of C00, C01, C10,
         * C11. C00 = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2
         */
        std::vector<int16_t>* stec_coeff() const { return m_stec_coeff; }
        ssr_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * A full set of STEC information will likely span multiple SBP messages,
     * since SBP message a limited to 255 bytes.  The header is used to tie
     * multiple SBP messages into a sequence.
     */

    class stec_header_dep_a_t : public kaitai::kstruct {

    public:

        stec_header_dep_a_t(kaitai::kstream* p__io, ssr_t::msg_ssr_stec_correction_dep_a_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~stec_header_dep_a_t();

    private:
        gnss_t::gps_time_sec_t* m_time;
        uint8_t m_num_msgs;
        uint8_t m_seq_num;
        uint8_t m_update_interval;
        uint8_t m_iod_atmo;
        ssr_t* m__root;
        ssr_t::msg_ssr_stec_correction_dep_a_t* m__parent;

    public:

        /**
         * GNSS reference time of the correction
         */
        gnss_t::gps_time_sec_t* time() const { return m_time; }

        /**
         * Number of messages in the dataset
         */
        uint8_t num_msgs() const { return m_num_msgs; }

        /**
         * Position of this message in the dataset
         */
        uint8_t seq_num() const { return m_seq_num; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        uint8_t update_interval() const { return m_update_interval; }

        /**
         * IOD of the SSR atmospheric correction
         */
        uint8_t iod_atmo() const { return m_iod_atmo; }
        ssr_t* _root() const { return m__root; }
        ssr_t::msg_ssr_stec_correction_dep_a_t* _parent() const { return m__parent; }
    };

    /**
     * A full set of STEC information will likely span multiple SBP messages,
     * since SBP message a limited to 255 bytes.  The header is used to tie
     * multiple SBP messages into a sequence.
     */

    class stec_header_t : public kaitai::kstruct {

    public:

        stec_header_t(kaitai::kstream* p__io, ssr_t::msg_ssr_stec_correction_dep_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~stec_header_t();

    private:
        uint16_t m_tile_set_id;
        uint16_t m_tile_id;
        gnss_t::gps_time_sec_t* m_time;
        uint8_t m_num_msgs;
        uint8_t m_seq_num;
        uint8_t m_update_interval;
        uint8_t m_iod_atmo;
        ssr_t* m__root;
        ssr_t::msg_ssr_stec_correction_dep_t* m__parent;

    public:

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        uint16_t tile_set_id() const { return m_tile_set_id; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        uint16_t tile_id() const { return m_tile_id; }

        /**
         * GNSS reference time of the correction
         */
        gnss_t::gps_time_sec_t* time() const { return m_time; }

        /**
         * Number of messages in the dataset
         */
        uint8_t num_msgs() const { return m_num_msgs; }

        /**
         * Position of this message in the dataset
         */
        uint8_t seq_num() const { return m_seq_num; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        uint8_t update_interval() const { return m_update_interval; }

        /**
         * IOD of the SSR atmospheric correction
         */
        uint8_t iod_atmo() const { return m_iod_atmo; }
        ssr_t* _root() const { return m__root; }
        ssr_t::msg_ssr_stec_correction_dep_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ssr_stec_correction_dep_a_t : public kaitai::kstruct {

    public:

        msg_ssr_stec_correction_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_stec_correction_dep_a_t();

    private:
        stec_header_dep_a_t* m_header;
        std::vector<stec_sat_element_t*>* m_stec_sat_list;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Header of a STEC message
         */
        stec_header_dep_a_t* header() const { return m_header; }

        /**
         * Array of STEC information for each space vehicle
         */
        std::vector<stec_sat_element_t*>* stec_sat_list() const { return m_stec_sat_list; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The 3GPP message contains nested variable length arrays which are not
     * supported in SBP, so each grid point will be identified by the index.
     */

    class gridded_correction_header_dep_a_t : public kaitai::kstruct {

    public:

        gridded_correction_header_dep_a_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~gridded_correction_header_dep_a_t();

    private:
        gnss_t::gps_time_sec_t* m_time;
        uint16_t m_num_msgs;
        uint16_t m_seq_num;
        uint8_t m_update_interval;
        uint8_t m_iod_atmo;
        uint8_t m_tropo_quality_indicator;
        ssr_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * GNSS reference time of the correction
         */
        gnss_t::gps_time_sec_t* time() const { return m_time; }

        /**
         * Number of messages in the dataset
         */
        uint16_t num_msgs() const { return m_num_msgs; }

        /**
         * Position of this message in the dataset
         */
        uint16_t seq_num() const { return m_seq_num; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        uint8_t update_interval() const { return m_update_interval; }

        /**
         * IOD of the SSR atmospheric correction
         */
        uint8_t iod_atmo() const { return m_iod_atmo; }

        /**
         * Quality of the troposphere data. Encoded following RTCM DF389
         * specification in units of m.
         */
        uint8_t tropo_quality_indicator() const { return m_tropo_quality_indicator; }
        ssr_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * Note 1: Range: 0-17.5 m. i<=200, mean=0.01i; 200<i<=230,
     * mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
     * 
     * Note 2: Range: 0-17.5 m. i<=200, std=0.01i; 200<i<=230, std=2+0.1(i-200)
     * i>230, std=5+0.5(i-230).
     */

    class msg_ssr_orbit_clock_bounds_t : public kaitai::kstruct {

    public:

        msg_ssr_orbit_clock_bounds_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_orbit_clock_bounds_t();

    private:
        bounds_header_t* m_header;
        uint8_t m_ssr_iod;
        uint8_t m_const_id;
        uint8_t m_n_sats;
        std::vector<orbit_clock_bound_t*>* m_orbit_clock_bounds;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Header of a bounds message.
         */
        bounds_header_t* header() const { return m_header; }

        /**
         * IOD of the SSR bound.
         */
        uint8_t ssr_iod() const { return m_ssr_iod; }

        /**
         * Constellation ID to which the SVs belong.
         */
        uint8_t const_id() const { return m_const_id; }

        /**
         * Number of satellites.
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Orbit and Clock Bounds per Satellite
         */
        std::vector<orbit_clock_bound_t*>* orbit_clock_bounds() const { return m_orbit_clock_bounds; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Note 1: Range: 0-17.5 m. i<= 200, mean = 0.01i; 200<i<=230,
     * mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
     */

    class msg_ssr_gridded_correction_bounds_t : public kaitai::kstruct {

    public:

        msg_ssr_gridded_correction_bounds_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_gridded_correction_bounds_t();

    private:
        bounds_header_t* m_header;
        uint8_t m_ssr_iod_atmo;
        uint16_t m_tile_set_id;
        uint16_t m_tile_id;
        uint8_t m_tropo_qi;
        uint16_t m_grid_point_id;
        tropospheric_delay_correction_t* m_tropo_delay_correction;
        uint8_t m_tropo_v_hydro_bound_mu;
        uint8_t m_tropo_v_hydro_bound_sig;
        uint8_t m_tropo_v_wet_bound_mu;
        uint8_t m_tropo_v_wet_bound_sig;
        uint8_t m_n_sats;
        std::vector<stec_sat_element_integrity_t*>* m_stec_sat_list;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Header of a bounds message.
         */
        bounds_header_t* header() const { return m_header; }

        /**
         * IOD of the correction.
         */
        uint8_t ssr_iod_atmo() const { return m_ssr_iod_atmo; }

        /**
         * Set this tile belongs to.
         */
        uint16_t tile_set_id() const { return m_tile_set_id; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        uint16_t tile_id() const { return m_tile_id; }

        /**
         * Tropo Quality Indicator. Similar to RTCM DF389.
         */
        uint8_t tropo_qi() const { return m_tropo_qi; }

        /**
         * Index of the Grid Point.
         */
        uint16_t grid_point_id() const { return m_grid_point_id; }

        /**
         * Tropospheric delay at grid point.
         */
        tropospheric_delay_correction_t* tropo_delay_correction() const { return m_tropo_delay_correction; }

        /**
         * Vertical Hydrostatic Error Bound Mean.
         */
        uint8_t tropo_v_hydro_bound_mu() const { return m_tropo_v_hydro_bound_mu; }

        /**
         * Vertical Hydrostatic Error Bound StDev.
         */
        uint8_t tropo_v_hydro_bound_sig() const { return m_tropo_v_hydro_bound_sig; }

        /**
         * Vertical Wet Error Bound Mean.
         */
        uint8_t tropo_v_wet_bound_mu() const { return m_tropo_v_wet_bound_mu; }

        /**
         * Vertical Wet Error Bound StDev.
         */
        uint8_t tropo_v_wet_bound_sig() const { return m_tropo_v_wet_bound_sig; }

        /**
         * Number of satellites.
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Array of STEC polynomial coefficients and its bounds for each space
         * vehicle.
         */
        std::vector<stec_sat_element_integrity_t*>* stec_sat_list() const { return m_stec_sat_list; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ssr_grid_definition_dep_a_t : public kaitai::kstruct {

    public:

        msg_ssr_grid_definition_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_grid_definition_dep_a_t();

    private:
        grid_definition_header_dep_a_t* m_header;
        std::vector<uint8_t>* m_rle_list;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Header of a Gridded Correction message
         */
        grid_definition_header_dep_a_t* header() const { return m_header; }

        /**
         * Run Length Encode list of quadrants that contain valid data. The
         * spec describes the encoding scheme in detail, but essentially the
         * index of the quadrants that contain transitions between valid and
         * invalid (and vice versa) are encoded as u8 integers.
         */
        std::vector<uint8_t>* rle_list() const { return m_rle_list; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Code biases are to be added to pseudorange. The corrections conform with
     * RTCMv3 MT 1059 / 1065.
     */

    class code_biases_content_t : public kaitai::kstruct {

    public:

        code_biases_content_t(kaitai::kstream* p__io, ssr_t::msg_ssr_code_biases_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~code_biases_content_t();

    private:
        uint8_t m_code;
        int16_t m_value;
        ssr_t* m__root;
        ssr_t::msg_ssr_code_biases_t* m__parent;

    public:

        /**
         * Signal encoded following RTCM specifications (DF380, DF381, DF382
         * and DF467).
         */
        uint8_t code() const { return m_code; }

        /**
         * Code bias value
         */
        int16_t value() const { return m_value; }
        ssr_t* _root() const { return m__root; }
        ssr_t::msg_ssr_code_biases_t* _parent() const { return m__parent; }
    };

    class msg_ssr_satellite_apc_t : public kaitai::kstruct {

    public:

        msg_ssr_satellite_apc_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_satellite_apc_t();

    private:
        gnss_t::gps_time_sec_t* m_time;
        uint8_t m_update_interval;
        uint8_t m_sol_id;
        uint8_t m_iod_ssr;
        std::vector<satellite_apc_t*>* m_apc;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GNSS reference time of the correction
         */
        gnss_t::gps_time_sec_t* time() const { return m_time; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        uint8_t update_interval() const { return m_update_interval; }

        /**
         * SSR Solution ID. Similar to RTCM DF415.
         */
        uint8_t sol_id() const { return m_sol_id; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        uint8_t iod_ssr() const { return m_iod_ssr; }

        /**
         * Satellite antenna phase center corrections
         */
        std::vector<satellite_apc_t*>* apc() const { return m_apc; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Phase biases are to be added to carrier phase measurements.
     */

    class phase_biases_content_t : public kaitai::kstruct {

    public:

        phase_biases_content_t(kaitai::kstream* p__io, ssr_t::msg_ssr_phase_biases_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~phase_biases_content_t();

    private:
        uint8_t m_code;
        uint8_t m_integer_indicator;
        uint8_t m_widelane_integer_indicator;
        uint8_t m_discontinuity_counter;
        int32_t m_bias;
        ssr_t* m__root;
        ssr_t::msg_ssr_phase_biases_t* m__parent;

    public:

        /**
         * Signal encoded following RTCM specifications (DF380, DF381, DF382
         * and DF467)
         */
        uint8_t code() const { return m_code; }

        /**
         * Indicator for integer property
         */
        uint8_t integer_indicator() const { return m_integer_indicator; }

        /**
         * Indicator for two groups of Wide-Lane(s) integer property
         */
        uint8_t widelane_integer_indicator() const { return m_widelane_integer_indicator; }

        /**
         * Signal phase discontinuity counter. Increased for every
         * discontinuity in phase.
         */
        uint8_t discontinuity_counter() const { return m_discontinuity_counter; }

        /**
         * Phase bias for specified signal
         */
        int32_t bias() const { return m_bias; }
        ssr_t* _root() const { return m__root; }
        ssr_t::msg_ssr_phase_biases_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ssr_tile_definition_dep_a_t : public kaitai::kstruct {

    public:

        msg_ssr_tile_definition_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_tile_definition_dep_a_t();

    private:
        uint16_t m_tile_set_id;
        uint16_t m_tile_id;
        int16_t m_corner_nw_lat;
        int16_t m_corner_nw_lon;
        uint16_t m_spacing_lat;
        uint16_t m_spacing_lon;
        uint16_t m_rows;
        uint16_t m_cols;
        uint64_t m_bitmask;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        uint16_t tile_set_id() const { return m_tile_set_id; }

        /**
         * Unique identifier of this tile in the tile set.
         * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
         */
        uint16_t tile_id() const { return m_tile_id; }

        /**
         * North-West corner correction point latitude.
         * 
         * The relation between the latitude X in the range [-90, 90] and the
         * coded number N is:
         * 
         * N = floor((X / 90) * 2^14)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
         */
        int16_t corner_nw_lat() const { return m_corner_nw_lat; }

        /**
         * North-West corner correction point longitude.
         * 
         * The relation between the longitude X in the range [-180, 180] and
         * the coded number N is:
         * 
         * N = floor((X / 180) * 2^15)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
         */
        int16_t corner_nw_lon() const { return m_corner_nw_lon; }

        /**
         * Spacing of the correction points in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
         */
        uint16_t spacing_lat() const { return m_spacing_lat; }

        /**
         * Spacing of the correction points in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
         */
        uint16_t spacing_lon() const { return m_spacing_lon; }

        /**
         * Number of steps in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
         */
        uint16_t rows() const { return m_rows; }

        /**
         * Number of steps in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
         */
        uint16_t cols() const { return m_cols; }

        /**
         * Specifies the availability of correction data at the correction
         * points in the array.
         * 
         * If a specific bit is enabled (set to 1), the correction is not
         * available. Only the first rows * cols bits are used, the remainder
         * are set to 0. If there are more then 64 correction points the
         * remaining corrections are always available.
         * 
         * Starting with the northwest corner of the array (top left on a north
         * oriented map) the correction points are enumerated with row
         * precedence - first row west to east, second row west to east, until
         * last row west to east - ending with the southeast corner of the
         * array.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
         * the definition of the bits is inverted.
         */
        uint64_t bitmask() const { return m_bitmask; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Orbit and clock bound.
     */

    class orbit_clock_bound_t : public kaitai::kstruct {

    public:

        orbit_clock_bound_t(kaitai::kstream* p__io, ssr_t::msg_ssr_orbit_clock_bounds_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~orbit_clock_bound_t();

    private:
        uint8_t m_sat_id;
        uint8_t m_orb_radial_bound_mu;
        uint8_t m_orb_along_bound_mu;
        uint8_t m_orb_cross_bound_mu;
        uint8_t m_orb_radial_bound_sig;
        uint8_t m_orb_along_bound_sig;
        uint8_t m_orb_cross_bound_sig;
        uint8_t m_clock_bound_mu;
        uint8_t m_clock_bound_sig;
        ssr_t* m__root;
        ssr_t::msg_ssr_orbit_clock_bounds_t* m__parent;

    public:

        /**
         * Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
         * or DF488 (BDS) depending on the constellation.
         */
        uint8_t sat_id() const { return m_sat_id; }

        /**
         * Mean Radial. See Note 1.
         */
        uint8_t orb_radial_bound_mu() const { return m_orb_radial_bound_mu; }

        /**
         * Mean Along-Track. See Note 1.
         */
        uint8_t orb_along_bound_mu() const { return m_orb_along_bound_mu; }

        /**
         * Mean Cross-Track. See Note 1.
         */
        uint8_t orb_cross_bound_mu() const { return m_orb_cross_bound_mu; }

        /**
         * Standard Deviation Radial. See Note 2.
         */
        uint8_t orb_radial_bound_sig() const { return m_orb_radial_bound_sig; }

        /**
         * Standard Deviation Along-Track. See Note 2.
         */
        uint8_t orb_along_bound_sig() const { return m_orb_along_bound_sig; }

        /**
         * Standard Deviation Cross-Track. See Note 2.
         */
        uint8_t orb_cross_bound_sig() const { return m_orb_cross_bound_sig; }

        /**
         * Clock Bound Mean. See Note 1.
         */
        uint8_t clock_bound_mu() const { return m_clock_bound_mu; }

        /**
         * Clock Bound Standard Deviation. See Note 2.
         */
        uint8_t clock_bound_sig() const { return m_clock_bound_sig; }
        ssr_t* _root() const { return m__root; }
        ssr_t::msg_ssr_orbit_clock_bounds_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ssr_gridded_correction_dep_a_t : public kaitai::kstruct {

    public:

        msg_ssr_gridded_correction_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_gridded_correction_dep_a_t();

    private:
        gridded_correction_header_dep_a_t* m_header;
        uint16_t m_index;
        tropospheric_delay_correction_t* m_tropo_delay_correction;
        std::vector<stec_residual_t*>* m_stec_residuals;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Header of a Gridded Correction message
         */
        gridded_correction_header_dep_a_t* header() const { return m_header; }

        /**
         * Index of the grid point
         */
        uint16_t index() const { return m_index; }

        /**
         * Wet and hydrostatic vertical delays (mean, stddev)
         */
        tropospheric_delay_correction_t* tropo_delay_correction() const { return m_tropo_delay_correction; }

        /**
         * STEC residuals for each satellite (mean, stddev)
         */
        std::vector<stec_residual_t*>* stec_residuals() const { return m_stec_residuals; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    class msg_ssr_orbit_clock_bounds_degradation_t : public kaitai::kstruct {

    public:

        msg_ssr_orbit_clock_bounds_degradation_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_orbit_clock_bounds_degradation_t();

    private:
        bounds_header_t* m_header;
        uint8_t m_ssr_iod;
        uint8_t m_const_id;
        uint64_t m_sat_bitmask;
        orbit_clock_bound_degradation_t* m_orbit_clock_bounds_degradation;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Header of a bounds message.
         */
        bounds_header_t* header() const { return m_header; }

        /**
         * IOD of the SSR bound degradation parameter.
         */
        uint8_t ssr_iod() const { return m_ssr_iod; }

        /**
         * Constellation ID to which the SVs belong.
         */
        uint8_t const_id() const { return m_const_id; }

        /**
         * Satellite Bit Mask. Put 1 for each satellite where the following
         * degradation parameters are applicable, 0 otherwise. Encoded
         * following RTCM DF394 specification.
         */
        uint64_t sat_bitmask() const { return m_sat_bitmask; }

        /**
         * Orbit and Clock Bounds Degradation Parameters
         */
        orbit_clock_bound_degradation_t* orbit_clock_bounds_degradation() const { return m_orbit_clock_bounds_degradation; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ssr_gridded_correction_no_std_dep_a_t : public kaitai::kstruct {

    public:

        msg_ssr_gridded_correction_no_std_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_gridded_correction_no_std_dep_a_t();

    private:
        gridded_correction_header_dep_a_t* m_header;
        uint16_t m_index;
        tropospheric_delay_correction_no_std_t* m_tropo_delay_correction;
        std::vector<stec_residual_no_std_t*>* m_stec_residuals;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Header of a Gridded Correction message
         */
        gridded_correction_header_dep_a_t* header() const { return m_header; }

        /**
         * Index of the grid point
         */
        uint16_t index() const { return m_index; }

        /**
         * Wet and hydrostatic vertical delays
         */
        tropospheric_delay_correction_no_std_t* tropo_delay_correction() const { return m_tropo_delay_correction; }

        /**
         * STEC residuals for each satellite
         */
        std::vector<stec_residual_no_std_t*>* stec_residuals() const { return m_stec_residuals; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    class msg_ssr_code_phase_biases_bounds_t : public kaitai::kstruct {

    public:

        msg_ssr_code_phase_biases_bounds_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_code_phase_biases_bounds_t();

    private:
        bounds_header_t* m_header;
        uint8_t m_ssr_iod;
        uint8_t m_const_id;
        uint8_t m_n_sats_signals;
        std::vector<code_phase_biases_sat_sig_t*>* m_satellites_signals;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Header of a bounds message.
         */
        bounds_header_t* header() const { return m_header; }

        /**
         * IOD of the SSR bound.
         */
        uint8_t ssr_iod() const { return m_ssr_iod; }

        /**
         * Constellation ID to which the SVs belong.
         */
        uint8_t const_id() const { return m_const_id; }

        /**
         * Number of satellite-signal couples.
         */
        uint8_t n_sats_signals() const { return m_n_sats_signals; }

        /**
         * Code and Phase Biases Bounds per Satellite-Signal couple.
         */
        std::vector<code_phase_biases_sat_sig_t*>* satellites_signals() const { return m_satellites_signals; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The precise code biases message is to be added to the pseudorange of the
     * corresponding signal to get corrected pseudorange. It is an equivalent
     * to the 1059 / 1065 RTCM message types.
     */

    class msg_ssr_code_biases_t : public kaitai::kstruct {

    public:

        msg_ssr_code_biases_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_code_biases_t();

    private:
        gnss_t::gps_time_sec_t* m_time;
        gnss_t::gnss_signal_t* m_sid;
        uint8_t m_update_interval;
        uint8_t m_iod_ssr;
        std::vector<code_biases_content_t*>* m_biases;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GNSS reference time of the correction
         */
        gnss_t::gps_time_sec_t* time() const { return m_time; }

        /**
         * GNSS signal identifier (16 bit)
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        uint8_t update_interval() const { return m_update_interval; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        uint8_t iod_ssr() const { return m_iod_ssr; }

        /**
         * Code biases for the different satellite signals
         */
        std::vector<code_biases_content_t*>* biases() const { return m_biases; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Provides the correction point coordinates for the atmospheric correction
     * values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
     * messages.
     * 
     * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
     * element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
     * correction points, not lists of points.
     */

    class msg_ssr_tile_definition_t : public kaitai::kstruct {

    public:

        msg_ssr_tile_definition_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_tile_definition_t();

    private:
        gnss_t::gps_time_sec_t* m_time;
        uint8_t m_update_interval;
        uint8_t m_sol_id;
        uint8_t m_iod_atmo;
        uint16_t m_tile_set_id;
        uint16_t m_tile_id;
        int16_t m_corner_nw_lat;
        int16_t m_corner_nw_lon;
        uint16_t m_spacing_lat;
        uint16_t m_spacing_lon;
        uint16_t m_rows;
        uint16_t m_cols;
        uint64_t m_bitmask;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GNSS reference time of the correction
         */
        gnss_t::gps_time_sec_t* time() const { return m_time; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        uint8_t update_interval() const { return m_update_interval; }

        /**
         * SSR Solution ID. Similar to RTCM DF415.
         */
        uint8_t sol_id() const { return m_sol_id; }

        /**
         * IOD of the SSR atmospheric correction.
         */
        uint8_t iod_atmo() const { return m_iod_atmo; }

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        uint16_t tile_set_id() const { return m_tile_set_id; }

        /**
         * Unique identifier of this tile in the tile set.
         * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
         */
        uint16_t tile_id() const { return m_tile_id; }

        /**
         * North-West corner correction point latitude.
         * 
         * The relation between the latitude X in the range [-90, 90] and the
         * coded number N is:  N = floor((X / 90) * 2^14)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
         */
        int16_t corner_nw_lat() const { return m_corner_nw_lat; }

        /**
         * North-West corner correction point longitude.
         * 
         * The relation between the longitude X in the range [-180, 180] and
         * the coded number N is: N = floor((X / 180) * 2^15)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
         */
        int16_t corner_nw_lon() const { return m_corner_nw_lon; }

        /**
         * Spacing of the correction points in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
         */
        uint16_t spacing_lat() const { return m_spacing_lat; }

        /**
         * Spacing of the correction points in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
         */
        uint16_t spacing_lon() const { return m_spacing_lon; }

        /**
         * Number of steps in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
         */
        uint16_t rows() const { return m_rows; }

        /**
         * Number of steps in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
         */
        uint16_t cols() const { return m_cols; }

        /**
         * Specifies the absence of correction data at the correction points in
         * the array (grid).
         * 
         * Only the first rows * cols bits are used, and if a specific bit is
         * enabled (set to 1), the correction is not available. If there are
         * more than 64 correction points the remaining corrections are always
         * available.
         * 
         * The correction points are packed by rows, starting with the
         * northwest corner of the array (top-left on a north oriented map),
         * with each row spanning west to east, ending with the southeast
         * corner of the array.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
         * the definition of the bits is inverted.
         */
        uint64_t bitmask() const { return m_bitmask; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Orbit and clock bound degradation.
     */

    class orbit_clock_bound_degradation_t : public kaitai::kstruct {

    public:

        orbit_clock_bound_degradation_t(kaitai::kstream* p__io, ssr_t::msg_ssr_orbit_clock_bounds_degradation_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~orbit_clock_bound_degradation_t();

    private:
        uint8_t m_orb_radial_bound_mu_dot;
        uint8_t m_orb_along_bound_mu_dot;
        uint8_t m_orb_cross_bound_mu_dot;
        uint8_t m_orb_radial_bound_sig_dot;
        uint8_t m_orb_along_bound_sig_dot;
        uint8_t m_orb_cross_bound_sig_dot;
        uint8_t m_clock_bound_mu_dot;
        uint8_t m_clock_bound_sig_dot;
        ssr_t* m__root;
        ssr_t::msg_ssr_orbit_clock_bounds_degradation_t* m__parent;

    public:

        /**
         * Orbit Bound Mean Radial First derivative. Range: 0-0.255 m/s
         */
        uint8_t orb_radial_bound_mu_dot() const { return m_orb_radial_bound_mu_dot; }

        /**
         * Orbit Bound Mean Along-Track First derivative. Range: 0-0.255 m/s
         */
        uint8_t orb_along_bound_mu_dot() const { return m_orb_along_bound_mu_dot; }

        /**
         * Orbit Bound Mean Cross-Track First derivative. Range: 0-0.255 m/s
         */
        uint8_t orb_cross_bound_mu_dot() const { return m_orb_cross_bound_mu_dot; }

        /**
         * Orbit Bound Standard Deviation Radial First derivative. Range:
         * 0-0.255 m/s
         */
        uint8_t orb_radial_bound_sig_dot() const { return m_orb_radial_bound_sig_dot; }

        /**
         * Orbit Bound Standard Deviation Along-Track First derivative. Range:
         * 0-0.255 m/s
         */
        uint8_t orb_along_bound_sig_dot() const { return m_orb_along_bound_sig_dot; }

        /**
         * Orbit Bound Standard Deviation Cross-Track First derivative. Range:
         * 0-0.255 m/s
         */
        uint8_t orb_cross_bound_sig_dot() const { return m_orb_cross_bound_sig_dot; }

        /**
         * Clock Bound Mean First derivative. Range: 0-0.255 m/s
         */
        uint8_t clock_bound_mu_dot() const { return m_clock_bound_mu_dot; }

        /**
         * Clock Bound Standard Deviation First derivative. Range: 0-0.255 m/s
         */
        uint8_t clock_bound_sig_dot() const { return m_clock_bound_sig_dot; }
        ssr_t* _root() const { return m__root; }
        ssr_t::msg_ssr_orbit_clock_bounds_degradation_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ssr_satellite_apc_dep_t : public kaitai::kstruct {

    public:

        msg_ssr_satellite_apc_dep_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_satellite_apc_dep_t();

    private:
        std::vector<satellite_apc_t*>* m_apc;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Satellite antenna phase center corrections
         */
        std::vector<satellite_apc_t*>* apc() const { return m_apc; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Troposphere vertical delays (mean and standard deviation) at the grid
     * point.
     */

    class tropospheric_delay_correction_t : public kaitai::kstruct {

    public:

        tropospheric_delay_correction_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~tropospheric_delay_correction_t();

    private:
        int16_t m_hydro;
        int8_t m_wet;
        uint8_t m_stddev;
        ssr_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Hydrostatic vertical delay. Add 2.3 m to get actual value.
         */
        int16_t hydro() const { return m_hydro; }

        /**
         * Wet vertical delay. Add 0.252 m to get actual value.
         */
        int8_t wet() const { return m_wet; }

        /**
         * Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
         * value/16) - 1)
         */
        uint8_t stddev() const { return m_stddev; }
        ssr_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_ssr_tile_definition_dep_b_t : public kaitai::kstruct {

    public:

        msg_ssr_tile_definition_dep_b_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_tile_definition_dep_b_t();

    private:
        uint8_t m_ssr_sol_id;
        uint16_t m_tile_set_id;
        uint16_t m_tile_id;
        int16_t m_corner_nw_lat;
        int16_t m_corner_nw_lon;
        uint16_t m_spacing_lat;
        uint16_t m_spacing_lon;
        uint16_t m_rows;
        uint16_t m_cols;
        uint64_t m_bitmask;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * SSR Solution ID.
         */
        uint8_t ssr_sol_id() const { return m_ssr_sol_id; }

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        uint16_t tile_set_id() const { return m_tile_set_id; }

        /**
         * Unique identifier of this tile in the tile set.
         * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
         */
        uint16_t tile_id() const { return m_tile_id; }

        /**
         * North-West corner correction point latitude.
         * 
         * The relation between the latitude X in the range [-90, 90] and the
         * coded number N is:
         * 
         * N = floor((X / 90) * 2^14)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
         */
        int16_t corner_nw_lat() const { return m_corner_nw_lat; }

        /**
         * North-West corner correction point longitude.
         * 
         * The relation between the longitude X in the range [-180, 180] and
         * the coded number N is:
         * 
         * N = floor((X / 180) * 2^15)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
         */
        int16_t corner_nw_lon() const { return m_corner_nw_lon; }

        /**
         * Spacing of the correction points in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
         */
        uint16_t spacing_lat() const { return m_spacing_lat; }

        /**
         * Spacing of the correction points in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
         */
        uint16_t spacing_lon() const { return m_spacing_lon; }

        /**
         * Number of steps in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
         */
        uint16_t rows() const { return m_rows; }

        /**
         * Number of steps in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
         */
        uint16_t cols() const { return m_cols; }

        /**
         * Specifies the availability of correction data at the correction
         * points in the array.
         * 
         * If a specific bit is enabled (set to 1), the correction is not
         * available. Only the first rows * cols bits are used, the remainder
         * are set to 0. If there are more then 64 correction points the
         * remaining corrections are always available.
         * 
         * Starting with the northwest corner of the array (top left on a north
         * oriented map) the correction points are enumerated with row
         * precedence - first row west to east, second row west to east, until
         * last row west to east - ending with the southeast corner of the
         * array.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
         * the definition of the bits is inverted.
         */
        uint64_t bitmask() const { return m_bitmask; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The precise phase biases message contains the biases to be added to the
     * carrier phase of the corresponding signal to get corrected carrier phase
     * measurement, as well as the satellite yaw angle to be applied to compute
     * the phase wind-up correction. It is typically an equivalent to the 1265
     * RTCM message types.
     */

    class msg_ssr_phase_biases_t : public kaitai::kstruct {

    public:

        msg_ssr_phase_biases_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, ssr_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_phase_biases_t();

    private:
        gnss_t::gps_time_sec_t* m_time;
        gnss_t::gnss_signal_t* m_sid;
        uint8_t m_update_interval;
        uint8_t m_iod_ssr;
        uint8_t m_dispersive_bias;
        uint8_t m_mw_consistency;
        uint16_t m_yaw;
        int8_t m_yaw_rate;
        std::vector<phase_biases_content_t*>* m_biases;
        ssr_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GNSS reference time of the correction
         */
        gnss_t::gps_time_sec_t* time() const { return m_time; }

        /**
         * GNSS signal identifier (16 bit)
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        uint8_t update_interval() const { return m_update_interval; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        uint8_t iod_ssr() const { return m_iod_ssr; }

        /**
         * Indicator for the dispersive phase biases property.
         */
        uint8_t dispersive_bias() const { return m_dispersive_bias; }

        /**
         * Consistency indicator for Melbourne-Wubbena linear combinations
         */
        uint8_t mw_consistency() const { return m_mw_consistency; }

        /**
         * Satellite yaw angle
         */
        uint16_t yaw() const { return m_yaw; }

        /**
         * Satellite yaw angle rate
         */
        int8_t yaw_rate() const { return m_yaw_rate; }

        /**
         * Phase biases corrections for a satellite being tracked.
         */
        std::vector<phase_biases_content_t*>* biases() const { return m_biases; }
        ssr_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

private:
    ssr_t* m__root;
    kaitai::kstruct* m__parent;

public:
    ssr_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // SSR_H_
