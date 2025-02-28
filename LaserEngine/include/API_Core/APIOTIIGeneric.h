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

#ifndef _APIOTIIGeneric_
#define _APIOTIIGeneric_

#include <windows.h>
namespace APIOTII
{
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
#define QVC_AveragingTime							5
#define nearzero									1.0e-20
#define nearinfinity								1.0e12
#define No											0
#define Yes											1
#define Fail										2
#define Inter										3
#define	FILTER_K8									8.0
#define	FILTER_K4									4.0
#define	PacketHeader								0x80
#define	PacketFooter								0x81
#define	ERR_COUNT_LIMIT								15 
#define CRITICALANGLE								0.002						// change to 0.001 for testing, need change to 0.002 for real
//#define	MINADMINTENSITY								0.15						// the lowest adm intensity
//#define	WARNADMINTENSITY							0.15						// the warning range adm intensity
//xw@111913- according to Helen set 0.10, for avoiding a long distance beam separation.
#define	MINADMINTENSITY								0.15						// the lowest adm intensity
#define	WARNADMINTENSITY							0.1						// the warning range adm intensity
#define ADMREFCRITERIA1								0.25						// in case of wrong prm file
#define ADMREFCRITERIA2								0.10						// in case of wrong prm file
#define ADMWARMUPRATE								0.03
#define ADMWARMUPTIME								1.0
#define SEARCHTIMEOUT								4000L
#define	MAXLENGTH_PATH								255
#define JOG_TIMEOUT									10000L
#define EXPFILTER_MAXV								10.0						// mm/s, cutoff exp filter if the SMR velocity is over this value
#define EXPFILTER_MINV								5.0							// mm/s, ramp exp filter weight between (EXPFILTER_MINV, EXPFILTER_MAXV)
#define PI											3.1415926
#define ARCSecToRadian								1.0/3600/180*PI
#define	No_of_SysParams								135
#define Number_of_Factors							24
#define Number_of_Functions							20
#define MAX_SERIAL_ID								99999
#define MAX_CONNECTION								100
#define OMNITRAK_II	

// General Command set
#define	ADMVELCOMP_ON								x0001					// Turn on the velocity compensation
#define	ADMVELCOMP_OFF								0xfffe					// Turn off the velocity compensation
// End of General Command set

#define	ABCDATANUM									50						// average number in ABC procedure
#define	ABCFILTERBAND								5						// 10 percent filter band
#define	ABCSAMPLEINTERVAL							20L						// ABC sample interval
#define	PACKSIZE									56
#define ADM_GATETIME								32		

#define	RTWORKEREXITCODE							101
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
	
#define DEFAULT_JOG_TIMEOUT							10000
#define API_AVERAGE_TIME							2000					// 2 seconds
//Macro definitions for all Optical Reference parameters
#define	OPTIC_REF_BUFFER_LENGTH				1000 

#define MAX_TREND_DATA_BUFFER_SIZE					5200
#define REDUCED_TREND_DATA_BUFFER_SIZE			650
#define TREND_DATA_BUFFER_REDUCING_FACTOR	8
#define MAX_TREND_DATA_WINDOW_SIZE					13
#define	MILLISEC_TO_HOUR_CONV_FACTOR				(3600.0*1000.0)
#define mmHG_TO_PASCAL								133.332;

#pragma pack(push, 8)
// for dual channels of data
/// \defgroup structures API Defined Data Types
/// \brief List of API defined data types
/*! \addtogroup structures
* @{
*/
/// Structure for 2D vectors of type double 
typedef struct D_VECTOR2 {
	double x;
	double y;
} DVECTOR2, *LPDVECTOR2, *LPD_VECTOR2;

/// Structure for 2D vectors of type float
typedef struct F_VECTOR2 {
	float x;
	float y;
} FVECTOR2, *LPFVECTOR2, *LPF_VECTOR2;

/// Structures for 2D vectors of type int
typedef struct I_VECTOR2 {
	int x;
	int y;
} IVECTOR2, *LPIVECTOR2, *LPI_VECTOR2;
/*! @} */

typedef struct DUAL_LEVEL {
	float level_x;
	float level_y;
} *LPDUAL_LEVEL;

/*! \addtogroup structures
* @{
*/
/// Structure for 4D vectors of type double
typedef struct D_VECTOR4 {
	double x;
	double y;
	double z;
	double w;
} DVECTOR4, *LPDVECTOR4, *LPD_VECTOR4;

/// Structure for 4D vectors of type float
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

/// Structure for 4D vectors of type int
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
/// Structure for 3D vectors of type double
typedef struct D_VECTOR3{
	double x;
	double y;
	double z;
} *LPD_VECTOR3, DVECTOR3;

/// Structure for 3D vectors of type float
typedef struct F_VECTOR3{
	float x;
	float y;
	float z;
} *LPF_VECTOR3, FVECTOR3;

/// Structure for 3D vectors of type int
typedef struct I_VECTOR3{
	int x;
	int y;
	int z;
} *LPI_VECTOR3, IVECTOR3;

/// Structure to define 6DoF data.
typedef struct D_VECTOR6{
	double	x;	///< x - coordinate in mm
	double	y;	///< y - coordinate in mm
	double	z;	///< z - coordinate in mm
	double pitch;	///< pitch angle in degree
	double roll;	///< roll angle in degree
	double yaw;		///< yaw angle in degree
	/// Default constructor
	D_VECTOR6():x(0.0),y(0.0),z(0.0),pitch(0.0),roll(0.0),yaw(0.0)
	{
	}

} DATA_6DOF;

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
/*! @} */

// Jogging Operation
/*! \addtogroup structures
* @{
*/
/// Structure containing information about the jogging position
typedef struct TARGET_JOG{
	bool	JogMode;			///< true:Absolute Jogging, false:Incremental Jogging
	float	Azimuth;			///< Azimuth Jogging Target
	float	Elevation;			///< Elevation Jogging Target
	bool	InPosition;			///< true:Check the in-positioning, false:Fly on the jog operation
} *LPTARGET_JOG;

/// Structure containing information about the jogging position. This is an extended structure of the TARGET_JOG structure
typedef struct TARGET_EXTENDED{
	bool    JogMode;
	bool	InPosition;			///< true:Check the in-positioning, false:Fly on the jog operation
	float	Azimuth;			///< Azimuth Jogging Target
	float	Elevation;			///< Elevation Jogging Target
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

/// Structure to jog the STS first correspoding to STS Az and El and then tracker will point to the given coordinates by x, y, z.
typedef struct TARGET_CARTESIAN{
	bool	InPosition;	
	float	x;					// coordinate x
	float	y;					// coordinate y
	float	z;					// coordinate z
	float	tg_AZ;				// STS Az
	float	tg_EL;				// STS El
} *LPTARGET_CARTESIAN;
/*! @} */
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

/*! \addtogroup structures
* @{
*/
/// Structure used in remote home operation
typedef struct RESET_CARTESIAN{
	float	Reset_Position_X;						///<	X in mm
	float	Reset_Position_Y;						///<	Y in mm
	float	Reset_Position_Z;						///<	Z in mm
	float	Reset_Position_AZ;						///<	Azimuth in Degree
	float	Reset_Position_EL;						///<	Elevation in Degree
	bool	TrueIFM;								///<	Record the current TrueIFM flag
	int		nCoordinate;							///<	0, Cartesian; 1, Polar
} *LPRESET_CARTESIAN, CARTESIAN_DATA;
/*! @}*/

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

/*! \addtogroup structures
* @{
*/
/// Structure used in CAPIDevice::PointTo function
typedef struct {
	bool	InPosition;	///< Must be set to true
	float	x;		///< coordinate x
	float	y;		///< coordinate y
	float	z;		///< coordinate z
} TARGET_Cartesian;
/*! @}*/
typedef struct {
	bool	InPosition;
	float	Azimuth;			///< Azimuth Jogging Target
	float	Elevation;			///< Elevation Jogging Target
	float	Distance;			///< Distance
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
	bool Warm_Up_Time;				//	true:System Initializing; false:System is ready.
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

/*! \addtogroup structures
* @{
*/
/// Enumeration defining tracker operation mode
enum OPERATION_MODE {
OP_Idle = 0,							///< idle mode. This mode means no power output from the gimbal
	OP_Position,							///< position mode. This mode holds the gimbal at the current position
	OP_Track,								///< tracking mode. This mode allows the laser tracker to track the targets and take measurements
	OP_TIdle,								///< track_idle mode. This mode is when the tracker is ready for tracking but no reflector is found.
	OP_IndexSearch = 5,						///< index search mode. In this mode laser tracker is searching for the encoder zero position
	OP_SpiralSearch = 7,					///< spiral search mode. Tracker is searching for the reflector.
	OP_CameraSearch = 9						///< Tracker is in camera mode to search the SMR.
};
/*! @}*/

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
/*! \addtogroup structures
* @{
*/
/// Structure defining FIFO information during data collection
typedef struct FIFO_INFO{
	unsigned long	Captured_Points;							//	Captured Number Of Points in the FIFO.
	unsigned long	Retrieved_Points;							//	Retrieved Number Of Points from the FIFO.
} *LPFIFO_INFO;

/// Structure defining the real time tracker information
typedef struct {
	///<	Part 1, general tracker channels	
	bool					Warm_Up_Time;								///< System warmpup status. "true": System Warming-Up; "false": System is ready.
	bool					Laser_Path_Error;							///< Laser path error status. "true": Laser Beam-Path Error; "false": Laser Beam-Path is O.K.
	bool					Laser_Dist_Error;							///< Laser distance error status. "true": Laser Distance Status Error; "false": Distance Status is O.K.
	bool					External_Switch;							///< "true": External Switch Contact; "false:External Switch Open
	bool					Filtering_Switch;							///< "true": Filtering Switch On; "false": Filtering Switch Off
	bool					TrueIFM;									///< "true": IFM has not been updated with ADM.	"false": IFM has ever been updated by ADM
	bool					bWeather;									///< "true": weather station attached; "false": no weather station.
	bool					bFrontSight;

	OPERATION_MODE			Operation_Mode;								///<	Tracker Operation Mode
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
	
	DWORD					Time_Stamp;									///< Tracker Time Stamp in ms
	float					Laser_Intensity;							///< The Laser intensity is between 0.0-1.0
	float					Laser_Distance;								///< IFM distance in mm. If the tracker mode is not in the Tracking Mode, the Laser Distance is 0.
	float					Laser_Distance_Filter;						///< If the tracker mode is not in the Tracking Mode, the Laser Distance is 0.
	float					Current_Position_AZ;						///< Azimuth angle of the tracker in Degree
	float					Current_Position_EL;						///< Elevation angle of the tracker in Degree
	float					Current_Position_AZ_Filter;					///< Filter Azimuth in Degree
	float					Current_Position_EL_Filter;					///< Filter Elevation in Degree
	float					Air_Temperature;							///< Weather Sensor Information : Air Temperature (Centigrade) 
	float					Air_Pressure;								///< Weather Sensor Information : Air Pressure	 (mm/Hg)
	float					Air_Humidity;								///< Weather Sensor Information : Air Humidity
	float					Current_Position_X;							///< X coordinate in mm
	float					Current_Position_Y;							///< Y coordinate in mm
	float					Current_Position_Z;							///< Z coordinate in mm
	float					Current_Position_X_Filter;					///< Filter X in mm
	float					Current_Position_Y_Filter;					///< Filter Y in mm
	float					Current_Position_Z_Filter;					///< Filter Z in mm
	float					Target_Velocity;							///< Target Velocity (mm/msec)
	float					Photo_X;									///< Calibrated Photo Sensor Eccentric in mm (X-direction)
	float					Photo_Y;									///< Calibrated Photo Sensor Eccentric in mm (Y-direction)
	float					MatTemp[4];									///<	Material temperature	 
	float					fUncalibratedDistance;
	float					Level_X;									///< Calibrated Level Sensor in ArcSec (X-direction)
	float					Level_Y;									///< Calibrated Level Sensor in ArcSec (Y-direction)
	bool					LevelX_OverLimit;							///< "true": Out of the limit "false": Within limit
	bool					LevelY_OverLimit;							///< "true": Out of the limit "false": Within limit
	
	// ADM data	
	float					ADM_Intensity;								///< ADM intensity
	float					ADM_Temp1;									///< ADM Temperature channel 1
	float					ADM_Temp2;									///< ADM Temperature channel 2
	float					ADM_Tube_Intensity;							///< ADM tube intensity
	float					ADM_Tube_Temp;								///< ADM Tube temperature
	float					ADM_Distance;								///< ADM Distance in mm
	int						admstate;									///< indicate adm weather compensation state. 1: on; 0: off.
	bool					AdmIntensityLow;							///< warning flag. true: adm intensity too low ( < 0.15); false: adm intensity ok.
	bool					AdmNoReading;								///< adm intensity too low, can't be used
	bool					AdmHWFail;									///< adm hardware failure flag
	bool					AdmReferenceWarning;						///< true, adm needs to redo referencing. false, adm is well referenced	
	// end ADM
	
	// 6D target STS channels
	bool					TGLevelX_OverLimit;							///< true:Out of the limit false:Within limit
	bool					TGLevelY_OverLimit;							///< true:Out of the limit false:Within limit
	short					Status;										///< Target Status/IP button status
	float					TgTilt_X;									///< Target tilt angle at X direction
	float					TgTilt_Y;									///< Target tilt angle at Y direction
	float					TgPos_AZ;									///< Target current az angle 
	float					TgPos_EL;									///< Target current el angle	
	float					NormalVec_I;								///< i. Internally used variable
	float					NormalVec_J;								///< j. Internally used variable
	float					NormalVec_K;								///< k. Internally used variable
	float					dpitch;										///< relative pitch
	float					dyaw;										///< relative	yaw
	float					droll;										///< relative roll
	float					HzAngle;									///< Internally used variable
	float					VtAngle;									///< Internally used variable
	float					tgAirTemp;
	
	// part 4, intelliprobe channels
	D_VECTOR3				Probe_Attitude;								///< Probe angles. This is used for STS, Probe, Scanner to give 6dof angles. x: Pitch, y: Yaw: z: Roll
	D_VECTOR4				PhotoReading;								///< Photo reading of the probe. Internally used
	D_VECTOR3				ProbeTip_Position;							///< Probe tip position in Inspect, Scan and Measure mode
	F_VECTOR3				IP_RTTip;									///< realtime tip position in accessory inspect mode
	F_VECTOR3				ResetPosition;								///< To record the position x, y, z for remote home operation
	long					ProbeTS;									///< Time stamp for IntelliProbe
	int						wCmd;										///< Internally used variable
	int						status_ind;									///< Internally used variable

	float					fEncRoll;									///< probe raw encoder roll value
	float					fEncYaw;									///< probe raw encoder yaw value
	float					fCentroidX;									///< probe optics centroid X value
	float					fCentroidY;									///< probe optics centroid Y value	
	short					sTriggerIP;									///<	TTL Trigger Counter
	short					sTriggerT3;									///<	TTL Trigger Counter
    bool					bProbeTrigger;								///<	true: on; false: off
	bool					b_ValidTip;
	bool					bIsLaserLockonIP;							///<	true: laser beam is on probe; false: laser beam is not 
																		///<	on probe, could be on SMR or not trackign at all	
	
	// IP3	
	unsigned short			usCamFrameCounter;							///<	Camera Frame Counter
	BYTE					camStatus;									///< cam status. Internally used variable
	BYTE					auxStatus;									///< auxillary status. Internally used variable
	BYTE					pwrStatus;									///< power status. Internally used variable
	BYTE					pciStatus;									///< PIC status. Internally used variable
	BYTE					encStatus;									///< Encoder status. Internally used variable

	bool					bOpticalRefSwitchOn;						///< Indicates if optical reference switch is On or Off
	float					fOpticalRefRealTimeOffset;					
	float					fOpticalRefRealTimeLength;
	float					fOpticalTempSensor1;
	float					fOpticalTempSensor2;
	DWORD					ADM_Frequency;
	float					fOpticalRefTrendCoef0;
	float					fOpticalRefTrendCoef1;
	unsigned short			usBatteryStatus;
	unsigned short			usSignalStrength;
	BYTE					probeTip;									///< Indicate which probe tip is selected 

} REALTIME_INFO;
/*! @}*/

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
	FVECTOR4 BasePhoto;
	FVECTOR2 RawEncoder;
}REALTIME_INFO_INTERNAL;

//#pragma pack(8)
typedef struct {
	DWORD			Time_Stamp;													//	Tracker Time Stamp in ms
	OPERATION_MODE	Operation_Mode;												//	Tracker Operation Mode
																				//	0 -> Servo Free Mode (Idle)
																				//	1 -> Servo Engaged Mode (Servo)
																				//	2 -> Tracking Mode (Track)
																				//	3 -> Losing target during Tracking (Track Idle)
																				//	4 -> Not Used by API user (Internal Use Only)
																				//	5 -> Searching the Encoder Index (Index Searching)
																				//	6 -> Not Used by API user (Internal Use Only)
																				//	7 -> Target Scan Search Mode (Search)
	float			Laser_Distance;												//	If the tracker mode is not in the Tracking Mode, the Laser Distance is 0.
	float			Current_Position_AZ;										//	Azimuth in Degree
	float			Current_Position_EL;										//	Elevation in Degree
	float			Current_Position_X;											//	X in mm
	float			Current_Position_Y;											//	Y in mm
	float			Current_Position_Z;											//	Z in mm
	float			Level_X;													//	Calibrated Level Sensor in ArcSec (X-direction)
	float			Level_Y;													//	Calibrated Level Sensor in ArcSec (Y-direction)
	bool			LevelX_OverLimit;											//	true:Out of the limit false:Within limit
	bool			LevelY_OverLimit;											//	true:Out of the limit false:Within limit
	bool			ErrorInfo;													//	Distance Error status

	//channels for ADM tracker data collection
	float			ADM_Distance;
	float			ADM_LaserIntensity;
	float			ADM_TubeIntensity;
	float			ADM_Temperature1;
	float			ADM_Temperature2;
	float			ADM_TubeTemperature;
	//end of ADM data
	
	float			AirPressure;
	float			AirTemperature;

	// add channels for Intelliprobe
	D_VECTOR3		Probe_Attitude;
	D_VECTOR4		PhotoReading;
	D_VECTOR3		ProbeTip_Position;
	//	Channels for 6d target
	float			TgPos_AZ;						//	Target current az angle 
	float			TgPos_EL;						//	Target current el angle
	bool			TGLevelX_OverLimit;				//	true:Out of the limit false:Within limit
	bool			TGLevelY_OverLimit;				//	true:Out of the limit false:Within limit
	float			NormalVec_I;					//	i
	float			NormalVec_J;					//	j
	float			NormalVec_K;					//	k
	// Probe / 6D target status
	// For intelliprobe, this is for trigger button press status
	// for 6D, this is for Target operation mode
	short			Status;							//	Target Status
	float			TgTilt_X;
	float           TgTilt_Y;
	long			ProbeTS;						//	time stamp for IntelliProbe
} FIFO_RECORD;

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
	
	//begin - extras for Optical Reference
	double			OpticTempSensor1;
	double			OpticTempSensor2;
	double			OpticTrendCoef0;
	double			OpticTrendCoef1;
	// Add two more channels for weather station (air temperature and air pressure)
	double			AirPressure;
	double			AirTemperature;
	double			MatTemperature[4]; //Added extra channel for material temperature
	double			IP3_Pitch;
	double			IP3_Yaw;
	double			IP3_Roll;
	double			IP3_Enc_Roll;
	double			IP3_Enc_Yaw;
	double			IP3_TipX;
	double			IP3_TipY;
	double			IP3_TipZ;
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
// socket
union Char2F
{
	char		ch[56];
	float		value[12];
};

union Char2I
{
	char		ch[12];
	int			value[3];
};
//////////////////////////////////////////////////////////////////////////
// Union used in socket
// AC 12/17/2002
// Used for 6D tracker
// Totally 8 channels
// 1~3: Cartesian coordinate: X, Y, Z
// 4~6: Target attitude angles: alpha, beta, gama
// 7: Tracker status
// 8: Target operation mode
//		0 -> Servo Free Mode (Idle)
//		1 -> Servo Engaged Mode (Servo)
//		2 -> Tracking Mode (Track)
//		3 -> Losing target during Tracking (Track Idle)
//		4 -> Not Used by API user (Internal Use Only)
//		5 -> Searching the Encoder Index (Index Searching)
//		6 -> Not Used by API user (Internal Use Only)
//		7 -> Target Scan Search Mode (Search)
// 9: Tracker status
// 10: Interferometer intensity
typedef struct {

	D_VECTOR3				TckCoordinate;
	D_VECTOR3				TgAngles;
	BYTE					SysStatus;
	BYTE					TgMode;
	BYTE					TckStatus;
	float					Laser_Intensity;

} ETHER_DATA, *LP_ETHER_DATA;
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
/*! \addtogroup structures
* @{
*/
/// Enumeration defining tracker adm type
enum TRACKER_ADM_TYPE {
	ADM_PLUS_IFM = 0,		///< Tracker with both IFM and ADM
	ADM_ONLY = 1			///< Tracker with ADM Only
};
/*! @}*/

/*! \addtogroup structures
* @{
*/
/// Enumeration defining the tracker type which is actively connected
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
/*! @}*/

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
	float													materialTemp[4]; //added extra temperature sensor channel

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

	// channels for intelliprobe
	IPROBE3_DATA									ip3Data;

	bool													bOpticalRefSwitchOn;
	float													fOpticalTempSensor1;
	float													fOpticalTempSensor2;
	DWORD											ADM_Frequency;

	//extras for vProbe working
	FVECTOR2										VProbeData;
	DWORD											VProbeIntensity;
	DWORD											VProbeIdentifier;													
} TCKESSENTIALDATA, *LPTCKESSENTIALDATA;

///////////////////////////////////////////////////////////////////////////
// tracker DIAGNOSTIC data packet
///////////////////////////////////////////////////////////////////////////
typedef struct {

	ENC_VECTOR													lj;									//lissajous information
	I_VECTOR2													AQB;
	FVECTOR2													AQBOff;
	FVECTOR2													PE;
	float														AzSpeed;
	float														ElSpeed;
	bool														Laser_Path_Error;					//	true:Laser Beam-Path Error; false:Laser Beam-Path is O.K. 
	F_VECTOR4													EnvData;							//	store the environment variables
	float														ivision_x;
	float														ivision_y;
	float														ivision_int;
	TCKESSENTIALDATA											RealTime;							//  Real time data structure inside the diagnostic data S.C. 9-15-14
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


typedef struct {
	long* CurPosX;
	long* CurPosY;
	long* CurPosZ;
	long* CurPosW;

	long* BasePhotoX;
	long* BasePhotoY;
	long* BasePhotoZ;
	long* BasePhotoW;

	long* TgPhotoX;
	long* TgPhotoY;
	long* TgPhotoZ;
	long* TgPhotoW;

	long* Laser;

	long* BaseTiltX;
	long* BaseTiltY;

	long* TgTiltX;
	long* TgTiltY;

	// new channels; for weatherstation
	long* airTemp;
	long* airPressure;
	long* airHumidity;
	long* materialTemp;
} BUFTCKESSENTIALDATA;

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
	V_PROBE
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
	VIDEO_MODE_ON
}INNOVO_CAMERA_MODE;

typedef enum {
	OPTICAL_SWITCH_OFF,
	OPTICAL_SWITCH_ON,
	OPTICAL_SWITCH_PAUSE,
	OPTICAL_SWITCH_FORCE,
	OPTICAL_SWITCH_MONITOR,
}OPTICAL_SWITCH_MODE;
/////////////////////////////////////////////////////////////////////
// data mask selector data structure
//////////////////////////////////////////////////////////////////////
// fiddle bit to one for channel selection

#define MAX_SIMTASK 10


/*! \addtogroup structures
* @{
*/
/// Union defining data masks for data collection.

typedef union {
	ULONG _int;
	struct {
		UINT TimeStamp : 1; ///< Timestamp of Traker is included collection of data requested. 
		UINT OpMode : 1; ///< operating mode of tracker is included
		UINT BaseEl : 1; ///< Tracker azimuth angle
		UINT BaseAz : 1; ///< Tracker elevation angle
		UINT TgEl : 1; ///< Connected accessory elevation angle
		UINT TgAz : 1; ///< Connected accessory azimuth angle
		UINT Laser : 1; ///< Laser distance
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
/*! @}*/

typedef union {
	DWORD64 _int;
	struct {
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
		//////////////////////////////////////////////////////////////////////
		//New material temp
		UINT Mat_Temp4 : 1;
		///////////////////////////////////////////////////////////////////////
		UINT AdmIntensity	: 1;
		UINT AdmDistance	: 1;
		UINT AdmTemp1		: 1;
		UINT AdmTemp2		: 1;
		UINT TubeIntensity : 1;
		UINT TubeTemperature : 1;
	
		////////////begin - extras for Optical Reference
		UINT OpticTempSensor1 : 1;
		UINT OpticTempSensor2 : 1;
		UINT OpticTrendCoef0 : 1;
		UINT OpticTrendCoef1 : 1;
		////////////end - extras for Optical Reference

		UINT IP3Pitch : 1;
		UINT IP3Yaw : 1;
		UINT IP3Roll : 1;
		UINT IP3EncRoll : 1;
		UINT IP3EncYaw : 1;
		UINT IP3TipX : 1;
		UINT IP3TipY : 1;
		UINT IP3TipZ : 1;
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

/*! \addtogroup structures
* @{
*/
/// Enumeration defining tracker data collection modes
typedef enum {

	TCK_CAPTURE_IDLE = 0,					///< No data collection mode is running
	TCK_CAPTURE_FIFO,						///< Not supported
	TCK_CAPTURE_STATIC_FSIGHT,				///< Realtime static frontsight data capturing
	TCK_CAPTURE_STATIC_FBSIGHT,				///< Realtime static frontbacksight data capturing
	TCK_CAPTURE_STATIC_FSIGHT_AUTO,			///< Realtime static frontsight data capturing with automatic triggering
	TCK_CAPTURE_STATIC_FBSIGHT_AUTO,		///< Realtime static frontbacksight data capturing with automatic triggering
	TCK_CAPTURE_DYNAMIC_TEMPORAL,			///< Capture dynamic temporal data
	TCK_CAPTURE_DYNAMIC_SPATIAL,			///< Capture dynamic spatial data
	TCK_CAPTURE_STATIC_SIGMA,				///< Capture single point static measurement with filtering
	TCK_CAPTURE_DYNAMIC_DISTANCE,			///< Capture dynamic data based on distance
	TCK_CAPTURE_DYNAMIC_TIME,				///< Capture dynamic data based on time
	TCK_CAPTURE_NEST_READING,				///< Capture nest reading data. Reserved for internal use
	TCK_CAPTURE_SCAN,						///< Capture scanning data during iscan scanning
	TCK_CAPTURE_EVENT_ONLY,					///< Capture data in TTL triggering mode
	TCK_CAPTURE_TEMPORAL_RATEFILTER,		///< Capture dynamic time based data with filtering
	TCK_CAPTURE_DYNAMIC_RATEFILTER			///< Capture dynamic time based data with filtering without need to predefine number of points


} TCK_CAPTUREMODE;
/*! @}*/

typedef union {
	float _gdFloat;
	int   _gdInt;
} GDATCAP_TYPE;

///////////////////////////////////////////////////////////////////////////
// Device task enum type
///////////////////////////////////////////////////////////////////////////
/*! \addtogroup structures
* @{
*/
/**
*	@brief Device task enumeration type
*	@details This ID number is used to identify the task which just finished. It is sending back with the Callback function.
*		This value does not need to be checked for each operation. However, certain subsequent function calls need to be followed after the callback function. 
*		In most of the cases, only one command can be issued at one time. If one task is not finished and another command is issued, an error code will return.
*/
typedef enum {
	APIDEVICE_IDLE = 0,						///< This ID will never return from the DI. It is an internal state only.
	APIDEVICE_CONNECT,						///< This ID corresponds to the call of function CAPIDevice::Connect()
	APIDEVICE_DISCONNECT,					///< This command is reserved and not used in this package
	APIDEVICE_HOME,							///< This ID corresponds to the call of function CAPIDevice::Home()
	APIDEVICE_JOGBY,						///< This ID corresponds to the call of function CAPIDevice::JogBy().
	APIDEVICE_JOGTO,						///< This ID corresponds to the call of function CAPIDevice::JogTo().
	APIDEVICE_POINTTO,						///< This ID corresponds to the call of function CAPIDevice::PointTo().
	APIDEVICE_SPIRAL_SEARCH,				///< This command is reserved for DI internal use. 
	APIDEVICE_ADM_SEARCH,					///< This command is reserved for DI internal use. 
	APIDEVICE_TARGET_SEARCH,				///< This ID corresponds to the call of function CAPIDevice::TargetSearch().
	APIDEVICE_ACC_SEARCH,					///< This ID corresponds to the call of function CAPIDevice::AccSearch().
	APIDEVICE_VIRTUAL_LEVEL,				///< This ID corresponds to the call of function CAPIDevice::VirtualLevel().
	APIDEVICE_NESTREADING,					///< This command is reserved for DI internal use.
	APIDEVICE_ADMBEAMOFFSET,				///< This command is reserved for DI internal use.
	APIDEVICE_REMOTEHOME,					///< This ID corresponds to the call of function CAPIDevice::RemoteHome().
	APIDEVICE_BKSIGHT_OPERATION,			///< This ID corresponds to the call of function CAPIDevice::BKSightOperation().
	APIDEVICE_BKSIGHT_CHECKING,				///< This ID corresponds to the call of function CAPIDevice::BKSightChecking().
	APIDEVICE_QVC,							///< This command is reserved for DI internal use.
	APIDEVICE_SWITCH_IDLE,					///< This ID corresponds to the call of function CAPIDevice::SwitchToIdle().
	APIDEVICE_SWITCH_POSITION,				///< This ID corresponds to the call of function CAPIDevice::SwitchToPosition().
	APIDEVICE_SWITCH_TRACK,					///< This ID corresponds to the call of function CAPIDevice::SwitchToTrack().
	APIDEVICE_SWITCH_TRACK_TUNE,			///< This command is reserved for DI internal use.
	APIDEVICE_POWER_ENABLE,					///< This ID corresponds to the call of function CAPIDevice::PowerEnable().
	APIDEVICE_POWER_DISABLE,				///< This ID corresponds to the call of function CAPIDevice::PowerDisable().
	APIDEVICE_INDEX_SEARCH,					///< This ID corresponds to the call of function CAPIDevice::IndexSearch(). 
	APIDEVICE_STS_INDEX,					///< This command is reserved for DI internal use.
	APIDEVICE_STS_JOGBY,					///< This ID corresponds to the call of function CAPIDevice::StsJogBy(). 
	APIDEVICE_STS_JOGTO,					///< This ID corresponds to the call of function CAPIDevice::StsJogTo().
	APIDEVICE_IP_SINGLEMEAS,				///< This ID corresponds to the call of function CAPIDevice::AccMeasure().
	APIDEVICE_IP_OFFSETCAL,					///< This command is reserved for DI internal use.
	APIDEVICE_IP_GLBMODEL,					///< This command is reserved for DI internal use.
	APIDEVICE_IS_SCAN,						///< This ID corresponds to the call of function CAPIDevice::ISScan.
	APIDEVICE_IP_SCAN,						///< This ID corresponds to the call of function CAPIDevice::AccScan().
	APIDEVICE_HOLD_POSITION,				///< This command is reserved for DI internal use.
	APIDEVICE_IP_INSPECT,					///< This ID corresponds to the call of function CAPIDevice::AccInspect().
	APIDEVICE_JOG_SEARCH,					///< This command is reserved for DI internal use.
	APIDEVICE_EXTERNAL_TRIGGER,				///< This command is reserved for DI internal use.
	APIDEVICE_WIRELESS_LOOPBACK,			///< This command is reserved for DI internal use.
	APIDEVICE_DISABLE_WIRELESS_LOOPBACK,	///< This command is reserved for DI internal use.
	APIDEVICE_SWITCH_PRELOAD,				///< This command is reserved for DI internal use.
	APIDEVICE_INNOVO_DATA,					///< This ID corresponds to Ivision Multi SMR measurement and teach to drive measurements
	APIDEVICE_ACC_SINGLEMEAS,				///< Reserved for future use
	APIDEVICE_GENERIC						///< This task ID can be applicable to any procedure, hence 'generic'. 

} APIDEVICE_TASK;

/// \brief Enumeration for the laser tracker and it's accessories
enum APIDEVICE_MODEL {
	APIDEVICE_TRACKER = 320,	///< No accessories is connected to laser tracker
	APIDEVICE_IPROBE = 330,		///< IProbe is connected to the laser tracker
	APIDEVICE_IPROBE3 = 331,	///< Iprobe 3 is connected to the laser tracker
	APIDEVICE_STS = 340,		///< STS is connected to the laser tracker
	APIDEVICE_ISCANNER = 350,	///< IScanner is connected to the laser tracker
	APIDEVICE_VPROBE = 360		///< vProbe is connected to the laser tracker

};

///////////////////////////////////////////////////////////////////////////
// Definition of the structure used for the call-back function for the task
// Different structure needs different structure to send back the result
/// \brief Definition of the structure used for the call-back function for the task
typedef struct {
	DWORD dwSize;		///< Size of the data structure in bytes. This is used for future extension
	int   iTaskID;		///< This indicates which task is completed. \see APIDEVICE_TASK for list of tasks
	bool  bSuccess;		///< A flag to indicate if the task completed successful or failure.
	int   iErrorCode;	///< Error code of the task. It should be ignored if operation finished successfully.
	int	  iResult1;		///< The first return value of the call back function. It has different meaning for different task.
	int   iResult2;		///< The second return value of the call back function. It has different meaning for different task.
	F_VECTOR3 fv3;		///< The third return value of the call back function. It has different meaning for different task. \see F_VECTOR3 struct for details

} TASK_RESULT;
/*! @}*/

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
}*LPSTS_INFO;

//AutoDetect trackers
typedef struct AUTODETECT_INFO{
	int trackerCount;
	UINT	SN[100];
	TCHAR	IP[100][64];
	DWORD	WorkMode[100];
}*LPAUTODETECT_INFO;

#pragma pack(pop)

/// \defgroup ErrorCodes Error Codes
/// \brief List of general error codes
/*! \addtogroup ErrorCodes
* This section includes the documentation for error codes
* @{
*/

// Error codes
#define API_ERROR_SUCCESS																							0	///< Returned when the function succeeds

#define API_ERROR_NODEVICE_DETECTED																					1	///< Returned when there is no laser tracker connected or detected by the software

#define API_ERROR_USERCANCEL_CONNECTION																				2	///< Returned when the user cancel the connection while connecting

#define API_ERROR_FXN_NOTIMPLEMENTED																				6   ///< Returned when the function is being called that is not supported by the laser tracker

#define API_ERROR_INSUFFICIENT_MEMORY																				10  ///< Returned when the requested operation cannot be complete due to insufficient memory

#define API_ERROR_INVALIDPARAMETERS																					20	///< Returned when the parameters to a function is not valids

#define API_ERROR_INVALID_POINTER																					25	///< Returned when the pointer parameter to a function is invalid

#define API_ERROR_DATASAMPLER_NOTRUNNING																			26	///< Returned in case of data sampler not running and failed to get real time data

#define API_ERROR_NOTIN_TRACKINGMODE																				30	///< Returned when tracker is not tracking the target

#define API_ERROR_DISTANCE_ERROR																					31	///< Returned when there is a distance error and trying to measure

#define API_ERROR_QVC_REPEATABILITY_ERROR																			33	///< Returned when API Laser Tracker QVC repeatability is not within specified limits

#define API_ERROR_QVC_NOTRUN																						34	///< Returned when API Laser Tracker QVC operation is not running

#define API_ERROR_NESTREADING_SIGMA_OUTOFRANGE																		40 /// Returned if Nest data collection band is out of range.

#define API_ERROR_NESTREADING_TIMEOUT																				41 ///< Returned if Nest data collection has timed out.

#define API_ERROR_NESTREADING_DATASIZE_OUTOFRANGE																	42 ///<	Returned of Nest data collection mode average points are out of range

#define API_ERROR_NESTREADING_FAILED																				43 ///<	Returned of Nest data collection mode is not set properly.

#define API_ERROR_OTHERMEASURE_ONGOING																				45	///< Returned when other measurement is ongoing

// Encoder error codes
// Encoder calibration table doesn't exist
#define API_ERROR_NOENCODERCALTABLE																					201 ///< Returned if Encoder calibration table doesn't exist
// Level error codes
// Level calibration table doesn't exist
#define API_ERROR_NOLEVELCALTABLE																					221 ///< Returned if Level calibration table doesn't exist
// Bird bath manager error codes
// Bird bath information is not initialized
#define API_ERROR_NOBIRDBATHINFO																					241 ///< Returned if Bird bath information is not initialized

#define API_ERROR_BIRDBATHOUTRANGE																					242 ///< Returned if Bird bath position index is out of range.


#define API_ERROR_NOIPSTS																							250	///< Returned when iProbe / STS is not connected

#define API_ERROR_TRACKERPRMFILENOTEXIST																			301	///< Returned when the tracker .prm file not exits or cannot download due to firewall issues

#define API_ERROR_TRACKERPRMFILEWRONGFORMAT																			302	///< Returned when .prm file format is wrong


#define API_ERROR_BUFFERTOOSMALL																					303 ///< Returned when One of the measurement parameters is out of valid range!


#define API_ERROR_TRACKERPRMFILENOTREAD																				304	///< Returned when API Laser Tracker PRM file cannot be read. Either the format is wrong or the file is empty

#define API_ERROR_TRACKER_NOT_INITIALIZED																			310	///< Returned when API Laser tracker has not been initialized correctly.

#define API_ERROR_FTPLOGIN_FAILED																					321	///< Returned when FTP connection to API Laser Tracker has failed.

//	"Failed to download PRM file. "
#define API_ERROR_DOWNLOAD_PRM_FAILED																				322	///< Returned when FTP connection to API Laser Tracker has failed and cannot dowload the .prm file

//	"Failed to upload PRM file."
#define API_ERROR_UPLOAD_PRM_FAILED																					323	///< Returned when the FTP connection to API Laser Tracker has failed and cannot upload the .prm file

#define API_ERROR_DOWNLOAD_INI_FILE_FAILED																			325	///< Returned when FTP connection to API Laser Tracker has failed and cannot dowload the .ini file

#define API_ERROR_LOCAL_FOLDER_NOT_EXIST																			326	///< Returned when API Laser Tracker Application installation directory may have an unidentified folder called 'bak'. Delete it and retry your operation

#define API_ERROR_UPDATE_PRM_FAILED																					327	///< Returned when the FTP connection to API Laser Tracker has failed and cannot upload the .prm file

#define API_ERROR_CREATE_LOCALFOLDER_FAILED																			328 ///< Returned when creation of local folder while connection has failed.

#define API_ERROR_CONNECTING																						332	///< Returned when the API Laser tracker is still in the process of connecting and tried to connect again
#define API_ERROR_NOPROCEDURETOSTOP																					351
#define API_ERROR_TIMEOUT																							352	///< Returned when the API Laser tracker operation has timed out

// "Device is already connected."
#define API_ERROR_ALREADY_CONNECTED																					353	///< Returned when the device is already connected and tried to connect again

//"Tracker object binding failed."
#define API_ERROR_BINDFAILED																						354	///< Returned when failed to connect to the laser tracker

//"Tracker object initialization failed. (90)",
#define API_ERROR_OBJECTFAILED																						355	///< Returned when failed to connect to the laser tracker

//"Failed to connect to FTP server. (92)",
#define API_ERROR_PING_FAILED																						356	///< Returned when pinging the tracker failed

// "Failed to get response from controller. (93)",
#define API_ERROR_NORESPONSE																						357	///< Returned when failed to connect to the laser tracker

// "Index search failed. (94)",
#define API_ERROR_INDEXSEARCH_FAILED																				358	///< Returned when index search is failed. May be servo is OFF.

// "Other procedure is on-going"
#define API_ERROR_OTHERTASK_ONGOING																					359	///< Returned when other task or procedure is in progress

// "System Parameters have not been initialized. (360)"
#define API_ERROR_SYSTEMPARAM_NOT_INITIALIZED																		360	///< Returned when system parameters are not initialized.

// "No procedure to abort"
#define API_ERROR_NOPROCEDURE_ABORT																					361	///< Returned when there is no procedure running to abort

#define API_ERROR_IPROBE_CALIBRATION_ONGOING																		364	///< Returned if Probe Calibration is in progress.

#define API_ERROR_HOME_FAIL																							369	///< Returned when the tracker failed to complete the homing procedure

#define API_ERROR_NO_SMR																							370	///< Returned when jogging operation has timed out

// "Jogging operation time out. (371)"
#define API_ERROR_JOG_TIMEOUT																						371	///< Returned when jogging operation has timed out

// "AZ target positin is out of positive range. (372)"
#define API_ERROR_AZ_OUTOF_POSRANGE																					372	///< Returned when the tracker AZ specified for jogging is out of positive range

// "AZ target positin is out of negative range. (373)"
#define API_ERROR_AZ_OUTOF_NEGRANGE																					373	///< Returned when the tracker AZ specified for jogging is out of negative range

// "EL target positin is out of positive range. (374)"
#define API_ERROR_EL_OUTOF_POSRANGE																					374	///< Returned when the tracker EL specified for jogging is out of positive range

// "EL target positin is out of negative range. (375)"
#define API_ERROR_EL_OUTOF_NEGRANGE																					375	///< Returned when the tracker EL specified for jogging is out of negative range

// "AZ target positin is out of positive range. (372)"
#define API_ERROR_STSAZ_OUTOF_POSRANGE																				376	///< Returned when the STS AZ specified for jogging is out of positive range

// "AZ target positin is out of negative range. (373)"
#define API_ERROR_STSAZ_OUTOF_NEGRANGE																				377	///< Returned when the STS AZ specified for jogging is out of negative range

// "EL target positin is out of positive range. (374)"
#define API_ERROR_STSEL_OUTOF_POSRANGE																				378	///< Returned when the STS EL specified for jogging is out of positive range

// "EL target positin is out of negative range. (375)"
#define API_ERROR_STSEL_OUTOF_NEGRANGE																				379	///< Returned when the STS EL specified for jogging is out of negative range

//API Laser Tracker initialization is in progress.
#define API_ERROR_LASER_WARMUP																						380

#define API_ERROR_SETPOINT_AIRPRESSURE_LOW																			381	///< Returned when the air pressure set is below permissible range

#define API_ERROR_SETPOINT_AIRPRESSURE_HIGH																			382	///< Returned when the air pressure set is above the permissible range

#define API_ERROR_SETPOINT_AIRTEMPERATURE_LOW																		383	///< Returned when the air temperature set is below permissible range

#define API_ERROR_SETPOINT_AIRTEMPERATURE_HIGH																		384 ///< Returned when the air temperature set is above the permissible range

#define API_ERROR_SETPOINT_AIRHUMIDITY_LOW																			385	///< Returned when the air humidity set is below permissible range

#define API_ERROR_SETPOINT_AIRHUMIDITY_HIGH																			386	///< Returned when the air humidity set is above the permissible range

#define API_ERROR_TGSEARCH_TIMEOUT																					400	///< Returned when the tracker target search operation is timed out

//"Target ADM Searching Failed........(403)"
#define API_ERROR_ADMSEARCH_FAILED																					403 ///< Returned when Target ADM Search has Failed

//"Target is moving during ADM Search........(404)"
#define API_ERROR_ADMSEARCH_NONSTATIC																				404	///< Returned when the target is moving during the ADM search

//"Target is not tracking before ADM Search........(405)"
#define API_ERROR_ADMSEARCH_NONTRACK																				405	///< Returned when the target is not tracking during ADM search

// "ADM distance is negative. (406)"
#define API_ERROR_ADM_NEGTIVE_DISTANCE																				406	///< Returned when ADM distance goes negative during ADM search

// "ADM intensity is too low. (407)"
#define API_ERROR_ADM_LOW_INTENSITY																					407	///< Returned when ADM intensity is below the minimum limit while tracking the target or during homing procedure

// "ADM search time out. (408)"
#define API_ERROR_ADMSEARCH_TIMEOUT																					408	///< Returned when ADM Search has timed out

// "ADM i-scan is out of tolerance. (409)
#define API_ERROR_ADMISCAN_OUTBAND																					409	///< Returned when ADM distance is not within the tolerable range during homing procedure

// "ADM auto set in ongoing."
#define API_ERROR_ADMAUTOSET_ONGOING																				411	///< Returned when the ADM Autoset is on-going

//"Level X direction out of range. (410)",
#define API_ERROR_LEVELX_OUTOFRANGE																					430	///< Returned when the Level in X direction is out of range

//"Tracker is not in tracking mode or the distance is not correct.",
#define API_ERROR_NOGOODDISTANCE																					440 ///< Returned when tracking mode or distance is not correct.

// "API Laser Tracker initialization is in progress. (421)."
#define API_ERROR_WARMUP																							441	///< Returned when tracker is still in warmp-up phase. Check REALTIME_INFO::Warm_Up_Time.

// "Laser intensity is low, can't track (422)."
#define API_ERROR_INTENSITYLOW																						442	///< Returned when the laser intensity is low and cannot track the target

// "Remote home failed (423)."
#define API_ERROR_REHOMEFAILED																						443	///< Returned when the tracker remote home failed

#define API_ERROR_LEDMANNOTINITIALIZED																				460	///< Returned when the LED Manager not initialized

// " No channel defined for the data collection."
#define API_ERROR_NODATACHANNELDEFINED																				470	///< Returned when no channel is selected for data collection

// " Zero data size defined for data collection."
#define API_ERROR_NODATASIZEDEFINED																					471	///< Returned when zero data size is defined for data collection

// " Other data collection procedure is running."
#define API_ERROR_OTHERDATACOLLECTIONRUNNING																		472	///< Returned when other data collection procedure is ongoing

// " Data size is out of range."
#define API_ERROR_DATASIZEOUTOFRANGE																				473	///< Returned when data size defined for data collection is out of range

// " Unknown/unsupported data collection mode."	
#define API_ERROR_UNKNOWNDATACOLLECTIONMODE																			474	///< Data collection mode is not supported / not known

// " Data collection initialization is not done."
#define API_ERROR_DATACOL_INCOMPLETE_INIT																			475	///< Data collection initialization is not finished

// " No tracker data collection process in process."
#define API_ERROR_NODATACOLLECTIONPROCESS																			476	///< No tracker data collection process in process

// " FIFO data collection has already started."
#define API_ERROR_TRIGGERED																							477	///< API Laser Tracker has already triggered for data collection

// " Tracker sim task initialization failed."		
#define API_ERROR_SIMINITFAILED																						481 ///< Returned if data collection could not be initialised.

// " Tracker sim trigger set up failed."		
#define API_ERROR_SIMCREATEFAILED																					482 ///< Returned if data collection task could not be set.

// " Tracker sim task creation failed."
#define API_ERROR_SIMTRIGSETUPFAILED																				483 ///< Returned if data collection trigger could not be set.

// " Tracker sim task channel selection failed."
#define API_ERROR_SIMCHANNELSELFAILED																				484 ///< returned if setting data collection task channel has failed.

// " Tracker sim task setting point number failed."
#define API_ERROR_SIMSETPTNUMFAILED																					485	///< Returned when setting point number in data collection has failed. 

// " Tracker starting sim task failed."
#define API_ERROR_SIMSTARTFAILED																					486 ///< Returned when starting sim task has failed.

// " Tracker starting sim task failed."
#define API_ERROR_DATACOLLECTIONINITFAILED																			487 ///< Returned when data collection couldnt start due to internal exception.

// " Can't abort the FIFO data collection process."
#define API_ERROR_NOABORTINFIFO																						489 ///< Returned if FIFO data collection process couldn't be aborted.

#define API_ERROR_IPMEASURE_OUTOFBAND																				510 ///< Returned if Accessory measurement is out of deviation band.

// "I-Probe tip offset is out of range
#define API_ERROR_IPOFFSET_OUTOFRANGE																				511 ///< Returned if Accessory tip offset is out of range

//"Calibration file for intelliprobe is not found. (512)",
#define API_ERROR_IPPRMFILE_NOTFOUND																				512 ///< Returned when Probe prm file is not found in the application directory or user chose wrong PRM when asked by SDK.

//"Incorrect calibration file format. (513)",
#define API_ERROR_IPPRMFILE_WRONGFORMAT																				513 ///< Returned if Probe PRM file format is wrong or corrupted. 

//"No intelli-probe is detected. (515)",	
#define API_ERROR_NOIPDETECTED																						515 ///< Returned if Probe or scanner was not detected by SDK during connection.

//"Intelli-probe prm file is not read. (516)",
#define API_ERROR_IPPRMNOTREAD																						516 ///< Returned if Probe PRM file was not parsed correctly.

//"Intelli-Probe moved too much during offset calibration. (76)",
#define API_ERROR_IPNOTSTABLE_OFFSETCAL																				517 ///<Returned if Accessory moved too much during offset calibration

//"Intelli-Probe data rate is too slow during offset calibration. (518)",
#define API_ERROR_IP_DATERATE_SLOW																					518 ///<Returned if Accessory data rate is too slow during offset calibration.

//"Tracker is not tracking in the intelli-probe. (519)",
#define API_ERROR_NOTTRACKINGIN_IP																					519 ///< Returned if Tracker is not tracking accessory.

//"Intelli-probe's ruled optimizition failed. (521)",
#define API_ERROR_IPGLB_RULEDOPTIMIZATIONFAIL																		521 ///< Returned if Accessory's ruled optimizition failed

//"Intelli-probe's accuracy check failed. (522)",
#define API_ERROR_IPGLB_ACCURACYCHECKFAIL																			522 ///< Returned if Accessory's accuracy check failed.

// "IScanner is not initialized."
#define API_ERROR_ISCANNER_SCANREADY_FAILED																			541 ///< Returned if iScan is not ready for scanning. 

#define API_ERROR_ISCANNER_NOTDETECTED																				542 ///< Returned if iScan is not detected by SDK during connection.

// Below is the error information for STS
#define API_ERROR_STSPRMFILE_NOTFOUND																				550 ///< Returned when STS prm file is not found in the application directory or user chose wrong PRM when asked by SDK.

// "STS Prm file has not be read.
#define API_ERROR_STSPRMFILE_NOTREAD																				551 ///< Returned if STS PRM file was not parsed correctly.

#define API_ERROR_NOSTS_DETECTED																					552 ///< Returned when STS specific functions are called but STS was not detected by SDK during connection process. 

#define API_ERROR_STSPRMFILE_WRONGFORMAT																			553 ///< Returned if STS PRM file format is wrong or corrupted. 

#define API_ERROR_NOTTRACKINGIN_STS																					554 ///< Returned if STS is not in track mode.

#define API_ERROR_OPENCAMERA_FAILED																					561	///< Returned if camera could not be started in old versions of trackers with side mounted camera.

#define API_ERROR_OPENCAMERA_PRMFILE_NOTFOUND																		562	///< Returned if camera prm file is not found for old versions of trackers with side mounted camera.

#define API_ERROR_ISCAN_PRMFILE_NOTFOUND																			570 ///< Returned if iScan PRM file is not present in the application directory.

#define API_ERROR_ISCAN_PRMFILE_FORMATWRONG																			571 ///< Returned if iScan PRM file format is wrong or corrupted. 

#define API_ERROR_SIGMAMEASURE_NOTDONE																				580 ///< Returned if sigma measurement could not be started.

#define API_ERROR_SIGMAMEASURE_NODATA																				581///< Returned if no data is collected.

#define API_ERROR_SIGMAMEASURE_DATAINVALID																			582 ///< Returned if STS dynamic measurement could not start.

#define API_ERROR_VIRTUALLEVEL_NOTFOUND																				669 ///< Returned if Virtual Level has not been performed before using any accessory.	

#define API_ERROR_VIRTUALLEVEL_DISABLED																				681 ///< Returned when applyVirtualLevel() is called with first input parameter as false.

// "Start TTL failed."
#define API_ERROR_STARTTTL_FAILED																					701 ///< Returned when TTL mode cannot start.

#define API_ERROR_STOPTTL_FAILED																					702///< Returned when TTL mode cannot stop..

//"I-Probe encoder index search is not finished"
#define API_ERROR_IPROBE_INDEXSEARCH_NOT_COMPLETE																	706///< Returned when accessory encoder index search is not finished before starting any kind of accessory measurement. 

//"Mask set for data capture mode is incorrect"
#define API_ERROR_DATA_MASK_INCORRECT																				802 ///< Data mask(TCKDATAMASK) are set incorrectly when calling TrackerCapturingOperation().

//"The controller cannot be set or reset to diagnostic mode"
#define API_ERROR_SET_RESET_T4_DIAGNOSTIC																			803 ///< Controller cannot send Diagnostic packets to the SDK.

//"This function is deprecated"
#define API_ERROR_FUNCTION_DEPRECATED																				805 ///< The function or feature is no more supported by the SDK.

//"This API Laser Tracker does not have Innovo Camera" 
#define API_ERROR_INNOVO_CAMERA_NOT_PRESENT																			806 ///< Tracker doesn't have iVision or doesn't support camera mode.

//"The API Laser Tracker Servo motor power is turned off"
#define API_ERROR_SERVO_OFF																							808 ///< Cannot start iVision because the Tracker servo has been turned off.

//"This data collection mode is not supported"
#define API_ERROR_DATA_COLLECTION_MODE_UNSUPPORTED																	809 ///< Returned if current data collection mode is not supported

//"IProbe single point data collection mode is not enabled"
#define API_ERROR_IPROBE_NOT_IN_IPMEASUREMODE																		811 ///< Cannot soft trigger(TriggerProbe()) a probe since the mode is different than APIDEVICE_IP_SINGLEMEAS or APIDEVICE_IP_INSPECT

//"This function is reserved for future use"
#define API_ERROR_RESERVED_FUNCTION																					812 ///< Returned when called function is reserved for future use and is not applicable as of now.

//"Cannot start IProbe tip offset verification"
#define API_ERROR_IPOFFSET_VERIFY																					813	///< Cannot start accessory tip offset verification

//"Cannot start IProbe in-field calibration"
#define API_ERROR_IPTIP_INFIELDCAL																					814	///<Cannot start accessory in-field calibration

//"I-Probe tip offset calibration is not successful"
#define API_ERROR_IPTIPOFFSETCAL_NOTDONE																			815	///< Accessory tip offset calibration is not successful

//"This feature is not supported"
#define API_ERROR_FEATURE_NOT_SUPPORTED																				816///< This feature is not supported

//"This function is already running"
#define API_ERROR_FUNCTION_RUNNING																					817///< This function is already running	

//"You need to 'home' the API Laser Tracker!"
#define API_ERROR_SYSTEM_NEVER_HOMED																				819	///< You need to 'home' the API Laser Tracker!

//"Homing operation failed during Virtual Level!"
#define API_ERROR_HOME_FAILED_DURING_VIRTUAL_LEVEL																	820	///< Homing operation failed during Virtual Level!

//"This Probe tip is not defined"
#define API_ERROR_IPROBE_TIP_NOT_DEFINED																			828	///< This accessory tip is not defined

//"The application failed to get response from API Laser Tracker"
#define	 API_ERROR_FAILED_RESPONSE_FOR_COMMAND																		829	///< The application failed to get response from API Laser Tracker
//"vProbe Measure average time limit is between 750ms and 2000ms"
#define	 API_ERROR_VPROBE_ACCMEASURE_OUTOFLIMIT																		830 ///< Returns if vProbe Measure average time not between 750ms and 2000ms

#define API_ERROR_UNABLETO_OPEN_WIRELESS_STRENGTH_INDICATOE_DIALOG													832	///< Error Opening the accessory wireless strength indicator window

#define API_ERROR_TGSEARCH_RADIUS_LIMIT_REACHED									                                    835	///< Error received when doing target search, search did not find SMR within the specified radius


/*! @} */
}
#endif