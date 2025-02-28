/////////////////////////////////////////////////////////////////////////////////////// 
//
// Header for APIDevice DLL
// 
// Copyright 2012 by Automated Precision, Inc.
// 15000 Johns Hopkins Drive
// Rockville, Maryland 20850
// (240) 268-0400
// www.apisensor.com
//
///////////////////////////////////////////////////////////////////////////////////////
#if !defined _APIOTIIDEVICE_H_
#define _APIOTIIDEVICE_H_

#ifdef _APIOTIIDEVICE_DLL_
#define APIOTIIDEVICE_API __declspec(dllexport)
#else
#define APIOTIIDEVICE_API __declspec(dllimport)
#endif

#include "APIOTIIGeneric.h"
#include <time.h>
#include <vector>
using namespace std;


namespace APIOTII
{
//Foward declaration
class IScanClient;
class CFTPManager;
class CSts;
class S_SIXDTRACKER;
class CTaskManager;
class CDataSampler;
class CApiIP;
class CPrmManager;
class CTLedMan;
class CPrmManager;
class CIPLed;
class CDataCollection;
class CAttAngle;
class IvisionDlg;
class CProbeWirelessStrength;
struct IScanData;
struct ScanLine;

class APIOTIIDEVICE_API CAPIOTIIDevice
{
    
public:
	/****/CAPIOTIIDevice();
	/****/virtual ~CAPIOTIIDevice();
	/****/void SetDIDllDirectory(LPCTSTR pszDLLPath=NULL);
	/****/void Destroy();   
	/****/int  autoDetect(double dTime, void (*pTaskCallBk)(LPVOID, LPVOID), LPVOID p = NULL);
	/****/int  Connect(LPTSTR  sPath, int nDev, void (*pTaskCallBk)(LPVOID, LPVOID), LPVOID = NULL, LPTSTR lpszIP=NULL);
	
	//To check if the API is connected 
	/****/bool IsConnected();
	
	//Disconnect API
	/****/int  DisConnect();
	
	//Bring the API to birdbath position.
	/****/int  Home(int nIdx=0);

	//Search for the target in spiral motion within estimated distance and radius
	/****/int  TargetSearch(const float fEstDis, float fEstRadius, float fTimeout = 40.0f); 

	//Jog/position the API to certain location in incremental step
	/****/int  JogBy(TARGET_JOG&);

	//Jog/position the API to absolute position
	/****/int  JogTo(TARGET_EXTENDED&);
	
	//Point API to certain position	
    /****/int  PointTo(TARGET_Cartesian& tg);
	
	//Drive the tracker to a remote position and make that a new home position
    /****/int  RemoteHome(const RESET_CARTESIAN&resetPos);
	
	//Search for any accessory that are connected to API
	/****/int  AccSearch();
	
	//Identify the proper level.
	/****/int  VirtualLevel(bool applyCalculatedVLFrame = true);
	
	//Apply the level compensation based on the virtual level routine
	/****/int  applyVirtualLevel(bool bEnableVL, bool bAbsoluteMode=true, double *fixedRxyz=NULL);
	
	//Get the existing level frame
	/****/int  getT3VirtualLevelFrame(double *pT3LevelFrame, double *calcVLFrame, double *fixedRxyz);
	
	//Get the existing level offset
	/****/int  getVirtualLevelOffset(double *virtualLvlOffset);
	
	//Reset IFM distance based on ADM distance value
	/****/int  ADMReset();
	
	//Check the status of suto ADM setting
	/****/int  getADMAutosetStatus(bool &bAutosetOn);
	
	//Get current home position
	/****/int  getHomePosition(POLAR_REF&, const int = 0);
	
	//Set/reset ADM auto setting.
	/****/int  ADMAutoSet(bool bFlag);
	
	//To know if ADM module is available or if ADM beam is available
	/****/int  isADMAvailable(bool &bAvailable);
	
	//To know if IFM beam is available
	/****/int  isIFMAvailable(bool &bAvailable);
	
	//To know if level sensor is present
	/****/int  isLevelSensorAvailable(bool &bAvailable);
	
	//To know if humidity sensor is present
	/****/int  isHumiditySensorAvailable(bool &bAvailable);
	
	//Abort any on-going task
	/****/int  AbortTask();
	
	//Get the current task information
	/****/int  getCurrentTask();
	
	//Check if the on-going task is successful or not
	/****/bool IsTaskSuccessful(int &nRetCode, bool&);
	
	//Check the status of the on-going task
	/****/int  getTaskStatus(int &nCur, int &nTotal);

	//Set the environmental variables to certain number, usually used when the weather station is not connected or 
	//when you want to override the real time weather station reading.
	/****/int  setEnvironment(float fAirPressure, float fAirTemperature, float fHumidity, bool bUseSensorReading,
							DWORD dwUpdateRate = 5000) const;

	//Drive the API to/from frontsight/backsight position to take a measurement
	/****/int  BKSightOperation();

	//Perform fronsight backsight check to verify the deviation is well within tolerance.
    /****/int  BKSightChecking();

	//Get the fron/back sight checking result
	/****/int  getBKCheckingResult(D_VECTOR4 &angles, D_VECTOR2 &diff);
	/****/int  getBKCheckingResult(D_VECTOR4 &angles, D_VECTOR2 &diff, bool &bChkPass);

	//Get the API unit info
	/****/int  setModel(APIDEVICE_MODEL nMod);
    /****/int  getModel(APIDEVICE_MODEL &nMod);

	//Get real time data from API device
	/****/int  getRTData(REALTIME_INFO &);
	
	//Set API device LED status as per requirement: ON, OFF, BLINKING, ADMFLY 
	/****/int  setLEDState(unsigned int ls);

	//-----------------------------------------Motor Control-----------------------------------------
	//Drive the API device to idle mode. You cannot do any measurement/operation when the device is in idle mode
	/****/int  SwitchToIdle();

	//Put the API device to position mode if you wish to jog it.
    /****/int  SwitchToPosition();

	//Put the API device to tracking mode
    /****/int  SwitchToTrack();
	
	//Perform index search and let the API device align itself to birdbath position. 
	/****/int  IndexSearch();
   
	//Put the API device in power disabled mode if you dont intend to use it for a while, but dont want to turn it off either.
	/****/int  PowerDisable();

	//Bring back the device to power enabled mode.
	/****/int  PowerEnable();

	//Start Innovo camera mode
	/****/int  EnableCameraMode(bool bFlag);
  
	   //-----------------------------------------Tracker measurement mode-----------------------------------------
	//Stop any on-going measurement
    /****/int  stopMeasure();
	
	//Used for starting single point measurement
	/****/int  startSigmaMeasure(const ULONG avgTime, HANDLE &hDone, const int sigma, bool bWarning=false);
																									
	//Used for getting single point measurement value
    /****/int  getSigmaMeasurement(D_VECTOR3 &result, bool &bDone, bool &bValid, double &average, double &max, double &rms);

	 //Start distance based measurement
    /****/int  startDynaDisMeasure(const float fDis, bool bWarning=false);

	//Start time based measurement
    /****/int  startDynaTempMeasure(const int iPeriod, bool bWarning=false); 

	//Start time based rate filetered measurement
    /****/int  startRateFilterMeasure(const int iPeriod, bool bWarning=false);

	//Retrieve time based rate filtered measurement
    /****/bool getRateFilterMeasurement(D_VECTOR4 &data);

	//Retrieve measurement result which was started using either startDynaDisMeasure or startDynaTempMeasure
    /****/bool getMeasurement(D_VECTOR3 &data);
	/****/bool getMeasurement(D_VECTOR4 &data);

	//Trigger the device to take a measurement. generally while using a SMR
	/****/int  TrackerCommandTrigger();

	//For various data collection 
	/****/int  TrackerCapturingOperation(TCK_CAPTUREMODE CaptureMode, GDATCAP_TYPE* pBuffer, TCKDATAMASK mask,float fParam1,
							  float fParam2, ULONG uParam1, ULONG uParam2, clock_t WaitingDelay, HANDLE &handle);

	//To keep track of tracker FIFO data
	/****/int  TrackerFIFOinformation(FIFO_INFO &FF_Info);

	//To know the on-going data collection mode
	/****/int  getDataCaptureMode(TCK_CAPTUREMODE &mode); 
	
	//Get the error code and message. A message box will not pop up giving the error message
	/****/bool getAPIErrorMessage(LPTSTR,const int errorCode);

	//To display the error message.
	/****/void DisplayAPIErrorMessage(const int errorCode);
			
	//-----------------------------------------For system information-----------------------------------------
	//Get the IP address of the API device
	/****/int  getTrackerIP(BYTE* pbIPAddress);

	//Check the API device firmware version
	/****/int  getFirmwareVersion(LPTSTR);
	/****/int getFirmwareVersion(DWORD &majRev, DWORD &minRev);

	//API device's owner information
	/****/int  getLicenseOwner(LPTSTR);

	//Device interface version 
	/****/int  getDIVersion(LPTSTR);

	//API device ID
	/****/int  getTrackerID(int&);

	//ID of any accessory that is connected to API Device
	/*89*/int  getAccID(int&);

	//Get the API device type, if it is only ADM unit or has both ADM and IFM modules
	/****/int  getTrackerType(LPTSTR trackerTypeStr, TRACKER_TYPE &type);

	//Get the type of the accessory
	/****/int  getAccType(LPTSTR);

	//Get the device interface release date(SDK release date)
	/****/int  getDIReleaseDate(LPTSTR pReleaseDate);

	//Get device identification string
	/****/int  getDeviceString(LPTSTR pDevString);

	//Accessory serial number	
	/****/int  getAccSerialNumber(int &sn);

	//Gives System Runtime; Needs supporting firmware at the moment
	/****/int getSystemUptime(int &uptime);

	//-------------------------------------per NRK's suggestion-----------------------------------------------
	/****/int  setSMRADMOffset(const float offset);
	/****/int  getSMRADMOffset(float &offset);

	//-------------------------------per Metrolog and verisurf's suggestion-----------------------------------
	/****/int  getVirtualScanLinePoints(LPVOID p);
	
	

	//functions for vProbe
	//Begin scanning process if a scanner is connected
	bool StartScan(); 

	//Check if the accessory is ready for scanning
	bool ScanReady(); 

	//Stop the on-going scanning process
	bool StopScan(); 

	//Check if IP360 accessory is connected
	bool IsIprobe3() const;

	//Check if scanning is going on
	bool isScanning()const;

	//Check if the API laser tracker device's beam is locked on to Accessory or not 
	bool isBeamLockedonAcc(const REALTIME_INFO& rt);

	// Check if API laser tracker device's beam is locked on to accessory or not ( vProbe, IProbe, etc.)
	bool isBeamLockedOnAcc();

	//Start scanning using probe or v-probe 
	int  AccScan(int avg_time = 750);

	//Start single point Probe measurement
	int  AccMeasure(int avg_time = 750);		// avg_time in milliseconds

	//Start continous Probe measurement. 
	int  AccInspect();

	//Soft trigger for IProbe
	int  TriggerProbe();

	//Retrieve STS rotation matrix
	int  getSTSRotationMatrix(double* pRot);

	//Get probe rotation matrix
	int  getRotationMatrix(double* pRot);

	//Get probe transformation matrix	
	int  getTransformMatrix(double* pTransform, const APIDEVICE_MODEL mod, bool bScannerVector=true);

	//Get probe tip values. 
	int  getTipPos(D_VECTOR3 &v3, D_VECTOR3 &dev, double* pMatrix, bool&); 
	int getAveragedTipPos(D_VECTOR3 &v3, D_VECTOR3 &dev, double* pMatrix, bool&);

	//Get probe tip vector frame when you are in Probe single point data collection mode
	int  getTipVectorFrame(D_VECTOR3 &v3, D_VECTOR3 &deviation, double* pMatrix, bool&);
	int  getTipVectorFrame(D_VECTOR3 &v3, D_VECTOR3 &deviation, D_VECTOR3 &vector, double* pMatrix, bool& bNew);
	int  getAveragedTipVectorFrame(D_VECTOR3 &v3, D_VECTOR3 &dev, double* pMatrix, bool&);
	int  getAveragedTipVectorFrame(D_VECTOR3 &v3, D_VECTOR3 &deviation, D_VECTOR3 &vector, double* pMatrix, bool& bNew);

	//Get probe tip vector frame when you are NOT in IProbe single point measurement mode.
	int  getTipVectorFrameRT(double* pMatrix);

	int  getTipVector(D_VECTOR3 &vector);

	//Get the current scanned line density
	UINT getScanLineDensity();

	//Set the scan line density
	void setScanLineDensity(UINT nFilterNo);

	//Set minimum distance for continous IProbe measurement
	int  setProbingDynamicDistance(double fDistance = 0.0);

	//Get the button status of the IProbe, if it is single clicked, double held or in "hold" position
	int  getIPButtonStatus(const REALTIME_INFO& rt, API_IP_BUTTON_STATUS& bs1, API_IP_BUTTON_STATUS& bs2, API_IP_BUTTON_STATUS& bs3);
		
	//Start universal probe measurement
	int  setUniversalProbe(bool bFlag);
	
	//Display the Probe attitude angle dialog
	int  displayAttitudes();

	//Side mount Camera dialog
	int  openCameraDlg(UINT nCamerID=1);
	//IP calibration dialog. Open dialog box that helps you perform V-probe tip calibration 
	int openAccOffsetDlg();

	//Get the active IProbe stylus information
	int  getActiveProbeStylus(F_VECTOR4 &tipoffset, float &diameter, LPTSTR id, bool &isVertical, unsigned int &tipPos);
	//To start IVision dialog box
	int  openIVisionDlg(HWND p = 0);
	int  getIVisionMode(INNOVO_CAMERA_MODE &mode);

	//External triggering funciton
	int  startTTL();
	int  stopTTL();
	bool isTTLMode();
	
	//---------------------Functions not active in OT-II--------------------------------------------------------
	//Jog the STS by incremental steps
	int  StsJogBy(TARGET_JOG&);

	//Jog the STS to absolute position
	int  StsJogTo(TARGET_EXTENDED&);

	//Enable Innovo camera mode
	int  EnableCameraMode(INNOVO_CAMERA_MODE mode, F_VECTOR4 captureCriteria, 
			TCK_CAPTUREMODE dataMode = TCK_CAPTURE_STATIC_SIGMA, HWND p = 0);

	//-----------------------------------------Removed functions----------------------------------------------

	//Get the next scanned line data from scanner
	bool getNextScanLine(ScanLine* line);


	int  openIPOffsetDlg();
	
	int  IPScan( bool bWarning=false );

	int  IPMeasure( bool bWarning=false );

	int  IPInspect();

	int  ISScan( bool bWarning=false );

	bool isBeamLockedonIP(const REALTIME_INFO& rt);

	static void __cdecl CloseAttDlg(LPVOID);
	//Need not be used by for 3rd party software
	
	int  ADMAutosetOn(); 
	//Instead use : int  ADMAutoSet(bool bFlag);
	
	int  ADMAutosetOff(); 
	//Instead use : int  ADMAutoSet(bool bFlag);

	bool isAdmAutosetOn(); 
	//Instead use : int  getADMAutosetStatus(bool &bAutosetOn);
	
	int  SpiralSearch(const float fEstDis, float fEstRadius = 0.0f); 
	//Instead use :  int  TargetSearch(const float fEstDis, float fEstRadius = 0.0f);

	int  stopDynaMeasure(); 
	//Instead use stopMeasure()
	
	int  stopSigmaMeasure(); 
	//Instead use stopMeasure()

	int  stopIPMeasure(); 
	//Instead use stopMeasure()
	
	int  stopIPScan(); 
	//Instead use stopMeasure()
	
	int  stopISScan(); 
	//Instead use stopMeasure()

	int  getIProbeRotationMatrix(double* pRot);
	//Instead use: int  getRotationMatrix(double*);

	int  getIProbeTransformMatrix(double* pTrans);
	//Instead use: int  getTransformMatrix(double*, const APIDEVICE_MODEL, bool bScannerVector = true);

	int  getTipPos(D_VECTOR3 &v3, bool &bNew); 
	//Instead use: int getTipPos(D_VECTOR3 &v3, D_VECTOR3 &dev, double* pMatrix, bool&);

	int  getTipPos(D_VECTOR3 &v3, D_VECTOR3 &dev, bool &bNew); 
	//Instead use: int getTipPos(D_VECTOR3 &v3, D_VECTOR3 &dev, double* pMatrix, bool&);

	int  getIPButtonStatus(const REALTIME_INFO& rt, API_IP_BUTTON_STATUS& bs1);
	//Instead use : int  getIPButtonStatus(const REALTIME_INFO& rt, API_IP_BUTTON_STATUS& bs1, API_IP_BUTTON_STATUS& bs2, API_IP_BUTTON_STATUS& bs3);
	
	int  getHWButtonStatus(const REALTIME_INFO& rt, API_IP_BUTTON_STATUS& bs1, API_IP_BUTTON_STATUS& bs2, API_IP_BUTTON_STATUS& bs3);
	//Instead use : int  getIPButtonStatus(const REALTIME_INFO& rt, API_IP_BUTTON_STATUS& bs1, API_IP_BUTTON_STATUS& bs2, API_IP_BUTTON_STATUS& bs3);
	
	int  getSigmaMeasurement(D_VECTOR3 &result, bool &bDone, bool &bValid);
	//Instead use :  int  getSigmaMeasurement(D_VECTOR3 &result, bool &bDone, bool &bValid, double&, double&, double&);

	int  nestReading(int numPoints, int sigma, bool bWarning);
	//Instead use : int  startSigmaMeasure(const ULONG avgTime, HANDLE &hDone, const int sigma, bool bWarning=false); 

	int  getNestReading(D_VECTOR3 &v3, double &avg, double &max, double &rms, bool& bReady);
	//Instead use :  int  getSigmaMeasurement(D_VECTOR3 &result, bool &bDone, bool &bValid, double&, double&, double&);

	int  TrackerCapturingOperation( TCK_CAPTUREMODE CaptureMode, GDATCAP_TYPE *pBuffer, TCKDATAMASK mask, 
									ULONG Number_of_Points, ULONG RequiredParameter, HANDLE&);
	//Instead use : int  TrackerCapturingOperation(TCK_CAPTUREMODE CaptureMode, GDATCAP_TYPE* pBuffer, TCKDATAMASK mask,
	//						 float MinimumTriggerDistance, float VelocityBand, ULONG Number_of_Points,
	//						 ULONG AveragingNumber, clock_t WaitingDelay, HANDLE &handle); 

	int  TrackerCapturingOperation(TCK_CAPTUREMODE CaptureMode, TCKDATAMASK mask, GDATCAP_TYPE* pBuffer,
								   ULONG Number_of_Points, ULONG RequiredParameter, HANDLE&);

	//Instead use : int  TrackerCapturingOperation(TCK_CAPTUREMODE CaptureMode, GDATCAP_TYPE* pBuffer, TCKDATAMASK mask,
	//						 float MinimumTriggerDistance, float VelocityBand, ULONG Number_of_Points,
	//						 ULONG AveragingNumber, clock_t WaitingDelay, HANDLE &handle);
 
	int  TrackerCapturingOperation(TCK_CAPTUREMODE CaptureMode, GDATCAP_TYPE* pBuffer, TCKDATAMASK mask,
								    ULONG Number_of_Points, clock_t WaitingDelay, float MinimumTriggerDistance,
									float VelocityBand, ULONG AveragingNumber, HANDLE&);
	//Instead use : int  TrackerCapturingOperation(TCK_CAPTUREMODE CaptureMode, GDATCAP_TYPE* pBuffer, TCKDATAMASK mask,
	//						 float MinimumTriggerDistance, float VelocityBand, ULONG Number_of_Points,
	//						 ULONG AveragingNumber, clock_t WaitingDelay, HANDLE &handle); 
   
	int  TrackerCapturingOperation(TCK_CAPTUREMODE CaptureMode, GDATCAP_TYPE* pBuffer, TCKDATAMASK mask, 
									ULONG Number_of_Points, float RequiredParameter, HANDLE&);
	//Instead use : int  TrackerCapturingOperation(TCK_CAPTUREMODE CaptureMode, GDATCAP_TYPE* pBuffer, TCKDATAMASK mask,
	//						 float MinimumTriggerDistance, float VelocityBand, ULONG Number_of_Points,
	//						 ULONG AveragingNumber, clock_t WaitingDelay, HANDLE &handle); 
	
	int  TrackerCapturingOperation(TCK_CAPTUREMODE CaptureMode, HANDLE &hEvent);
	//Instead use : int  TrackerCapturingOperation(TCK_CAPTUREMODE CaptureMode, GDATCAP_TYPE* pBuffer, TCKDATAMASK mask,
	//						 float MinimumTriggerDistance, float VelocityBand, ULONG Number_of_Points,
	//						 ULONG AveragingNumber, clock_t WaitingDelay, HANDLE &handle); 

    int  TrackerStopDataCollection(); 
	//Instead use: int stopMeasure();

	bool isButtonDownIP(const REALTIME_INFO& rt);
	//Instead use : int  getIPButtonStatus(const REALTIME_INFO& rt, API_IP_BUTTON_STATUS& bs1,
	//										API_IP_BUTTON_STATUS& bs2, API_IP_BUTTON_STATUS& bs3);

	int  skipABCalibration(bool bSkip);
	int  AdmBirdbathCalibSwitch( const bool switchOn);
	int  updateAdmUserParam(float* param);
	int  getThermalCompStage(int &iStage);
	int  ADMVelComp(const bool bCompOn);
	int  call_InitADM();
	int  setADMCalibFlag(bool bFlag);
	int  getABCOffset(float &f);
	int  getAdmUserParam(float* param);
	int  getADMDistParam(float *param);
	int  updateADMDistParam(float *param);
	bool AdmBBCalibration(bool&, bool, float&, int&, const int = 0);
	void setADMCalibrationSwitch(const bool bADMCalibSwitch);
	int  AdmFlyDisable(int iDisableMode = 3);
	int  AdmFlyPurge();

	bool isHoldPosOn();
	int  startProbeScanFilter();
	int  stopProbeScanFilter();
	int  getSize();
	int  updateBirdBathCalib(const float f, const int homeIdx);
	int  updateBirdBathCalibTemp(const float f, const int homeIdx);
	int  startQVC(int mode);
	int  getQVCStatus(int &CurPos, bool &bInPos, bool &b2FaceDone);
	int  QVCPick();
	int  getQVCTolerance( float *p ) const;
	int  getQVCResult(float *pResult, float *pRepeatability);
	int  updateOnePointQVC(const float *p);
	int  updateQVC(const float *p);
	int  uploadPRMFile();
	int  parsePRMFile();
	int  HoldPosSwitch(bool);
	int  pauseMeasure(); 
	int  startExternalTrigger(const ULONG avgTime, HANDLE &hMeasureDone, const int sigma);
	bool getNextIScanData(IScanData* iscandata);
	bool getNextIScanData(IScanData& iscandata);
	int  getRTDataInternal(REALTIME_INFO_INTERNAL &rtInfoInternal);
	int  SwitchToTckTune();
	int  setIPMeasPoints(unsigned int uiPts);

	//IScan calibration dialog
	int  openISCalibDlg();
	int  calIPTipOffset();
    int  openIPGlbDlg(); 
	int openProbeWirelessStrengthDialog(HWND P = 0);

private:
	S_SIXDTRACKER*		m_pTck;
    CDataSampler*		m_pDatSampler;
    CTaskManager*		m_pTaskMan;
	CDataCollection*	m_pDatCollection;
	CAttAngle*			m_pAttDialog;

    CFTPManager*		m_pFtp;
	CPrmManager*		m_pPrmMan;
    CTLedMan*			m_pledMan;
    CIPLed*				m_pIPLed;
    CApiIP*				m_pIPMod;
    CSts*				m_pSts;
	IScanClient*		m_pIScanClient;
	IvisionDlg*			m_pIVisionDlg;
	
	
	LPVOID				m_pCallBackParam;
	TCHAR*				m_pszDLLDirectory;

	HANDLE				m_hTrackerEvent;
	HANDLE				m_hDoneEvent;
	HANDLE				m_hConMonitor;
	HANDLE				m_hConnFail;
	HANDLE				m_hConnDone;
        
    // device status
	APIDEVICE_MODEL		m_iDevModel;
	TRACKER_ADM_TYPE	m_iDeviceType;
   

	bool	m_bConnecting;
    bool	m_bHasIProbe;
    bool	m_bHasSTS;
	bool	m_bHasIScanner;
    bool	m_bTrackerInited;    
	bool    m_bIdxFlag;
	bool	m_bADMLinCalibrationSwitch; 

	int		m_iConnectErr;
	int		m_currentSMR; 

	float	m_fADMCutoffIntensity;
	float	m_fADMLinearA[3];	
	float	m_fADMLinearB;
	float	m_fADMUserParams[4];	

	BYTE		m_nAddr[6];
    TCHAR		m_sTckPrm[MAXLENGTH_PATH];
	TCHAR		m_sCamPrm[MAXLENGTH_PATH];
	TCHAR		m_sPrmPath[MAXLENGTH_PATH];
	TCHAR		m_sIP[MAXLENGTH_PATH];
	DWORD   	m_DevSN;
	DWORD		m_AccSN;
    DWORD  		m_dwWorkMode;
	HMODULE		m_hTcpIp;
	CRITICAL_SECTION	m_cs;
	
	unsigned long		m_ulIP[MAX_CONNECTION];
	bool m_bUseSIUnit;
	CProbeWirelessStrength* m_pProbeWirelessStrengthIndicator;

	void ConnDone();
	void ConnFail(int);
	void abortMeasureTask();
	void (*m_pCallBackFn)(LPVOID, LPVOID);

	bool IP2Char3(LPTSTR sIn, BYTE *pChar);
	bool GetDevType(LPTSTR pszIP, DWORD &dwWorkMode);
    
	int  InitTracker();
    int  InitADM();
    int  InitLevel();
    int  InitEncoder();
    int  InitPhotoSensor();
    int  InitIProbe(LPCTSTR sPath, DWORD sn);
    int  InitSTS(LPCTSTR sPath, DWORD sn);
	int  Initialization(LPTSTR pszPRMFolder, int nDev, LPTSTR lpszIP=NULL);
   
	static UINT ConMonitor(LPVOID);
	
	friend class CTaskManager;
	friend class CDevController;

};
}
#endif // !defined _APIDEVICE_H_
