#ifndef INTEGRITY_H_
#define INTEGRITY_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class integrity_t : public kaitai::kstruct {

public:
    class msg_ssr_flag_satellites_t;
    class msg_ssr_flag_iono_tile_sat_los_t;
    class msg_ssr_flag_iono_grid_point_sat_los_t;
    class integrity_ssr_header_t;
    class msg_acknowledge_t;
    class msg_ssr_flag_iono_grid_points_t;
    class msg_ssr_flag_tropo_grid_points_t;
    class msg_ssr_flag_high_level_t;

    integrity_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, integrity_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~integrity_t();

    class msg_ssr_flag_satellites_t : public kaitai::kstruct {

    public:

        msg_ssr_flag_satellites_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, integrity_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_flag_satellites_t();

    private:
        gnss_t::gps_time_sec_t* m_obs_time;
        uint8_t m_num_msgs;
        uint8_t m_seq_num;
        uint8_t m_ssr_sol_id;
        uint8_t m_chain_id;
        uint8_t m_const_id;
        uint8_t m_n_faulty_sats;
        std::vector<uint8_t>* m_faulty_sats;
        integrity_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * GNSS reference time of the observation used to generate the flag.
         */
        gnss_t::gps_time_sec_t* obs_time() const { return m_obs_time; }

        /**
         * Number of messages in the dataset
         */
        uint8_t num_msgs() const { return m_num_msgs; }

        /**
         * Position of this message in the dataset
         */
        uint8_t seq_num() const { return m_seq_num; }

        /**
         * SSR Solution ID.
         */
        uint8_t ssr_sol_id() const { return m_ssr_sol_id; }

        /**
         * Chain and type of flag.
         */
        uint8_t chain_id() const { return m_chain_id; }

        /**
         * Constellation ID.
         */
        uint8_t const_id() const { return m_const_id; }

        /**
         * Number of faulty satellites.
         */
        uint8_t n_faulty_sats() const { return m_n_faulty_sats; }

        /**
         * List of faulty satellites.
         */
        std::vector<uint8_t>* faulty_sats() const { return m_faulty_sats; }
        integrity_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    class msg_ssr_flag_iono_tile_sat_los_t : public kaitai::kstruct {

    public:

        msg_ssr_flag_iono_tile_sat_los_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, integrity_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_flag_iono_tile_sat_los_t();

    private:
        integrity_ssr_header_t* m_header;
        uint8_t m_n_faulty_los;
        std::vector<gnss_t::sv_id_t*>* m_faulty_los;
        integrity_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Header of an integrity message.
         */
        integrity_ssr_header_t* header() const { return m_header; }

        /**
         * Number of faulty LOS.
         */
        uint8_t n_faulty_los() const { return m_n_faulty_los; }

        /**
         * List of faulty LOS
         */
        std::vector<gnss_t::sv_id_t*>* faulty_los() const { return m_faulty_los; }
        integrity_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    class msg_ssr_flag_iono_grid_point_sat_los_t : public kaitai::kstruct {

    public:

        msg_ssr_flag_iono_grid_point_sat_los_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, integrity_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_flag_iono_grid_point_sat_los_t();

    private:
        integrity_ssr_header_t* m_header;
        uint16_t m_grid_point_id;
        uint8_t m_n_faulty_los;
        std::vector<gnss_t::sv_id_t*>* m_faulty_los;
        integrity_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Header of an integrity message.
         */
        integrity_ssr_header_t* header() const { return m_header; }

        /**
         * Index of the grid point.
         */
        uint16_t grid_point_id() const { return m_grid_point_id; }

        /**
         * Number of faulty LOS.
         */
        uint8_t n_faulty_los() const { return m_n_faulty_los; }

        /**
         * List of faulty LOS
         */
        std::vector<gnss_t::sv_id_t*>* faulty_los() const { return m_faulty_los; }
        integrity_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    class integrity_ssr_header_t : public kaitai::kstruct {

    public:

        integrity_ssr_header_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, integrity_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~integrity_ssr_header_t();

    private:
        gnss_t::gps_time_sec_t* m_obs_time;
        uint8_t m_num_msgs;
        uint8_t m_seq_num;
        uint8_t m_ssr_sol_id;
        uint16_t m_tile_set_id;
        uint16_t m_tile_id;
        uint8_t m_chain_id;
        integrity_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * GNSS reference time of the observation used to generate the flag.
         */
        gnss_t::gps_time_sec_t* obs_time() const { return m_obs_time; }

        /**
         * Number of messages in the dataset
         */
        uint8_t num_msgs() const { return m_num_msgs; }

        /**
         * Position of this message in the dataset
         */
        uint8_t seq_num() const { return m_seq_num; }

        /**
         * SSR Solution ID.
         */
        uint8_t ssr_sol_id() const { return m_ssr_sol_id; }

        /**
         * Unique identifier of the set this tile belongs to.
         */
        uint16_t tile_set_id() const { return m_tile_set_id; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        uint16_t tile_id() const { return m_tile_id; }

        /**
         * Chain and type of flag.
         */
        uint8_t chain_id() const { return m_chain_id; }
        integrity_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class msg_acknowledge_t : public kaitai::kstruct {

    public:

        msg_acknowledge_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, integrity_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_acknowledge_t();

    private:
        uint8_t m_request_id;
        uint32_t m_area_id;
        uint8_t m_response_code;
        uint16_t m_correction_mask_on_demand;
        uint16_t m_correction_mask_stream;
        uint8_t m_solution_id;
        integrity_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Echo of the request ID field from the corresponding CRA message, or
         * 255 if no request ID was provided.
         */
        uint8_t request_id() const { return m_request_id; }

        /**
         * Echo of the Area ID field from the corresponding CRA message.
         */
        uint32_t area_id() const { return m_area_id; }

        /**
         * Reported status of the request.
         */
        uint8_t response_code() const { return m_response_code; }

        /**
         * Contains the message group(s) that will be sent in response from the
         * corresponding CRA correction mask. An echo of the correction mask
         * field from the corresponding CRA message.
         */
        uint16_t correction_mask_on_demand() const { return m_correction_mask_on_demand; }

        /**
         * For future expansion. Always set to 0.
         */
        uint16_t correction_mask_stream() const { return m_correction_mask_stream; }

        /**
         * The solution ID of the instance providing the corrections.
         */
        uint8_t solution_id() const { return m_solution_id; }
        integrity_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    class msg_ssr_flag_iono_grid_points_t : public kaitai::kstruct {

    public:

        msg_ssr_flag_iono_grid_points_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, integrity_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_flag_iono_grid_points_t();

    private:
        integrity_ssr_header_t* m_header;
        uint8_t m_n_faulty_points;
        std::vector<uint16_t>* m_faulty_points;
        integrity_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Header of an integrity message.
         */
        integrity_ssr_header_t* header() const { return m_header; }

        /**
         * Number of faulty grid points.
         */
        uint8_t n_faulty_points() const { return m_n_faulty_points; }

        /**
         * List of faulty grid points.
         */
        std::vector<uint16_t>* faulty_points() const { return m_faulty_points; }
        integrity_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    class msg_ssr_flag_tropo_grid_points_t : public kaitai::kstruct {

    public:

        msg_ssr_flag_tropo_grid_points_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, integrity_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_flag_tropo_grid_points_t();

    private:
        integrity_ssr_header_t* m_header;
        uint8_t m_n_faulty_points;
        std::vector<uint16_t>* m_faulty_points;
        integrity_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Header of an integrity message.
         */
        integrity_ssr_header_t* header() const { return m_header; }

        /**
         * Number of faulty grid points.
         */
        uint8_t n_faulty_points() const { return m_n_faulty_points; }

        /**
         * List of faulty grid points.
         */
        std::vector<uint16_t>* faulty_points() const { return m_faulty_points; }
        integrity_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Integrity monitoring flags for multiple aggregated elements. An element
     * could be a satellite, SSR grid point, or SSR tile. A group of aggregated
     * elements being monitored for integrity could refer to:
     * 
     * - Satellites in a particular {GPS, GAL, BDS} constellation.
     * 
     * - Satellites in the line-of-sight of a particular SSR tile.
     * 
     * - Satellites in the line-of-sight of a particular SSR grid point.
     * 
     * The integrity usage for a group of aggregated elements varies according
     * to the integrity flag of the satellites comprising that group.
     * 
     * SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the
     * integrity check and have flag INTEGRITY_FLAG_OK.
     * 
     * SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group
     * failed the integrity check. Refer to more granular integrity messages
     * for details on the specific failing elements.
     * 
     * SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the
     * integrity check, do not use for positioning.
     * 
     * SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag
     * of elements in the group.
     */

    class msg_ssr_flag_high_level_t : public kaitai::kstruct {

    public:

        msg_ssr_flag_high_level_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, integrity_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ssr_flag_high_level_t();

    private:
        gnss_t::gps_time_sec_t* m_obs_time;
        gnss_t::gps_time_sec_t* m_corr_time;
        uint8_t m_ssr_sol_id;
        uint16_t m_tile_set_id;
        uint16_t m_tile_id;
        uint8_t m_chain_id;
        uint8_t m_use_gps_sat;
        uint8_t m_use_gal_sat;
        uint8_t m_use_bds_sat;
        std::vector<uint8_t>* m_reserved;
        uint8_t m_use_tropo_grid_points;
        uint8_t m_use_iono_grid_points;
        uint8_t m_use_iono_tile_sat_los;
        uint8_t m_use_iono_grid_point_sat_los;
        integrity_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * GNSS reference time of the observation used to generate the flag.
         */
        gnss_t::gps_time_sec_t* obs_time() const { return m_obs_time; }

        /**
         * GNSS reference time of the correction associated to the flag.
         */
        gnss_t::gps_time_sec_t* corr_time() const { return m_corr_time; }

        /**
         * SSR Solution ID.
         */
        uint8_t ssr_sol_id() const { return m_ssr_sol_id; }

        /**
         * Unique identifier of the set this tile belongs to.
         */
        uint16_t tile_set_id() const { return m_tile_set_id; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        uint16_t tile_id() const { return m_tile_id; }

        /**
         * Chain and type of flag.
         */
        uint8_t chain_id() const { return m_chain_id; }

        /**
         * Use GPS satellites.
         */
        uint8_t use_gps_sat() const { return m_use_gps_sat; }

        /**
         * Use GAL satellites.
         */
        uint8_t use_gal_sat() const { return m_use_gal_sat; }

        /**
         * Use BDS satellites.
         */
        uint8_t use_bds_sat() const { return m_use_bds_sat; }

        /**
         * Reserved
         */
        std::vector<uint8_t>* reserved() const { return m_reserved; }

        /**
         * Use tropo grid points.
         */
        uint8_t use_tropo_grid_points() const { return m_use_tropo_grid_points; }

        /**
         * Use iono grid points.
         */
        uint8_t use_iono_grid_points() const { return m_use_iono_grid_points; }

        /**
         * Use iono tile satellite LoS.
         */
        uint8_t use_iono_tile_sat_los() const { return m_use_iono_tile_sat_los; }

        /**
         * Use iono grid point satellite LoS.
         */
        uint8_t use_iono_grid_point_sat_los() const { return m_use_iono_grid_point_sat_los; }
        integrity_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

private:
    integrity_t* m__root;
    kaitai::kstruct* m__parent;

public:
    integrity_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // INTEGRITY_H_
