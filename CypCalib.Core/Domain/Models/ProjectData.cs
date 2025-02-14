using CypCalib.Core.Domain.Interface;
using CypCalib.Core.Domain.Shared;

namespace CypCalib.Core.Domain.Models
{
    public class ProjectInfo
    {
        // 工程名
        public string ProjectName { get; }
        // 项目类型
        public ProjectEnum ProjectType { get; }
        // 元数据，包括：版本、创建时间等
        public MetaData MetaData { get; }
        // 保存路径
        public string SavePath { get; set; } = "";
        // Module 接口
        public IModule Module { get; }
        
        public ProjectInfo(string projectName, ProjectEnum projectType, IModule module)
        {
            ProjectName = projectName;
            ProjectType = projectType;
            MetaData = new MetaData();
            Module = module;
        }
    }
}
