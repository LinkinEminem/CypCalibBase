using CypCalib.Core.Domain.Interface;
using CypCalib.Core.Domain.Shared;

namespace CypCalib.Core.Domain.Models
{
    public class ProjectInfo
    {
        // 工程名
        public string ProjectName { get; set; }

        // 项目类型
        private readonly ProjectEnum _projectEnum;
        
        private MetaData _metaData;
        
        // 保存路径
        public string SavePath { get; set; } = "";

        public IModule Module { get; set; }
        
        public ProjectInfo(string projectName, ProjectEnum projectEnum)
        {
            ProjectName = projectName;
            _projectEnum = projectEnum;
            _metaData = new MetaData();
        }
    }
}
