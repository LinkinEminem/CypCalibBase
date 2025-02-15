using System.Collections.Generic;
using CypCalib.Core.Interface;
using CypCalib.Core.Shared;

namespace CypCalib.Core.Modules
{
    public class RobotLaserCalibModule : IModule
    {
        public Robot6DInfo RobotInfo { get; set; } = new Robot6DInfo();
        
        public EnvironmentInfo EnvironmentInfo { get; set; } = new EnvironmentInfo();
        
        // 数据配置
        public RobotPreCalibConfig PreConfig { get; } = new RobotPreCalibConfig();
        public RobotMainCalibConfig MainConfig { get; } = new RobotMainCalibConfig();
        public RobotCalibRstConfig RstConfig { get; } = new RobotCalibRstConfig();
        
        // 跟踪仪配置
        public LaserTrackerConfig TrackerConfig { get; } = new LaserTrackerConfig();
        
        public List<Robot6DLaserData> PreCalibData { get; set; } =  new List<Robot6DLaserData>();
        public List<Robot6DLaserData> MainCalibData { get; set; } =  new List<Robot6DLaserData>();
    }
}
