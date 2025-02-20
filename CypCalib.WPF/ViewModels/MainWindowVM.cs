using System;
using System.Windows;
using absLib.Services;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using CypCalib.Core.Models;
using CypCalib.WPF.Services;
using CypCalib.Core.Shared;

namespace CypCalib.WPF.ViewModels
{
    public partial class MainWindowVM : ObservableObject
    {
        public MainWindowVM()
        {
            GlobalManager.Register(Tokens.Token_WM_New_Project, OnCallbackReceived);
        }
        
        /**
         * @brief 新建项目
         */
        [RelayCommand]
        private void New()
        {
            GlobalManager.DoAction(Tokens.Token_WM_Show_NewProject, new NewProjectVM());
        }

        /**
         * @brief 创建工程后的回调函数
         */
        private static void OnCallbackReceived(object data)
        {
            var jObject = JsonSerializeHelper.Deserialize<ProjectInfo>(data as string ?? string.Empty);

            switch (jObject.ProjectType)
            {
                case ProjectEnum.peRobotLaserCalib:
                {
                    GlobalManager.DoAction(Tokens.Token_WM_Show_RobotLaserCalib, new RobotLaserCalibVM());
                    break;
                }
                case ProjectEnum.peRobotISOTest:
                {
                    GlobalManager.DoAction(Tokens.Token_WM_Show_RobotISOTest, new RobotISOTestVM());
                    break;
                }
            }
        }
    }
}
