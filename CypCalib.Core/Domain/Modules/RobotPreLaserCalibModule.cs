using System.Collections.Generic;
using CypCalib.Core.Domain.Interface;
using CypCalib.Core.Domain.Shared;

namespace CypCalib.Core.Domain.Modules
{
    public class RobotPreLaserCalibModule : IModule
    {
        // 机械臂模型
        public Robot6DInfo RobotInfo { get; set; } = new Robot6DInfo();
        
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
