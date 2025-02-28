#pragma once

#include "ILaserTracker.h"
#include "APIPro.h"
#include "APICore.h"
#include "TrackerFactory.h"

using namespace System;

namespace Proxy
{
	public delegate void LaserCallback(IntPtr param, IntPtr p2);

	public ref class TLaserTrackWrapper
	{
	private:
		ILaserTracker* _trackerDev;
	public:
		TLaserTrackWrapper(int brand);

		int Connect(String^ ipAddress, const int devNum, LaserCallback^ callback, int taskID);

		int Disconnect();

		int Home(const int smrSize);

		bool IsConnected();

		int GetSingleMeasure(const int interval, cli::array<double>^ varResult);
		
		int IsBeamLocked();
		
		int JogTo(const float azimuth, const float elevation);
		
		int TargetSearch(const float distance, const float radium, const float waitTime);
		
		bool GetAPIErrorMessage(const int errID, String^ errMsg);
		
		int SetTrackMode();
	};
}
