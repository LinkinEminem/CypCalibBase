using System.Collections.Generic;
using CypCalib.Core.Interface;
using CypCalib.Core.Shared;

namespace CypCalib.Core.Modules
{
    public class RobotLaserCalibModule : IModule
    {
        public Robot6DInfo RobotInfo { get; set; } = new Robot6DInfo();
        
        public EnvironmentInfo EnvironmentInfo { get; set; } = new EnvironmentInfo();
        
        public RobotPreCalibModule RobotPreCalibModule { get; set; } = new RobotPreCalibModule();
        public RobotMainCalibModule RobotMainCalibModule { get; set; } = new RobotMainCalibModule();
        public RobotCalibRstModule RobotCalibRstModule { get; set; } = new RobotCalibRstModule();
        
        // 跟踪仪配置
        public LaserTrackerConfig TrackerConfig { get; } = new LaserTrackerConfig();
        
    }

    public class RobotPreCalibModule : IModule
    {
        public RobotPreCalibConfig PreConfig { get; } = new RobotPreCalibConfig();
        public List<Robot6DLaserData> PreCalibData { get; set; } =  new List<Robot6DLaserData>();
    }

    public class RobotMainCalibModule : IModule
    {
        public RobotMainCalibConfig MainConfig { get; } = new RobotMainCalibConfig();
        public List<Robot6DLaserData> MainCalibData { get; set; } =  new List<Robot6DLaserData>();
    }

    public class RobotCalibRstModule : IModule
    {
        public RobotCalibRstConfig RstConfig { get; } = new RobotCalibRstConfig();
    }
}
