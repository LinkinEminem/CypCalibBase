using System;
using System.Runtime.InteropServices;
using System.Threading;
using System.Threading.Tasks;
using CypCalib.Core.Shared;
using Proxy;

namespace CypCalib.Core.Helper
{
    public class LaserTrackerHelper
    {
        public enum LaserType
        {
            apiCore,
            apiPro
        }

        #region 为内存映射做准备

        private struct Vector3
        {
            public float X;
            public float Y;
            public float Z;

            public Vector3(float x = 0, float y = 0, float z = 0)
            {
                X = x;
                Y = y;
                Z = z;
            }
        }

        private struct TaskResult
        {
            public uint Size;
            public readonly int TaskID;
            [MarshalAs(UnmanagedType.I1)]
            public readonly bool Success;
            public readonly int ErrorCode;
            public int Result1;
            public int Result2;
            public Vector3 Fv3;

            public TaskResult(float x = 0, float y = 0, float z = 0)
            {
                Size = 0;
                TaskID = -1;
                Success = false;
                ErrorCode = -1;
                Result1 = 0;
                Result2 = 0;
                Fv3 = new Vector3(x, y, z);
            }
        }

        #endregion

        // 通过 Interlocked.Increment 生成全局的任务 ID，保证原子性
        private static int _globalTaskID = 0;
        private static int GenerateTaskID() => Interlocked.Increment(ref _globalTaskID);
        private TaskCompletionSource<bool>? _curTcs;
        private int _isBusy = 0;
        public bool CallbackRegistered { get; private set; } = false;
        
        // 单例模式实现，暂未考虑跟踪仪类型切换
        private readonly TLaserTrackWrapper _laserTrackWrapper;
        static LaserTrackerHelper() { }
        private readonly LaserCallback _laserCallback;
        public static LaserTrackerHelper Instance { get; } = new();
        
        /**
         * @brief 被注册的回调函数，通过 Marshall 映射回 struct
         */
        private void OnLaserCallback(IntPtr p1, IntPtr p2)
        {
            try
            {
                var taskRst = Marshal.PtrToStructure<TaskResult>(p1);
                var taskId = Marshal.ReadInt32(p2);
                LogHelper.Info(
                    $"激光跟踪仪回调函数被调用，任务类型：{taskRst.TaskID}，结果：{taskRst.Success}，错误码：{taskRst.ErrorCode}，任务 ID：{taskId}");
                _curTcs?.SetResult(taskRst.Success);
            }
            catch (Exception e)
            {
                _curTcs?.SetException(e);
                LogHelper.Error(e.Message);
            }
        }
        
        private LaserTrackerHelper()
        {
            _laserTrackWrapper = new TLaserTrackWrapper(0);
            _laserCallback = OnLaserCallback;
        }

        public async Task<ErrCodes> ConnectAsync(string ipAddress, int devNum)
        {
            if (Interlocked.CompareExchange(ref _isBusy, 1, 0) != 0)
            {
                LogHelper.Error("激光跟踪仪 状态忙，无法执行其他操作。");
                return ErrCodes.LASER_IS_BUSY;
            }
            
            if (_laserTrackWrapper.IsConnected() || !CallbackRegistered)
            {
                return ErrCodes.LASER_CONNECT_FIRST;
            }

            try
            {
                _curTcs = new TaskCompletionSource<bool>();
                LogHelper.Info("执行 激光跟踪仪 Connect。");
                var rst = _laserTrackWrapper.Connect(ipAddress, devNum, _laserCallback, GenerateTaskID());
                if (rst != 0)
                {
                    LogHelper.Error($"激光跟踪仪 连接失败，错误码：{rst}。");
                    return ErrCodes.LASER_CONNECT_FAILED;
                }
                await _curTcs.Task;
                // TODO：根据结果做处理，不能直接 SUCCESS
                CallbackRegistered = true;
                return ErrCodes.SUCCESS;
            }
            finally
            {
                Interlocked.Exchange(ref _isBusy, 0);
                _curTcs = null;
            }
        }

        public async Task<ErrCodes> DisconnectAsync()
        {
            if (Interlocked.CompareExchange(ref _isBusy, 1, 0) != 0)
            {
                LogHelper.Error("激光跟踪仪 状态忙，无法执行其他操作。");
                return ErrCodes.LASER_IS_BUSY;
            }
            
            if (_laserTrackWrapper.IsConnected() || !CallbackRegistered)
            {
                return ErrCodes.LASER_CONNECT_FIRST;
            }

            try
            {
                _curTcs = new TaskCompletionSource<bool>();
                LogHelper.Info("执行 激光跟踪仪 Disconnect。");
                var rst = _laserTrackWrapper.Disconnect();
                if (rst != 0)
                {
                    LogHelper.Error($"激光跟踪仪 断开失败，错误码：{rst}。");
                    return ErrCodes.LASER_CONNECT_FAILED;
                }
                await _curTcs.Task;
                // TODO：根据结果做处理，不能直接 SUCCESS
                return ErrCodes.SUCCESS;
            }
            finally
            {
                Interlocked.Exchange(ref _isBusy, 0);
                _curTcs = null;
            }
        }

        public async Task<ErrCodes> Home(int smrSize)
        {
            if (Interlocked.CompareExchange(ref _isBusy, 1, 0) != 0)
            {
                LogHelper.Error("激光跟踪仪 状态忙，无法执行其他操作。");
                return ErrCodes.LASER_IS_BUSY;
            }
            
            if (_laserTrackWrapper.IsConnected() || !CallbackRegistered)
            {
                return ErrCodes.LASER_CONNECT_FIRST;
            }

            try
            {
                _curTcs = new TaskCompletionSource<bool>();
                LogHelper.Info("执行 激光跟踪仪 Home。");
                var rst = _laserTrackWrapper.Home(smrSize);
                if (rst != 0)
                {
                    LogHelper.Error($"激光跟踪仪 回 Home 失败，错误码：{rst}。");
                    return ErrCodes.LASER_HOME_FAILED;
                }
                await _curTcs.Task;
                // TODO：根据结果做处理，不能直接 SUCCESS
                return ErrCodes.SUCCESS;
            }
            finally
            {
                Interlocked.Exchange(ref _isBusy, 0);
                _curTcs = null;
            }
        }
        
    }
}