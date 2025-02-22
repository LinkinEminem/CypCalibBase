using System;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls.Primitives;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using CypCalib.Core.Shared;
using CypCalib.WPF.Services;
using CypCalib.WPF.Services.FSM;
using Newtonsoft.Json.Linq;

namespace CypCalib.WPF.ViewModels
{
    public partial class RobotLaserCalibVM : ObservableObject
    {
        #region 属性定义

        private JObject _uiInfo;
        public JObject UiInfo
        {
            get => _uiInfo;
            set
            {
                if (_uiInfo == value) return;
                _uiInfo = value;
                OnPropertyChanged();
                ParseUpdatedData();
            }
        }

        private DateTime _updateTime = DateTime.Now;
        
        private double _interval;

        public double Interval
        {
            get => _interval;
            set
            {
                if (_interval > value) return;
                _interval = value;
                OnPropertyChanged();
            }
        }
        
        private int _fsmSubState = 0;
        public int FsmSubState
        {
            get => _fsmSubState;
            set
            {
                if (_fsmSubState == value) return;
                _fsmSubState = value;
                OnPropertyChanged();
            }
        }
        
        #endregion

        private void ParseUpdatedData()
        {
            if (UiInfo != null && UiInfo.TryGetValue("test", out var token))
            {
                FsmSubState = token.Value<int>();
            }
        }
        
        [RelayCommand]
        private void TestCommApi()
        {
            _updateTime = DateTime.Now;
            var fsm = new RobotLaserCalibFSM();
            fsm.StateChanged += (jsonInfo) =>
            {
                Application.Current.Dispatcher.Invoke(() =>
                {
                    UiInfo = jsonInfo;
                    Interval = (DateTime.Now - _updateTime).TotalMilliseconds;
                    _updateTime = DateTime.Now;
                });
            };
            var rst = StateMachineManager.Instance.StartOrResume(fsm);
            if (rst.Code != ErrorCodeEnum.ERR_SUCCESS)
            {
                MessageBox.Show(rst.Message);
            }
        }
    }
}