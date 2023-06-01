#ifndef ORIENTATION_H_
#define ORIENTATION_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class orientation_t : public kaitai::kstruct {

public:
    class msg_baseline_heading_t;
    class msg_orient_quat_t;
    class msg_orient_euler_t;
    class msg_angular_rate_t;

    orientation_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, orientation_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~orientation_t();

    /**
     * This message reports the baseline heading pointing from the base station
     * to the rover relative to True North. The full GPS time is given by the
     * preceding MSG_GPS_TIME with the matching time-of-week (tow). It is
     * intended that time-matched RTK mode is used when the base station is
     * moving.
     */

    class msg_baseline_heading_t : public kaitai::kstruct {

    public:

        msg_baseline_heading_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, orientation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_baseline_heading_t();

    private:
        uint32_t m_tow;
        uint32_t m_heading;
        uint8_t m_n_sats;
        uint8_t m_flags;
        orientation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

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
        orientation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the quaternion vector describing the vehicle body
     * frame's orientation with respect to a local-level NED frame. The
     * components of the vector should sum to a unit vector assuming that the
     * LSB of each component as a value of 2^-31. This message will only be
     * available in future INS versions of Swift Products and is not produced
     * by Piksi Multi or Duro.
     */

    class msg_orient_quat_t : public kaitai::kstruct {

    public:

        msg_orient_quat_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, orientation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_orient_quat_t();

    private:
        uint32_t m_tow;
        int32_t m_w;
        int32_t m_x;
        int32_t m_y;
        int32_t m_z;
        float m_w_accuracy;
        float m_x_accuracy;
        float m_y_accuracy;
        float m_z_accuracy;
        uint8_t m_flags;
        orientation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Real component
         */
        int32_t w() const { return m_w; }

        /**
         * 1st imaginary component
         */
        int32_t x() const { return m_x; }

        /**
         * 2nd imaginary component
         */
        int32_t y() const { return m_y; }

        /**
         * 3rd imaginary component
         */
        int32_t z() const { return m_z; }

        /**
         * Estimated standard deviation of w
         */
        float w_accuracy() const { return m_w_accuracy; }

        /**
         * Estimated standard deviation of x
         */
        float x_accuracy() const { return m_x_accuracy; }

        /**
         * Estimated standard deviation of y
         */
        float y_accuracy() const { return m_y_accuracy; }

        /**
         * Estimated standard deviation of z
         */
        float z_accuracy() const { return m_z_accuracy; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        orientation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the yaw, pitch, and roll angles of the vehicle body
     * frame. The rotations should applied intrinsically in the order yaw,
     * pitch, and roll in order to rotate the from a frame aligned with the
     * local-level NED frame to the vehicle body frame.  This message will only
     * be available in future INS versions of Swift Products and is not
     * produced by Piksi Multi or Duro.
     */

    class msg_orient_euler_t : public kaitai::kstruct {

    public:

        msg_orient_euler_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, orientation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_orient_euler_t();

    private:
        uint32_t m_tow;
        int32_t m_roll;
        int32_t m_pitch;
        int32_t m_yaw;
        float m_roll_accuracy;
        float m_pitch_accuracy;
        float m_yaw_accuracy;
        uint8_t m_flags;
        orientation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * rotation about the forward axis of the vehicle
         */
        int32_t roll() const { return m_roll; }

        /**
         * rotation about the rightward axis of the vehicle
         */
        int32_t pitch() const { return m_pitch; }

        /**
         * rotation about the downward axis of the vehicle
         */
        int32_t yaw() const { return m_yaw; }

        /**
         * Estimated standard deviation of roll
         */
        float roll_accuracy() const { return m_roll_accuracy; }

        /**
         * Estimated standard deviation of pitch
         */
        float pitch_accuracy() const { return m_pitch_accuracy; }

        /**
         * Estimated standard deviation of yaw
         */
        float yaw_accuracy() const { return m_yaw_accuracy; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        orientation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the orientation rates in the vehicle body frame.
     * The values represent the measurements a strapped down gyroscope would
     * make and are not equivalent to the time derivative of the Euler angles.
     * The orientation and origin of the user frame is specified via device
     * settings. By convention, the vehicle x-axis is expected to be aligned
     * with the forward direction, while the vehicle y-axis is expected to be
     * aligned with the right direction, and the vehicle z-axis should be
     * aligned with the down direction. This message will only be available in
     * future INS versions of Swift Products and is not produced by Piksi Multi
     * or Duro.
     */

    class msg_angular_rate_t : public kaitai::kstruct {

    public:

        msg_angular_rate_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, orientation_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_angular_rate_t();

    private:
        uint32_t m_tow;
        int32_t m_x;
        int32_t m_y;
        int32_t m_z;
        uint8_t m_flags;
        orientation_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * angular rate about x axis
         */
        int32_t x() const { return m_x; }

        /**
         * angular rate about y axis
         */
        int32_t y() const { return m_y; }

        /**
         * angular rate about z axis
         */
        int32_t z() const { return m_z; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        orientation_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

private:
    orientation_t* m__root;
    kaitai::kstruct* m__parent;

public:
    orientation_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // ORIENTATION_H_
