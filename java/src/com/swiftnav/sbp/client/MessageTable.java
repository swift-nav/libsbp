/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.client;

import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPMessage.Builder;
import com.swiftnav.sbp.SBPMessage.Parser;
import com.swiftnav.sbp.ext_events.MsgExtEvent;
import com.swiftnav.sbp.file_io.MsgFileioReadReq;
import com.swiftnav.sbp.file_io.MsgFileioReadResp;
import com.swiftnav.sbp.file_io.MsgFileioReadDirReq;
import com.swiftnav.sbp.file_io.MsgFileioReadDirResp;
import com.swiftnav.sbp.file_io.MsgFileioRemove;
import com.swiftnav.sbp.file_io.MsgFileioWriteReq;
import com.swiftnav.sbp.file_io.MsgFileioWriteResp;
import com.swiftnav.sbp.system.MsgStartup;
import com.swiftnav.sbp.system.MsgHeartbeat;
import com.swiftnav.sbp.logging.MsgLog;
import com.swiftnav.sbp.logging.MsgTweet;
import com.swiftnav.sbp.logging.MsgPrintDep;
import com.swiftnav.sbp.settings.MsgSettingsSave;
import com.swiftnav.sbp.settings.MsgSettingsWrite;
import com.swiftnav.sbp.settings.MsgSettingsReadReq;
import com.swiftnav.sbp.settings.MsgSettingsReadResp;
import com.swiftnav.sbp.settings.MsgSettingsReadByIndexReq;
import com.swiftnav.sbp.settings.MsgSettingsReadByIndexResp;
import com.swiftnav.sbp.settings.MsgSettingsReadByIndexDone;
import com.swiftnav.sbp.settings.MsgSettingsRegister;
import com.swiftnav.sbp.observation.MsgObs;
import com.swiftnav.sbp.observation.MsgBasePosLLH;
import com.swiftnav.sbp.observation.MsgBasePosECEF;
import com.swiftnav.sbp.observation.MsgEphemeris;
import com.swiftnav.sbp.observation.MsgEphemerisDepA;
import com.swiftnav.sbp.observation.MsgEphemerisDepB;
import com.swiftnav.sbp.observation.MsgEphemerisDepC;
import com.swiftnav.sbp.observation.MsgObsDepA;
import com.swiftnav.sbp.observation.MsgObsDepB;
import com.swiftnav.sbp.bootload.MsgBootloaderHandshakeReq;
import com.swiftnav.sbp.bootload.MsgBootloaderHandshakeResp;
import com.swiftnav.sbp.bootload.MsgBootloaderJumpToApp;
import com.swiftnav.sbp.bootload.MsgNapDeviceDnaReq;
import com.swiftnav.sbp.bootload.MsgNapDeviceDnaResp;
import com.swiftnav.sbp.bootload.MsgBootloaderHandshakeDepA;
import com.swiftnav.sbp.flash.MsgFlashProgram;
import com.swiftnav.sbp.flash.MsgFlashDone;
import com.swiftnav.sbp.flash.MsgFlashReadReq;
import com.swiftnav.sbp.flash.MsgFlashReadResp;
import com.swiftnav.sbp.flash.MsgFlashErase;
import com.swiftnav.sbp.flash.MsgStmFlashLockSector;
import com.swiftnav.sbp.flash.MsgStmFlashUnlockSector;
import com.swiftnav.sbp.flash.MsgStmUniqueIdReq;
import com.swiftnav.sbp.flash.MsgStmUniqueIdResp;
import com.swiftnav.sbp.flash.MsgM25FlashWriteStatus;
import com.swiftnav.sbp.tracking.MsgTrackingState;
import com.swiftnav.sbp.tracking.MsgTrackingIq;
import com.swiftnav.sbp.tracking.MsgTrackingStateDepA;
import com.swiftnav.sbp.user.MsgUserData;
import com.swiftnav.sbp.navigation.MsgGPSTime;
import com.swiftnav.sbp.navigation.MsgDops;
import com.swiftnav.sbp.navigation.MsgPosECEF;
import com.swiftnav.sbp.navigation.MsgPosLLH;
import com.swiftnav.sbp.navigation.MsgBaselineECEF;
import com.swiftnav.sbp.navigation.MsgBaselineNED;
import com.swiftnav.sbp.navigation.MsgVelECEF;
import com.swiftnav.sbp.navigation.MsgVelNED;
import com.swiftnav.sbp.navigation.MsgBaselineHeading;
import com.swiftnav.sbp.acquisition.MsgAcqResult;
import com.swiftnav.sbp.acquisition.MsgAcqResultDepA;
import com.swiftnav.sbp.piksi.MsgAlmanac;
import com.swiftnav.sbp.piksi.MsgSetTime;
import com.swiftnav.sbp.piksi.MsgReset;
import com.swiftnav.sbp.piksi.MsgCwResults;
import com.swiftnav.sbp.piksi.MsgCwStart;
import com.swiftnav.sbp.piksi.MsgResetFilters;
import com.swiftnav.sbp.piksi.MsgInitBase;
import com.swiftnav.sbp.piksi.MsgThreadState;
import com.swiftnav.sbp.piksi.MsgUartState;
import com.swiftnav.sbp.piksi.MsgUartStateDepa;
import com.swiftnav.sbp.piksi.MsgIarState;
import com.swiftnav.sbp.piksi.MsgMaskSatellite;

final class MessageTable {
    static SBPMessage dispatch(SBPMessage msg) throws SBPBinaryException {
        switch (msg.type) {
            case MsgExtEvent.TYPE:
                return new MsgExtEvent(msg);
            case MsgFileioReadReq.TYPE:
                return new MsgFileioReadReq(msg);
            case MsgFileioReadResp.TYPE:
                return new MsgFileioReadResp(msg);
            case MsgFileioReadDirReq.TYPE:
                return new MsgFileioReadDirReq(msg);
            case MsgFileioReadDirResp.TYPE:
                return new MsgFileioReadDirResp(msg);
            case MsgFileioRemove.TYPE:
                return new MsgFileioRemove(msg);
            case MsgFileioWriteReq.TYPE:
                return new MsgFileioWriteReq(msg);
            case MsgFileioWriteResp.TYPE:
                return new MsgFileioWriteResp(msg);
            case MsgStartup.TYPE:
                return new MsgStartup(msg);
            case MsgHeartbeat.TYPE:
                return new MsgHeartbeat(msg);
            case MsgLog.TYPE:
                return new MsgLog(msg);
            case MsgTweet.TYPE:
                return new MsgTweet(msg);
            case MsgPrintDep.TYPE:
                return new MsgPrintDep(msg);
            case MsgSettingsSave.TYPE:
                return new MsgSettingsSave(msg);
            case MsgSettingsWrite.TYPE:
                return new MsgSettingsWrite(msg);
            case MsgSettingsReadReq.TYPE:
                return new MsgSettingsReadReq(msg);
            case MsgSettingsReadResp.TYPE:
                return new MsgSettingsReadResp(msg);
            case MsgSettingsReadByIndexReq.TYPE:
                return new MsgSettingsReadByIndexReq(msg);
            case MsgSettingsReadByIndexResp.TYPE:
                return new MsgSettingsReadByIndexResp(msg);
            case MsgSettingsReadByIndexDone.TYPE:
                return new MsgSettingsReadByIndexDone(msg);
            case MsgSettingsRegister.TYPE:
                return new MsgSettingsRegister(msg);
            case MsgObs.TYPE:
                return new MsgObs(msg);
            case MsgBasePosLLH.TYPE:
                return new MsgBasePosLLH(msg);
            case MsgBasePosECEF.TYPE:
                return new MsgBasePosECEF(msg);
            case MsgEphemeris.TYPE:
                return new MsgEphemeris(msg);
            case MsgEphemerisDepA.TYPE:
                return new MsgEphemerisDepA(msg);
            case MsgEphemerisDepB.TYPE:
                return new MsgEphemerisDepB(msg);
            case MsgEphemerisDepC.TYPE:
                return new MsgEphemerisDepC(msg);
            case MsgObsDepA.TYPE:
                return new MsgObsDepA(msg);
            case MsgObsDepB.TYPE:
                return new MsgObsDepB(msg);
            case MsgBootloaderHandshakeReq.TYPE:
                return new MsgBootloaderHandshakeReq(msg);
            case MsgBootloaderHandshakeResp.TYPE:
                return new MsgBootloaderHandshakeResp(msg);
            case MsgBootloaderJumpToApp.TYPE:
                return new MsgBootloaderJumpToApp(msg);
            case MsgNapDeviceDnaReq.TYPE:
                return new MsgNapDeviceDnaReq(msg);
            case MsgNapDeviceDnaResp.TYPE:
                return new MsgNapDeviceDnaResp(msg);
            case MsgBootloaderHandshakeDepA.TYPE:
                return new MsgBootloaderHandshakeDepA(msg);
            case MsgFlashProgram.TYPE:
                return new MsgFlashProgram(msg);
            case MsgFlashDone.TYPE:
                return new MsgFlashDone(msg);
            case MsgFlashReadReq.TYPE:
                return new MsgFlashReadReq(msg);
            case MsgFlashReadResp.TYPE:
                return new MsgFlashReadResp(msg);
            case MsgFlashErase.TYPE:
                return new MsgFlashErase(msg);
            case MsgStmFlashLockSector.TYPE:
                return new MsgStmFlashLockSector(msg);
            case MsgStmFlashUnlockSector.TYPE:
                return new MsgStmFlashUnlockSector(msg);
            case MsgStmUniqueIdReq.TYPE:
                return new MsgStmUniqueIdReq(msg);
            case MsgStmUniqueIdResp.TYPE:
                return new MsgStmUniqueIdResp(msg);
            case MsgM25FlashWriteStatus.TYPE:
                return new MsgM25FlashWriteStatus(msg);
            case MsgTrackingState.TYPE:
                return new MsgTrackingState(msg);
            case MsgTrackingIq.TYPE:
                return new MsgTrackingIq(msg);
            case MsgTrackingStateDepA.TYPE:
                return new MsgTrackingStateDepA(msg);
            case MsgUserData.TYPE:
                return new MsgUserData(msg);
            case MsgGPSTime.TYPE:
                return new MsgGPSTime(msg);
            case MsgDops.TYPE:
                return new MsgDops(msg);
            case MsgPosECEF.TYPE:
                return new MsgPosECEF(msg);
            case MsgPosLLH.TYPE:
                return new MsgPosLLH(msg);
            case MsgBaselineECEF.TYPE:
                return new MsgBaselineECEF(msg);
            case MsgBaselineNED.TYPE:
                return new MsgBaselineNED(msg);
            case MsgVelECEF.TYPE:
                return new MsgVelECEF(msg);
            case MsgVelNED.TYPE:
                return new MsgVelNED(msg);
            case MsgBaselineHeading.TYPE:
                return new MsgBaselineHeading(msg);
            case MsgAcqResult.TYPE:
                return new MsgAcqResult(msg);
            case MsgAcqResultDepA.TYPE:
                return new MsgAcqResultDepA(msg);
            case MsgAlmanac.TYPE:
                return new MsgAlmanac(msg);
            case MsgSetTime.TYPE:
                return new MsgSetTime(msg);
            case MsgReset.TYPE:
                return new MsgReset(msg);
            case MsgCwResults.TYPE:
                return new MsgCwResults(msg);
            case MsgCwStart.TYPE:
                return new MsgCwStart(msg);
            case MsgResetFilters.TYPE:
                return new MsgResetFilters(msg);
            case MsgInitBase.TYPE:
                return new MsgInitBase(msg);
            case MsgThreadState.TYPE:
                return new MsgThreadState(msg);
            case MsgUartState.TYPE:
                return new MsgUartState(msg);
            case MsgUartStateDepa.TYPE:
                return new MsgUartStateDepa(msg);
            case MsgIarState.TYPE:
                return new MsgIarState(msg);
            case MsgMaskSatellite.TYPE:
                return new MsgMaskSatellite(msg);
        }
        return msg;
    }
}

