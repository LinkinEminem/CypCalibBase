using System;

namespace CypCalib.Core.Domain.Models
{
    public class MetaData
    {
        public DateTime CreatedTime { get; set; }
        
        public DateTime ModifiedTime { get; set; }
        
        public Version Version { get; set; }

        public MetaData()
        {
            CreatedTime = DateTime.Now;
            ModifiedTime = DateTime.Now;
            Version = new Version();
        }
    }
}