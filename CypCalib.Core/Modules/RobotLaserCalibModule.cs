using System.Collections.ObjectModel;
using CommunityToolkit.Mvvm.ComponentModel;
using CypCalib.Core.Interface;
using CypCalib.Core.Shared;

namespace CypCalib.Core.Modules
{
    public partial class RobotLaserCalibModule : ObservableObject, IModule
    {
        [ObservableProperty]
        private Robot6DInfo _robotInfo = new Robot6DInfo();
        
        [ObservableProperty]
        private EnvironmentInfo _environmentInfo  = new EnvironmentInfo();
        
        [ObservableProperty]
        private RobotPreCalibModule _robotPreCalibModule = new RobotPreCalibModule();
        
        [ObservableProperty]
        private RobotMainCalibModule _robotMainCalibModule = new RobotMainCalibModule();
        
        [ObservableProperty]
        private RobotCalibRstModule _robotCalibRstModule = new RobotCalibRstModule();
        
        [ObservableProperty]
        private LaserTrackerConfig _trackerConfig = new LaserTrackerConfig();
        
    }

    public partial class RobotPreCalibModule : ObservableObject, IModule
    {
        [ObservableProperty]
        private RobotPreCalibConfig _preConfig = new RobotPreCalibConfig();
        
        [ObservableProperty]
        private ObservableCollection<Robot6DLaserData> _preCalibData =  new ObservableCollection<Robot6DLaserData>();
    }

    public partial class RobotMainCalibModule : ObservableObject, IModule
    {
        [ObservableProperty]
        private RobotMainCalibConfig _mainConfig = new RobotMainCalibConfig();
        
        [ObservableProperty]
        private ObservableCollection<Robot6DLaserData> _mainCalibData = new ObservableCollection<Robot6DLaserData>();
    }

    public partial class RobotCalibRstModule : ObservableObject, IModule
    {
        [ObservableProperty]
        private RobotCalibRstConfig _rstConfig = new RobotCalibRstConfig();
    }
}
