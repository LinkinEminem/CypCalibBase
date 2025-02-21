using System.Timers;
using absLib.Services;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using CypCalib.Core.Models;
using CypCalib.WPF.Services;
using CypCalib.Core.Shared;
using CypCalib.WPF.Services.FSM;

namespace CypCalib.WPF.ViewModels
{
    public partial class MainWindowVM : ObservableObject
    {
        private const int TIMER_INTERVAL = 10;
        private readonly StateMachineManager _stateMachineManager = StateMachineManager.Instance;
        private Timer _timer;
        private readonly object _syncLock = new object();
        
        private void InitStateMachine()
        {
            _timer = new(TIMER_INTERVAL);
            _timer.Elapsed += (s, e) =>
            {
                lock (_syncLock)
                {
                    _stateMachineManager.Update();
                }
            };
            _timer.AutoReset = true;
            _timer.Start();
            LogHelper.Debug("主状态机初始化完成。");
        }
        
        public MainWindowVM()
        {
            GlobalManager.Register(Tokens.Token_WM_New_Project, OnCallbackReceived);
            InitStateMachine();
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
