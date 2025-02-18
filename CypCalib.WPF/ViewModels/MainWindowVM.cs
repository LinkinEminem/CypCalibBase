using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using CypCalib.WPF.Services;

namespace CypCalib.WPF.ViewModels
{
    public partial class MainWindowVM : ObservableObject
    {
        [RelayCommand]
        private void New()
        {
            CreateProjectVM vm = new CreateProjectVM();
            WindowsManager.DoAction("ShowCreateProject", vm);
        }
    }
}