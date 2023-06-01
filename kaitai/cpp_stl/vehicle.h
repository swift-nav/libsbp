#ifndef VEHICLE_H_
#define VEHICLE_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class vehicle_t : public kaitai::kstruct {

public:
    class msg_odometry_t;
    class msg_wheeltick_t;

    vehicle_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, vehicle_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~vehicle_t();

    /**
     * Message representing the x component of vehicle velocity in the user
     * frame at the odometry reference point(s) specified by the user. The
     * offset for the odometry reference point and the definition and origin of
     * the user frame are defined through the device settings interface. There
     * are 4 possible user-defined sources of this message which are labeled
     * arbitrarily source 0 through 3. If using "processor time" time tags, the
     * receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
     * becomes available to synchronise odometry measurements with GNSS.
     * Processor time shall roll over to zero after one week.
     */

    class msg_odometry_t : public kaitai::kstruct {

    public:

        msg_odometry_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, vehicle_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_odometry_t();

    private:
        uint32_t m_tow;
        int32_t m_velocity;
        uint8_t m_flags;
        vehicle_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Time field representing either milliseconds in the GPS Week or local
         * CPU time from the producing system in milliseconds.  See the
         * tow_source flag for the exact source of this timestamp.
         */
        uint32_t tow() const { return m_tow; }

        /**
         * The signed forward component of vehicle velocity.
         */
        int32_t velocity() const { return m_velocity; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        vehicle_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Message containing the accumulated distance travelled by a wheel located
     * at an odometry reference point defined by the user. The offset for the
     * odometry reference point and the definition and origin of the user frame
     * are defined through the device settings interface. The source of this
     * message is identified by the source field, which is an integer ranging
     * from 0 to 255. The timestamp associated with this message should
     * represent the time when the accumulated tick count reached the value
     * given by the contents of this message as accurately as possible. If
     * using "local CPU time" time tags, the receiving end will expect a
     * `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise
     * wheeltick measurements with GNSS. Local CPU time shall roll over to zero
     * after one week.
     */

    class msg_wheeltick_t : public kaitai::kstruct {

    public:

        msg_wheeltick_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, vehicle_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_wheeltick_t();

    private:
        uint64_t m_time;
        uint8_t m_flags;
        uint8_t m_source;
        int32_t m_ticks;
        vehicle_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Time field representing either microseconds since the last PPS,
         * microseconds in the GPS Week or local CPU time from the producing
         * system in microseconds. See the synch_type field for the exact
         * meaning of this timestamp.
         */
        uint64_t time() const { return m_time; }

        /**
         * Field indicating the type of timestamp contained in the time field.
         */
        uint8_t flags() const { return m_flags; }

        /**
         * ID of the sensor producing this message
         */
        uint8_t source() const { return m_source; }

        /**
         * Free-running counter of the accumulated distance for this sensor.
         * The counter should be incrementing if travelling into one direction
         * and decrementing when travelling in the opposite direction.
         */
        int32_t ticks() const { return m_ticks; }
        vehicle_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

private:
    vehicle_t* m__root;
    kaitai::kstruct* m__parent;

public:
    vehicle_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // VEHICLE_H_
