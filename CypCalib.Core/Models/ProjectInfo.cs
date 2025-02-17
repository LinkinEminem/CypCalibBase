using CommunityToolkit.Mvvm.ComponentModel;
using CypCalib.Core.Interface;
using CypCalib.Core.Shared;

namespace CypCalib.Core.Models
{
    public partial class ProjectInfo : ObservableObject
    {
        // 工程名
        [ObservableProperty]
        private string _projectName;
        
        // 项目类型
        [ObservableProperty]
        private ProjectEnum _projectType;
        
        // 元数据，包括：版本、创建时间等
        [ObservableProperty]
        private MetaData _metaData;
        
        // Module 接口
        [ObservableProperty] 
        private IModule _module;
        
        public ProjectInfo(string projectName, ProjectEnum projectType, IModule module)
        {
            _projectName = projectName;
            _projectType = projectType;
            _metaData = new MetaData();
            _module = module;
        }
    }
}
