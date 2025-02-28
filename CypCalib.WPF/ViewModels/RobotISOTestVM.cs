using System.Windows;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using CypCalib.Core.Helper;
using CypCalib.Core.Shared;
using CypCalib.WPF.Services;

namespace CypCalib.WPF.ViewModels
{
    public partial class RobotISOTestVM : ObservableObject
    {
        [RelayCommand]
        private void TestCommApi()
        {
            var rst = LaserTrackerHelper.Instance.DisconnectAsync().Result;
            if(rst.Code != ErrCodes.SUCCESS.Code)
            {
                MessageBox.Show(rst.Message);
            }
        }
    }
}
