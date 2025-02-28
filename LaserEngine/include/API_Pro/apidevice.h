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
#if !defined _APIDEVICE_H_
#define _APIDEVICE_H_

#ifdef _APIDEVICE_DLL_
#define APIDEVICE_API __declspec(dllexport)
#else
#define APIDEVICE_API __declspec(dllimport)
#endif

#include "APIGeneric.h"
#include <time.h>
#include <vector>
using namespace std;

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
class CTrackerCamera;
class IvisionDlg;

struct IScanData;
struct ScanLine;

class APIDEVICE_API CAPIDevice
{
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
	CTrackerCamera*		m_pCameraOne;
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

private:
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

public:
	/*1*/CAPIDevice();
	/*2*/virtual ~CAPIDevice();
	/*3*/void SetDIDllDirectory(LPCTSTR pszDLLPath=NULL);
	/*4*/void Destroy();   
	/*5*/int  autoDetect(double dTime, void (*pTaskCallBk)(LPVOID, LPVOID), LPVOID p = NULL);
	/*6*/int  Connect(LPTSTR  sPath, int nDev, void (*pTaskCallBk)(LPVOID, LPVOID), LPVOID = NULL, LPTSTR lpszIP=NULL);
	
	//To check if the API is connected 
	/*7*/bool IsConnected();
	
	//Disconnect API
	/*8*/int  DisConnect();
	
	//Bring the API to birdbath position.
	/*9*/int  Home(int nIdx=0);
	
	//Search for the target in spiral motion within estimated distance and radius
	/*10*/int  TargetSearch(const float fEstDis, float fEstRadius = 0.0f, float fTimeOut = 40.0f);

	//Jog/position the API to certain location in incremental step
	/*11*/int  JogBy(TARGET_JOG&);

	//Jog/position the API to absolute position
	/*12*/int  JogTo(TARGET_EXTENDED&);

	//Jog the STS by incremental steps
	/*13*/int  StsJogBy(TARGET_JOG&);
	
	//Jog the STS to absolute position
    /*14*/int  StsJogTo(TARGET_EXTENDED&);
	
	//Point API to certain position	
    /*15*/int  PointTo(TARGET_Cartesian& tg);
	
	//Drive the tracker to a remote position and make that a new home position
    /*16*/int  RemoteHome(const RESET_CARTESIAN&);
	
	//Search for any accessory that are connected to API
	/*17*/int  AccSearch();
	

	//Identify the proper level.
	/*18*/int  VirtualLevel(bool applyCalculatedVLFrame = true);
	
	//Apply the level compensation based on the virtual level routine
	/*19*/int  applyVirtualLevel(bool bEnableVL, bool bAbsoluteMode=true, double *fixedRxyz=NULL);
	
	//Get the existing level frame
	/*20*/int  getT3VirtualLevelFrame(double *pT3LevelFrame, double *calcVLFrame, double *fixedRxyz);
	
	//Get the existing level offset
	/*21*/int  getVirtualLevelOffset(double *virtualLvlOffset);
	
	//-----------------------------------------adm realted calibration-----------------------------------------
	//Reset IFM distance based on ADM distance value
	/*22*/int  ADMReset();
	
	//Check the status of suto ADM setting
	/*23*/int  getADMAutosetStatus(bool &bAutosetOn);
	
	//Get current home position
	/*24*/int  getHomePosition(POLAR_REF&, const int = 0);
	
	//Set/reset ADM auto setting.
	/*25*/int  ADMAutoSet(bool bFlag);
	
	//To know if ADM module is available or if ADM beam is available
	/*26*/int  isADMAvailable(bool &bAvailable);
	
	//To know if IFM beam is available
	/*27*/int  isIFMAvailable(bool &bAvailable);
	
	//To know if level sensor is present
	/*28*/int  isLevelSensorAvailable(bool &bAvailable);
	
	//To know if humidity sensor is present
	/*29*/int  isHumiditySensorAvailable(bool &bAvailable);
	
	//Abort any on-going task
	/*30*/int  AbortTask();
	
	//Get the current task information
	/*31*/int  getCurrentTask();
	
	//Check if the on-going task is successful or not
	/*32*/bool IsTaskSuccessful(int &nRetCode, bool&);
	
	//Check the status of the on-going task
	/*33*/int  getTaskStatus(int &nCur, int &nTotal);

	//Set the environmental variables to certain number, usually used when the weather station is not connected or 
	//when you want to override the real time weather station reading.
	/*34*/int  setEnvironment(float fAirPressure, float fAirTemperature, float fHumidity, bool bUseSensorReading,
							DWORD dwUpdateRate = 5000) const;

	//Drive the API to/from frontsight/backsight position to take a measurement
	/*35*/int  BKSightOperation();

	//Perform fronsight backsight check to verify the deviation is well within tolerance.
    /*36*/int  BKSightChecking();

	//Get the fron/back sight checking result
	/*37*/int  getBKCheckingResult(D_VECTOR4 &dv4, D_VECTOR2 &dv2, bool &chkPass);

	//Get the API unit info
	/*38*/int  setModel(APIDEVICE_MODEL nMod);
    /*39*/int  getModel(APIDEVICE_MODEL &nMod);

	//Get real time data from API device
	/*40*/int  getRTData(REALTIME_INFO &);
	
	//ON, OFF, BLINKING, ADMFLY //set the API device LED status as per requirement
	/*41*/int  setLEDState(unsigned int ls);

	//-----------------------------------------motor control-----------------------------------------
	//Drive the API device to idle mode. You cannot do any measurement/operation when the device is in idle mode
	/*42*/int  SwitchToIdle();

	//Put the API device to position mode if you wish to jog it.
    /*43*/int  SwitchToPosition();

	//Put the API device to tracking mode
    /*44*/int  SwitchToTrack();
	
	//Perform index search and let the API device align itself to birdbath position. 
	/*45*/int  IndexSearch();
   
	//Put the API device in power disabled mode if you dont intend to use it for a while, but dont want to turn it off either.
	/*46*/int  PowerDisable();

	//Bring back the device to power enabled mode.
	/*47*/int  PowerEnable();

	//Start Innovo camera mode
	/*48-a*/int  EnableCameraMode(bool bFlag);
    /*48-b*/int  EnableCameraMode(INNOVO_CAMERA_MODE mode, F_VECTOR4 captureCriteria, TCK_CAPTUREMODE dataMode = TCK_CAPTURE_STATIC_SIGMA, HWND p = 0, LPVOID pp = NULL);
       
    //-----------------------------------------Tracker measure mode-----------------------------------------
	//Stop any on-going measurement
    /*49*/int  stopMeasure();
	
	//Used for starting single point measurement
	/*50*/int  startSigmaMeasure(const ULONG avgTime, HANDLE &hDone, const int sigma, bool bWarning=false);
																									
	//Used for getting single point measurement value
    /*51-a*/int  getSigmaMeasurement(D_VECTOR3 &result, bool &bDone, bool &bValid, double &average, double &max, double &rms);

	// Used for getting single point measurement and STS rotation angles if STS is connected
	/*51-b*/int  getSigmaMeasurement(D_VECTOR3 &result, bool &bDone, bool &bValid, double &average, double &max, double &rms, 
										D_VECTOR3 &stsRotationAngles, bool &bIsAccData);

	 //Start distance based measurement
    /*52*/int  startDynaDisMeasure(const float fDis, bool bWarning=false);

	//Start time based measurement
    /*53*/int  startDynaTempMeasure(const int iPeriod, bool bWarning=false); 

	//Start time based rate filetered measurement
    /*54*/int  startRateFilterMeasure(const int iPeriod, bool bWarning=false);

	//Retrieve time based rate filtered measurement
    /*55*/bool getRateFilterMeasurement(D_VECTOR4 &dv4);

	//Retrieve measurement result which was started using either startDynaDisMeasure or startDynaTempMeasure
	/*56*/bool getMeasurement(D_VECTOR4 &dv4);

	//Trigger the device to take a measurement. generally while using a SMR
	/*57*/int  TrackerCommandTrigger();

	//For TCK_CAPTURE_EVENT_ONLY(TTL mode) data collection 
	/*58*/int  TrackerCapturingOperation(TCK_CAPTUREMODE CaptureMode, GDATCAP_TYPE* pBuffer, TCKDATAMASK mask,float fParam1,
							  float fParam2, ULONG uParam1, ULONG uParam2, clock_t WaitingDelay, HANDLE &handle);

	//To keep track of tracker FIFO data
	/*59*/int  TrackerFIFOinformation(FIFO_INFO &FF_Info);

	//-----------------------------------------Scanning/Probing funcs----------------------------------------- 
	//Begin scanning process if a scanner is connected
    /*60*/bool StartScan(); 

	//Check if the accessory is ready for scanning
	/*61*/bool ScanReady(); 

	//Stop the on-going scanning process
	/*62*/bool StopScan(); 

	//Check if accessory (IProbe/vProbe) accessory is connected
	/*63*/bool IsIprobe3() const;

	//Check if scanning is going on
    /*64*/bool isScanning()const;

	//Check if the API laser tracker device's beam is locked on to IProbe or not 
	/*65*/bool isBeamLockedonAcc(const REALTIME_INFO& rt);

	// Check if API laser tracker device's beam is locked on to accessory or not (STS, vProbe, IProbe, etc.)
	/*65-b*/ bool isBeamLockedOnAcc();

	//Get the next scanned line data from scanner
	/*66*/bool getNextScanLine(ScanLine* line);

	//Start scanning using an IScanner
	/*67*/int  ISScan( bool bWarning=false );

	//Start scanning using accessory (IProbe/vProbe). 
	/*68*/int  AccScan( bool bWarning=false );

	//Start single point accessory (IProbe/vProbe) measurement
	/*69*/int  AccMeasure( bool bWarning=false );

	//Start continous accessory (IProbe/vProbe) measurement. 
	/*70*/int  AccInspect();

	//Soft trigger for accessory (IProbe/vProbe). 
	/*71*/int  TriggerProbe();

	//-----------------------------------------probe/Scanner measruements-------------------------------------
	//Retrieve STS rotation matrix
	/*72*/int  getSTSRotationMatrix(double*);

	//Get accessory (IProbe/vProbe) rotation matrix
	/*73*/int  getRotationMatrix(double*);

	//Get accessory (IProbe/vProbe) transformation matrix	
	/*74*/int  getTransformMatrix(double*, const APIDEVICE_MODEL, bool bScannerVector = true);

	//Get accessory (IProbe/vProbe) tip values. 
	/*75-a*/int  getTipPos(D_VECTOR3 &v3, D_VECTOR3 &dev, double* pMatrix, bool&); 
	/*75-b*/int getAveragedTipPos(D_VECTOR3 &v3, D_VECTOR3 &dev, double* pMatrix, bool&);
	
	//Get accessory (IProbe/vProbe) tip vector frame when you are in single point data collection mode
	/*76-a*/int  getTipVectorFrame(D_VECTOR3 &v3, D_VECTOR3 &dev, double* pMatrix, bool&);
	/*76-b*/int getTipVectorFrame(D_VECTOR3 &v3, D_VECTOR3 &deviation, D_VECTOR3 &vector, double* pMatrix, bool& bNew);
	/*76-c*/int  getAveragedTipVectorFrame(D_VECTOR3 &v3, D_VECTOR3 &dev, double* pMatrix, bool&);
	/*76-d*/int getAveragedTipVectorFrame(D_VECTOR3 &v3, D_VECTOR3 &deviation, D_VECTOR3 &vector, double* pMatrix, bool& bNew);

	//Get accessory (IProbe/vProbe) tip vector frame when you are NOT single point measurement mode.
	/*78*/int  getTipVectorFrameRT(double* pMatrix);

	/*79*/int  getTipVector(D_VECTOR3 &vector);

	//Get the current scanned line density
	/*80*/UINT getScanLineDensity();

	//Set the scan line density
	/*81*/void setScanLineDensity(UINT nFilterNo);

	//Set minimum distance for continous accessory (IProbe/vProbe) measurement
	/*82*/int  setProbingDynamicDistance(double fDistance = 0.0);
	
	//Get the button status of the accessory (IProbe/vProbe), if it is single clicked, double held or in "hold" position
	/*83*/int  getIPButtonStatus(const REALTIME_INFO& rt, API_IP_BUTTON_STATUS& bs1, API_IP_BUTTON_STATUS& bs2, API_IP_BUTTON_STATUS& bs3);

	//-----------------------------------------For system information-----------------------------------------
	//Get the IP address of the API device
	/*84*/int  getTrackerIP(BYTE* pbIPAddress);

	//Check the API device firmware version
	/*85-a*/int  getFirmwareVersion(LPTSTR);
	/*85-b*/int  getFirmwareVersion(DWORD &majRev, DWORD &minRev);

	//API device's owner information
	/*86*/int  getLicenseOwner(LPTSTR);

	//Device interface version 
	/*87*/int  getDIVersion(LPTSTR);

	//API device ID
	/*88*/int  getTrackerID(int&);

	//ID of any accessory that is connected to API Device
	/*89*/int  getAccID(int&);

	//Get the API device type, if it is only ADM unit or has both ADM and IFM modules
	/*90*/int  getTrackerType(LPTSTR trackerTypeStr, TRACKER_TYPE &type);

	//Get the type of the accessory
	/*91*/int  getAccType(LPTSTR);

	//Get the device interface release date(SDK release date)
	/*92*/int  getDIReleaseDate(LPTSTR pReleaseDate);

	//Get device identification string
	/*93*/int  getDeviceString(LPTSTR pDevString);

	//Accessory serial number	
	/*94*/int  getAccSerialNumber(int &sn);

	//Get the error code and message. A message box will not pop up giving the error message
	/*95*/bool getAPIErrorMessage(LPTSTR,const int errorCode);

	//To display the error message.
	/*96*/void DisplayAPIErrorMessage(const int errorCode);
		
	//-----------------------------------------IP/Camera calibration------------------------------------------
	//Display the accessory (IProbe/vProbe) attitude angle dialog
    /*97*/int  displayAttitudes();

	//Side mount Camera dialog
	/*98*/int  openCameraDlg(UINT nCamerID=1);

	//Accessory (IProbe/vProbe) calibration dialog
	//Open dialog box that helps you perform accessory (IProbe/VProbe) tip calibration 
	/*99*/int openAccOffsetDlg();

	//Get the active accessory (IProbe/vProbe) stylus information
	/*100-a*/int  getActiveProbeStylus(F_VECTOR4 &tipoffset, float &diameter, LPTSTR id, bool &isVertical);
	/*100-b*/int  getActiveProbeStylus(F_VECTOR4 &tipoffset, float &diameter, LPTSTR id, bool &isVertical, unsigned int &tipPos);

	//To start IVision dialog box
	//Open and close dialog box that helps you use Innovo Camera features
	/*101-a*/int  openIVisionDlg(HWND p = 0);
	/*101-b*/int  closeIVisionDlg(HWND p = 0);
	/*102*/int  getIVisionMode(INNOVO_CAMERA_MODE &mode);
	/*103*/int  getDataCaptureMode(TCK_CAPTUREMODE &mode); 

	//-------------------------------------per NRK's suggestion-----------------------------------------------
	/*104*/int  setSMRADMOffset(const float offset);
	/*105*/int  getSMRADMOffset(float &offset);
	/*106*/int  startTTL();
	/*107*/int  stopTTL();
	/*108*/bool isTTLMode();

	//-------------------------------per Metrolog and verisurf's suggestion-----------------------------------
	/*109*/int  getVirtualScanLinePoints(LPVOID p);
	//--------------------------------------------------------------------------------------------------------

	//To get API Laser Tracker operation time, starting from the time it was built in API facility.
	/*110*/int getSystemUptime(int &uptime);

	// To start/stop IVision video streaming 
	/*111*/int StartStreaming(HWND hWnd);
	/*112*/int StopStreaming();

	/*113*/	int GetNumberOfLines() ;


	/*114*/ int startSTSDynamicMeasurement();

	/*115*/ int getSTSDynamicMeasurement(D_VECTOR8&);
	//-----------------------------------------Internally used functions----------------------------------------------

	int  updateBirdBathCalib(const float f, const int homeIdx);
	int  updateBirdBathCalibTemp(const float f, const int homeIdx);
	static void __cdecl CloseAttDlg(LPVOID);
	//Cannot be used by 3rd party software yet
	int  getRTDataInternal(REALTIME_INFO_INTERNAL &rtInfoInternal);
};
#endif // !defined _APIDEVICE_H_
