using CypCalib.Core.Domain.Models;
using CypCalib.Core.Domain.Modules;
using CypCalib.Core.Domain.Shared;
using Xunit;

namespace CypCalib.Tests
{
    public class CoreTests
    {
        [Fact]
        public void ProjectTest()
        {
            var ProjectInfo = new ProjectInfo("TestProject", ProjectEnum.peRobotLaserCalib,
                new RobotPreLaserCalibModule());
        }
    }
}