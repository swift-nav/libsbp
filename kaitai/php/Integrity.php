<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Integrity extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Integrity $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

namespace Integrity {
    class MsgSsrFlagSatellites extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Integrity $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_obsTime = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_numMsgs = $this->_io->readU1();
            $this->_m_seqNum = $this->_io->readU1();
            $this->_m_ssrSolId = $this->_io->readU1();
            $this->_m_chainId = $this->_io->readU1();
            $this->_m_constId = $this->_io->readU1();
            $this->_m_nFaultySats = $this->_io->readU1();
            $this->_m_faultySats = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_faultySats[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_obsTime;
        protected $_m_numMsgs;
        protected $_m_seqNum;
        protected $_m_ssrSolId;
        protected $_m_chainId;
        protected $_m_constId;
        protected $_m_nFaultySats;
        protected $_m_faultySats;

        /**
         * GNSS reference time of the observation used to generate the flag.
         */
        public function obsTime() { return $this->_m_obsTime; }

        /**
         * Number of messages in the dataset
         */
        public function numMsgs() { return $this->_m_numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public function seqNum() { return $this->_m_seqNum; }

        /**
         * SSR Solution ID.
         */
        public function ssrSolId() { return $this->_m_ssrSolId; }

        /**
         * Chain and type of flag.
         */
        public function chainId() { return $this->_m_chainId; }

        /**
         * Constellation ID.
         */
        public function constId() { return $this->_m_constId; }

        /**
         * Number of faulty satellites.
         */
        public function nFaultySats() { return $this->_m_nFaultySats; }

        /**
         * List of faulty satellites.
         */
        public function faultySats() { return $this->_m_faultySats; }
    }
}

namespace Integrity {
    class MsgSsrFlagIonoTileSatLos extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Integrity $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Integrity\IntegritySsrHeader($this->_io, $this, $this->_root);
            $this->_m_nFaultyLos = $this->_io->readU1();
            $this->_m_faultyLos = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_faultyLos[] = new \Gnss\SvId($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_nFaultyLos;
        protected $_m_faultyLos;

        /**
         * Header of an integrity message.
         */
        public function header() { return $this->_m_header; }

        /**
         * Number of faulty LOS.
         */
        public function nFaultyLos() { return $this->_m_nFaultyLos; }

        /**
         * List of faulty LOS
         */
        public function faultyLos() { return $this->_m_faultyLos; }
    }
}

namespace Integrity {
    class MsgSsrFlagIonoGridPointSatLos extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Integrity $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Integrity\IntegritySsrHeader($this->_io, $this, $this->_root);
            $this->_m_gridPointId = $this->_io->readU2le();
            $this->_m_nFaultyLos = $this->_io->readU1();
            $this->_m_faultyLos = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_faultyLos[] = new \Gnss\SvId($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_gridPointId;
        protected $_m_nFaultyLos;
        protected $_m_faultyLos;

        /**
         * Header of an integrity message.
         */
        public function header() { return $this->_m_header; }

        /**
         * Index of the grid point.
         */
        public function gridPointId() { return $this->_m_gridPointId; }

        /**
         * Number of faulty LOS.
         */
        public function nFaultyLos() { return $this->_m_nFaultyLos; }

        /**
         * List of faulty LOS
         */
        public function faultyLos() { return $this->_m_faultyLos; }
    }
}

namespace Integrity {
    class IntegritySsrHeader extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Integrity $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_obsTime = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_numMsgs = $this->_io->readU1();
            $this->_m_seqNum = $this->_io->readU1();
            $this->_m_ssrSolId = $this->_io->readU1();
            $this->_m_tileSetId = $this->_io->readU2le();
            $this->_m_tileId = $this->_io->readU2le();
            $this->_m_chainId = $this->_io->readU1();
        }
        protected $_m_obsTime;
        protected $_m_numMsgs;
        protected $_m_seqNum;
        protected $_m_ssrSolId;
        protected $_m_tileSetId;
        protected $_m_tileId;
        protected $_m_chainId;

        /**
         * GNSS reference time of the observation used to generate the flag.
         */
        public function obsTime() { return $this->_m_obsTime; }

        /**
         * Number of messages in the dataset
         */
        public function numMsgs() { return $this->_m_numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public function seqNum() { return $this->_m_seqNum; }

        /**
         * SSR Solution ID.
         */
        public function ssrSolId() { return $this->_m_ssrSolId; }

        /**
         * Unique identifier of the set this tile belongs to.
         */
        public function tileSetId() { return $this->_m_tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        public function tileId() { return $this->_m_tileId; }

        /**
         * Chain and type of flag.
         */
        public function chainId() { return $this->_m_chainId; }
    }
}

namespace Integrity {
    class MsgAcknowledge extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Integrity $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_requestId = $this->_io->readU1();
            $this->_m_areaId = $this->_io->readU4le();
            $this->_m_responseCode = $this->_io->readU1();
            $this->_m_correctionMaskOnDemand = $this->_io->readU2le();
            $this->_m_correctionMaskStream = $this->_io->readU2le();
            $this->_m_solutionId = $this->_io->readU1();
        }
        protected $_m_requestId;
        protected $_m_areaId;
        protected $_m_responseCode;
        protected $_m_correctionMaskOnDemand;
        protected $_m_correctionMaskStream;
        protected $_m_solutionId;

        /**
         * Echo of the request ID field from the corresponding CRA message, or
         * 255 if no request ID was provided.
         */
        public function requestId() { return $this->_m_requestId; }

        /**
         * Echo of the Area ID field from the corresponding CRA message.
         */
        public function areaId() { return $this->_m_areaId; }

        /**
         * Reported status of the request.
         */
        public function responseCode() { return $this->_m_responseCode; }

        /**
         * Contains the message group(s) that will be sent in response from the
         * corresponding CRA correction mask. An echo of the correction mask
         * field from the corresponding CRA message.
         */
        public function correctionMaskOnDemand() { return $this->_m_correctionMaskOnDemand; }

        /**
         * For future expansion. Always set to 0.
         */
        public function correctionMaskStream() { return $this->_m_correctionMaskStream; }

        /**
         * The solution ID of the instance providing the corrections.
         */
        public function solutionId() { return $this->_m_solutionId; }
    }
}

namespace Integrity {
    class MsgSsrFlagIonoGridPoints extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Integrity $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Integrity\IntegritySsrHeader($this->_io, $this, $this->_root);
            $this->_m_nFaultyPoints = $this->_io->readU1();
            $this->_m_faultyPoints = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_faultyPoints[] = $this->_io->readU2le();
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_nFaultyPoints;
        protected $_m_faultyPoints;

        /**
         * Header of an integrity message.
         */
        public function header() { return $this->_m_header; }

        /**
         * Number of faulty grid points.
         */
        public function nFaultyPoints() { return $this->_m_nFaultyPoints; }

        /**
         * List of faulty grid points.
         */
        public function faultyPoints() { return $this->_m_faultyPoints; }
    }
}

namespace Integrity {
    class MsgSsrFlagTropoGridPoints extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Integrity $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Integrity\IntegritySsrHeader($this->_io, $this, $this->_root);
            $this->_m_nFaultyPoints = $this->_io->readU1();
            $this->_m_faultyPoints = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_faultyPoints[] = $this->_io->readU2le();
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_nFaultyPoints;
        protected $_m_faultyPoints;

        /**
         * Header of an integrity message.
         */
        public function header() { return $this->_m_header; }

        /**
         * Number of faulty grid points.
         */
        public function nFaultyPoints() { return $this->_m_nFaultyPoints; }

        /**
         * List of faulty grid points.
         */
        public function faultyPoints() { return $this->_m_faultyPoints; }
    }
}

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

namespace Integrity {
    class MsgSsrFlagHighLevel extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Integrity $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_obsTime = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_corrTime = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_ssrSolId = $this->_io->readU1();
            $this->_m_tileSetId = $this->_io->readU2le();
            $this->_m_tileId = $this->_io->readU2le();
            $this->_m_chainId = $this->_io->readU1();
            $this->_m_useGpsSat = $this->_io->readU1();
            $this->_m_useGalSat = $this->_io->readU1();
            $this->_m_useBdsSat = $this->_io->readU1();
            $this->_m_reserved = [];
            $n = 6;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_reserved[] = $this->_io->readU1();
            }
            $this->_m_useTropoGridPoints = $this->_io->readU1();
            $this->_m_useIonoGridPoints = $this->_io->readU1();
            $this->_m_useIonoTileSatLos = $this->_io->readU1();
            $this->_m_useIonoGridPointSatLos = $this->_io->readU1();
        }
        protected $_m_obsTime;
        protected $_m_corrTime;
        protected $_m_ssrSolId;
        protected $_m_tileSetId;
        protected $_m_tileId;
        protected $_m_chainId;
        protected $_m_useGpsSat;
        protected $_m_useGalSat;
        protected $_m_useBdsSat;
        protected $_m_reserved;
        protected $_m_useTropoGridPoints;
        protected $_m_useIonoGridPoints;
        protected $_m_useIonoTileSatLos;
        protected $_m_useIonoGridPointSatLos;

        /**
         * GNSS reference time of the observation used to generate the flag.
         */
        public function obsTime() { return $this->_m_obsTime; }

        /**
         * GNSS reference time of the correction associated to the flag.
         */
        public function corrTime() { return $this->_m_corrTime; }

        /**
         * SSR Solution ID.
         */
        public function ssrSolId() { return $this->_m_ssrSolId; }

        /**
         * Unique identifier of the set this tile belongs to.
         */
        public function tileSetId() { return $this->_m_tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        public function tileId() { return $this->_m_tileId; }

        /**
         * Chain and type of flag.
         */
        public function chainId() { return $this->_m_chainId; }

        /**
         * Use GPS satellites.
         */
        public function useGpsSat() { return $this->_m_useGpsSat; }

        /**
         * Use GAL satellites.
         */
        public function useGalSat() { return $this->_m_useGalSat; }

        /**
         * Use BDS satellites.
         */
        public function useBdsSat() { return $this->_m_useBdsSat; }

        /**
         * Reserved
         */
        public function reserved() { return $this->_m_reserved; }

        /**
         * Use tropo grid points.
         */
        public function useTropoGridPoints() { return $this->_m_useTropoGridPoints; }

        /**
         * Use iono grid points.
         */
        public function useIonoGridPoints() { return $this->_m_useIonoGridPoints; }

        /**
         * Use iono tile satellite LoS.
         */
        public function useIonoTileSatLos() { return $this->_m_useIonoTileSatLos; }

        /**
         * Use iono grid point satellite LoS.
         */
        public function useIonoGridPointSatLos() { return $this->_m_useIonoGridPointSatLos; }
    }
}
