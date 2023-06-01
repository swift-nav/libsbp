#ifndef IMU_H_
#define IMU_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class imu_t : public kaitai::kstruct {

public:
    class msg_imu_raw_t;
    class msg_imu_aux_t;

    imu_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, imu_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~imu_t();

    /**
     * Raw data from the Inertial Measurement Unit, containing accelerometer
     * and gyroscope readings. The sense of the measurements are to be aligned
     * with the indications on the device itself. Measurement units, which are
     * specific to the device hardware and settings, are communicated via the
     * MSG_IMU_AUX message. If using "time since startup" local time tags, the
     * receiving end will expect a `MSG_PPS_TIME` regardless of GNSS fix state.
     * This also requires that the MSG_PPS_TIME message be sent prior to any
     * IMU RAW messages that are based on the current (as measured at the PPS
     * edge) local time timestamps. The local time (as defined in the
     * MSG_PPS_TIME message) must wrap around to zero when reaching the extent
     * of the u64 "Local time in microseconds" parameter.
     * The time-tagging mode should not change throughout a run.
     */

    class msg_imu_raw_t : public kaitai::kstruct {

    public:

        msg_imu_raw_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, imu_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_imu_raw_t();

    private:
        uint32_t m_tow;
        uint8_t m_tow_f;
        int16_t m_acc_x;
        int16_t m_acc_y;
        int16_t m_acc_z;
        int16_t m_gyr_x;
        int16_t m_gyr_y;
        int16_t m_gyr_z;
        imu_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Milliseconds since reference epoch and time status.
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Milliseconds since reference epoch, fractional part
         */
        uint8_t tow_f() const { return m_tow_f; }

        /**
         * Acceleration in the IMU frame X axis
         */
        int16_t acc_x() const { return m_acc_x; }

        /**
         * Acceleration in the IMU frame Y axis
         */
        int16_t acc_y() const { return m_acc_y; }

        /**
         * Acceleration in the IMU frame Z axis
         */
        int16_t acc_z() const { return m_acc_z; }

        /**
         * Angular rate around IMU frame X axis
         */
        int16_t gyr_x() const { return m_gyr_x; }

        /**
         * Angular rate around IMU frame Y axis
         */
        int16_t gyr_y() const { return m_gyr_y; }

        /**
         * Angular rate around IMU frame Z axis
         */
        int16_t gyr_z() const { return m_gyr_z; }
        imu_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Auxiliary data specific to a particular IMU. The `imu_type` field will
     * always be consistent but the rest of the payload is device specific and
     * depends on the value of `imu_type`.
     */

    class msg_imu_aux_t : public kaitai::kstruct {

    public:

        msg_imu_aux_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, imu_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_imu_aux_t();

    private:
        uint8_t m_imu_type;
        int16_t m_temp;
        uint8_t m_imu_conf;
        imu_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * IMU type
         */
        uint8_t imu_type() const { return m_imu_type; }

        /**
         * Raw IMU temperature
         */
        int16_t temp() const { return m_temp; }

        /**
         * IMU configuration
         */
        uint8_t imu_conf() const { return m_imu_conf; }
        imu_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

private:
    imu_t* m__root;
    kaitai::kstruct* m__parent;

public:
    imu_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // IMU_H_
