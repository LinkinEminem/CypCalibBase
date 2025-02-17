using System;
using CommunityToolkit.Mvvm.ComponentModel;

namespace CypCalib.Core.Models
{
    public partial class MetaData : ObservableObject
    {
        [ObservableProperty]
        private DateTime _createdTime = DateTime.Now;
        
        [ObservableProperty]
        private DateTime _modifiedTime = DateTime.Now;
        
        [ObservableProperty]
        private Version _version = new Version(0, 1);
    }
}
