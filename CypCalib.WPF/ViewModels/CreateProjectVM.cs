using System.Windows;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using CypCalib.Core.Shared;

namespace CypCalib.WPF.ViewModels
{
    public partial class CreateProjectVM : ObservableObject
    {
        [ObservableProperty]
        private ProjectEnum _projectType = ProjectEnum.peRobotLaserCalib;
        
        [ObservableProperty]
        private string _serialNum = "123";
        
        [ObservableProperty]
        private string _operator = "";
        
        [ObservableProperty]
        private double _temperature = 20;
        
        [ObservableProperty]
        private double _humidity = 60;

        [RelayCommand]
        private void Confirm()
        {
            MessageBox.Show("Project created successfully");
        }

        [RelayCommand]
        private void Cancel()
        {
            MessageBox.Show("Project cancelled");
        }
    }
}