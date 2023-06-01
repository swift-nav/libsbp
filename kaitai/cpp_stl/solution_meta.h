#ifndef SOLUTION_META_H_
#define SOLUTION_META_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class solution_meta_t : public kaitai::kstruct {

public:
    class gnss_input_type_t;
    class msg_soln_meta_t;
    class msg_soln_meta_dep_a_t;
    class imu_input_type_t;
    class odo_input_type_t;
    class solution_input_type_t;

    solution_meta_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, solution_meta_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~solution_meta_t();

    /**
     * Metadata around the GNSS sensors involved in the fuzed solution.
     * Accessible through sol_in[N].flags in a MSG_SOLN_META.
     */

    class gnss_input_type_t : public kaitai::kstruct {

    public:

        gnss_input_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, solution_meta_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~gnss_input_type_t();

    private:
        uint8_t m_flags;
        solution_meta_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * flags that store all relevant info specific to this sensor type.
         */
        uint8_t flags() const { return m_flags; }
        solution_meta_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * This message contains all metadata about the sensors received and/or
     * used in computing the sensorfusion solution. It focuses primarily, but
     * not only, on GNSS metadata. Regarding the age of the last received valid
     * GNSS solution, the highest two bits are time status, indicating whether
     * age gnss can or can not be used to retrieve time of measurement (noted
     * TOM, also known as time of validity) If it can, subtract 'age gnss' from
     * 'tow' in navigation messages to get TOM. Can be used before alignment is
     * complete in the Fusion Engine, when output solution is the last received
     * valid GNSS solution and its tow is not a TOM.
     */

    class msg_soln_meta_t : public kaitai::kstruct {

    public:

        msg_soln_meta_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, solution_meta_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_soln_meta_t();

    private:
        uint32_t m_tow;
        uint16_t m_pdop;
        uint16_t m_hdop;
        uint16_t m_vdop;
        uint16_t m_age_corrections;
        uint32_t m_age_gnss;
        std::vector<solution_input_type_t*>* m_sol_in;
        solution_meta_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        uint32_t tow() const { return m_tow; }

        /**
         * Position Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        uint16_t pdop() const { return m_pdop; }

        /**
         * Horizontal Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        uint16_t hdop() const { return m_hdop; }

        /**
         * Vertical Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        uint16_t vdop() const { return m_vdop; }

        /**
         * Age of corrections as per last available AGE_CORRECTIONS from PVT
         * engine (0xFFFF indicates invalid)
         */
        uint16_t age_corrections() const { return m_age_corrections; }

        /**
         * Age and Time Status of the last received valid GNSS solution.
         */
        uint32_t age_gnss() const { return m_age_gnss; }

        /**
         * Array of Metadata describing the sensors potentially involved in the
         * solution. Each element in the array represents a single sensor type
         * and consists of flags containing (meta)data pertaining to that
         * specific single sensor. Refer to each (XX)InputType descriptor in
         * the present doc.
         */
        std::vector<solution_input_type_t*>* sol_in() const { return m_sol_in; }
        solution_meta_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_soln_meta_dep_a_t : public kaitai::kstruct {

    public:

        msg_soln_meta_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, solution_meta_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_soln_meta_dep_a_t();

    private:
        uint16_t m_pdop;
        uint16_t m_hdop;
        uint16_t m_vdop;
        uint8_t m_n_sats;
        uint16_t m_age_corrections;
        uint8_t m_alignment_status;
        uint32_t m_last_used_gnss_pos_tow;
        uint32_t m_last_used_gnss_vel_tow;
        std::vector<solution_input_type_t*>* m_sol_in;
        solution_meta_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Position Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        uint16_t pdop() const { return m_pdop; }

        /**
         * Horizontal Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        uint16_t hdop() const { return m_hdop; }

        /**
         * Vertical Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        uint16_t vdop() const { return m_vdop; }

        /**
         * Number of satellites as per last available solution from PVT engine
         */
        uint8_t n_sats() const { return m_n_sats; }

        /**
         * Age of corrections as per last available AGE_CORRECTIONS from PVT
         * engine (0xFFFF indicates invalid)
         */
        uint16_t age_corrections() const { return m_age_corrections; }

        /**
         * State of alignment and the status and receipt of the alignment
         * inputs
         */
        uint8_t alignment_status() const { return m_alignment_status; }

        /**
         * Tow of last-used GNSS position measurement
         */
        uint32_t last_used_gnss_pos_tow() const { return m_last_used_gnss_pos_tow; }

        /**
         * Tow of last-used GNSS velocity measurement
         */
        uint32_t last_used_gnss_vel_tow() const { return m_last_used_gnss_vel_tow; }

        /**
         * Array of Metadata describing the sensors potentially involved in the
         * solution. Each element in the array represents a single sensor type
         * and consists of flags containing (meta)data pertaining to that
         * specific single sensor. Refer to each (XX)InputType descriptor in
         * the present doc.
         */
        std::vector<solution_input_type_t*>* sol_in() const { return m_sol_in; }
        solution_meta_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Metadata around the IMU sensors involved in the fuzed solution.
     * Accessible through sol_in[N].flags in a MSG_SOLN_META.
     */

    class imu_input_type_t : public kaitai::kstruct {

    public:

        imu_input_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, solution_meta_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~imu_input_type_t();

    private:
        uint8_t m_flags;
        solution_meta_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Instrument time, grade, and architecture for a sensor.
         */
        uint8_t flags() const { return m_flags; }
        solution_meta_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * Metadata around the Odometry sensors involved in the fuzed solution.
     * Accessible through sol_in[N].flags in a MSG_SOLN_META.
     */

    class odo_input_type_t : public kaitai::kstruct {

    public:

        odo_input_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, solution_meta_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~odo_input_type_t();

    private:
        uint8_t m_flags;
        solution_meta_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Instrument ODO rate, grade, and quality.
         */
        uint8_t flags() const { return m_flags; }
        solution_meta_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * Metadata describing which sensors were involved in the solution. The
     * structure is fixed no matter what the actual sensor type is. The
     * sensor_type field tells you which sensor we are talking about. It also
     * tells you whether the sensor data was actually used or not. The flags
     * field, always a u8, contains the sensor-specific data. The content of
     * flags, for each sensor type, is described in the relevant structures in
     * this section.
     */

    class solution_input_type_t : public kaitai::kstruct {

    public:

        solution_input_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, solution_meta_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~solution_input_type_t();

    private:
        uint8_t m_sensor_type;
        uint8_t m_flags;
        solution_meta_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * The type of sensor
         */
        uint8_t sensor_type() const { return m_sensor_type; }

        /**
         * Refer to each InputType description
         */
        uint8_t flags() const { return m_flags; }
        solution_meta_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

private:
    solution_meta_t* m__root;
    kaitai::kstruct* m__parent;

public:
    solution_meta_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // SOLUTION_META_H_
