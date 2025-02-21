using System;

namespace CypCalib.Core.Shared
{
    public class ErrCodes
    {
        public ErrorCodeEnum Code { get; set; }
        public string? Message { get; set; }

        public ErrCodes(ErrorCodeEnum code, string message = "")
        {
            Code = code;
            Message = message;
        }

        public static ErrCodes ERR_SUCCESS => new(ErrorCodeEnum.ERR_SUCCESS);
        public static ErrCodes ERR_JSONRPC_RESP_EMPTY => new(ErrorCodeEnum.ERR_JSONRPC_RESP_EMPTY, "JsonRPC 返回值为空。");
        public static ErrCodes ERR_JSONRPC_EXEX_FIALED => new(ErrorCodeEnum.ERR_JSONRPC_EXEX_FIALED, "JsonRPC 命令执行失败。");
        public static ErrCodes ERR_FSM_MANAGER_BUSY => new(ErrorCodeEnum.ERR_FSM_MANAGER_BUSY, "当前状态机忙，无法执行新任务。");

    }
}