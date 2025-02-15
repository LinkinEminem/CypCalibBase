using System;

namespace CypCalib.Core.Models
{
    public class MetaData
    {
        public DateTime CreatedTime { get; set; } = DateTime.Now;

        public DateTime ModifiedTime { get; set; } = DateTime.Now;

        public Version Version { get; set; } = new Version(0, 1);
    }
}