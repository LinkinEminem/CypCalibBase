using System.Windows;
using CypCalib.WPF.Services;
using CypCalib.WPF.ViewModels;
using CypCalib.WPF.Views;

namespace CypCalib.WPF
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            
            WindowsManager.Register("ShowCreateProject", (obj) =>
            {
                var view = new CreateProject
                {
                    DataContext = obj as CreateProjectVM,
                    Owner = this
                };
                view.ShowDialog();
            });

            this.Closing += (sender, e) =>
            {
                WindowsManager.Unregister("ShowCreateProject");
            };
        }
    }
}
