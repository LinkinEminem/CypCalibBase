#include "APICore.h"
#include <fstream>

namespace apicore
{
    TAPICore::TAPICore()
    = default;

    // TAPICore::~TAPICore()
    // = default;

    int TAPICore::Connect(const char* ipAddress, const int devNum, CallbackType callback, void* taskID)
    {
        const auto ipPath = const_cast<LPTSTR>(ipAddress);
        const int retCode = FApiDev.Connect(nullptr, devNum, callback, taskID, ipPath);
        if (retCode == API_ERROR_SUCCESS)
        {
            return FApiDev.ADMAutoSet(true);
        }
        return retCode;
    }

    int TAPICore::Disconnect()
    {
        return FApiDev.DisConnect();
    }

    int TAPICore::Home(const int smrSize)
    {
        return FApiDev.Home(smrSize);
    }

    bool TAPICore::IsConnected()
    {
        return FApiDev.IsConnected();
    }

    int TAPICore::GetSingleMeasure(const int interval, double* rstValue)
    {
        constexpr ULONG avgTime = 1000;
        constexpr int sigma = 3;
        HANDLE callback = nullptr;
        int nRetCode = FApiDev.startSigmaMeasure(avgTime, callback, sigma);
        if (nRetCode != API_ERROR_SUCCESS)
        {
            rstValue[0] = -1;
            rstValue[1] = -1;
            rstValue[2] = -1;
            return -111;
        }

        // 使能静态测量模式
        nRetCode = FApiDev.TrackerCommandTrigger();
        if (nRetCode != API_ERROR_SUCCESS)
        {
            rstValue[0] = -2;
            rstValue[1] = -2;
            rstValue[2] = -2;
            return -222;
        }
        Sleep(interval);

        // 取回测量结果
        APIOTII::D_VECTOR3 rstBuffer;
        bool bDone = false, bValid = false;
        double avgRst = 0.0;
        double maxError = 0.0;
        double rmsError = 0.0;
        nRetCode = FApiDev.getSigmaMeasurement(rstBuffer, bDone, bValid, avgRst, maxError, rmsError);
        if (nRetCode != API_ERROR_SUCCESS)
        {
            Sleep(500);
            nRetCode = FApiDev.getSigmaMeasurement(rstBuffer, bDone, bValid, avgRst, maxError, rmsError);
        }
        if (nRetCode != API_ERROR_SUCCESS)
        {
            rstValue[0] = -3;
            rstValue[1] = -3;
            rstValue[2] = -3;
            if (rmsError > 1e-1)
            {
                rstValue[0] = -4;
                rstValue[1] = -4;
                rstValue[2] = -4;
            }
            return nRetCode;
        }

        rstValue[0] = rstBuffer.x;
        rstValue[1] = rstBuffer.y;
        rstValue[2] = rstBuffer.z;

        return nRetCode;
    }
    
    int TAPICore::IsBeamLocked()
    {
        REALTIME_INFO info;
        const int ret = FApiDev.getRTData(info);
        if (ret == API_ERROR_SUCCESS)
        {
            return !info.Laser_Path_Error && !info.Laser_Dist_Error && (info.Operation_Mode == APIOTII::OP_Track);
        }
        return ret; 
    }
    
    int TAPICore::JogTo(float azimuth, float elevation)
    {
        TARGET_EXTENDED jog;
        jog.JogMode = false;
        jog.InPosition = true;
        jog.Azimuth = azimuth;
        jog.Elevation = elevation;
        jog.ApplyOffset = false;
        jog.UseCompensated = false;
        return FApiDev.JogTo(jog);
    }
    
    int TAPICore::TargetSearch(const float distance, const float radium, const float waitTime)
    {
        return FApiDev.TargetSearch(distance, radium, waitTime);
    }

    bool TAPICore::GetAPIErrorMessage(const int errID, char* errMsg)
    {
        return FApiDev.getAPIErrorMessage(errMsg, errID);
    }
    
    int TAPICore::SetTrackMode()
    {
        return FApiDev.SwitchToTrack();
    }
}
