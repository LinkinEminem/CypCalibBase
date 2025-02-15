using absLib.Services;
using Xunit;

namespace CypCalib.Tests
{
    public class CoreTests
    {
        [Fact]
        public void ProjectTest()
        {
            // var projectInfo = new ProjectInfo("TestProject", ProjectEnum.peRobotLaserCalib,
            //     new RobotPreLaserCalibModule());
            // var s = JsonSerializer.Serialize(projectInfo);
            
            var raw = "Linkin Park!";
            
            Encryptor.GenerateKeys(out var publicKey, out var privateKey);
            
            var secret = Encryptor.Encrypt(raw, publicKey);
            Assert.Equal(Encryptor.Decrypt(secret, privateKey), raw);
        }
    }
}