using CypCalib.Core.Comms;
using CypCalib.Core.Shared;
using Newtonsoft.Json.Linq;

namespace CypCalib.WPF.Services
{
    public static class CypWeldJsonRpcApi
    {
        private const string Url = "http://localhost:5060/fsNc";

        private static readonly HttpPoster HttpPoster = new(Url);

        private static ErrCodes AssembleCmd(string method, JObject param)
        {
            param.Add("method", method);
            param.Add("jsonrpc", 2.0);
            param.Add("id", 0);
            var rst = HttpPoster.Post(param.ToString());

            if (string.IsNullOrEmpty(rst))
            {
                return ErrCodes.ERR_JSONRPC_RESP_EMPTY;
            }

            try
            {
                var jsonResp = JObject.Parse(rst);
                return jsonResp["result"]?.ToString() == "True" ? ErrCodes.ERR_SUCCESS : ErrCodes.ERR_JSONRPC_EXEX_FIALED;
            }
            catch
            {
                return ErrCodes.ERR_JSONRPC_EXEX_FIALED;
            }
        }
        
        public static ErrCodes RobotMcsMoveTo(double[] config)
        {
            var obj = new JObject();
            var arr = new JArray { config };
            obj["params"] = arr;
            return AssembleCmd("McsSafeMoveTo", obj);
        }
    }
}