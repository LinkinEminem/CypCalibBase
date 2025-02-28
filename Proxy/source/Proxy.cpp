#include "Proxy.h"

using namespace System::Runtime::InteropServices;

namespace Proxy
{
	TLaserTrackWrapper::TLaserTrackWrapper(int brand)
	{
		_trackerDev = TrackerFactory::CreateTracker(brand);
	}

	int TLaserTrackWrapper::Connect(String^ ipAddress, const int devNum, LaserCallback^ callback, int taskID)
	{
		const auto ip = static_cast<const char*>((Marshal::StringToHGlobalAnsi(ipAddress)).ToPointer());
		const auto nativeCallback = static_cast<CallbackType>(Marshal::GetFunctionPointerForDelegate(callback).ToPointer());
		
		Object^ boxedID = taskID;
		GCHandle gch = GCHandle::Alloc(boxedID, GCHandleType::Pinned);
		IntPtr taskIDPtr = GCHandle::ToIntPtr(gch);
		int rst = _trackerDev->Connect(ip, devNum, nativeCallback, taskIDPtr.ToPointer());
		Marshal::FreeHGlobal(IntPtr((void*)ip));
		return rst;
	}

	int TLaserTrackWrapper::Disconnect()
	{
		return _trackerDev->Disconnect();
	}

	int TLaserTrackWrapper::Home(const int smrSize)
	{
		return _trackerDev->Home(smrSize);
	}

	bool TLaserTrackWrapper::IsConnected()
	{
		return _trackerDev->IsConnected();
	}

	int TLaserTrackWrapper::GetSingleMeasure(const int interval, cli::array<double>^ varResult)
	{
		pin_ptr<double> varResultPtr = &varResult[0];
		return _trackerDev->GetSingleMeasure(interval, varResultPtr);
	}
		
	int TLaserTrackWrapper::IsBeamLocked()
	{
		return _trackerDev->IsBeamLocked();
	}
		
	int TLaserTrackWrapper::JogTo(const float azimuth, const float elevation)
	{
		return _trackerDev->JogTo(azimuth, elevation);
	}
		
	int TLaserTrackWrapper::TargetSearch(const float distance, const float radium, const float waitTime)
	{
		return _trackerDev->TargetSearch(distance, radium, waitTime);
	}
		
	bool TLaserTrackWrapper::GetAPIErrorMessage(const int errID, String^ errMsg)
	{
		auto msg = static_cast<char*>((Marshal::StringToHGlobalAnsi(errMsg)).ToPointer());
		return _trackerDev->GetAPIErrorMessage(errID, msg);
	}
		
	int TLaserTrackWrapper::SetTrackMode()
	{
		return _trackerDev->SetTrackMode();
	}

}
