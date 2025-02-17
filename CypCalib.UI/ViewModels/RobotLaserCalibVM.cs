using CommunityToolkit.Mvvm.ComponentModel;
using CypCalib.Core.Interface;
using CypCalib.Core.Models;
using CypCalib.Core.Modules;
using CypCalib.Core.Shared;

namespace CypCalib.UI.ViewModels
{
    public partial class RobotLaserCalibVM : ObservableObject
    {
        [ObservableProperty]
        private RobotLaserCalibModule _module;

        [ObservableProperty]
        private ProjectInfo _projectInfo;

        [ObservableProperty]
        private RobotPreLaserCalibVM _preVM;
        
        [ObservableProperty]
        private RobotMainLaserCalibVM _mainVM;
        
        [ObservableProperty]
        private RobotLaserCalibRstVM _rstVM;

        public RobotLaserCalibVM()
        {
            _module = new RobotLaserCalibModule();
            _projectInfo = new ProjectInfo("", ProjectEnum.peRobotLaserCalib, Module);
            _preVM = new RobotPreLaserCalibVM(Module.RobotPreCalibModule);
            _mainVM = new RobotMainLaserCalibVM(Module.RobotMainCalibModule);
            _rstVM = new RobotLaserCalibRstVM(Module.RobotCalibRstModule);
        }
    }

    public partial class RobotPreLaserCalibVM : ObservableObject
    {
        [ObservableProperty]
        private IModule _module;

        public RobotPreLaserCalibVM(IModule module)
        {
            Module = module;
        }
    }

    public partial class RobotMainLaserCalibVM : ObservableObject
    {
        [ObservableProperty]
        private IModule _module;

        public RobotMainLaserCalibVM(IModule module)
        {
            Module = module;
        }
    }

    public partial class RobotLaserCalibRstVM : ObservableObject
    {
        [ObservableProperty]
        private IModule _module;

        public RobotLaserCalibRstVM(IModule module)
        {
            Module = module;
        }
    }
}