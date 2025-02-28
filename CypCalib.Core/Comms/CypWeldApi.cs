using CypCalib.Core.Comms;
using CypCalib.Core.Shared;
using Newtonsoft.Json.Linq;

namespace CypCalib.WPF.Services
{
    public static class CypWeldJsonRpcApi
    {
        private const string Url = "http://localhost:5060/fsNc";

        private static readonly JsonRpcPoster JsonRpcPoster = new(Url);

        private static ErrCodes AssembleCmd(string method, JObject param)
        {
            param.Add("method", method);
            param.Add("jsonrpc", "2.0");
            param.Add("id", 0);
            var rst = JsonRpcPoster.Post(param.ToString());

            if (string.IsNullOrEmpty(rst))
            {
                return ErrCodes.JSONRPC_RESP_EMPTY;
            }

            try
            {
                var jsonResp = JObject.Parse(rst);
                return jsonResp["result"]?.ToString() == "True" ? ErrCodes.SUCCESS : ErrCodes.JSONRPC_EXEX_FAILED;
            }
            catch
            {
                return ErrCodes.JSONRPC_EXEX_FAILED;
            }
        }
        
        public static ErrCodes RobotMcsMoveTo(double[] config)
        {
            var arr = new JArray { config };
            var obj = new JObject
            {
                ["params"] = arr
            };
            return AssembleCmd("OTIIMcsSafeMoveTo", obj);
        }

        public static ErrCodes RobotMcsPlanMoveTo(double[] config)
        {
            var arr = new JArray { config };
            var obj = new JObject
            {
                ["params"] = arr
            };
            return AssembleCmd("McsPlanMoveTo", obj);
        }
        
        public static ErrCodes RobotDecStop()
        {
            var obj = new JObject
            {
                ["params"] = new JArray()
            };
            return AssembleCmd("DecStopRobot", obj);
        }

        public static ErrCodes RobotWriteParam(double[] configs)
        {
            var arr = new JArray();
            foreach (var config in configs)
            {
                arr.Add(config);
            }

            var obj = new JObject
            {
                ["params"] = arr
            };
            return AssembleCmd("OTIIModifyRobotParam", obj);
        }
        
    }
}