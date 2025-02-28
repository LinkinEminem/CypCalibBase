#pragma once

#include <Windows.h>
#include "EnvDefs.h"

typedef void(*CallbackType)(LPVOID, LPVOID);

class LASER_ENGINE_API ILaserTracker
{
public:
	virtual ~ILaserTracker() = default;
	
	virtual int Connect(const char* ipAddress, const int devNum, CallbackType callback, void* taskID) = 0;

	virtual int Disconnect() = 0;

	virtual int Home(const int smrSize) = 0;

	virtual bool IsConnected() = 0;

	virtual int GetSingleMeasure(int interval, double* rstValue) = 0;

	virtual int IsBeamLocked() = 0;

	virtual int JogTo(float azimuth, float elevation) = 0;

	virtual int TargetSearch(float distance, float radium, float waitTime) = 0;

	virtual bool GetAPIErrorMessage(const int errID, char* errMsg) = 0;

	virtual int SetTrackMode() = 0;
	
};

