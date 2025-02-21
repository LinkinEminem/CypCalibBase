using System.Windows;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using CypCalib.Core.Shared;
using CypCalib.WPF.Services;
using CypCalib.WPF.Services.FSM;

namespace CypCalib.WPF.ViewModels
{
    public partial class RobotLaserCalibVM : ObservableObject
    {
        [RelayCommand]
        private void TestCommApi()
        {
            var rst = StateMachineManager.Instance.StartOrResume(new RobotLaserCalibFSM());
            if (rst.Code != ErrorCodeEnum.ERR_SUCCESS)
            {
                MessageBox.Show(rst.Message);
            }
        }
    }
}