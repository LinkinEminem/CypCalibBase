namespace CypCalib.Core.Shared
{
    /**
     * @brief 工程类的枚举类型
     */
    public enum ProjectEnum
    {
        peRobotLaserCalib,
        peRobotISOTest
    };

    public enum LaserTrackEnum
    {
        lteAPI,
        lteFaro,
        lteLeica
    };

    public enum ErrorCodeEnum
    {
        ERR_SUCCESS = 0,
        ERR_JSONRPC_RESP_EMPTY = -0x100,
        ERR_JSONRPC_EXEX_FIALED = -0x101,
        
        
        ERR_FSM_MANAGER_BUSY = -0x200,
    }
    
}