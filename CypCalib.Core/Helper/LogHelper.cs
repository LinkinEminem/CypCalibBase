using NLog;

namespace CypCalib.Core.Helper
{
    public static class LogHelper
    {
        private static readonly Logger Logger = LogManager.GetCurrentClassLogger();
        
        public static void Debug(string message, params object[] args)
        {
            Logger.Debug(message, args);
        }

        public static void Info(string message, params object[] args)
        {
            Logger.Info(message, args);
        }

        public static void Warn(string message, params object[] args)
        {
            Logger.Warn(message, args);
        }

        public static void Error(string message, params object[] args)
        {
            Logger.Error(message, args);
        }

        public static void Fatal(string message, params object[] args)
        {
            Logger.Fatal(message, args);
        }
    }
}
