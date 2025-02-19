using System.Windows;

namespace CypCalib.WPF.Views
{
    public partial class NewProjectView : Window
    {
        public NewProjectView()
        {
            InitializeComponent();

            this.IsEnabledChanged += delegate
            {
                if (!IsEnabled)
                {
                    this.Close();
                }
            };
        }
    }
}