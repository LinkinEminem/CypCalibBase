using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using CypCalib.WPF.Services;

namespace CypCalib.WPF.ViewModels
{
    public partial class RobotISOTestVM : ObservableObject
    {
        [RelayCommand]
        private void TestCommApi()
        {
            CypWeldJsonRpcApi.RobotMcsMoveTo(new double[] { 0, 0, 0, 0, 0, 0 });
        }
    }
}
