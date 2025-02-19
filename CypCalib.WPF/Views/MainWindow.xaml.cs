using System.Windows;
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
            
            GlobalManager.Register(Tokens.Token_WM_Show_NewProject, (obj) =>
            {
                var view = new NewProjectView
                {
                    DataContext = obj as NewProjectVM,
                    Owner = this,
                };
                view.ShowDialog();
            });

            GlobalManager.Register(Tokens.Token_WM_Show_RobotLaserCalib, (obj) =>
            {
                var view = new RobotLaserCalibView
                {
                    DataContext = obj as RobotLaserCalibVM,
                    Owner = this
                };
                view.ShowDialog();
            });
            
            GlobalManager.Register(Tokens.Token_WM_Show_RobotISOTest, (obj) =>
            {
                var view = new RobotISOTestView
                {
                    DataContext = obj as RobotISOTestVM,
                    Owner = this
                };
                view.ShowDialog();
            });

            this.Closing += (_, _) =>
            {
                GlobalManager.Unregister(Tokens.Token_WM_Show_NewProject);
            };
        }
    }
}
