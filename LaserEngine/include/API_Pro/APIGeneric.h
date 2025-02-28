//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2013	Automated Precision, Inc.
// Module Name:
// APIGeneric.h
// Abstract:
//	This module defines the general data stuctures and constants which will be used for API trackers interface
// Author:
// Revision History:
//	V1.00.0000, 2006/12/####

//      V1.6.5.1250     11/13/2009      Caijing
//      1. ADD: Struct for internal data.

//      V1.6.5.1300     02/09/2010      Cai Jing
//      1. Add timestamp and IFM distance into internal struct

//		Not yet versioned 11/23/2010	Sindhu Shankar
//		1. Add APIDEVICE_WIRELESS_LOOPBACK and APIDEVICE_DISABLE_WIRELESS_LOOPBACK in APIDEVICE_TASK list.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _APIGeneric_
#define _APIGeneric_

#include <windows.h>
#define MONITOR_THREADS
// Parameter file
#define PrmFileMark_OldLevel						_T(":::")
#define PrmFileMark_NewLevel						_T("---")
#define TrackerApiObjectName						_T("NG-Tracker")
#define trackerId									2000
#define	DegreeToRadian(degree)						(0.01745329251994 * (degree))
#define	RadianToDegree(radian)						(57.29577951308 * (radian))
#define Radian90									1.570796326795
#define PhiX2										6.28318530717958647692528676655901
#define Null_Handle									(HANDLE)0xfffe
#define nearzero									1.0e-20
#define nearinfinity								1.0e12
// added below to fix redefinition error of No,Yes and PI in RMS software - chd 12182017
#ifndef No
	#define No											0
#endif
#ifndef Yes
	#define Yes											1
#endif
#define Fail										2
#define Inter										3
#define	PacketHeader								0x80
#define	PacketFooter								0x81
#define CRITICALANGLE								0.002						// change to 0.001 for testing, need change to 0.002 for real
#define	MINADMINTENSITY								0.15						// the lowest adm intensity
#define	WARNADMINTENSITY							0.15						// the warning range adm intensity
#define ADMREFCRITERIA1								0.25						// in case of wrong prm file
#define ADMREFCRITERIA2								0.10						// in case of wrong prm file
#define ADMWARMUPRATE								0.03
#define ADMWARMUPTIME								1.0
#define SEARCHTIMEOUT								4000L
#define	MAXLENGTH_PATH								255
#define JOG_TIMEOUT									10000L
#ifndef PI
	#define PI											3.1415926
#endif
#define ARCSecToRadian								1.0/3600/180*PI
#define	No_of_SysParams								135
#define Number_of_Factors							24
#define MAX_SERIAL_ID								99999
#define MAX_CONNECTION								100

#define	ABCDATANUM									50						// average number in ABC procedure
#define	ABCFILTERBAND								5						// 10 percent filter band

typedef int (*CMPFUN)(int, int);
#define uint32 unsigned int
#define INSERTION_SORT_BOUND						16						// boundary point to use insertion sort 
#define	LEVELPOINT									1000		
#define	LEVELWAIT									10000					// time for tracker to be stable, ms, 
#define MatrixSize									3
#define	zeroangle									1.0e-12
#define DEFAULT_VELCRI								5.0						// mm/s
#define ABSLASER_SCALE_FACTOR						(double) 316.49525e-6	// dualmode laser wavelength / 2.0
#define LEVEL_SHIFT									35						// delay from pitch
#define IPARRAYSIZE									1000					// array size to hold the raw data
#define PHOTOINT_AZ									28000
#define PHOTOINT_EL									28000

#define DYNBUFMAXSIZE								15000					// For the filter data buffer

#define MAXHOLDPOSITIONTIME							5000

#define UNIVERSALPROBE								111
#define INITTLCOUNTER								-1			
#define DEFAULT_JOG_TIMEOUT							10000
#define API_AVERAGE_TIME							2000					// 2 seconds
#define SWITCHPAIRS							        6
#define	SAMPLES_PER_SWITCH_COUNT					24
#define OPTICAL_SWITCHPAIR_MODE						4
#pragma pack(push, 8)

const float STS_GYRO_SAMPLING_RATE = 80.0f;
const float STS_GYRO_SENSITIVITY = 524.0f;


// for dual channels of data
typedef struct D_VECTOR2 {
	double x;
	double y;
} DVECTOR2, *LPDVECTOR2, *LPD_VECTOR2;

typedef struct F_VECTOR2 {
	float x;
	float y;
} FVECTOR2, *LPFVECTOR2, *LPF_VECTOR2;

typedef struct I_VECTOR2 {
	int x;
	int y;
} IVECTOR2, *LPIVECTOR2, *LPI_VECTOR2;

typedef struct DUAL_LEVEL {
	float level_x;
	float level_y;
} *LPDUAL_LEVEL;

// for quad channels of data
typedef struct D_VECTOR4 {
	double x;
	double y;
	double z;
	double w;
} DVECTOR4, *LPDVECTOR4, *LPD_VECTOR4;

typedef struct F_VECTOR4 {
	float x;
	float y;
	float z;
	float w;
} FVECTOR4, *LPFVECTOR4, *LPF_VECTOR4;

struct ENC_VECTOR {
	BYTE ElR1Sine;
	BYTE ElR1Cos;
	BYTE ElR2Sine;
	BYTE ElR2Cos;

	BYTE AzR1Sine;
	BYTE AzR1Cos;
	BYTE AzR2Sine;
	BYTE AzR2Cos;
	
	float ELDiff;
	float AZDiff;
};

typedef struct I_VECTOR4 {
	int x;
	int y;
	int z;
	int w;
} IVECTOR4, *LPIVECTOR4, *LPI_VECTOR4;

typedef struct F_PHOTO4 {
	float Intensity_x;
	float Intensity_y;
	float Distance_x;
	float Distance_y;
} *LPF_PHOTO4;

// for triple channels data
typedef struct D_VECTOR3{
	double x;
	double y;
	double z;
} *LPD_VECTOR3, DVECTOR3;

typedef struct F_VECTOR3{
	float x;
	float y;
	float z;
} *LPF_VECTOR3, FVECTOR3;

typedef struct I_VECTOR3{
	int x;
	int y;
	int z;
} *LPI_VECTOR3, IVECTOR3;

//	Define the structure for 6D dynamic information
struct	D_VECTOR8
{
	double	x;
	double	y;
	double	z;
	double	a;
	double	b;
	double	c;
	DWORD	TCKTS;		// tracker timestamp
	DWORD	IPTS;		// IProbe timestamp
};

struct	D_VECTOR10
{
	double	x;
	double	y;
	double	z;
	double	a;
	double	b;
	double	c;
	double  roll;						// encoder roll IP3
	double  yaw;						// encoder yaw IP3
	DWORD	TCKTS;						// tracker timestamp
	DWORD	IPTS;						// IProbe timestamp
	int     matched;	
};

struct	D_VECTOR11
{
	double	x;
	double	y;
	double	z;
	double	a;
	double	b;
	double	c;
	double  roll;								// encoder roll IP3
	double  yaw;								// encoder yaw IP3
	DWORD	TCKTS;								// tracker timestamp
	DWORD	IPTS;								// IProbe timestamp
    int     matched;	
    unsigned short  FrameCounter;				// Camera Frame Counter
};

struct D_VECTOR16
{
	double	x;
	double	y;
	double	z;
	double	a;
	double	b;
	double	c;
	double  roll;								// encoder roll IP3
	double  yaw;								// encoder yaw IP3
	DWORD	TCKTS;								// tracker timestamp
	DWORD	IPTS;								// IProbe timestamp
	int     matched;
	double  Laccx ;								// acceleration estimated , xyz is defined in the local roll pendulum cage coordinate system
	double  Laccy ;
	double  Laccz ; 
    double  LatchPitch;
	double  LatchYaw;							// reserved field 
    unsigned short  FrameCounter;				// Camera Frame Counter
};

typedef struct F_PHOTO3 {
	float Intensity;
	float Distance_x;
	float Distance_y;
} *LPF_PHOTO3;

typedef struct THIRDORDERFACTOR {
	float a0;
	float a1;
	float a2;
	float a3;
} *LP3RDORDERFACTOR;

// Jogging Operation
typedef struct TARGET_JOG{
	bool	JogMode;			// true:Absolute Jogging, false:Incremental Jogging
	float	Azimuth;			// Azimuth Jogging Target
	float	Elevation;			// Elevation Jogging Target
	bool	InPosition;			// true:Check the in-positioning, false:Fly on the jog operation
} *LPTARGET_JOG;

typedef struct TARGET_EXTENDED{
	bool    JogMode;
	bool	InPosition;			// true:Check the in-positioning, false:Fly on the jog operation
	float	Azimuth;			// Azimuth Jogging Target
	float	Elevation;			// Elevation Jogging Target
	bool    ApplyOffset;
	bool	UseCompensated;
} *LPTARGET_EXTENDED;

typedef struct TARGET_EX{
	bool	JogMode;			// true:Absolute Jogging, false:Incremental Jogging
	bool	InPosition;
	float	Azimuth;			// Azimuth Jogging Target
	float	Elevation;			// Elevation Jogging Target
	float	tg_AZ;				// STS Az
	float	tg_EL;				// STS El
} *LPTARGET_EX;

typedef struct TARGET_CARTESIAN{
	bool	InPosition;	
	float	x;					// coordinate x
	float	y;					// coordinate y
	float	z;					// coordinate z
	float	tg_AZ;				// STS Az
	float	tg_EL;				// STS El
} *LPTARGET_CARTESIAN;

typedef struct TARGET_POLAR{
	bool	InPosition;
	float	Azimuth;			// Azimuth Jogging Target
	float	Elevation;			// Elevation Jogging Target
	float	Distance;			// Distance
	float	tg_AZ;				// STS Az
	float	tg_EL;				// STS El
} *LPTARGET_POLAR;

typedef struct JOGNSEARCH{
	bool	JogMode;			// true:Absolute Jogging, false:Incremental Jogging
	bool	InPosition;			// true:Check the in-positioning, false:Fly on the jog operation
	float	Azimuth;			// Azimuth Jogging Target
	float	Elevation;			// Elevation Jogging Target
	float	EstDistance;		// Estimated distance
	bool	m_Lockon;			// false, jog only; true, jog & search.
} *LPJOGNSEARCH;

// Reset Operation
typedef struct RESET_ANGULAR{
	float	Reset_Laser_Distance;					//	If the tracker mode is not in the Tracking Mode, the Laser Distance is 0.
	float	Reset_Position_AZ;						//	Azimuth in Degree
	float	Reset_Position_EL;						//	Elevation in Degree
	bool	TrueIFM;								//	Record the current TrueIFM flag
	int		nCoordinate;							//	0, Cartesian; 1, Polar
} *LPRESET_ANGULAR, ANGULAR_DATA;

typedef struct RESET_CARTESIAN{
	float	Reset_Position_X;						//	X in mm
	float	Reset_Position_Y;						//	Y in mm
	float	Reset_Position_Z;						//	Z in mm
	float	Reset_Position_AZ;						//	Azimuth in Degree
	float	Reset_Position_EL;						//	Elevation in Degree
	bool	TrueIFM;								//	Record the current TrueIFM flag
	int		nCoordinate;							//	0, Cartesian; 1, Polar
} *LPRESET_CARTESIAN, CARTESIAN_DATA;

typedef struct CARTESIAN_REF{
	float x;
	float y;
	float z;
} *LPCARTESIAN_REF;

typedef struct POLAR_REF {
	float azimuth;
	float elevation;
	float distance;
} *LPPOLAR_REF;

// sixd informaion
typedef struct NORMAL_VECTOR {
	float I;
	float J;
	float K;
} *LPNORMAL_VECTOR;

typedef struct ATTITUDE_ANGLE {
	float pitch;
	float yaw;
	float roll;
} *LPATTUTUDE_ANGLE;

typedef struct {
	bool	InPosition;	
	float	x;		// coordinate x
	float	y;		// coordinate y
	float	z;		// coordinate z
} TARGET_Cartesian;

typedef struct {
	bool	InPosition;
	float	Azimuth;			// Azimuth Jogging Target
	float	Elevation;			// Elevation Jogging Target
	float	Distance;			// Distance
} TARGET_Polar;


enum	LEDSTATE{
	GREENLIGHT_ON = 0,
	GREENLIGHT_BLINKING,
	RED_ON,
	RED_BLINKING
};

enum LEDSTATE2 {
};

enum API_IP_BUTTON_STATUS {
	BUTTON_UNDEFINED = -1,
	BUTTON_UP = 0,
	BUTTON_DOWN = 1,
	BUTTON_DCLICKED = 2,
	BUTTON_HOLDING = 3
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Name : ADM_RAWINFO
// Description:
//	arSize:	Specifies the number of bytes required by the structure.
//	arIntensity: ADM intensity,  in bits
//  arTemperature1: ADM temperature 1, diagnosis purpose, in bits
//  arTemperature2: ADM temperature 2, diagnosis purpose, in bits
//  arTubeIntensity: tube intensity, in bits
//  arTubeTemperature: tube temperature, diagnosis purpose, in bits
//  arDistance:	ADM distance, in mm
/////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADM_RAWINFO {
	DWORD	arSize;
	float	arIntensity;
	float	arTemperature1;
	float	arTemperature2;
	float	arTubeIntensity;
	float	arTubeTemperature;
	float	arDistance;
	DWORD	arTimeStamp;
	float	arThermalRate;
}*LPADM_RAWINFO;

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Name : ADM_INFO
// Description:
//	aiSize:	Specifies the number of bytes required by the structure.
//	aiRawInfo: ADM_RAWINFO structure
//  aiIntensityLow: ADM intensity low flag
//  aiNoReading: ADM no reading flag.
//  aiHWFail:	ADM hardware failure flag.
/////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADM_INFO {
	DWORD		aiSize;
	ADM_RAWINFO aiRawInfo;
	bool		aiIntensityLow;			// warning flag. true: adm intensity too low ( < 0.15); false: adm intensity ok.
	bool		aiNoReading;			// adm intensity too low, can't be used
	bool		aiHWFail;				// adm hardware failure flag
}*LPADM_INFO;

typedef struct TRACKER_STATUS {
	bool Warm_Up_Time;				//	true:System Warming-Up; false:System is ready.
	bool Laser_Path_Error;			//	true:Laser Beam-Path Error; false:Laser Beam-Path is O.K.
	bool Laser_Dist_Error;			//	true:Laser Distance Status Error; false:Distance Status is O.K.
	bool External_Switch;			//	true:External Switch Contact; false:External Switch Open
	bool Filtering_Switch;			//	true:Filtering Switch On; false:Filtering Switch Off
	bool AZ_OverSpeed;
	bool EL_OverSpeed;
	bool AZ_EncError;
	bool EL_EncError;
} *LPTRACKER_STATUS;

typedef struct WEATHERSTATION_INFO {
	float Air_Temperature;
	float Air_Pressure;
	float Material_Temperature[3];
	float Air_Humidity;
} WS_INFO, *LPWS_INFO;

// operation mode
enum OPERATION_MODE {
	OP_Idle = 0,							// idle
	OP_Position,							// position
	OP_Track,								// tracking
	OP_TIdle,								// track_idle
	OP_IndexSearch = 5,						// index search
	OP_SpiralSearch = 7,					// spiral search
	OP_CameraSearch = 9						// innovo camera search mode 
};

//Possible HD board settings for laser
struct HDPARAMS {
	float AQBOffX,
	AQBOffY,
	PathErrHi,
	PathErrLo;
};

enum ENCODER_MODE {
	Enc_Cal_Off = 14,
	Enc_Cal_click1 = 10,
	Enc_Cal_hold1 = 11,
	Enc_Cal_click2 = 12,
	Enc_Cal_hold2 = 13,
	Enc_Dual = 9,
	Enc_Single = 5,
	Enc_Off = 8,
	Enc_Reset = 1,

	//Only AZ
	AZ_Enc_Cal_Off = 19,
	AZ_Enc_Cal_click1 = 15,
	AZ_Enc_Cal_hold1 = 16,
	AZ_Enc_Cal_click2 = 17,
	AZ_Enc_Cal_hold2 = 18,
	
	//Only EL
	EL_Enc_Cal_Off = 24,
	EL_Enc_Cal_click1 = 20,
	EL_Enc_Cal_hold1 = 21,
	EL_Enc_Cal_click2 = 22,
	EL_Enc_Cal_hold2 = 23

};
enum API_ACCESSORY {
	API_NONE = 0,
	API_STS,
	API_IPROBE
};

typedef struct FIFO_INFO{
	unsigned long	Captured_Points;							//	Captured Number Of Points in the FIFO.
	unsigned long	Retrieved_Points;							//	Retrieved Number Of Points from the FIFO.
} *LPFIFO_INFO;

typedef struct {
	//	Part 1, general tracker channels	
	bool			Warm_Up_Time;								//	true:System Warming-Up; false:System is ready.
	bool			Laser_Path_Error;							//	true:Laser Beam-Path Error; false:Laser Beam-Path is O.K.
	bool			Laser_Dist_Error;							//	true:Laser Distance Status Error; false:Distance Status is O.K.
	bool			External_Switch;							//	true:External Switch Contact; false:External Switch Open
	bool			Filtering_Switch;							//	true:Filtering Switch On; false:Filtering Switch Off
	bool			TrueIFM;									//	true, IFM has not been updated with ADM.	// false,IFM has ever been updated by ADM
	bool			bWeather;									//	true, weather station attached; false, no weather station.
	bool			bFrontSight;

					OPERATION_MODE	Operation_Mode;					//	Tracker Operation Mode
																	//	0 -> Servo Free Mode (Idle)
																	//	1 -> Servo Engaged Mode (Servo)
																	//	2 -> Tracking Mode (Track)
																	//	3 -> Losing target during Tracking (Track Idle)
																	//	4 -> Not Used by API DI user (Internal Use Only)
																	//	5 -> Searching the Encoder Index (Index Searching)
																	//	6 -> Not Used by API user (Internal Use Only)
																	//	7 -> Target Scan Search Mode (Search)
																	//	8 -> Not Used by API user (Internal Use Only)
																	//	9 -> Innovo camera search mode
	
	DWORD			Time_Stamp;										//	Tracker Time Stamp in ms
	float			Laser_Intensity;								//	The Laser intensity is between 0.0-1.0
	float			Laser_Distance;									//	If the tracker mode is not in the Tracking Mode, the Laser Distance is 0.
	float			Laser_Distance_Filter;							//	If the tracker mode is not in the Tracking Mode, the Laser Distance is 0.
	float			Current_Position_AZ;							//	Azimuth in Degree
	float			Current_Position_EL;							//	Elevation in Degree
	float			Current_Position_AZ_Filter;						//	Filter Azimuth in Degree
	float			Current_Position_EL_Filter;						//	Filter Elevation in Degree
	float			Air_Temperature;								//	Weather Sensor Information : Air Temperature (Centigrade) 
	float			Air_Pressure;									//	Weather Sensor Information : Air Pressure	 (mm/Hg)
	float           Air_Humidity;									//	Weather Sensor Information : Air Humidity
	float			Body_Temperature;
	DWORD	ADM_Frequency;
	float			Current_Position_X;								//	X in mm
	float			Current_Position_Y;								//	Y in mm
	float			Current_Position_Z;								//	Z in mm
	float			Current_Position_X_Filter;						//	Filter X in mm
	float			Current_Position_Y_Filter;						//	Filter Y in mm
	float			Current_Position_Z_Filter;						//	Filter Z in mm
	float			Target_Velocity;								//	Velocity (mm/sec)
	float			Photo_X;										//	Calibrated Photo Sensor Eccentric in mm (X-direction)
	float			Photo_Y;										//	Calibrated Photo Sensor Eccentric in mm (Y-direction)
	float			MatTemp[3];										//	Material temperature	
	float			fUncalibratedDistance;
	float			Level_X;										//	Calibrated Level Sensor in ArcSec (X-direction)
	float			Level_Y;										//	Calibrated Level Sensor in ArcSec (Y-direction)
	bool			LevelX_OverLimit;								//	true:Out of the limit false:Within limit
	bool			LevelY_OverLimit;								//	true:Out of the limit false:Within limit
	
	// ADM data	
	float			ADM_Intensity;
	float			ADM_Temp1;
	float			ADM_Temp2;
	float			ADM_Tube_Intensity;
	float			ADM_Tube_Temp;
	float			ADM_Distance;
	int				admstate;										//	indicate adm weather compensation state. 1: on; 0: off.
	bool			AdmIntensityLow;								//	warning flag. true: adm intensity too low ( < 0.15); false: adm intensity ok.
	bool			AdmNoReading;									//	adm intensity too low, can't be used
	bool			AdmHWFail;										//	adm hardware failure flag
	bool			AdmReferenceWarning;							//	true, adm needs to redo referencing. false, adm is well referenced	
	// end ADM
	
	// 6D target STS channels
	bool			TGLevelX_OverLimit;								//	true:Out of the limit false:Within limit
	bool			TGLevelY_OverLimit;								//	true:Out of the limit false:Within limit
	short			Status;											//	Target Status/IP button status
	float			TgTilt_X;										//	Target tilt angle at X direction
	float			TgTilt_Y;										//	Target tilt angle at Y direction
	float			TgPos_AZ;										//	Target current az angle 
	float			TgPos_EL;										//	Target current el angle	
	float			NormalVec_I;									//	i
	float			NormalVec_J;									//	j
	float			NormalVec_K;									//	k
	float			dpitch;											//	relative pitch
	float			dyaw;											//	relative	yaw
	float			droll;											//	relative roll
	float			HzAngle;
	float           VtAngle;
	float			tgAirTemp;
	
	// part 4, intelliprobe channels
	D_VECTOR3		Probe_Attitude;
	D_VECTOR4		PhotoReading;
	D_VECTOR3		ProbeTip_Position;
	F_VECTOR3			IP_RTTip;									//	realtime tip position
	F_VECTOR3			ResetPosition;
	long					ProbeTS;								//	time stamp for IntelliProbe
	int						wCmd;
	int						status_ind;

	float					fEncRoll;								//	probe raw encoder roll value
	float					fEncYaw;								//	probe raw encoder yaw value
	float					fCentroidX;								//	probe optics centroid X value
	float					fCentroidY;								//	probe optics centroid Y value	
	DWORD				sTriggerIP;								//	TTL Trigger Counter
	DWORD					sTriggerT3;								//	TTL Trigger Counter
    bool					bProbeTrigger;							//	true: on; false: off
	bool					b_ValidTip;
	bool					bIsLaserLockonIP;						//	true: laser beam is on probe; false: laser beam is not 
																	//	on probe, could be on SMR or not trackign at all	
	
	//IP3	
	unsigned short  usCamFrameCounter;								//	Camera Frame Counter
	BYTE					camStatus;
	BYTE					auxStatus;
	BYTE					pwrStatus;
	BYTE					pciStatus;
	BYTE					encStatus;
	BYTE					probeTip; //added new channel to indicate which probe tip is selected 
} REALTIME_INFO;


typedef struct {
	DWORD dwTimeStamp;					// Tracker Time Stamp in ms
	float fIntensityOrg;				// original intensity
	float fIntensityRev;				// intensity after revise
	float fDistanceOrg;					// original distance
	float fDistanceThm;					// distance after thermal
	float fDistance2De;					// distance after 2D error
	float fDistanceLin;					// distance after linear
	float fDistanceABC;					// distance after ABC
	float fTemperature1;
	float fTemperature2;
	float fTubeTemperature;
	float fThermalRate;
	float fABCOffset;
	float fIFMDistance;
}REALTIME_INFO_INTERNAL;



//////////////////////////////////////////////////////////////////////////
// Define the data structure for averaging data
//////////////////////////////////////////////////////////////////////////
typedef struct {
	double			Laser_Distance;							//	If the tracker mode is not in the Tracking Mode, the Laser Distance is 0.
	double			Current_Position_AZ;					//	Azimuth in Degree
	double			Current_Position_EL;					//	Elevation in Degree
	double			Current_Position_X;						//	X in mm
	double			Current_Position_Y;						//	Y in mm
	double			Current_Position_Z;						//	Z in mm
	double			Level_X;								//	Calibrated Level Sensor in ArcSec (X-direction)
	double			Level_Y;								//	Calibrated Level Sensor in ArcSec (Y-direction)
	D_VECTOR4		Tck_PhotoReading;
	
	//	add more channels for ADM tracker data collection
	double			ADM_Distance;
	double			ADM_LaserIntensity;
	double			ADM_TubeIntensity;
	double			ADM_Temperature1;
	double			ADM_Temperature2;
	double			ADM_TubeTemperature;
	
	// Add two more channels for weather station (air temperature and air pressure)
	double			AirPressure;
	double			AirTemperature;
	double			MatTemperature[3];
	double			IP3_Pitch;
	double			IP3_Yaw;
	double			IP3_Roll;
	double			IP3_Enc_Roll;
	double			IP3_Enc_Yaw;
	double			IP3_TipX;
	double			IP3_TipY;
	double			IP3_TipZ;
	D_VECTOR4		STS_Psd;
} AVERAGE_BUFFER;

//////////////////////////////////////////////////////////////////////////
// Define the raw data structure
//////////////////////////////////////////////////////////////////////////
typedef struct {
	F_VECTOR2						fv2_RawAngles;
	F_VECTOR2 						fv2_RawOffset;
	F_VECTOR4						fv4_NCAngles;
	ADM_RAWINFO						adm_RawInfo;
	F_PHOTO4						fv4_RawPhoto;
	float							fUCDistance;		// uncalibrated distance
} REALTIME_RAWINFO;

//////////////////////////////////////////////////////////////////////////
// Used for Latched data
typedef struct {

	BOOL						dataAvailable;
	LONG						timeStamp;
	D_VECTOR4					photoSensor;
	D_VECTOR2					anglePos;
	FLOAT						laser;
	BYTE						SysStatus;

} LATCHED_DATA, *LP_LATCHED_DATA;

// More 
// 6d FLOAT vector
typedef struct {
	FLOAT x;
	FLOAT y;
	FLOAT z;
	FLOAT w;
	FLOAT a;
	FLOAT b;
} FVECTOR6, *LPFVECTOR6;

// 2d LONG vector
typedef struct {
	LONG x;
	LONG y;
} LVECTOR2, *LPLVECTOR2;

// 4d LONG vector
typedef struct {
	LONG x;
	LONG y;
	LONG z;
	LONG w;
} LVECTOR4, *LPLVECTOR4;

// 6d LONG vector
typedef struct {
	LONG x;
	LONG y;
	LONG z;
	LONG w;
	LONG a;
	LONG b;
} LVECTOR6, *LPLVECTOR6;


/////////////////////////////////////////////////////////////////////
enum TRACKER_ADM_TYPE {
	ADM_PLUS_IFM = 0,		//IFM+ADM
	ADM_ONLY = 1			//ADM Only
};

enum TRACKER_TYPE {
	TRACKER_OLD_DEV = 1,
	TRACKER_OT_PLUS = 10,
	TRACKER_T3 = 20,
	TRACKER_T3_PLUS = 30,
	TRACKER_RADIAN = 40,
	TRACKER_NEWEST = 50,
	TRACKER_OT_TWO = 60,
	TRACKER_UNKNOWN = 1000
};

typedef enum {  NORMAL = 0,
				ERROR_SERVO_ERROR,
				ERROR_LOST_TRACK,
				ERROR_HOME_FAILED

} TCKERROR, *LPTCKERROR;

// 6d tracker operation mode
typedef enum {	IDLE = 0,
				TPOSITION,
				TRACK,
				TRACK_IDLE,
				TACH_TUNE,
				IDX_SEARCHING,
				SERVO_FIRSTUSE,
				SEARCH,
				ADM_SEARCH,
				CAM_SEARCH,
				PRELOAD
} TRACKEROPMODE, *LPTRACKEROPMODE;

////////////////////////////////////////////////////////////////////
//	Enum type of Led status
////////////////////////////////////////////////////////////////////
enum	LEDSTATUS{
	NOREADY = 0,
	ON,
	OFF,
	BLINKING,
	ADMFLY
};

enum	ACC_LEDSTATUS{
	ACC_OFF,
	ACC_ON, 
	ACC_FAST,
	ACC_SLOW
};

enum	IPLEDSTATUS{
	IPLED_ON = 0,	
	IPLED_OFF,											// Both led off
	IPLED_TRIGGER,										// Green Led On
	IPLED_DATACOLLECTIONEND,							// Green led blinking
	IPLED_WARNING,										// Red led blinking
	IPLED_INVALIDDATA									// Invalid result
};

typedef struct {
	TRACKEROPMODE CurOpMode;				 // current six d tracker operational mode
	TCKERROR TckError;
	BOOL MoveComplete;						 // flag to indicate servo move completion or not.
} TCKSTATUS, *LPTCKSTATUS;

// Define I-Probe 3 data srructure
typedef struct {
	UINT  sProbeTimeStamp;
	UINT  sProbeTriggerCounter;						//IP TTL sync trigger counter 
	UINT  sT3TriggerCounter;						//T3 TTL sync trigger counter 
	UINT  sIP2Delay;								//IP2 Delay

	DWORD dwRoll;
	DWORD dwYaw;	
	float fCentroidX;
	float fCentroidY;
	short sIntensity;
	short sLevel;
	
	BYTE  bEncoder;
	BYTE  bCamera;
	BYTE  bAuxillary;
	BYTE  bPower;	
	BYTE  bButton;
	BYTE  bPICStatus;
	
	//daignosis channel
	BYTE  bAQB1;
	BYTE  bAQB2;
	BYTE  bAQB3;
	BYTE  bAQB4;
	BYTE  bARMFWVersion;
	short sExpTime;
	short sPICFWVersion;
	short sFPGA1Version;
	short sFPGA2Version;
	short sFPGA3Version;
	short camFPGAVersion;
    unsigned short camFrameCounter;
} IPROBE3_DATA, *LPIP3_DATA;

typedef struct 
{
	float		fAz;
	float		fEl;
	I_VECTOR3	iv3Gyro;
	WORD		wSerialNum;
	WORD		wGyroTemp;
	int			iLatchTS;
	int			iClock;
	short		sPSDx;
	short		sPSDy;
	WORD		wPSDint;
	WORD		wStatus;
	int			iTTLCounter;
	short		sLevel1;
	short		sLevel2;

}STSDATA, *LPSTSDATA;
///////////////////////////////////////////////////////////////////////////
// tracker essential data packet
///////////////////////////////////////////////////////////////////////////
typedef struct {
	LONG													HeartBeat;
	TRACKEROPMODE											Mode;
	FVECTOR4												CurPos;
	FVECTOR4												BasePhoto;
	FVECTOR4												TgPhoto;
	FLOAT													Laser;
	FVECTOR2												BaseTilt;
	FVECTOR2												TgTilt;

	// new channels; for weatherstation
	float													airTemp;
	float													airPressure;
	float													airHumidity;
	float													materialTemp[3];

	float													tgAirTemp;
	long													sysStatus;					// laser path error
	short													tgStatus; 
	WORD													wFCmd;						// feed command	

	// for internal use (essential data packet)
	FVECTOR4												HomePos;					// home position of the six-d tracker

	// Data for ADM tracker
	FLOAT													LaserTubeIntensity;
	FLOAT													ADMTemp1;
	FLOAT													ADMTemp2;
	FLOAT													ADMLaserIntensity;
	FLOAT													LaserTubeTemp;
	FLOAT													ADMDistance;

	FLOAT													BodyTemp;
	DWORD													ADMFrequency;
	DWORD													hwStatus;
	// channels for intelliprobe
	IPROBE3_DATA											ip3Data;
	// channels for new STS
	STSDATA													stsData;
} TCKESSENTIALDATA, *LPTCKESSENTIALDATA;

///////////////////////////////////////////////////////////////////////////
// tracker DIAGNOSTIC data packet
///////////////////////////////////////////////////////////////////////////
typedef struct {
	LONG														HeartBeat;
	TRACKEROPMODE												Mode;
	FVECTOR2													CurPos;
	FVECTOR4													BasePhoto;
	ENC_VECTOR													lj;									//lissajous information
	I_VECTOR2													AQB;
	FVECTOR2													AQBOff;
	FVECTOR2													PE;
	double														ADMDistance;
	double														LaserDistance;
	float														AzSpeed;
	float														ElSpeed;
	DVECTOR2													BaseTilt;
	float														LaserTubeIntensity;
	float														ADMTemp1;
	float														ADMTemp2;
	float														ADMIntensity;
	float														TubeTemp;
	bool														Warm_Up_Time;						//	true:System Warming-Up; false:System is ready. 
	bool														Laser_Path_Error;					//	true:Laser Beam-Path Error; false:Laser Beam-Path is O.K. 
	F_VECTOR4													EnvData;							//	store the environment variables
} TCKDIAGDATA, *LPTCKDIAGDATA;

typedef struct {
	LONG HeartBeat;
	TRACKEROPMODE Mode;
	DVECTOR4 CurPos;
	DVECTOR4 BasePhoto;
	DVECTOR4 TgPhoto;
	double Laser;
	DVECTOR2 BaseTilt;
	DVECTOR2 TgTilt;

	// new channels; for weatherstation
	float airTemp;
	float airPressure;
	float airHumidity;
	float materialTemp[3];
} DTCKESSENTIALDATA;



// Used for Latched data
typedef struct {

	BOOL				dataAvailable;
	LONG				timeStamp;
	FVECTOR4			photoSensor;
	FVECTOR2			anglePos;
	FLOAT				laser;
	BYTE				SysStatus;

} TCK_LATCHED_DATA, *LP_TCK_LATCHED_DATA;

typedef enum {
	ISA,
	EISA,
	VME,
	MICROCHANNEL,
	PCI
} BUSTYPE;

typedef enum {
	IO_MAPPED,
	MEMORY_MAPPED
} MAPTYPE;

typedef enum {
	NULL_TRIGGER,
	SOFT_TRIGGER,
	INTERNAL_TIMER_TRIGGER,
	SYNCBUS_TRIGGER
} SIMEVENT;

typedef enum {
	IDLE_STATE,
	ACTIVE,
	PAUSED,
	COMPLETE,
	DELETED
} SIMTASKSTATE;

typedef struct {
	FLOAT Kp;
	FLOAT Ki;
	FLOAT Kd;
	FLOAT Antiwindup;
} PIDBLK, *LPPIDBLK;

/////////////////////////////////////////////////////////////////////
// Data structure for System Startup Parameters
/////////////////////////////////////////////////////////////////////

typedef struct {
	PIDBLK BaseElServoParam;
	FVECTOR2 BaseElServoReserved;	// reserved

	PIDBLK BaseAzServoParam;
	FVECTOR2 BaseAzServoReserved;	// reserved

	PIDBLK TgElServoParam;
	FVECTOR2 TgElServoReserved;		// reserved

	PIDBLK TgAzServoParam;
	FVECTOR2 TgAzServoReserved;		// reserved

	PIDBLK BaseElTrackParam;
	FVECTOR2 BaseElTrackReserved;	// reserved

	PIDBLK BaseAzTrackParam;
	FVECTOR2 BaseAzTrackReserved;	// reserved

	PIDBLK TgElTrackParam;
	FVECTOR2 TgElTrackReserved;		// reserved

	PIDBLK TgAzTrackParam;
	FVECTOR2 TgAzTrackReserved;		// reserved

	PIDBLK BaseElAzVelReserved;		// reserved
	PIDBLK BaseElVelReserved;		// reserved
	
	// new parameters
	PIDBLK ElDamperParam;
	PIDBLK AzDamperParam;
	PIDBLK TgElDamperParam;
	PIDBLK TgAzDamperParam;

	PIDBLK ElInnovoDampCtrl;
	PIDBLK AzInnovoDampCtrl;
	PIDBLK ElInnovoCtrl;
	PIDBLK AzInnovoCtrl;

	FLOAT BaseAzDamperKdReserved;
	FLOAT BaseElDamperKdReserved;
	FLOAT TgAzDamperKdReserved;
	FLOAT TgElDamperKdReserved;

	FLOAT AzExpoFilterReserved;
	FLOAT ElExpoFilterReserved;

	FVECTOR4 HomePos;														// home position of the six-d tracker
	FVECTOR4 HomeIncrement;

	FLOAT InitialTrackDistance;												// initial startup distance for tracking
	FLOAT BasePhotoThreshold;
	FLOAT TgPhotoThreshold;

	FVECTOR2 BasePhotoSetpt;
	FVECTOR2 TgPhotoSetpt;

	FVECTOR4 MaxPhotoIntensity;

	// new attributes
	FLOAT TrackTuneUpDistance;												// initial startup distance for tracking
	FLOAT LaserFactor;

	LONG BaseElEncoderLines;												// encoder number of lines per revolution
	LONG BaseElEncoderSubdivision;											// level of subdivision by electronics

	LONG BaseAzEncoderLines;												// encoder number of lines per revolution
	LONG BaseAzEncoderSubdivision;											// level of subdivision by electronics

	LONG TgElEncoderLines;													// encoder number of lines per revolution
	LONG TgElEncoderSubdivision;											// level of subdivision by electronics

	LONG TgAzEncoderLines;													// encoder number of lines per revolution
	LONG TgAzEncoderSubdivision;											// level of subdivision by electronics
	
	FVECTOR4 BasePhotoFactor;
	FVECTOR4 TgPhotoFactor;
	FLOAT K_pressure[3];
	FLOAT ref_pressure;
	FLOAT K_temp[3];
	FLOAT ref_temp;

	// target roll detector
	// roll math model: roll = k2 * arcsin (k1 * Rd / Rs)
	// where Rd and Rs are analog voltage input from roll detector
	FLOAT RollScaleFactor; // k1
	FLOAT RollNormFactor;  // k2
} TCKSYSTEMPARAM, *LPTCKSYSTEMPARAM;

/////////////////////////////////////////////////////////////////////
// equivalent to the controller ini file 
// these are persistent parameters stored in 
typedef struct {
	PIDBLK BaseElServoParam;
	PIDBLK BaseAzServoParam;
	PIDBLK TgElServoParam;
	PIDBLK TgAzServoParam;


	PIDBLK BaseElTrackParam;
	PIDBLK BaseAzTrackParam;
	PIDBLK TgElTrackParam;
	PIDBLK TgAzTrackParam;

	// new parameters
	PIDBLK ElDamperParam;
	PIDBLK AzDamperParam;
	PIDBLK TgElDamperParam;
	PIDBLK TgAzDamperParam;

	PIDBLK ElTachSimuParam;
	PIDBLK AzTachSimuParam;

	FVECTOR4 HomePos;				// home position of the six-d tracker
	FVECTOR4 HomeSpeed;

	FLOAT InitialTrackDistance;		// initial startup distance for tracking
	FLOAT TrackTuneUpDistance;		// initial startup distance for tracking

	FLOAT BasePhotoThreshold;
	FLOAT TgPhotoThreshold;

	FVECTOR2 BasePhotoSetpt;
	FVECTOR2 TgPhotoSetpt;

	FLOAT LaserFactor;

	LONG BaseElEncoderLines;					// encoder number of lines per revolution
	LONG BaseElEncoderSubdivision;				// level of subdivision by electronics

	LONG BaseAzEncoderLines;					// encoder number of lines per revolution
	LONG BaseAzEncoderSubdivision;				// level of subdivision by electronics

	LONG TgElEncoderLines;						// encoder number of lines per revolution
	LONG TgElEncoderSubdivision;				// level of subdivision by electronics

	LONG TgAzEncoderLines;						// encoder number of lines per revolution
	LONG TgAzEncoderSubdivision;				// level of subdivision by electronics

	FVECTOR4 BasePhotoFactor;
	FVECTOR4 TgPhotoFactor;

	// target roll detector
	// roll math model: roll = k2 * arcsin (k1 * Rd / Rs)
	// where Rd and Rs are analog voltage input from roll detector
	FLOAT RollScaleFactor;						// k1
	FLOAT RollNormFactor;						// k2

	//IDX_SEARCHING constant
	float ElIdxSearchVoltage;
	float AzIdxSearchVoltage;
	float TgElIdxSearchVoltage;
	float TgAzIdxSearchVoltage;
	int   IdxSearchTimeCycle;

	float prev_idx_pos_x;
	float prev_idx_pos_y;
	float idx_search_no_move;
	float idx_search_moving;
	float index_search_delta_pulse_found;

	BOOL  el_idx_pulse_crossed;
	BOOL  az_idx_pulse_crossed;

	float El_horizontal_Angle;					// deg, when the El flip over the top, reverse polarity for AZ control in effect
	int PathErrorClearedWaitTime;				// wait this long in ms for path error to clear before locking on to target

	float search_frequency;
	float search_multiplier;

	float airTempDefault;
	float airHumidityDefault;
	float airPressureDefault;
	float materialTempDefault;

	float AirTemperature_scaleFactor;
	float AirHumidity_scaleFactor;
	float AirPressure_scaleFactor;

	PIDBLK ElInnovoDampCtrl;
	PIDBLK AzInnovoDampCtrl;
	PIDBLK ElInnovoCtrl;
	PIDBLK AzInnovoCtrl;
// to be continued....
} TCKSYSTEMPARAM2, *LPTCKSYSTEMPARAM2;

/////////////////////////////////////////////////////////////////////
// data structure for basic data type
/////////////////////////////////////////////////////////////////////

typedef union {
	DWORD _int;
	FLOAT _float;
	BYTE byte[4];
	WORD _word[2];
	short _short[2];
} UDATA;


/////////////////////////////////////////////////////////////////////
// data structure for tracker commu port serial port
/////////////////////////////////////////////////////////////////////
typedef struct {
	LPCTSTR gszPort; 
	DWORD BaudRate;
	BYTE ByteSize;
	BYTE Parity;
	BYTE StopBits;
} TCKCOMMUPORT;

/////////////////////////////////////////////////////////////////////
// Enum type decode state machine for incoming data
/////////////////////////////////////////////////////////////////////
typedef enum {
	WAITING_SYNCHEAD,
	INSIDE_DATA_PACKET,
	END_DATA_PACKET
} DECODESTATES;

/////////////////////////////////////////////////////////////////////
// Enum type of tracker type
/////////////////////////////////////////////////////////////////////
typedef enum {
	TRACKERII = 0,
	TRACKERIIPLUS,
	INTELLIPROBE,
	INTELLIPROBE_III,
	TRACKER6D,
	V_PROBE,
	ISCAN2PLUS,
	NSTS
} TRACKERSERIES;

/////////////////////////////////////////////////////////////////////
// Enum type of Innovo Camera mode
/////////////////////////////////////////////////////////////////////

typedef enum {
	INNOVO_OFF = 0,
	SINGLE_SMR_ON,
	MULTI_SMR_ON,
	MANUAL_SMR_MODE_ON,
	INNOVO_CALIB_ON,
	SHAKE2DRIVE_ON,
	TEACHING_ON,
	TEACH_EXECUTE_ON,
	VIDEO_MODE_ON
}INNOVO_CAMERA_MODE;


/////////////////////////////////////////////////////////////////////
// data mask selector data structure
//////////////////////////////////////////////////////////////////////
// fiddle bit to one for channel selection

#define MAX_SIMTASK 10

typedef union {
	ULONG _int;
	struct {
		UINT TimeStamp : 1;
		UINT OpMode : 1;
		UINT BaseEl : 1;
		UINT BaseAz : 1;
		UINT TgEl : 1;
		UINT TgAz : 1;
		UINT Laser : 1;
		UINT BasePhotoXInt : 1;
		UINT BasePhotoXDist : 1;
		UINT BasePhotoYInt : 1;
		UINT BasePhotoYDist : 1;
		UINT TgPhotoXInt : 1;
		UINT TgPhotoXDist : 1;
		UINT TgPhotoYInt : 1;
		UINT TgPhotoYDist : 1;
		UINT BaseTiltX : 1;
		UINT BaseTiltY : 1;
		UINT TgTiltX : 1;
		UINT TgTiltY : 1;
		UINT TgRollDetector : 1;
		UINT LaserDistError	: 1;
		//UINT Reserved : 11;
		// add 6 more channels for adm tracker
		UINT AdmIntensity	: 1;
		UINT AdmDistance	: 1;
		UINT AdmTemp1		: 1;
		UINT AdmTemp2		: 1;
		UINT AdmTubeIntensity : 1;
		UINT AdmTubeTempture : 1;
		UINT Reserved : 5;
	} _bit;
} DATAMASK, *LPDATAMASK;

typedef union {
	DWORD64 _int;
	struct {
		// 27 channels defined, 01-18-2007
		// 8  channels define for IP3, 5-18-2009
		// 4 new channels for STS
		// added target veclocity channel - chd 07192018
		UINT TimeStamp : 1;	
		UINT OpMode : 1;	
		UINT BaseEl : 1;	
		UINT BaseAz : 1;	
		UINT LaserDistance : 1;
		UINT BasePhotoXInt : 1;
		UINT BasePhotoXDist : 1;
		UINT BasePhotoYInt : 1;
		UINT BasePhotoYDist : 1;
		UINT BaseTiltX : 1;
		UINT BaseTiltY : 1;
		UINT LaserDistError	: 1;
		UINT LaserPathError : 1;
		UINT Current_X : 1;
		UINT Current_Y : 1;
		UINT Current_Z : 1;
		UINT Air_Temp : 1;
		UINT Air_Pressure : 1;
		UINT Mat_Temp1 : 1;
		UINT Mat_Temp2 : 1;
		UINT Mat_Temp3 : 1;

		UINT AdmIntensity	: 1;
		UINT AdmDistance	: 1;
		UINT AdmTemp1		: 1;
		UINT AdmTemp2		: 1;
		UINT TubeIntensity : 1;
		UINT TubeTemperature : 1;
		UINT Target_Velocity : 1;
		UINT IP3Pitch : 1;
		UINT IP3Yaw : 1;
		UINT IP3Roll : 1;
		UINT IP3EncRoll : 1;
		UINT IP3EncYaw : 1;
		UINT IP3TipX : 1;
		UINT IP3TipY : 1;
		UINT IP3TipZ : 1;
		UINT STSPsdX : 1;
		UINT STSPsdY : 1;
		UINT STSPsdZ : 1;
		UINT STSPsdW : 1;
		
		//UINT Reserved : 37;
		//UINT Reserved : 37;
	} _bit;
} TCKDATAMASK, *LPTCKDATAMASK;

/////////////////////////////////////////////////////////////////////////
// Name: TCK_CAPTUREMODE
// Definition for the tracker data capturing mode.
//	TCK_CAPTURE_IDLE: 0, no data collection is set up.
//	TCK_CAPTURE_STATIC_FSIGHT: 2, PC Realtime Static FrontSight Capturing.
//	TCK_CAPTURE_STATIC_FBSIGHT:3, PC Realtime Static FrontBackSight Capturing.
//	TCK_CAPTURE_STATIC_FSIGHT_AUTO: 4, PC Realtime Static FrontSight 
//			Capturing in Automatic Triggering Mode.
//	TCK_CAPTURE_STATIC_FBSIGHT_AUTO: 5, PC Realtime Static FrontBackSight 
//			Capturing in Automatic Triggering Mode.
//	TCK_CAPTURE_DYNAMIC_TEMPORAL: 6, PC Realtime Dynamic temporal capturing.
//	TCK_CAPTURE_DYNAMIC_SPATIAL: 7, PC Realtime Dynamic spatial capturing.
//////////////////////////////////////////////////////////////////////////
typedef enum {
	TCK_CAPTURE_IDLE = 0,
	TCK_CAPTURE_FIFO, 
	TCK_CAPTURE_STATIC_FSIGHT,  
	TCK_CAPTURE_STATIC_FBSIGHT,  
	TCK_CAPTURE_STATIC_FSIGHT_AUTO, 
	TCK_CAPTURE_STATIC_FBSIGHT_AUTO,
	TCK_CAPTURE_DYNAMIC_TEMPORAL,	
	TCK_CAPTURE_DYNAMIC_SPATIAL,
	TCK_CAPTURE_STATIC_SIGMA,
	TCK_CAPTURE_DYNAMIC_DISTANCE,
	TCK_CAPTURE_DYNAMIC_TIME,
	TCK_CAPTURE_NEST_READING,
	TCK_CAPTURE_SCAN,
	TCK_CAPTURE_EVENT_ONLY,
	TCK_CAPTURE_TEMPORAL_RATEFILTER,
	TCK_CAPTURE_DYNAMIC_RATEFILTER,
	TCK_CAPTURE_STS_DYNAMIC
} TCK_CAPTUREMODE;

typedef union {
	float _gdFloat;
	int   _gdInt;
} GDATCAP_TYPE;

///////////////////////////////////////////////////////////////////////////
// Device task enum type
///////////////////////////////////////////////////////////////////////////
typedef enum {
	APIDEVICE_IDLE = 0,
	APIDEVICE_CONNECT,
	APIDEVICE_DISCONNECT,
	APIDEVICE_HOME,
	APIDEVICE_JOGBY,
	APIDEVICE_JOGTO,
	APIDEVICE_POINTTO,
	APIDEVICE_SPIRAL_SEARCH,
	APIDEVICE_ADM_SEARCH,
	APIDEVICE_TARGET_SEARCH,
	APIDEVICE_ACC_SEARCH,
	APIDEVICE_VIRTUAL_LEVEL,
	APIDEVICE_NESTREADING,
	APIDEVICE_ADMBEAMOFFSET,
	APIDEVICE_REMOTEHOME,
	APIDEVICE_BKSIGHT_OPERATION,
	APIDEVICE_BKSIGHT_CHECKING,
	APIDEVICE_QVC,
	APIDEVICE_SWITCH_IDLE,
	APIDEVICE_SWITCH_POSITION,
	APIDEVICE_SWITCH_TRACK,
	APIDEVICE_SWITCH_TRACK_TUNE,
	APIDEVICE_POWER_ENABLE,
	APIDEVICE_POWER_DISABLE,
	APIDEVICE_INDEX_SEARCH,
	APIDEVICE_STS_INDEX,
	APIDEVICE_STS_JOGBY,
	APIDEVICE_STS_JOGTO,
	APIDEVICE_IP_SINGLEMEAS,
	APIDEVICE_IP_OFFSETCAL,
	APIDEVICE_IP_GLBMODEL,
	APIDEVICE_IS_SCAN,
	APIDEVICE_IP_SCAN,
	APIDEVICE_HOLD_POSITION,
	APIDEVICE_IP_INSPECT,
	APIDEVICE_JOG_SEARCH,
	APIDEVICE_EXTERNAL_TRIGGER,
	APIDEVICE_WIRELESS_LOOPBACK, 
	APIDEVICE_DISABLE_WIRELESS_LOOPBACK,
	APIDEVICE_SWITCH_PRELOAD,
	APIDEVICE_INNOVO_DATA, 
	APIDEVICE_ACC_SINGLEMEAS,
	APIDEVICE_GENERIC
} APIDEVICE_TASK;

enum APIDEVICE_MODEL {
	APIDEVICE_TRACKER = 320,
	APIDEVICE_IPROBE = 330,
	APIDEVICE_IPROBE3 = 331,
	APIDEVICE_STS = 340,
	APIDEVICE_ISCANNER = 350,
	APIDEVICE_VPROBE = 360,
	APIDEVICE_ISCAN2PLUS = 370,
	APIDEVICE_NSTS = 380
};

///////////////////////////////////////////////////////////////////////////
// Definition of the structure used for the call-back function for the task
// Different structure needs different structure to send back the result
typedef struct {
	DWORD dwSize;
	int   iTaskID;
	bool  bSuccess;
	int   iErrorCode;
	int	  iResult1;
	int   iResult2;
	F_VECTOR3 fv3;
} TASK_RESULT;


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Name : IPROBE_RAWINFO
// Description:
//	irSize:	Specifies the number of bytes required by the structure.
//	irTKTimeStamp:	Tracker time stamp
//	irStatus:	status
//	irDistance: distance
//	irPosX: coordinate x.
//	irPosY: coordinate y.
//	irPosZ: coordinate z.
//	irIntensity: intensity.
//	irCentroidX: centroid x.
//	irCentroidY: centroid y.
//	irLevelX: level x.
//	irLevelY: level y.
//	irIPTimeStamp: probe time stamp.
/////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct IPROBE_RAWINFO {
	DWORD	irSize;
	DWORD	irTKTimeStamp;
	DWORD	irIPTimeStamp;
	DWORD	irStatus;
	DWORD	irRollCounter;
	DWORD	irYawCounter;
	
	float	irDistance;
	float	irPosX;
	float	irPosY;
	float	irPosZ;
	float	irIntensity;
	float	irCentroidX;
	float	irCentroidY;
	float	irLevelX;
	float	irLevelY;	
	short	irLevelCounter;	
	
	OPERATION_MODE	irOpMode;
	bool	irDistanceError;	
	BYTE	irEncoder;
	BYTE	irCamera;
	BYTE	irAuxiliary;
	BYTE	irPower;
	BYTE    irPCIStatus;
}*LPIP_RAWINFO;

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Name : IPROBE_INFO
// Description:
//	iiSize:	Specifies the number of bytes required by the structure.
//	iiTKTimeStamp:	Tracker time stamp
//	iiStatus:	status
//	iiPosX: coordinate x.
//	iiPosY: coordinate y.
//	iiPosZ: coordinate z.
//	iiCentroidX: centroid x.
//	iiCentroidY: centroid y.
//	iiPitch: pitch.
//	iiYaw:	yaw.
//	iiRoll:	roll.
//	iiIPTimeStamp: probe time stamp.
/////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct IPROBE_INFO {
	DWORD	iiSize;
	DWORD	iiTKTimeStamp;
	DWORD	irIPTimeStamp;
	DWORD	iiStatus;
	
	float	iiPosX;
	float	iiPosY;
	float	iiPosZ;
	
	float	iiCentroidX;
	float	iiCentroidY;
	
	float	iiPitch;
	float	iiYaw;
	float	iiRoll;
	
	float	iiRollEnc;
	float	iiYawEnc;
	
	F_VECTOR3 rtTip;
	F_VECTOR3 rtVector;

	BYTE	irEncoder;
	BYTE	irCamera;
	BYTE	irAuxiliary;
	BYTE	irPower;
	
}*LPIP_INFO;

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Name : STS_RAWINFO
// Description:
//	srSize:	Specifies the number of bytes required by the structure.
//	srStatus:	status
//	srPosX: coordinate x.
//	srPosY: coordinate y.
//	srPosZ: coordinate z.
//	srLevelX: level x.
//	srLevelY: level y.
/////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct STS_RAWINFO {
	DWORD	srSize;
	DWORD	srStatus;
	float	srPosX;
	float	srPosY;
	float	srPosZ;
	float	srAzimuth;
	float	srElevation;
	float	srLevelX;
	float	srLevelY;
	float	tgAirTemp;
	float	Target_Velocity;
	OPERATION_MODE	srOpMode;
	bool	srDistanceError;
	int		srGyroX;
	int		srGyroY;
	int		srGyroZ;
	DWORD	srTimeStamp;
}*LPSTS_RAWINFO;

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Name : STS_INFO
// Description:
//	srSize:	Specifies the number of bytes required by the structure.
//	srStatus:	status
//	srPosX: coordinate x.
//	srPosY: coordinate y.
//	srPosZ: coordinate z.
//	srLevelX: level x.
//	srLevelY: level y.
/////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct STS_INFO {
	DWORD	siSize;
	float	siAzimuth;
	float	siElevation;
	float	siLevelX;
	float	siLevelY;
	float	siPitch;
	float	siYaw;
	float	siRoll;
	bool	srDistanceError;
	float	siPosX;
	float	siPosY;
	float	siPosZ;
	float	siGyroX;
	float	siGyroY;
	float	siGyroZ;
}*LPSTS_INFO;

//AutoDetect trackers
typedef struct AUTODETECT_INFO{
	int trackerCount;
	UINT	SN[100];
	TCHAR	IP[100][64];
	DWORD	WorkMode[100];
}*LPAUTODETECT_INFO;

#pragma pack(pop)

// Error codes
#define API_ERROR_SUCCESS																							0

// General error codes
#define API_ERROR_NODEVICE_DETECTED																					1
#define API_ERROR_USERCANCEL_CONNECTION																				2
#define API_ERROR_T3_OTSN																							3
#define API_ERROR_OT_T3SN																							4
#define API_ERROR_NOTCONNECTED																						5
#define API_ERROR_FXN_NOTIMPLEMENTED																				6
#define API_ERROR_INSUFFICIENT_MEMORY																				10
#define API_ERROR_OUTOFBOUNDARY																						15
#define API_ERROR_INVALIDPARAMETERS																					20
#define API_ERROR_INVALID_POINTER																					25
#define API_ERROR_DATASAMPLER_NOTRUNNING																			26

#define API_ERROR_NOTIN_TRACKINGMODE																				30
#define API_ERROR_DISTANCE_ERROR																					31
#define API_ERROR_USERCANCEL_COMMAND																				32
#define API_ERROR_QVC_REPEATABILITY_ERROR																			33
#define API_ERROR_QVC_NOTRUN																						34

#define API_ERROR_NESTREADING_SIGMA_OUTOFRANGE																		40
#define API_ERROR_NESTREADING_TIMEOUT																				41
#define API_ERROR_NESTREADING_DATASIZE_OUTOFRANGE																	42
#define API_ERROR_NESTREADING_FAILED																				43
#define API_ERROR_NESTREADING_ONGOING																				44
#define API_ERROR_OTHERMEASURE_ONGOING																				45
#define API_ERROR_INPOSITION_TIMEOUT																				46
// Encoder error codes
// Encoder calibration table doesn't exist
#define API_ERROR_NOENCODERCALTABLE																					201

// Level error codes
// Level calibration table doesn't exist
#define API_ERROR_NOLEVELCALTABLE																					221

// Bird bath manager error codes
// Bird bath information is not initialized
#define API_ERROR_NOBIRDBATHINFO																					241
#define API_ERROR_BIRDBATHOUTRANGE																					242

#define API_ERROR_NOIPSTS																							250

// PRM file error messages
//	"No Configuration File exists"
#define API_ERROR_TRACKERPRMFILENOTEXIST																			301

// "Wrong Format Prm File (Contact API)..(1)",	// Old format prm file
#define API_ERROR_TRACKERPRMFILEWRONGFORMAT																			302

#define API_ERROR_BUFFERTOOSMALL																					303
#define API_ERROR_TRACKERPRMFILENOTREAD																				304

// "Tracker object has not been initialized. "
#define API_ERROR_TRACKER_NOT_INITIALIZED																			310

//"Failed to log in the ftp server."
#define API_ERROR_FTPLOGIN_FAILED																					321

//	"Failed to download PRM file. "
#define API_ERROR_DOWNLOAD_PRM_FAILED																				322

//	"Failed to upload PRM file."
#define API_ERROR_UPLOAD_PRM_FAILED																					323

//	"Failed to download manufactory default PRM file. "
#define API_ERROR_DOWNLOAD_DEF_PRM_FAILED																			324
#define API_ERROR_DOWNLOAD_INI_FILE_FAILED																			325
#define API_ERROR_LOCAL_FOLDER_NOT_EXIST																			326
#define API_ERROR_UPDATE_PRM_FAILED																					327
#define API_ERROR_CREATE_LOCALFOLDER_FAILED																			328

#define API_ERROR_CONNECTION_FAILED																					331
#define API_ERROR_CONNECTING																						332
#define API_ERROR_NOPROCEDURETOSTOP																					351
#define API_ERROR_TIMEOUT																							352

// "Device is already connected."
#define API_ERROR_ALREADY_CONNECTED																					353

//"Tracker object binding failed."
#define API_ERROR_BINDFAILED																						354

//"Tracker object initialization failed. (90)",
#define API_ERROR_OBJECTFAILED																						355

//"Failed to connect to FTP server. (92)",
#define API_ERROR_PING_FAILED																						356

// "Failed to get response from controller. (93)",
#define API_ERROR_NORESPONSE																						357

// "Index search failed. (94)",
#define API_ERROR_INDEXSEARCH_FAILED																				358

// "Other procedure is on-going"
#define API_ERROR_OTHERTASK_ONGOING																					359

// "System Parameters have not been initialized. (360)"
#define API_ERROR_SYSTEMPARAM_NOT_INITIALIZED																		360

// "No procedure to abort"
#define API_ERROR_NOPROCEDURE_ABORT																					361

#define API_ERROR_ADMAUTOON_NORESPONSE																				362
#define API_ERROR_ADMAUTOOFF_NORESPONSE																				363
#define API_ERROR_IPROBE_CALIBRATION_ONGOING																		364
#define API_ERROR_HOME_FAIL																							369
#define API_ERROR_NO_SMR																							370

#define API_ERROR_JOG_TIMEOUT																						371
#define API_ERROR_AZ_OUTOF_POSRANGE																					372
#define API_ERROR_AZ_OUTOF_NEGRANGE																					373
#define API_ERROR_EL_OUTOF_POSRANGE																					374
#define API_ERROR_EL_OUTOF_NEGRANGE																					375
#define API_ERROR_STSAZ_OUTOF_POSRANGE																				376
#define API_ERROR_STSAZ_OUTOF_NEGRANGE																				377
#define API_ERROR_STSEL_OUTOF_POSRANGE																				378

#define API_ERROR_STSEL_OUTOF_NEGRANGE																				379

#define API_ERROR_LASER_WARMUP																						380

#define API_ERROR_SETPOINT_AIRPRESSURE_LOW																			381
#define API_ERROR_SETPOINT_AIRPRESSURE_HIGH																			382
#define API_ERROR_SETPOINT_AIRTEMPERATURE_LOW																		383
#define API_ERROR_SETPOINT_AIRTEMPERATURE_HIGH																		384
#define API_ERROR_SETPOINT_AIRHUMIDITY_LOW																			385
#define API_ERROR_SETPOINT_AIRHUMIDITY_HIGH																			386

#define API_ERROR_TGSEARCH_TIMEOUT																					400
#define API_ERROR_TGSEARCH_IDLE																						401
#define API_ERROR_TGSEARCH_TIDLE																					402

//"Target ADM Searching Failed........(403)"
#define API_ERROR_ADMSEARCH_FAILED																					403

//"Target is moving during ADM Search........(404)"
#define API_ERROR_ADMSEARCH_NONSTATIC																				404

//"Target is not tracking before ADM Search........(405)"
#define API_ERROR_ADMSEARCH_NONTRACK																				405

// "ADM distance is negative. (406)"
#define API_ERROR_ADM_NEGTIVE_DISTANCE																				406

// "ADM intensity is too low. (407)"
#define API_ERROR_ADM_LOW_INTENSITY																					407

// "ADM search time out. (408)"
#define API_ERROR_ADMSEARCH_TIMEOUT																					408

#define API_ERROR_ADMISCAN_OUTBAND																					409

// "Failed to get realtime data."
#define API_ERROR_READRTDATA_FAILED																					410

// "ADM auto set in ongoing."
#define API_ERROR_ADMAUTOSET_ONGOING																				411

//"Level X direction out of range. (410)",
#define API_ERROR_LEVELX_OUTOFRANGE																					430

//"Level Y direction out of range. (411)",
#define API_ERROR_LEVELY_OUTOFRANGE																					431

//"Tracker is not in tracking mode or the distance is not correct.",
#define API_ERROR_NOGOODDISTANCE																					440

// "Laser is warming up. (421)."
#define API_ERROR_WARMUP																							441

// "Laser intensity is low, can't track (422)."
#define API_ERROR_INTENSITYLOW																						442

// "Remote home failed (423)."
#define API_ERROR_REHOMEFAILED																						443

#define API_ERROR_CLOSEFAILED																						450

#define API_ERROR_LEDMANNOTINITIALIZED																				460

// " No channel defined for the data collection."
#define API_ERROR_NODATACHANNELDEFINED																				470

// " Zero data size defined for data collection."
#define API_ERROR_NODATASIZEDEFINED																					471

// " Other data collection procedure is running."
#define API_ERROR_OTHERDATACOLLECTIONRUNNING																		472

// " Data size is out of range."
#define API_ERROR_DATASIZEOUTOFRANGE																				473

// " Unknown/unsupported data collection mode."	
#define API_ERROR_UNKNOWNDATACOLLECTIONMODE																			474

// " Data collection initialization is not done."
#define API_ERROR_DATACOL_INCOMPLETE_INIT																			475

// " No tracker data collection process in process."
#define API_ERROR_NODATACOLLECTIONPROCESS																			476

// " FIFO data collection has already started."
#define API_ERROR_TRIGGERED																							477

// " Tracker sim task initialization failed."		
#define API_ERROR_SIMINITFAILED																						481

// " Tracker sim trigger set up failed."		
#define API_ERROR_SIMCREATEFAILED																					482

// " Tracker sim task creation failed."
#define API_ERROR_SIMTRIGSETUPFAILED																				483

// " Tracker sim task channel selection failed."
#define API_ERROR_SIMCHANNELSELFAILED																				484

// " Tracker sim task setting point number failed."
#define API_ERROR_SIMSETPTNUMFAILED																					485

// " Tracker starting sim task failed."
#define API_ERROR_SIMSTARTFAILED																					486

// " Tracker starting sim task failed."
#define API_ERROR_DATACOLLECTIONINITFAILED																			487

// " Can't abort the FIFO data collection process."
#define API_ERROR_NOABORTINFIFO																						489

// "Static data collection failed."
#define API_ERROR_DCSTATIC_FSIGHT_FAILED																			490

// "System function failed. (501)"
#define API_SYSTEM_FUNCTION_FAILED																					501

// Below is the error code for intelli-probe
// "Accessory measurement is out of the deviation band
#define API_ERROR_IPMEASURE_NOTSTABLE																				509

#define API_ERROR_IPMEASURE_OUTOFBAND																				510

// "Accessory tip offset is out of range
#define API_ERROR_IPOFFSET_OUTOFRANGE																				511

//"Calibration file for intelliprobe is not found. (512)",
#define API_ERROR_IPPRMFILE_NOTFOUND																				512

//"Incorrect calibration file format. (513)",
#define API_ERROR_IPPRMFILE_WRONGFORMAT																				513

//"Can't create empty file. (514)",
#define API_ERROR_IPEMPTYFILE_OPENFAILED																			514

//"No intelli-probe is detected. (515)",	
#define API_ERROR_NOIPDETECTED																						515

//"Accessory prm file is not read. (516)",
#define API_ERROR_IPPRMNOTREAD																						516

//"Accessory moved too much during offset calibration. (76)",
#define API_ERROR_IPNOTSTABLE_OFFSETCAL																				517

//"Accessory data rate is too slow during offset calibration. (518)",
#define API_ERROR_IP_DATERATE_SLOW																					518

//"Tracker is not tracking in the accessory. (519)",
#define API_ERROR_NOTTRACKINGIN_IP																					519

//"Accessory's position is out of range during globla calibration. (520)",
#define API_ERROR_IPGLB_POSITION_OUTOFRANGE																			520

//"Accessory's ruled optimizition failed. (521)",
#define API_ERROR_IPGLB_RULEDOPTIMIZATIONFAIL																		521

//"Accessory's accuracy check failed. (522)",
#define API_ERROR_IPGLB_ACCURACYCHECKFAIL																			522

#define API_ERROR_IPMEASURE_NOTREADY																				523

#define API_ERROR_IPMEASURE_TTL_FAILURE																		        526
#define API_ERROR_IPMEASURE_TIMEOUT																				    527

// "IScanner is not initialized."
#define API_ERROR_ISCANNER_NOTINITIALIZED																			540
#define API_ERROR_ISCANNER_SCANREADY_FAILED																			541
#define API_ERROR_ISCANNER_NOTDETECTED																				542
#define API_ERROR_ISCANNER_CALIBRATIONFAILED																		543

// Below is the error information for STS
#define API_ERROR_STSPRMFILE_NOTFOUND																				550

// "STS Prm file has not be read.
#define API_ERROR_STSPRMFILE_NOTREAD																				551
#define API_ERROR_NOSTS_DETECTED																					552
#define API_ERROR_STSPRMFILE_WRONGFORMAT																			553
#define API_ERROR_NOTTRACKINGIN_STS																					554

#define API_ERROR_OPENCAMERA_FAILED																					561
#define API_ERROR_OPENCAMERA_PRMFILE_NOTFOUND																		562

#define API_ERROR_ISCAN_PRMFILE_NOTFOUND																			570
#define API_ERROR_ISCAN_PRMFILE_FORMATWRONG																			571

#define API_ERROR_SIGMAMEASURE_NOTDONE																				580
#define API_ERROR_SIGMAMEASURE_NODATA																				581
#define API_ERROR_SIGMAMEASURE_DATAINVALID																			582

#define API_ERROR_NOTMEASURED																						583

#define API_ERROR_SNBLK_NOTFOUND																					601
#define API_ERROR_SNBLK_NOTMATCH																					602

#define API_ERROR_VIRTUALLEVEL_NOTFOUND																				669

#define API_ERROR_ADMLATERALBLK_NOTFOUND																			671
#define API_ERROR_ADMLATERALBLK_NOTMATCH																			672

#define API_ERROR_SFACTOR2BLK_NOTFOUND																				673
#define API_ERROR_SFACTOR2BLK_NOTMATCH																				674

#define API_ERROR_IPROLLTABLE_NOTFOUND																				675
#define API_ERROR_IPROLLTABLE_NOTMATCH																				676
	
#define API_ERROR_IPYAWTABLE_NOTFOUND																				677
#define API_ERROR_IPYAWTABLE_NOTMATCH																				678

#define API_ERROR_VIRTUALLEVEL_DISABLED																				681

// "Start TTL failed."
#define API_ERROR_STARTTTL_FAILED																					701
#define API_ERROR_STOPTTL_FAILED																					702

//"Accessory encoder index search is not finished"
#define API_ERROR_IPROBE_INDEXSEARCH_NOT_COMPLETE																	706

#define API_ERROR_FAILED_GETFILESTATUS																				800
#define API_ERROR_FAILED_CREATEFILE																					801
//"Mask set for data capture mode is incorrect"
#define API_ERROR_DATA_MASK_INCORRECT																				802

//"The controller cannot be set or reset to diagnostic mode"
#define API_ERROR_SET_RESET_T4_DIAGNOSTIC																			803

//"The controllet cannot transmit TCKDIAGDATA packet"
#define API_ERROR_TCKDIAGDATA_PACKET																				804

//"This function is deprecated"
#define API_ERROR_FUNCTION_DEPRECATED																				805

//"This API Laser Tracker does not have Innovo Camera" 
#define API_ERROR_INNOVO_CAMERA_NOT_PRESENT																			806

//"Communication channel could not be created"
#define API_ERROR_NO_DATA_COMMUNICATION_CHANNEL																		807

//"The API Laser Tracker Servo motor power is turned off"
#define API_ERROR_SERVO_OFF																							808

//"This data collection mode is not supported"
#define API_ERROR_DATA_COLLECTION_MODE_UNSUPPORTED																	809

//"Multi SMR Innovo camera operation is not supported" 
#define API_ERROR_MULTI_SMR_INNOVO_MODE_UNSUPPORTED																	810

//"Accessory single point data collection mode is not enabled"
#define API_ERROR_IPROBE_NOT_IN_IPMEASUREMODE																		811

//"This function is reserved for future use"
#define API_ERROR_RESERVED_FUNCTION																					812

//"Cannot start accessory tip offset verification"
#define API_ERROR_IPOFFSET_VERIFY																					813

//"Cannot start accessory in-field calibration"
#define API_ERROR_IPTIP_INFIELDCAL																					814

//"Accessory tip offset calibration is not successful"
#define API_ERROR_IPTIPOFFSETCAL_NOTDONE																			815

//"This feature is not supported"
#define API_ERROR_FEATURE_NOT_SUPPORTED																				816

//"This function is already running"
#define API_ERROR_FUNCTION_RUNNING																					817

//"Innovo Multi SMR mode has finished measuring all visible targets"	
#define API_INNOVO_MULTISMR_DONE																					818			
																				
//"You need to 'home' the API Laser Tracker!"
#define API_ERROR_SYSTEM_NEVER_HOMED																				819

//"Homing operation failed during Virtual Level!"
#define API_ERROR_HOME_FAILED_DURING_VIRTUAL_LEVEL																	820

//"Teaching plan does not exist in the input directory"
#define API_ERROR_INNOVO_TEACHING_PLAN_NO_EXIST																		821

//"Cannot start Innovo Teaching mode"
#define API_ERROR_INNOVO_TEACHING_ERROR																				822

//"Innovo Teach2Drive mode has finished all targets"	
#define API_INNOVO_TEACH2DRIVE_DONE																					823

//"Innovo Teaching Mode Done"	
#define API_INNOVO_TEACHING_DONE																					824

//"Error in loading teaching plan in the teaching mode" 
#define API_ERROR_INNOVO_LOADING_TEACHING_PLAN																		825

//"Number of iterations in is incorrect"
#define API_ERROR_INNOVO_TEACHING_ITER																				826

//"Current iVision application does not support this mode"
#define API_ERROR_IVISION_MODE_NEEDS_CURRENT_IVISION_APP															827

//"This accessory tip is not defined"
#define API_ERROR_IPROBE_TIP_NOT_DEFINED																			828
//"The application failed to get response from API Laser Tracker"
#define API_ERROR_FAILED_RESPONSE_FOR_COMMAND																		829

#endif