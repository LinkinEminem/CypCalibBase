#pragma once

#include "ILaserTracker.h"
#include "./API_Core/APIOTIIDevice.h"
#include "EnvDefs.h"

namespace apicore
{
    using namespace APIOTII;
    
    class LASER_ENGINE_API TAPICore : public ILaserTracker
    {
    public:
        TAPICore();
        // ~TAPICore() override;
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
        CAPIOTIIDevice FApiDev;
    };
}
