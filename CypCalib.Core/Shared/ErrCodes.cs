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

        public static ErrCodes SUCCESS => new(ErrorCodeEnum.SUCCESS);
        public static ErrCodes JSONRPC_RESP_EMPTY =>
            new(ErrorCodeEnum.JSONRPC_RESP_EMPTY, "JsonRPC 返回值为空。");
        public static ErrCodes JSONRPC_EXEX_FAILED =>
            new(ErrorCodeEnum.JSONRPC_EXEX_FAILED, "JsonRPC 命令执行失败。");
        public static ErrCodes FSM_MANAGER_BUSY =>
            new(ErrorCodeEnum.FSM_MANAGER_BUSY, "当前状态机忙，无法执行新任务。");
        public static ErrCodes LASER_IS_BUSY =>
            new ErrCodes(ErrorCodeEnum.LASER_IS_BUSY, "跟踪仪正忙。");
        public static ErrCodes LASER_OPERATION_CANCELED =>
            new ErrCodes(ErrorCodeEnum.LASER_OPERATION_CANCELED, "跟踪仪任务取消。");
        public static ErrCodes LASER_CONNECT_FIRST =>
            new ErrCodes(ErrorCodeEnum.LASER_CONNECT_FIRST, "未注册回调函数，请先连接跟踪仪。");
        public static ErrCodes LASER_CONNECT_FAILED =>
            new ErrCodes(ErrorCodeEnum.LASER_CONNECT_FAILED, "跟踪仪连接失败。");
        public static ErrCodes LASER_DISCONNECT_FAILED =>
            new ErrCodes(ErrorCodeEnum.LASER_DISCONNECT_FAILED, "跟踪仪断开失败。");
        public static ErrCodes LASER_HOME_FAILED =>
            new ErrCodes(ErrorCodeEnum.LASER_HOME_FAILED, "跟踪仪回原点失败。");
    }
}