#ifndef NAVIGATION_H_
#define NAVIGATION_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class navigation_t : public kaitai::kstruct {

public:
    class msg_pos_llh_dep_a_t;
    class msg_protection_level_dep_a_t;
    class msg_pos_llh_cov_t;
    class msg_vel_ned_dep_a_t;
    class msg_vel_ned_cov_t;
    class msg_utc_time_t;
    class msg_pos_ecef_cov_gnss_t;
    class msg_vel_ned_gnss_t;
    class msg_vel_ned_cov_gnss_t;
    class msg_baseline_ned_dep_a_t;
    class msg_vel_ecef_dep_a_t;
    class msg_reference_frame_param_t;
    class msg_pose_relative_t;
    class msg_vel_ecef_cov_t;
    class msg_vel_body_t;
    class msg_vel_ecef_gnss_t;
    class msg_vel_ecef_t;
    class msg_pos_llh_cov_gnss_t;
    class msg_baseline_ecef_t;
    class msg_dops_dep_a_t;
    class msg_pos_ecef_t;
    class msg_age_corrections_t;
    class msg_vel_ecef_cov_gnss_t;
    class msg_protection_level_t;
    class msg_pos_ecef_cov_t;
    class msg_pos_ecef_gnss_t;
    class msg_vel_ned_t;
    class msg_utc_leap_second_t;
    class msg_gps_time_dep_a_t;
    class msg_pos_llh_gnss_t;
    class msg_utc_time_gnss_t;
    class msg_vel_cog_t;
    class msg_baseline_ned_t;
    class msg_pos_llh_t;
    class msg_baseline_heading_dep_a_t;
    class msg_gps_time_gnss_t;
    class msg_baseline_ecef_dep_a_t;
    class msg_gps_time_t;
    class msg_dops_t;
    class msg_pos_ecef_dep_a_t;
    class estimated_horizontal_error_ellipse_t;
    class msg_pos_llh_acc_t;

    navigation_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, navigation_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~navigation_t();

    /**
     * Deprecated.
     */

    class msg_pos_llh_dep_a_t : public kaitai::kstruct {

    public:

        msg_pos_llh_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_pos_llh_dep_a_t();

    private:
        uint32_t m_tow;
        double m_lat;
        double m_lon;
        double m_height;
        uint16_t m_h_accuracy;
        uint16_t m_v_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

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

        /**
         * Horizontal position accuracy estimate (not implemented). Defaults to
         * 0.
         */
        uint16_t h_accuracy() const { return m_h_accuracy; }

        /**
         * Vertical position accuracy estimate (not implemented). Defaults to
         * 0.
         */
        uint16_t v_accuracy() const { return m_v_accuracy; }

        /**
         * Number of satellites used in solution.
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_protection_level_dep_a_t : public kaitai::kstruct {

    public:

        msg_protection_level_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_protection_level_dep_a_t();

    private:
        uint32_t m_tow;
        uint16_t m_vpl;
        uint16_t m_hpl;
        double m_lat;
        double m_lon;
        double m_height;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Vertical protection level
         */
        uint16_t vpl() const { return m_vpl; }

        /**
         * Horizontal protection level
         */
        uint16_t hpl() const { return m_hpl; }

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

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This position solution message reports the absolute geodetic coordinates
     * and the status (single point vs pseudo-absolute RTK) of the position
     * solution as well as the upper triangle of the 3x3 covariance matrix.
     * The position information and Fix Mode flags follow the MSG_POS_LLH
     * message.  Since the covariance matrix is computed in the local-level
     * North, East, Down frame, the covariance terms follow that convention.
     * Thus, covariances are reported against the "downward" measurement and
     * care should be taken with the sign convention.
     * 
     * The values in this message are from GNSS measurements fused with
     * inertial measurements. To get values from GNSS measurements only use
     * MSG_POS_LLH_COV_GNSS.
     */

    class msg_pos_llh_cov_t : public kaitai::kstruct {

    public:

        msg_pos_llh_cov_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_pos_llh_cov_t();

    private:
        uint32_t m_tow;
        double m_lat;
        double m_lon;
        double m_height;
        float m_cov_n_n;
        float m_cov_n_e;
        float m_cov_n_d;
        float m_cov_e_e;
        float m_cov_e_d;
        float m_cov_d_d;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Latitude
         */
        double lat() const { return m_lat; }

        /**
         * Longitude
         */
        double lon() const { return m_lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        double height() const { return m_height; }

        /**
         * Estimated variance of northing
         */
        float cov_n_n() const { return m_cov_n_n; }

        /**
         * Covariance of northing and easting
         */
        float cov_n_e() const { return m_cov_n_e; }

        /**
         * Covariance of northing and downward measurement
         */
        float cov_n_d() const { return m_cov_n_d; }

        /**
         * Estimated variance of easting
         */
        float cov_e_e() const { return m_cov_e_e; }

        /**
         * Covariance of easting and downward measurement
         */
        float cov_e_d() const { return m_cov_e_d; }

        /**
         * Estimated variance of downward measurement
         */
        float cov_d_d() const { return m_cov_d_d; }

        /**
         * Number of satellites used in solution.
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_vel_ned_dep_a_t : public kaitai::kstruct {

    public:

        msg_vel_ned_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_vel_ned_dep_a_t();

    private:
        uint32_t m_tow;
        int32_t m_n;
        int32_t m_e;
        int32_t m_d;
        uint16_t m_h_accuracy;
        uint16_t m_v_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Velocity North coordinate
         */
        int32_t n() const { return m_n; }

        /**
         * Velocity East coordinate
         */
        int32_t e() const { return m_e; }

        /**
         * Velocity Down coordinate
         */
        int32_t d() const { return m_d; }

        /**
         * Horizontal velocity accuracy estimate (not implemented). Defaults to
         * 0.
         */
        uint16_t h_accuracy() const { return m_h_accuracy; }

        /**
         * Vertical velocity accuracy estimate (not implemented). Defaults to
         * 0.
         */
        uint16_t v_accuracy() const { return m_v_accuracy; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags (reserved)
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the velocity in local North East Down (NED)
     * coordinates. The NED coordinate system is defined as the local WGS84
     * tangent plane centered at the current position. The full GPS time is
     * given by the preceding MSG_GPS_TIME with the matching time-of-week
     * (tow). This message is similar to the MSG_VEL_NED, but it includes the
     * upper triangular portion of the 3x3 covariance matrix.
     * 
     * The values in this message are from GNSS measurements fused with
     * inertial measurements. To get values from GNSS measurements only use
     * MSG_VEL_NED_COV_GNSS.
     */

    class msg_vel_ned_cov_t : public kaitai::kstruct {

    public:

        msg_vel_ned_cov_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_vel_ned_cov_t();

    private:
        uint32_t m_tow;
        int32_t m_n;
        int32_t m_e;
        int32_t m_d;
        float m_cov_n_n;
        float m_cov_n_e;
        float m_cov_n_d;
        float m_cov_e_e;
        float m_cov_e_d;
        float m_cov_d_d;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Velocity North coordinate
         */
        int32_t n() const { return m_n; }

        /**
         * Velocity East coordinate
         */
        int32_t e() const { return m_e; }

        /**
         * Velocity Down coordinate
         */
        int32_t d() const { return m_d; }

        /**
         * Estimated variance of northward measurement
         */
        float cov_n_n() const { return m_cov_n_n; }

        /**
         * Covariance of northward and eastward measurement
         */
        float cov_n_e() const { return m_cov_n_e; }

        /**
         * Covariance of northward and downward measurement
         */
        float cov_n_d() const { return m_cov_n_d; }

        /**
         * Estimated variance of eastward measurement
         */
        float cov_e_e() const { return m_cov_e_e; }

        /**
         * Covariance of eastward and downward measurement
         */
        float cov_e_d() const { return m_cov_e_d; }

        /**
         * Estimated variance of downward measurement
         */
        float cov_d_d() const { return m_cov_d_d; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the Universal Coordinated Time (UTC).  Note the
     * flags which indicate the source of the UTC offset value and source of
     * the time fix.
     * 
     * The values in this message are from GNSS measurements fused with
     * inertial measurements. To get values from GNSS measurements only use
     * MSG_UTC_TIME_GNSS.
     */

    class msg_utc_time_t : public kaitai::kstruct {

    public:

        msg_utc_time_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_utc_time_t();

    private:
        uint8_t m_flags;
        uint32_t m_tow;
        uint16_t m_year;
        uint8_t m_month;
        uint8_t m_day;
        uint8_t m_hours;
        uint8_t m_minutes;
        uint8_t m_seconds;
        uint32_t m_ns;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Indicates source and time validity
         */
        uint8_t flags() const { return m_flags; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        uint32_t tow() const { return m_tow; }

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
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The position solution message reports absolute Earth Centered Earth
     * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
     * RTK) of the position solution. The message also reports the upper
     * triangular portion of the 3x3 covariance matrix. If the receiver knows
     * the surveyed position of the base station and has an RTK solution, this
     * reports a pseudo-absolute position solution using the base station
     * position and the rover's RTK baseline vector. The full GPS time is given
     * by the preceding MSG_GPS_TIME_GNSS with the matching time-of-week (tow).
     * 
     * The values in this message are from GNSS measurements only. To get
     * values fused with inertial measurements use MSG_POS_ECEF_COV.
     */

    class msg_pos_ecef_cov_gnss_t : public kaitai::kstruct {

    public:

        msg_pos_ecef_cov_gnss_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_pos_ecef_cov_gnss_t();

    private:
        uint32_t m_tow;
        double m_x;
        double m_y;
        double m_z;
        float m_cov_x_x;
        float m_cov_x_y;
        float m_cov_x_z;
        float m_cov_y_y;
        float m_cov_y_z;
        float m_cov_z_z;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

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

        /**
         * Estimated variance of x
         */
        float cov_x_x() const { return m_cov_x_x; }

        /**
         * Estimated covariance of x and y
         */
        float cov_x_y() const { return m_cov_x_y; }

        /**
         * Estimated covariance of x and z
         */
        float cov_x_z() const { return m_cov_x_z; }

        /**
         * Estimated variance of y
         */
        float cov_y_y() const { return m_cov_y_y; }

        /**
         * Estimated covariance of y and z
         */
        float cov_y_z() const { return m_cov_y_z; }

        /**
         * Estimated variance of z
         */
        float cov_z_z() const { return m_cov_z_z; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the velocity in local North East Down (NED)
     * coordinates. The NED coordinate system is defined as the local WGS84
     * tangent plane centered at the current position. The full GPS time is
     * given by the preceding MSG_GPS_TIME_GNSS with the matching time-of-week
     * (tow).
     * 
     * The values in this message are from GNSS measurements only. To get
     * values fused with inertial measurements use MSG_VEL_NED.
     */

    class msg_vel_ned_gnss_t : public kaitai::kstruct {

    public:

        msg_vel_ned_gnss_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_vel_ned_gnss_t();

    private:
        uint32_t m_tow;
        int32_t m_n;
        int32_t m_e;
        int32_t m_d;
        uint16_t m_h_accuracy;
        uint16_t m_v_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Velocity North coordinate
         */
        int32_t n() const { return m_n; }

        /**
         * Velocity East coordinate
         */
        int32_t e() const { return m_e; }

        /**
         * Velocity Down coordinate
         */
        int32_t d() const { return m_d; }

        /**
         * Horizontal velocity estimated standard deviation
         */
        uint16_t h_accuracy() const { return m_h_accuracy; }

        /**
         * Vertical velocity estimated standard deviation
         */
        uint16_t v_accuracy() const { return m_v_accuracy; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the velocity in local North East Down (NED)
     * coordinates. The NED coordinate system is defined as the local WGS84
     * tangent plane centered at the current position. The full GPS time is
     * given by the preceding MSG_GPS_TIME_GNSS with the matching time-of-week
     * (tow). This message is similar to the MSG_VEL_NED_GNSS, but it includes
     * the upper triangular portion of the 3x3 covariance matrix.
     * 
     * The values in this message are from GNSS measurements only. To get
     * values fused with inertial measurements use MSG_VEL_NED_COV.
     */

    class msg_vel_ned_cov_gnss_t : public kaitai::kstruct {

    public:

        msg_vel_ned_cov_gnss_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_vel_ned_cov_gnss_t();

    private:
        uint32_t m_tow;
        int32_t m_n;
        int32_t m_e;
        int32_t m_d;
        float m_cov_n_n;
        float m_cov_n_e;
        float m_cov_n_d;
        float m_cov_e_e;
        float m_cov_e_d;
        float m_cov_d_d;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Velocity North coordinate
         */
        int32_t n() const { return m_n; }

        /**
         * Velocity East coordinate
         */
        int32_t e() const { return m_e; }

        /**
         * Velocity Down coordinate
         */
        int32_t d() const { return m_d; }

        /**
         * Estimated variance of northward measurement
         */
        float cov_n_n() const { return m_cov_n_n; }

        /**
         * Covariance of northward and eastward measurement
         */
        float cov_n_e() const { return m_cov_n_e; }

        /**
         * Covariance of northward and downward measurement
         */
        float cov_n_d() const { return m_cov_n_d; }

        /**
         * Estimated variance of eastward measurement
         */
        float cov_e_e() const { return m_cov_e_e; }

        /**
         * Covariance of eastward and downward measurement
         */
        float cov_e_d() const { return m_cov_e_d; }

        /**
         * Estimated variance of downward measurement
         */
        float cov_d_d() const { return m_cov_d_d; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_baseline_ned_dep_a_t : public kaitai::kstruct {

    public:

        msg_baseline_ned_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_baseline_ned_dep_a_t();

    private:
        uint32_t m_tow;
        int32_t m_n;
        int32_t m_e;
        int32_t m_d;
        uint16_t m_h_accuracy;
        uint16_t m_v_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Baseline North coordinate
         */
        int32_t n() const { return m_n; }

        /**
         * Baseline East coordinate
         */
        int32_t e() const { return m_e; }

        /**
         * Baseline Down coordinate
         */
        int32_t d() const { return m_d; }

        /**
         * Horizontal position accuracy estimate (not implemented). Defaults to
         * 0.
         */
        uint16_t h_accuracy() const { return m_h_accuracy; }

        /**
         * Vertical position accuracy estimate (not implemented). Defaults to
         * 0.
         */
        uint16_t v_accuracy() const { return m_v_accuracy; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_vel_ecef_dep_a_t : public kaitai::kstruct {

    public:

        msg_vel_ecef_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_vel_ecef_dep_a_t();

    private:
        uint32_t m_tow;
        int32_t m_x;
        int32_t m_y;
        int32_t m_z;
        uint16_t m_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Velocity ECEF X coordinate
         */
        int32_t x() const { return m_x; }

        /**
         * Velocity ECEF Y coordinate
         */
        int32_t y() const { return m_y; }

        /**
         * Velocity ECEF Z coordinate
         */
        int32_t z() const { return m_z; }

        /**
         * Velocity accuracy estimate (not implemented). Defaults to 0.
         */
        uint16_t accuracy() const { return m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags (reserved)
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    class msg_reference_frame_param_t : public kaitai::kstruct {

    public:

        msg_reference_frame_param_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_reference_frame_param_t();

    private:
        uint8_t m_ssr_iod;
        std::string m_sn;
        std::string m_tn;
        uint8_t m_sin;
        uint16_t m_utn;
        uint16_t m_re_t0;
        int32_t m_delta_x0;
        int32_t m_delta_y0;
        int32_t m_delta_z0;
        int32_t m_theta_01;
        int32_t m_theta_02;
        int32_t m_theta_03;
        int32_t m_scale;
        int32_t m_dot_delta_x0;
        int32_t m_dot_delta_y0;
        int32_t m_dot_delta_z0;
        int32_t m_dot_theta_01;
        int32_t m_dot_theta_02;
        int32_t m_dot_theta_03;
        int16_t m_dot_scale;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * SSR IOD parameter.
         */
        uint8_t ssr_iod() const { return m_ssr_iod; }

        /**
         * Name of source coordinate-system.
         */
        std::string sn() const { return m_sn; }

        /**
         * Name of target coordinate-system.
         */
        std::string tn() const { return m_tn; }

        /**
         * System Identification Number.
         */
        uint8_t sin() const { return m_sin; }

        /**
         * Utilized Transformation Message.
         */
        uint16_t utn() const { return m_utn; }

        /**
         * Reference Epoch t0 for transformation parameter set given as
         * Modified Julian Day (MJD) Number minus 44244 days.
         */
        uint16_t re_t0() const { return m_re_t0; }

        /**
         * Translation in X for Reference Epoch t0.
         */
        int32_t delta_x0() const { return m_delta_x0; }

        /**
         * Translation in Y for Reference Epoch t0.
         */
        int32_t delta_y0() const { return m_delta_y0; }

        /**
         * Translation in Z for Reference Epoch t0.
         */
        int32_t delta_z0() const { return m_delta_z0; }

        /**
         * Rotation around the X-axis for Reference Epoch t0.
         */
        int32_t theta_01() const { return m_theta_01; }

        /**
         * Rotation around the Y-axis for Reference Epoch t0.
         */
        int32_t theta_02() const { return m_theta_02; }

        /**
         * Rotation around the Z-axis for Reference Epoch t0.
         */
        int32_t theta_03() const { return m_theta_03; }

        /**
         * Scale correction for Reference Epoch t0.
         */
        int32_t scale() const { return m_scale; }

        /**
         * Rate of change of translation in X.
         */
        int32_t dot_delta_x0() const { return m_dot_delta_x0; }

        /**
         * Rate of change of translation in Y.
         */
        int32_t dot_delta_y0() const { return m_dot_delta_y0; }

        /**
         * Rate of change of translation in Z.
         */
        int32_t dot_delta_z0() const { return m_dot_delta_z0; }

        /**
         * Rate of change of rotation around the X-axis.
         */
        int32_t dot_theta_01() const { return m_dot_theta_01; }

        /**
         * Rate of change of rotation around the Y-axis.
         */
        int32_t dot_theta_02() const { return m_dot_theta_02; }

        /**
         * Rate of change of rotation around the Z-axis.
         */
        int32_t dot_theta_03() const { return m_dot_theta_03; }

        /**
         * Rate of change of scale correction.
         */
        int16_t dot_scale() const { return m_dot_scale; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This solution message reports the relative pose of a sensor between two
     * time instances. The relative pose comprises of a rotation and a
     * translation which relates the sensor (e.g. camera) frame at a given time
     * (first keyframe) to the sensor frame at another time (second keyframe).
     * The relative translations is a 3x1 vector described in the first
     * keyframe. Relative rotation is described by a quaternion from second
     * keyframe to the first keyframe.
     */

    class msg_pose_relative_t : public kaitai::kstruct {

    public:

        msg_pose_relative_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_pose_relative_t();

    private:
        uint32_t m_tow;
        uint8_t m_sensor_id;
        uint32_t m_timestamp_1;
        uint32_t m_timestamp_2;
        std::vector<int32_t>* m_trans;
        int32_t m_w;
        int32_t m_x;
        int32_t m_y;
        int32_t m_z;
        float m_cov_r_x_x;
        float m_cov_r_x_y;
        float m_cov_r_x_z;
        float m_cov_r_y_y;
        float m_cov_r_y_z;
        float m_cov_r_z_z;
        float m_cov_c_x_x;
        float m_cov_c_x_y;
        float m_cov_c_x_z;
        float m_cov_c_y_y;
        float m_cov_c_y_z;
        float m_cov_c_z_z;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * ID of the sensor producing this message
         */
        uint8_t sensor_id() const { return m_sensor_id; }

        /**
         * Timestamp of first keyframe
         */
        uint32_t timestamp_1() const { return m_timestamp_1; }

        /**
         * Timestamp of second keyframe
         */
        uint32_t timestamp_2() const { return m_timestamp_2; }

        /**
         * Relative translation [x,y,z] described in first keyframe
         */
        std::vector<int32_t>* trans() const { return m_trans; }

        /**
         * Real component of quaternion to describe relative rotation (second
         * to first keyframe)
         */
        int32_t w() const { return m_w; }

        /**
         * 1st imaginary component of quaternion to describe relative rotation
         * (second to first keyframe)
         */
        int32_t x() const { return m_x; }

        /**
         * 2nd imaginary component of quaternion to describe relative rotation
         * (second to first keyframe)
         */
        int32_t y() const { return m_y; }

        /**
         * 3rd imaginary component of quaternion to describe relative rotation
         * (second to first keyframe)
         */
        int32_t z() const { return m_z; }

        /**
         * Estimated variance of x (relative translation)
         */
        float cov_r_x_x() const { return m_cov_r_x_x; }

        /**
         * Covariance of x and y (relative translation)
         */
        float cov_r_x_y() const { return m_cov_r_x_y; }

        /**
         * Covariance of x and z (relative translation)
         */
        float cov_r_x_z() const { return m_cov_r_x_z; }

        /**
         * Estimated variance of y (relative translation)
         */
        float cov_r_y_y() const { return m_cov_r_y_y; }

        /**
         * Covariance of y and z (relative translation)
         */
        float cov_r_y_z() const { return m_cov_r_y_z; }

        /**
         * Estimated variance of z (relative translation)
         */
        float cov_r_z_z() const { return m_cov_r_z_z; }

        /**
         * Estimated variance of x (relative rotation)
         */
        float cov_c_x_x() const { return m_cov_c_x_x; }

        /**
         * Covariance of x and y (relative rotation)
         */
        float cov_c_x_y() const { return m_cov_c_x_y; }

        /**
         * Covariance of x and z (relative rotation)
         */
        float cov_c_x_z() const { return m_cov_c_x_z; }

        /**
         * Estimated variance of y (relative rotation)
         */
        float cov_c_y_y() const { return m_cov_c_y_y; }

        /**
         * Covariance of y and z (relative rotation)
         */
        float cov_c_y_z() const { return m_cov_c_y_z; }

        /**
         * Estimated variance of z (relative rotation)
         */
        float cov_c_z_z() const { return m_cov_c_z_z; }

        /**
         * Status flags of relative translation and rotation
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
     * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
     * with the matching time-of-week (tow).
     * 
     * The values in this message are from GNSS measurements fused with
     * inertial measurements. To get values from GNSS measurements only use
     * MSG_VEL_ECEF_COV_GNSS.
     */

    class msg_vel_ecef_cov_t : public kaitai::kstruct {

    public:

        msg_vel_ecef_cov_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_vel_ecef_cov_t();

    private:
        uint32_t m_tow;
        int32_t m_x;
        int32_t m_y;
        int32_t m_z;
        float m_cov_x_x;
        float m_cov_x_y;
        float m_cov_x_z;
        float m_cov_y_y;
        float m_cov_y_z;
        float m_cov_z_z;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Velocity ECEF X coordinate
         */
        int32_t x() const { return m_x; }

        /**
         * Velocity ECEF Y coordinate
         */
        int32_t y() const { return m_y; }

        /**
         * Velocity ECEF Z coordinate
         */
        int32_t z() const { return m_z; }

        /**
         * Estimated variance of x
         */
        float cov_x_x() const { return m_cov_x_x; }

        /**
         * Estimated covariance of x and y
         */
        float cov_x_y() const { return m_cov_x_y; }

        /**
         * Estimated covariance of x and z
         */
        float cov_x_z() const { return m_cov_x_z; }

        /**
         * Estimated variance of y
         */
        float cov_y_y() const { return m_cov_y_y; }

        /**
         * Estimated covariance of y and z
         */
        float cov_y_z() const { return m_cov_y_z; }

        /**
         * Estimated variance of z
         */
        float cov_z_z() const { return m_cov_z_z; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the velocity in the Vehicle Body Frame. By
     * convention, the x-axis should point out the nose of the vehicle and
     * represent the forward direction, while as the y-axis should point out
     * the right hand side of the vehicle. Since this is a right handed system,
     * z should point out the bottom of the vehicle. The orientation and origin
     * of the Vehicle Body Frame are specified via the device settings. The
     * full GPS time is given by the preceding MSG_GPS_TIME with the matching
     * time-of-week (tow). This message is only produced by inertial versions
     * of Swift products and is not available from Piksi Multi or Duro.
     * 
     * The values in this message are from GNSS measurements fused with
     * inertial measurements.
     */

    class msg_vel_body_t : public kaitai::kstruct {

    public:

        msg_vel_body_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_vel_body_t();

    private:
        uint32_t m_tow;
        int32_t m_x;
        int32_t m_y;
        int32_t m_z;
        float m_cov_x_x;
        float m_cov_x_y;
        float m_cov_x_z;
        float m_cov_y_y;
        float m_cov_y_z;
        float m_cov_z_z;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Velocity in x direction
         */
        int32_t x() const { return m_x; }

        /**
         * Velocity in y direction
         */
        int32_t y() const { return m_y; }

        /**
         * Velocity in z direction
         */
        int32_t z() const { return m_z; }

        /**
         * Estimated variance of x
         */
        float cov_x_x() const { return m_cov_x_x; }

        /**
         * Covariance of x and y
         */
        float cov_x_y() const { return m_cov_x_y; }

        /**
         * Covariance of x and z
         */
        float cov_x_z() const { return m_cov_x_z; }

        /**
         * Estimated variance of y
         */
        float cov_y_y() const { return m_cov_y_y; }

        /**
         * Covariance of y and z
         */
        float cov_y_z() const { return m_cov_y_z; }

        /**
         * Estimated variance of z
         */
        float cov_z_z() const { return m_cov_z_z; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
     * coordinates. The full GPS time is given by the preceding
     * MSG_GPS_TIME_GNSS with the matching time-of-week (tow).
     * 
     * The values in this message are from GNSS measurements only. To get
     * values fused with inertial measurements use MSG_VEL_ECEF.
     */

    class msg_vel_ecef_gnss_t : public kaitai::kstruct {

    public:

        msg_vel_ecef_gnss_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_vel_ecef_gnss_t();

    private:
        uint32_t m_tow;
        int32_t m_x;
        int32_t m_y;
        int32_t m_z;
        uint16_t m_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Velocity ECEF X coordinate
         */
        int32_t x() const { return m_x; }

        /**
         * Velocity ECEF Y coordinate
         */
        int32_t y() const { return m_y; }

        /**
         * Velocity ECEF Z coordinate
         */
        int32_t z() const { return m_z; }

        /**
         * Velocity estimated standard deviation
         */
        uint16_t accuracy() const { return m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
     * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
     * with the matching time-of-week (tow).
     * 
     * The values in this message are from GNSS measurements fused with
     * inertial measurements. To get values from GNSS measurements only use
     * MSG_VEL_ECEF_GNSS.
     */

    class msg_vel_ecef_t : public kaitai::kstruct {

    public:

        msg_vel_ecef_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_vel_ecef_t();

    private:
        uint32_t m_tow;
        int32_t m_x;
        int32_t m_y;
        int32_t m_z;
        uint16_t m_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Velocity ECEF X coordinate
         */
        int32_t x() const { return m_x; }

        /**
         * Velocity ECEF Y coordinate
         */
        int32_t y() const { return m_y; }

        /**
         * Velocity ECEF Z coordinate
         */
        int32_t z() const { return m_z; }

        /**
         * Velocity estimated standard deviation
         */
        uint16_t accuracy() const { return m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This position solution message reports the absolute geodetic coordinates
     * and the status (single point vs pseudo-absolute RTK) of the position
     * solution as well as the upper triangle of the 3x3 covariance matrix.
     * The position information and Fix Mode flags should follow the
     * MSG_POS_LLH_GNSS message.  Since the covariance matrix is computed in
     * the local-level North, East, Down frame, the covariance terms follow
     * with that convention. Thus, covariances are reported against the
     * "downward" measurement and care should be taken with the sign
     * convention.
     * 
     * The values in this message are from GNSS measurements only. To get
     * values fused with inertial measurements use MSG_POS_LLH_COV.
     */

    class msg_pos_llh_cov_gnss_t : public kaitai::kstruct {

    public:

        msg_pos_llh_cov_gnss_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_pos_llh_cov_gnss_t();

    private:
        uint32_t m_tow;
        double m_lat;
        double m_lon;
        double m_height;
        float m_cov_n_n;
        float m_cov_n_e;
        float m_cov_n_d;
        float m_cov_e_e;
        float m_cov_e_d;
        float m_cov_d_d;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Latitude
         */
        double lat() const { return m_lat; }

        /**
         * Longitude
         */
        double lon() const { return m_lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        double height() const { return m_height; }

        /**
         * Estimated variance of northing
         */
        float cov_n_n() const { return m_cov_n_n; }

        /**
         * Covariance of northing and easting
         */
        float cov_n_e() const { return m_cov_n_e; }

        /**
         * Covariance of northing and downward measurement
         */
        float cov_n_d() const { return m_cov_n_d; }

        /**
         * Estimated variance of easting
         */
        float cov_e_e() const { return m_cov_e_e; }

        /**
         * Covariance of easting and downward measurement
         */
        float cov_e_d() const { return m_cov_e_d; }

        /**
         * Estimated variance of downward measurement
         */
        float cov_d_d() const { return m_cov_d_d; }

        /**
         * Number of satellites used in solution.
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the baseline solution in Earth Centered Earth Fixed
     * (ECEF) coordinates. This baseline is the relative vector distance from
     * the base station to the rover receiver. The full GPS time is given by
     * the preceding MSG_GPS_TIME with the matching time-of-week (tow).
     * 
     * The values in this message are from GNSS measurements only.
     */

    class msg_baseline_ecef_t : public kaitai::kstruct {

    public:

        msg_baseline_ecef_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_baseline_ecef_t();

    private:
        uint32_t m_tow;
        int32_t m_x;
        int32_t m_y;
        int32_t m_z;
        uint16_t m_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Baseline ECEF X coordinate
         */
        int32_t x() const { return m_x; }

        /**
         * Baseline ECEF Y coordinate
         */
        int32_t y() const { return m_y; }

        /**
         * Baseline ECEF Z coordinate
         */
        int32_t z() const { return m_z; }

        /**
         * Position estimated standard deviation
         */
        uint16_t accuracy() const { return m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_dops_dep_a_t : public kaitai::kstruct {

    public:

        msg_dops_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_dops_dep_a_t();

    private:
        uint32_t m_tow;
        uint16_t m_gdop;
        uint16_t m_pdop;
        uint16_t m_tdop;
        uint16_t m_hdop;
        uint16_t m_vdop;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Geometric Dilution of Precision
         */
        uint16_t gdop() const { return m_gdop; }

        /**
         * Position Dilution of Precision
         */
        uint16_t pdop() const { return m_pdop; }

        /**
         * Time Dilution of Precision
         */
        uint16_t tdop() const { return m_tdop; }

        /**
         * Horizontal Dilution of Precision
         */
        uint16_t hdop() const { return m_hdop; }

        /**
         * Vertical Dilution of Precision
         */
        uint16_t vdop() const { return m_vdop; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The position solution message reports absolute Earth Centered Earth
     * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
     * RTK) of the position solution. If the rover receiver knows the surveyed
     * position of the base station and has an RTK solution, this reports a
     * pseudo-absolute position solution using the base station position and
     * the rover's RTK baseline vector. The full GPS time is given by the
     * preceding MSG_GPS_TIME with the matching time-of-week (tow).
     * 
     * The values in this message are from GNSS measurements fused with
     * inertial measurements. To get values from GNSS measurements only use
     * MSG_POS_ECEF_GNSS.
     */

    class msg_pos_ecef_t : public kaitai::kstruct {

    public:

        msg_pos_ecef_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_pos_ecef_t();

    private:
        uint32_t m_tow;
        double m_x;
        double m_y;
        double m_z;
        uint16_t m_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

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

        /**
         * Position estimated standard deviation
         */
        uint16_t accuracy() const { return m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the Age of the corrections used for the current
     * Differential solution.
     */

    class msg_age_corrections_t : public kaitai::kstruct {

    public:

        msg_age_corrections_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_age_corrections_t();

    private:
        uint32_t m_tow;
        uint16_t m_age;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Age of the corrections (0xFFFF indicates invalid)
         */
        uint16_t age() const { return m_age; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
     * coordinates. The full GPS time is given by the preceding
     * MSG_GPS_TIME_GNSS with the matching time-of-week (tow).
     * 
     * The values in this message are from GNSS measurements only. To get
     * values fused with inertial measurements use MSG_VEL_ECEF_COV.
     */

    class msg_vel_ecef_cov_gnss_t : public kaitai::kstruct {

    public:

        msg_vel_ecef_cov_gnss_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_vel_ecef_cov_gnss_t();

    private:
        uint32_t m_tow;
        int32_t m_x;
        int32_t m_y;
        int32_t m_z;
        float m_cov_x_x;
        float m_cov_x_y;
        float m_cov_x_z;
        float m_cov_y_y;
        float m_cov_y_z;
        float m_cov_z_z;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Velocity ECEF X coordinate
         */
        int32_t x() const { return m_x; }

        /**
         * Velocity ECEF Y coordinate
         */
        int32_t y() const { return m_y; }

        /**
         * Velocity ECEF Z coordinate
         */
        int32_t z() const { return m_z; }

        /**
         * Estimated variance of x
         */
        float cov_x_x() const { return m_cov_x_x; }

        /**
         * Estimated covariance of x and y
         */
        float cov_x_y() const { return m_cov_x_y; }

        /**
         * Estimated covariance of x and z
         */
        float cov_x_z() const { return m_cov_x_z; }

        /**
         * Estimated variance of y
         */
        float cov_y_y() const { return m_cov_y_y; }

        /**
         * Estimated covariance of y and z
         */
        float cov_y_z() const { return m_cov_y_z; }

        /**
         * Estimated variance of z
         */
        float cov_z_z() const { return m_cov_z_z; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the protection levels associated to the given state
     * estimate. The full GPS time is given by the preceding MSG_GPS_TIME with
     * the matching time-of-week (tow).
     */

    class msg_protection_level_t : public kaitai::kstruct {

    public:

        msg_protection_level_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_protection_level_t();

    private:
        uint32_t m_tow;
        int16_t m_wn;
        uint16_t m_hpl;
        uint16_t m_vpl;
        uint16_t m_atpl;
        uint16_t m_ctpl;
        uint16_t m_hvpl;
        uint16_t m_vvpl;
        uint16_t m_hopl;
        uint16_t m_popl;
        uint16_t m_ropl;
        double m_lat;
        double m_lon;
        double m_height;
        int32_t m_v_x;
        int32_t m_v_y;
        int32_t m_v_z;
        int32_t m_roll;
        int32_t m_pitch;
        int32_t m_heading;
        uint32_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * GPS week number
         */
        int16_t wn() const { return m_wn; }

        /**
         * Horizontal protection level
         */
        uint16_t hpl() const { return m_hpl; }

        /**
         * Vertical protection level
         */
        uint16_t vpl() const { return m_vpl; }

        /**
         * Along-track position error protection level
         */
        uint16_t atpl() const { return m_atpl; }

        /**
         * Cross-track position error protection level
         */
        uint16_t ctpl() const { return m_ctpl; }

        /**
         * Protection level for the error vector between estimated and true
         * along/cross track velocity vector
         */
        uint16_t hvpl() const { return m_hvpl; }

        /**
         * Protection level for the velocity in vehicle upright direction
         * (different from vertical direction if on a slope)
         */
        uint16_t vvpl() const { return m_vvpl; }

        /**
         * Heading orientation protection level
         */
        uint16_t hopl() const { return m_hopl; }

        /**
         * Pitch orientation protection level
         */
        uint16_t popl() const { return m_popl; }

        /**
         * Roll orientation protection level
         */
        uint16_t ropl() const { return m_ropl; }

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

        /**
         * Velocity in vehicle x direction
         */
        int32_t v_x() const { return m_v_x; }

        /**
         * Velocity in vehicle y direction
         */
        int32_t v_y() const { return m_v_y; }

        /**
         * Velocity in vehicle z direction
         */
        int32_t v_z() const { return m_v_z; }

        /**
         * Roll angle
         */
        int32_t roll() const { return m_roll; }

        /**
         * Pitch angle
         */
        int32_t pitch() const { return m_pitch; }

        /**
         * Heading angle
         */
        int32_t heading() const { return m_heading; }

        /**
         * Status flags
         */
        uint32_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The position solution message reports absolute Earth Centered Earth
     * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
     * RTK) of the position solution. The message also reports the upper
     * triangular portion of the 3x3 covariance matrix. If the receiver knows
     * the surveyed position of the base station and has an RTK solution, this
     * reports a pseudo-absolute position solution using the base station
     * position and the rover's RTK baseline vector. The full GPS time is given
     * by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
     * 
     * The values in this message are from GNSS measurements fused with
     * inertial measurements. To get values from GNSS measurements only use
     * MSG_POS_ECEF_COV_GNSS.
     */

    class msg_pos_ecef_cov_t : public kaitai::kstruct {

    public:

        msg_pos_ecef_cov_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_pos_ecef_cov_t();

    private:
        uint32_t m_tow;
        double m_x;
        double m_y;
        double m_z;
        float m_cov_x_x;
        float m_cov_x_y;
        float m_cov_x_z;
        float m_cov_y_y;
        float m_cov_y_z;
        float m_cov_z_z;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

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

        /**
         * Estimated variance of x
         */
        float cov_x_x() const { return m_cov_x_x; }

        /**
         * Estimated covariance of x and y
         */
        float cov_x_y() const { return m_cov_x_y; }

        /**
         * Estimated covariance of x and z
         */
        float cov_x_z() const { return m_cov_x_z; }

        /**
         * Estimated variance of y
         */
        float cov_y_y() const { return m_cov_y_y; }

        /**
         * Estimated covariance of y and z
         */
        float cov_y_z() const { return m_cov_y_z; }

        /**
         * Estimated variance of z
         */
        float cov_z_z() const { return m_cov_z_z; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The position solution message reports absolute Earth Centered Earth
     * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
     * RTK) of the position solution. If the rover receiver knows the surveyed
     * position of the base station and has an RTK solution, this reports a
     * pseudo-absolute position solution using the base station position and
     * the rover's RTK baseline vector. The full GPS time is given by the
     * preceding MSG_GPS_TIME_GNSS with the matching time-of-week (tow).
     * 
     * The values in this message are from GNSS measurements only. To get
     * values fused with inertial measurements use MSG_POS_ECEF.
     */

    class msg_pos_ecef_gnss_t : public kaitai::kstruct {

    public:

        msg_pos_ecef_gnss_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_pos_ecef_gnss_t();

    private:
        uint32_t m_tow;
        double m_x;
        double m_y;
        double m_z;
        uint16_t m_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

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

        /**
         * Position estimated standard deviation
         */
        uint16_t accuracy() const { return m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the velocity in local North East Down (NED)
     * coordinates. The NED coordinate system is defined as the local WGS84
     * tangent plane centered at the current position. The full GPS time is
     * given by the preceding MSG_GPS_TIME with the matching time-of-week
     * (tow).
     * 
     * The values in this message are from GNSS measurements fused with
     * inertial measurements. To get values from GNSS measurements only use
     * MSG_VEL_NED_GNSS.
     */

    class msg_vel_ned_t : public kaitai::kstruct {

    public:

        msg_vel_ned_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_vel_ned_t();

    private:
        uint32_t m_tow;
        int32_t m_n;
        int32_t m_e;
        int32_t m_d;
        uint16_t m_h_accuracy;
        uint16_t m_v_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Velocity North coordinate
         */
        int32_t n() const { return m_n; }

        /**
         * Velocity East coordinate
         */
        int32_t e() const { return m_e; }

        /**
         * Velocity Down coordinate
         */
        int32_t d() const { return m_d; }

        /**
         * Horizontal velocity estimated standard deviation
         */
        uint16_t h_accuracy() const { return m_h_accuracy; }

        /**
         * Vertical velocity estimated standard deviation
         */
        uint16_t v_accuracy() const { return m_v_accuracy; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * UTC-GPST leap seconds before and after the most recent (past, or future,
     * for announced insertions) UTC leap second insertion.
     */

    class msg_utc_leap_second_t : public kaitai::kstruct {

    public:

        msg_utc_leap_second_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_utc_leap_second_t();

    private:
        int16_t m_reserved_0;
        int16_t m_reserved_1;
        int8_t m_reserved_2;
        int8_t m_count_before;
        uint16_t m_reserved_3;
        uint16_t m_reserved_4;
        uint16_t m_ref_wn;
        uint8_t m_ref_dn;
        int8_t m_count_after;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Reserved.
         */
        int16_t reserved_0() const { return m_reserved_0; }

        /**
         * Reserved.
         */
        int16_t reserved_1() const { return m_reserved_1; }

        /**
         * Reserved.
         */
        int8_t reserved_2() const { return m_reserved_2; }

        /**
         * Leap second count before insertion.
         */
        int8_t count_before() const { return m_count_before; }

        /**
         * Reserved.
         */
        uint16_t reserved_3() const { return m_reserved_3; }

        /**
         * Reserved.
         */
        uint16_t reserved_4() const { return m_reserved_4; }

        /**
         * Leap second reference GPS week number.
         */
        uint16_t ref_wn() const { return m_ref_wn; }

        /**
         * Leap second reference day number.
         */
        uint8_t ref_dn() const { return m_ref_dn; }

        /**
         * Leap second count after insertion.
         */
        int8_t count_after() const { return m_count_after; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_gps_time_dep_a_t : public kaitai::kstruct {

    public:

        msg_gps_time_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_gps_time_dep_a_t();

    private:
        uint16_t m_wn;
        uint32_t m_tow;
        int32_t m_ns_residual;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS week number
         */
        uint16_t wn() const { return m_wn; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        int32_t ns_residual() const { return m_ns_residual; }

        /**
         * Status flags (reserved)
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This position solution message reports the absolute geodetic coordinates
     * and the status (single point vs pseudo-absolute RTK) of the position
     * solution. If the rover receiver knows the surveyed position of the base
     * station and has an RTK solution, this reports a pseudo-absolute position
     * solution using the base station position and the rover's RTK baseline
     * vector. The full GPS time is given by the preceding MSG_GPS_TIME_GNSS
     * with the matching time-of-week (tow).
     * 
     * The values in this message are from GNSS measurements only. To get
     * values fused with inertial measurements use MSG_POS_LLH.
     */

    class msg_pos_llh_gnss_t : public kaitai::kstruct {

    public:

        msg_pos_llh_gnss_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_pos_llh_gnss_t();

    private:
        uint32_t m_tow;
        double m_lat;
        double m_lon;
        double m_height;
        uint16_t m_h_accuracy;
        uint16_t m_v_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Latitude
         */
        double lat() const { return m_lat; }

        /**
         * Longitude
         */
        double lon() const { return m_lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        double height() const { return m_height; }

        /**
         * Horizontal position estimated standard deviation
         */
        uint16_t h_accuracy() const { return m_h_accuracy; }

        /**
         * Vertical position estimated standard deviation
         */
        uint16_t v_accuracy() const { return m_v_accuracy; }

        /**
         * Number of satellites used in solution.
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the Universal Coordinated Time (UTC).  Note the
     * flags which indicate the source of the UTC offset value and source of
     * the time fix.
     * 
     * The values in this message are from GNSS measurements only. To get
     * values fused with inertial measurements use MSG_UTC_TIME.
     */

    class msg_utc_time_gnss_t : public kaitai::kstruct {

    public:

        msg_utc_time_gnss_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_utc_time_gnss_t();

    private:
        uint8_t m_flags;
        uint32_t m_tow;
        uint16_t m_year;
        uint8_t m_month;
        uint8_t m_day;
        uint8_t m_hours;
        uint8_t m_minutes;
        uint8_t m_seconds;
        uint32_t m_ns;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Indicates source and time validity
         */
        uint8_t flags() const { return m_flags; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        uint32_t tow() const { return m_tow; }

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
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the receiver course over ground (COG) and speed
     * over ground (SOG) based on the horizontal (N-E) components of the NED
     * velocity vector. It also includes the vertical velocity coordinate. A
     * flag is provided to indicate whether the COG value has been frozen. When
     * the flag is set to true, the COG field is set to its last valid value
     * until the system exceeds a minimum velocity threshold. No other fields
     * are affected by this flag. The NED coordinate system is defined as the
     * local WGS84 tangent plane centered at the current position. The full GPS
     * time is given by the preceding MSG_GPS_TIME with the matching time-of-
     * week (tow). Note: course over ground represents the receiver's direction
     * of travel, but not necessarily the device heading.
     * 
     * The values in this message are from GNSS measurements fused with
     * inertial measurements.
     */

    class msg_vel_cog_t : public kaitai::kstruct {

    public:

        msg_vel_cog_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_vel_cog_t();

    private:
        uint32_t m_tow;
        uint32_t m_cog;
        uint32_t m_sog;
        int32_t m_v_up;
        uint32_t m_cog_accuracy;
        uint32_t m_sog_accuracy;
        uint32_t m_v_up_accuracy;
        uint16_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Course over ground relative to north direction
         */
        uint32_t cog() const { return m_cog; }

        /**
         * Speed over ground (based on horizontal velocity)
         */
        uint32_t sog() const { return m_sog; }

        /**
         * Vertical velocity component (positive up)
         */
        int32_t v_up() const { return m_v_up; }

        /**
         * Course over ground estimated standard deviation
         */
        uint32_t cog_accuracy() const { return m_cog_accuracy; }

        /**
         * Speed over ground estimated standard deviation
         */
        uint32_t sog_accuracy() const { return m_sog_accuracy; }

        /**
         * Vertical velocity estimated standard deviation
         */
        uint32_t v_up_accuracy() const { return m_v_up_accuracy; }

        /**
         * Status flags
         */
        uint16_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the baseline solution in North East Down (NED)
     * coordinates. This baseline is the relative vector distance from the base
     * station to the rover receiver, and NED coordinate system is defined at
     * the local WGS84 tangent plane centered at the base station position.
     * The full GPS time is given by the preceding MSG_GPS_TIME with the
     * matching time-of-week (tow).
     * 
     * The values in this message are from GNSS measurements only.
     */

    class msg_baseline_ned_t : public kaitai::kstruct {

    public:

        msg_baseline_ned_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_baseline_ned_t();

    private:
        uint32_t m_tow;
        int32_t m_n;
        int32_t m_e;
        int32_t m_d;
        uint16_t m_h_accuracy;
        uint16_t m_v_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Baseline North coordinate
         */
        int32_t n() const { return m_n; }

        /**
         * Baseline East coordinate
         */
        int32_t e() const { return m_e; }

        /**
         * Baseline Down coordinate
         */
        int32_t d() const { return m_d; }

        /**
         * Horizontal position estimated standard deviation
         */
        uint16_t h_accuracy() const { return m_h_accuracy; }

        /**
         * Vertical position estimated standard deviation
         */
        uint16_t v_accuracy() const { return m_v_accuracy; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This position solution message reports the absolute geodetic coordinates
     * and the status (single point vs pseudo-absolute RTK) of the position
     * solution. If the rover receiver knows the surveyed position of the base
     * station and has an RTK solution, this reports a pseudo-absolute position
     * solution using the base station position and the rover's RTK baseline
     * vector. The full GPS time is given by the preceding MSG_GPS_TIME with
     * the matching time-of-week (tow).
     * 
     * The values in this message are from GNSS measurements fused with
     * inertial measurements. To get values from GNSS measurements only use
     * MSG_POS_LLH_GNSS.
     */

    class msg_pos_llh_t : public kaitai::kstruct {

    public:

        msg_pos_llh_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_pos_llh_t();

    private:
        uint32_t m_tow;
        double m_lat;
        double m_lon;
        double m_height;
        uint16_t m_h_accuracy;
        uint16_t m_v_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Latitude
         */
        double lat() const { return m_lat; }

        /**
         * Longitude
         */
        double lon() const { return m_lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        double height() const { return m_height; }

        /**
         * Horizontal position estimated standard deviation
         */
        uint16_t h_accuracy() const { return m_h_accuracy; }

        /**
         * Vertical position estimated standard deviation
         */
        uint16_t v_accuracy() const { return m_v_accuracy; }

        /**
         * Number of satellites used in solution.
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_baseline_heading_dep_a_t : public kaitai::kstruct {

    public:

        msg_baseline_heading_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_baseline_heading_dep_a_t();

    private:
        uint32_t m_tow;
        uint32_t m_heading;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Heading
         */
        uint32_t heading() const { return m_heading; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the GPS time, representing the time since the GPS
     * epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
     * and seconds of the week. The weeks begin at the Saturday/Sunday
     * transition. GPS week 0 began at the beginning of the GPS time scale.
     * 
     * Within each week number, the GPS time of the week is between between 0
     * and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
     * leap seconds, and as of now, has a small offset from UTC. In a message
     * stream, this message precedes a set of other navigation messages
     * referenced to the same time (but lacking the ns field) and indicates a
     * more precise time of these messages.
     * 
     * The values in this message are from GNSS measurements only. To get
     * values fused with inertial measurements use MSG_GPS_TIME.
     */

    class msg_gps_time_gnss_t : public kaitai::kstruct {

    public:

        msg_gps_time_gnss_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_gps_time_gnss_t();

    private:
        uint16_t m_wn;
        uint32_t m_tow;
        int32_t m_ns_residual;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS week number
         */
        uint16_t wn() const { return m_wn; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        int32_t ns_residual() const { return m_ns_residual; }

        /**
         * Status flags (reserved)
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_baseline_ecef_dep_a_t : public kaitai::kstruct {

    public:

        msg_baseline_ecef_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_baseline_ecef_dep_a_t();

    private:
        uint32_t m_tow;
        int32_t m_x;
        int32_t m_y;
        int32_t m_z;
        uint16_t m_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Baseline ECEF X coordinate
         */
        int32_t x() const { return m_x; }

        /**
         * Baseline ECEF Y coordinate
         */
        int32_t y() const { return m_y; }

        /**
         * Baseline ECEF Z coordinate
         */
        int32_t z() const { return m_z; }

        /**
         * Position accuracy estimate
         */
        uint16_t accuracy() const { return m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the GPS time, representing the time since the GPS
     * epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
     * and seconds of the week. The weeks begin at the Saturday/Sunday
     * transition. GPS week 0 began at the beginning of the GPS time scale.
     * 
     * Within each week number, the GPS time of the week is between between 0
     * and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
     * leap seconds, and as of now, has a small offset from UTC. In a message
     * stream, this message precedes a set of other navigation messages
     * referenced to the same time (but lacking the ns field) and indicates a
     * more precise time of these messages.
     * 
     * The values in this message are from GNSS measurements fused with
     * inertial measurements. To get values from GNSS measurements only use
     * MSG_GPS_TIME_GNSS.
     */

    class msg_gps_time_t : public kaitai::kstruct {

    public:

        msg_gps_time_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_gps_time_t();

    private:
        uint16_t m_wn;
        uint32_t m_tow;
        int32_t m_ns_residual;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS week number
         */
        uint16_t wn() const { return m_wn; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        int32_t ns_residual() const { return m_ns_residual; }

        /**
         * Status flags (reserved)
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This dilution of precision (DOP) message describes the effect of
     * navigation satellite geometry on positional measurement precision.  The
     * flags field indicated whether the DOP reported corresponds to
     * differential or SPP solution.
     * 
     * The values in this message are from GNSS measurements only.
     */

    class msg_dops_t : public kaitai::kstruct {

    public:

        msg_dops_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_dops_t();

    private:
        uint32_t m_tow;
        uint16_t m_gdop;
        uint16_t m_pdop;
        uint16_t m_tdop;
        uint16_t m_hdop;
        uint16_t m_vdop;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Geometric Dilution of Precision
         */
        uint16_t gdop() const { return m_gdop; }

        /**
         * Position Dilution of Precision
         */
        uint16_t pdop() const { return m_pdop; }

        /**
         * Time Dilution of Precision
         */
        uint16_t tdop() const { return m_tdop; }

        /**
         * Horizontal Dilution of Precision
         */
        uint16_t hdop() const { return m_hdop; }

        /**
         * Vertical Dilution of Precision
         */
        uint16_t vdop() const { return m_vdop; }

        /**
         * Indicates the position solution with which the DOPS message
         * corresponds
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_pos_ecef_dep_a_t : public kaitai::kstruct {

    public:

        msg_pos_ecef_dep_a_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_pos_ecef_dep_a_t();

    private:
        uint32_t m_tow;
        double m_x;
        double m_y;
        double m_z;
        uint16_t m_accuracy;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

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

        /**
         * Position accuracy estimate (not implemented). Defaults to 0.
         */
        uint16_t accuracy() const { return m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    class estimated_horizontal_error_ellipse_t : public kaitai::kstruct {

    public:

        estimated_horizontal_error_ellipse_t(kaitai::kstream* p__io, navigation_t::msg_pos_llh_acc_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~estimated_horizontal_error_ellipse_t();

    private:
        float m_semi_major;
        float m_semi_minor;
        float m_orientation;
        navigation_t* m__root;
        navigation_t::msg_pos_llh_acc_t* m__parent;

    public:

        /**
         * The semi major axis of the estimated horizontal error ellipse at the
         * user-configured confidence level; zero implies invalid.
         */
        float semi_major() const { return m_semi_major; }

        /**
         * The semi minor axis of the estimated horizontal error ellipse at the
         * user-configured confidence level; zero implies invalid.
         */
        float semi_minor() const { return m_semi_minor; }

        /**
         * The orientation of the semi major axis of the estimated horizontal
         * error ellipse with respect to North.
         */
        float orientation() const { return m_orientation; }
        navigation_t* _root() const { return m__root; }
        navigation_t::msg_pos_llh_acc_t* _parent() const { return m__parent; }
    };

    /**
     * This position solution message reports the absolute geodetic coordinates
     * and the status (single point vs pseudo-absolute RTK) of the position
     * solution as well as the estimated horizontal, vertical, cross-track and
     * along-track errors.  The position information and Fix Mode flags  follow
     * the MSG_POS_LLH message. Since the covariance matrix is computed in the
     * local-level North, East, Down frame, the estimated error terms follow
     * that convention.
     * 
     * The estimated errors are reported at a user-configurable confidence
     * level. The user-configured percentile is encoded in the percentile
     * field.
     * 
     * The values in this message are from GNSS measurements fused with
     * inertial measurements.
     */

    class msg_pos_llh_acc_t : public kaitai::kstruct {

    public:

        msg_pos_llh_acc_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, navigation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_pos_llh_acc_t();

    private:
        uint32_t m_tow;
        double m_lat;
        double m_lon;
        double m_height;
        double m_orthometric_height;
        float m_h_accuracy;
        float m_v_accuracy;
        float m_ct_accuracy;
        float m_at_accuracy;
        estimated_horizontal_error_ellipse_t* m_h_ellipse;
        uint8_t m_confidence_and_geoid;
        uint8_t m_n_sats;
        uint8_t m_flags;
        navigation_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Latitude
         */
        double lat() const { return m_lat; }

        /**
         * Longitude
         */
        double lon() const { return m_lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        double height() const { return m_height; }

        /**
         * Height above the geoid (i.e. height above mean sea level). See
         * confidence_and_geoid for geoid model used.
         */
        double orthometric_height() const { return m_orthometric_height; }

        /**
         * Estimated horizontal error at the user-configured confidence level;
         * zero implies invalid.
         */
        float h_accuracy() const { return m_h_accuracy; }

        /**
         * Estimated vertical error at the user-configured confidence level;
         * zero implies invalid.
         */
        float v_accuracy() const { return m_v_accuracy; }

        /**
         * Estimated cross-track error at the user-configured confidence level;
         * zero implies invalid.
         */
        float ct_accuracy() const { return m_ct_accuracy; }

        /**
         * Estimated along-track error at the user-configured confidence level;
         * zero implies invalid.
         */
        float at_accuracy() const { return m_at_accuracy; }

        /**
         * The estimated horizontal error ellipse at the user-configured
         * confidence level.
         */
        estimated_horizontal_error_ellipse_t* h_ellipse() const { return m_h_ellipse; }

        /**
         * The lower bits describe the configured confidence level for the
         * estimated position error. The middle bits describe the geoid model
         * used to calculate the orthometric height.
         */
        uint8_t confidence_and_geoid() const { return m_confidence_and_geoid; }

        /**
         * Number of satellites used in solution.
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        navigation_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

private:
    navigation_t* m__root;
    kaitai::kstruct* m__parent;

public:
    navigation_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // NAVIGATION_H_
