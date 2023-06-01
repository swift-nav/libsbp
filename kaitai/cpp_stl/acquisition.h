#ifndef ACQUISITION_H_
#define ACQUISITION_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class acquisition_t : public kaitai::kstruct {

public:
    class msg_acq_result_dep_c_t;
    class msg_acq_result_dep_b_t;
    class acq_sv_profile_t;
    class msg_acq_sv_profile_t;
    class acq_sv_profile_dep_t;
    class msg_acq_result_t;
    class msg_acq_result_dep_a_t;
    class msg_acq_sv_profile_dep_t;

    acquisition_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, acquisition_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~acquisition_t();

    /**
     * Deprecated.
     */

    class msg_acq_result_dep_c_t : public kaitai::kstruct {

    public:

        msg_acq_result_dep_c_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, acquisition_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_acq_result_dep_c_t();

    private:
        float m_cn0;
        float m_cp;
        float m_cf;
        gnss_t::gnss_signal_dep_t* m_sid;
        acquisition_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * CN/0 of best point
         */
        float cn0() const { return m_cn0; }

        /**
         * Code phase of best point
         */
        float cp() const { return m_cp; }

        /**
         * Carrier frequency of best point
         */
        float cf() const { return m_cf; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }
        acquisition_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_acq_result_dep_b_t : public kaitai::kstruct {

    public:

        msg_acq_result_dep_b_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, acquisition_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_acq_result_dep_b_t();

    private:
        float m_snr;
        float m_cp;
        float m_cf;
        gnss_t::gnss_signal_dep_t* m_sid;
        acquisition_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * SNR of best point. Currently in arbitrary SNR points, but will be in
         * units of dB Hz in a later revision of this message.
         */
        float snr() const { return m_snr; }

        /**
         * Code phase of best point
         */
        float cp() const { return m_cp; }

        /**
         * Carrier frequency of best point
         */
        float cf() const { return m_cf; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }
        acquisition_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Profile for a specific SV for debugging purposes. The message describes
     * SV profile during acquisition time. The message is used to debug and
     * measure the performance.
     */

    class acq_sv_profile_t : public kaitai::kstruct {

    public:

        acq_sv_profile_t(kaitai::kstream* p__io, acquisition_t::msg_acq_sv_profile_t* p__parent = 0, acquisition_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~acq_sv_profile_t();

    private:
        uint8_t m_job_type;
        uint8_t m_status;
        uint16_t m_cn0;
        uint8_t m_int_time;
        gnss_t::gnss_signal_t* m_sid;
        uint16_t m_bin_width;
        uint32_t m_timestamp;
        uint32_t m_time_spent;
        int32_t m_cf_min;
        int32_t m_cf_max;
        int32_t m_cf;
        uint32_t m_cp;
        acquisition_t* m__root;
        acquisition_t::msg_acq_sv_profile_t* m__parent;

    public:

        /**
         * SV search job type (deep, fallback, etc)
         */
        uint8_t job_type() const { return m_job_type; }

        /**
         * Acquisition status 1 is Success, 0 is Failure
         */
        uint8_t status() const { return m_status; }

        /**
         * CN0 value. Only valid if status is '1'
         */
        uint16_t cn0() const { return m_cn0; }

        /**
         * Acquisition integration time
         */
        uint8_t int_time() const { return m_int_time; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }

        /**
         * Acq frequency bin width
         */
        uint16_t bin_width() const { return m_bin_width; }

        /**
         * Timestamp of the job complete event
         */
        uint32_t timestamp() const { return m_timestamp; }

        /**
         * Time spent to search for sid.code
         */
        uint32_t time_spent() const { return m_time_spent; }

        /**
         * Doppler range lowest frequency
         */
        int32_t cf_min() const { return m_cf_min; }

        /**
         * Doppler range highest frequency
         */
        int32_t cf_max() const { return m_cf_max; }

        /**
         * Doppler value of detected peak. Only valid if status is '1'
         */
        int32_t cf() const { return m_cf; }

        /**
         * Codephase of detected peak. Only valid if status is '1'
         */
        uint32_t cp() const { return m_cp; }
        acquisition_t* _root() const { return m__root; }
        acquisition_t::msg_acq_sv_profile_t* _parent() const { return m__parent; }
    };

    /**
     * The message describes all SV profiles during acquisition time. The
     * message is used to debug and measure the performance.
     */

    class msg_acq_sv_profile_t : public kaitai::kstruct {

    public:

        msg_acq_sv_profile_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, acquisition_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_acq_sv_profile_t();

    private:
        std::vector<acq_sv_profile_t*>* m_acq_sv_profile;
        acquisition_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * SV profiles during acquisition time
         */
        std::vector<acq_sv_profile_t*>* acq_sv_profile() const { return m_acq_sv_profile; }
        acquisition_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class acq_sv_profile_dep_t : public kaitai::kstruct {

    public:

        acq_sv_profile_dep_t(kaitai::kstream* p__io, acquisition_t::msg_acq_sv_profile_dep_t* p__parent = 0, acquisition_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~acq_sv_profile_dep_t();

    private:
        uint8_t m_job_type;
        uint8_t m_status;
        uint16_t m_cn0;
        uint8_t m_int_time;
        gnss_t::gnss_signal_dep_t* m_sid;
        uint16_t m_bin_width;
        uint32_t m_timestamp;
        uint32_t m_time_spent;
        int32_t m_cf_min;
        int32_t m_cf_max;
        int32_t m_cf;
        uint32_t m_cp;
        acquisition_t* m__root;
        acquisition_t::msg_acq_sv_profile_dep_t* m__parent;

    public:

        /**
         * SV search job type (deep, fallback, etc)
         */
        uint8_t job_type() const { return m_job_type; }

        /**
         * Acquisition status 1 is Success, 0 is Failure
         */
        uint8_t status() const { return m_status; }

        /**
         * CN0 value. Only valid if status is '1'
         */
        uint16_t cn0() const { return m_cn0; }

        /**
         * Acquisition integration time
         */
        uint8_t int_time() const { return m_int_time; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }

        /**
         * Acq frequency bin width
         */
        uint16_t bin_width() const { return m_bin_width; }

        /**
         * Timestamp of the job complete event
         */
        uint32_t timestamp() const { return m_timestamp; }

        /**
         * Time spent to search for sid.code
         */
        uint32_t time_spent() const { return m_time_spent; }

        /**
         * Doppler range lowest frequency
         */
        int32_t cf_min() const { return m_cf_min; }

        /**
         * Doppler range highest frequency
         */
        int32_t cf_max() const { return m_cf_max; }

        /**
         * Doppler value of detected peak. Only valid if status is '1'
         */
        int32_t cf() const { return m_cf; }

        /**
         * Codephase of detected peak. Only valid if status is '1'
         */
        uint32_t cp() const { return m_cp; }
        acquisition_t* _root() const { return m__root; }
        acquisition_t::msg_acq_sv_profile_dep_t* _parent() const { return m__parent; }
    };

    /**
     * This message describes the results from an attempted GPS signal
     * acquisition search for a satellite PRN over a code phase/carrier
     * frequency range. It contains the parameters of the point in the
     * acquisition search space with the best carrier-to-noise (CN/0) ratio.
     */

    class msg_acq_result_t : public kaitai::kstruct {

    public:

        msg_acq_result_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, acquisition_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_acq_result_t();

    private:
        float m_cn0;
        float m_cp;
        float m_cf;
        gnss_t::gnss_signal_t* m_sid;
        acquisition_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * CN/0 of best point
         */
        float cn0() const { return m_cn0; }

        /**
         * Code phase of best point
         */
        float cp() const { return m_cp; }

        /**
         * Carrier frequency of best point
         */
        float cf() const { return m_cf; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }
        acquisition_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_acq_result_dep_a_t : public kaitai::kstruct {

    public:

        msg_acq_result_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, acquisition_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_acq_result_dep_a_t();

    private:
        float m_snr;
        float m_cp;
        float m_cf;
        uint8_t m_prn;
        acquisition_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * SNR of best point. Currently dimensionless, but will have units of
         * dB Hz in the revision of this message.
         */
        float snr() const { return m_snr; }

        /**
         * Code phase of best point
         */
        float cp() const { return m_cp; }

        /**
         * Carrier frequency of best point
         */
        float cf() const { return m_cf; }

        /**
         * PRN-1 identifier of the satellite signal for which acquisition was
         * attempted
         */
        uint8_t prn() const { return m_prn; }
        acquisition_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_acq_sv_profile_dep_t : public kaitai::kstruct {

    public:

        msg_acq_sv_profile_dep_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, acquisition_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_acq_sv_profile_dep_t();

    private:
        std::vector<acq_sv_profile_dep_t*>* m_acq_sv_profile;
        acquisition_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * SV profiles during acquisition time
         */
        std::vector<acq_sv_profile_dep_t*>* acq_sv_profile() const { return m_acq_sv_profile; }
        acquisition_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

private:
    acquisition_t* m__root;
    kaitai::kstruct* m__parent;

public:
    acquisition_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // ACQUISITION_H_
