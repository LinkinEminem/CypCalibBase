using CypCalib.Core.Interface;
using CypCalib.Core.Models;
using CypCalib.Core.Modules;
using CypCalib.Core.Shared;

namespace CypCalib.UI.ViewModels
{
    public class RobotLaserCalibVM
    {
        public RobotLaserCalibModule Module { get; set; }
        public ProjectInfo ProjectInfo { get; set; }
        
        public RobotPreLaserCalibVM PreVM { get; set; } 
        public RobotMainLaserCalibVM MainVM { get; set; }
        public RobotLaserCalibRstVM RstVM { get; set; }

        public RobotLaserCalibVM()
        {
            Module = new RobotLaserCalibModule();
            ProjectInfo = new ProjectInfo("", ProjectEnum.peRobotLaserCalib, Module);
            PreVM = new RobotPreLaserCalibVM(Module.RobotPreCalibModule);
            MainVM = new RobotMainLaserCalibVM(Module.RobotMainCalibModule);
            RstVM = new RobotLaserCalibRstVM(Module.RobotCalibRstModule);
        }
    }

    public class RobotPreLaserCalibVM
    {
        public IModule Module { get; set; }

        public RobotPreLaserCalibVM(IModule module)
        {
            Module = module;
        }
    }

    public class RobotMainLaserCalibVM
    {
        public IModule Module { get; set; }

        public RobotMainLaserCalibVM(IModule module)
        {
            Module = module;
        }
    }

    public class RobotLaserCalibRstVM
    {
        public IModule Module { get; set; }

        public RobotLaserCalibRstVM(IModule module)
        {
            Module = module;
        }
    }
}