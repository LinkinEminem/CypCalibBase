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
        SUCCESS = 0,
        JSONRPC_RESP_EMPTY = -0x100,
        JSONRPC_EXEX_FAILED = -0x101,
        
        FSM_MANAGER_BUSY = -0x200,
        
        LASER_IS_BUSY = -0x300,
        LASER_OPERATION_CANCELED = -0x301,
        LASER_CONNECT_FIRST = -0x302,
        
        LASER_CONNECT_FAILED = -0x310,
        LASER_DISCONNECT_FAILED = -0x311,
        LASER_HOME_FAILED = -0x312,
    }
    
}