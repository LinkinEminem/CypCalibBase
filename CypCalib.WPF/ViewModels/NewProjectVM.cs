using System.Collections.Generic;
using System.Windows;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using CypCalib.Core.Models;
using CypCalib.Core.Shared;
using absLib.Services;
using CypCalib.WPF.Services;


namespace CypCalib.WPF.ViewModels
{
    public partial class NewProjectVM : ObservableObject
    {
        
    #region 属性定义
    
        public Dictionary<ProjectEnum, string> EnumStrMapping { get; set; } = new()
        {
            { ProjectEnum.peRobotLaserCalib, "机械臂激光跟踪仪标定" },
            { ProjectEnum.peRobotISOTest, "机械臂国标性能检测" }
        };

        private bool _isViewOpen = true;
        public bool IsViewOpen
        {
            get => _isViewOpen;
            set
            {
                if (_isViewOpen == value) return;
                _isViewOpen = value;
                OnPropertyChanged();
            }
        }

        private ProjectInfo _projectInfo = new ProjectInfo();
        public ProjectInfo ProjectInfo
        {
            get => _projectInfo;
            set
            {
                if (_projectInfo == value) return;
                _projectInfo = value;
                OnPropertyChanged();
            }
        }

    #endregion

        /**
         * @brief 点击 “创建” 后，界面上的信息会被传回主界面
         */
        [RelayCommand]
        private void Confirm()
        {
            IsViewOpen = false;
            var obj = JsonSerializeHelper.Serialize(ProjectInfo);
            GlobalManager.DoAction(Tokens.Token_WM_New_Project, obj);
        }

        [RelayCommand]
        private void Cancel()
        {
            IsViewOpen = false;
        }
    }
}
