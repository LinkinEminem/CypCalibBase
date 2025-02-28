using System.Windows;
using CypCalib.Core.Helper;
using CypCalib.Core.Shared;
using CypCalib.WPF.Services;
using CypCalib.WPF.ViewModels;

namespace CypCalib.WPF.Views
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            
            GlobalManager.WindowRegister<MainWindow, NewProjectView, NewProjectVM>(
                Tokens.Token_WM_Show_NewProject,
                this,
                obj => new NewProjectVM()
                );
            
            GlobalManager.WindowRegister<MainWindow, RobotLaserCalibView, RobotLaserCalibVM>(
                Tokens.Token_WM_Show_RobotLaserCalib,
                this,
                obj => new RobotLaserCalibVM()
                );
            
            GlobalManager.WindowRegister<MainWindow, RobotISOTestView, RobotISOTestVM>(
                Tokens.Token_WM_Show_RobotISOTest,
                this,
                obj => new RobotISOTestVM()
            );
            
            // 上述方法等效于：
            // GlobalManager.Register(Tokens.Token_WM_Show_NewProject, (obj) =>
            // {
            //     var view = new NewProjectView
            //     {
            //         DataContext = obj as NewProjectVM,
            //         Owner = this,
            //     };
            //     view.ShowDialog();
            // });

            this.SourceInitialized += (_, __) =>
            {
                LogHelper.Info("MainWindow 打开。");
            };
            
            this.Closing += (_, _) =>
            {
                GlobalManager.Unregister(Tokens.Token_WM_Show_NewProject);
                
                LogHelper.Info("MainWindow 关闭。");
            };
        }
    }
}
