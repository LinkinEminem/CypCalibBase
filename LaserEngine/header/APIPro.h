#pragma once

#include "ILaserTracker.h"
#include "./API_Pro/apidevice.h"
#include "EnvDefs.h"

namespace apipro
{
    class LASER_ENGINE_API TAPIPro : public ILaserTracker
    {
    public:
        TAPIPro();
        // ~TAPIPro() override;
        int Connect(const char* ipAddress, const int devNum, CallbackType callback, void* taskID) override;
        int Disconnect() override;
        int Home(const int smrSize) override;
        bool IsConnected() override;
        int GetSingleMeasure(const int interval, double* rstValue) override;
        int IsBeamLocked() override;
        int JogTo(const float azimuth, const float elevation) override;
        int TargetSearch(const float distance, const float radium, const float waitTime) override;
        bool GetAPIErrorMessage(const int errID, char* errMsg) override;
        int SetTrackMode() override;
    private:
        CAPIDevice FApiDev;
    };
}
