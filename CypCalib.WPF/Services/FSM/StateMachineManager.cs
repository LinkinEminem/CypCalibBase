using CypCalib.Core.Interface;
using CypCalib.Core.Shared;

namespace CypCalib.WPF.Services.FSM
{
    public class StateMachineManager
    {
        private enum ManagerState
        {
            idle,
            running
        }
        
        static StateMachineManager() { }
        private StateMachineManager() { }
        public static StateMachineManager Instance { get; } = new();
        
        private ManagerState _state = ManagerState.idle;
        private readonly object _lockObject = new();
        
        private IStateMachine _curTask;
        
        public bool IsCompleted => false;
        
        public ErrCodes StartOrResume(IStateMachine curTask)
        {
            lock (_lockObject)
            {
                if (_state == ManagerState.running)
                {
                    return ErrCodes.ERR_FSM_MANAGER_BUSY;
                }
                _state = ManagerState.running;
                _curTask = curTask;
                _curTask?.StartOrResume();
                LogHelper.Info($"主状态机加载：{curTask.ToString()}");
            }
            return ErrCodes.ERR_SUCCESS;
        }

        public void Update()
        {
            lock (_lockObject)
            {
                if (_state != ManagerState.running || _curTask == null) return;
                
                ProcessTask();
            }
        }

        private void ProcessTask()
        {
            switch (_state)
            {
                case ManagerState.running:
                {
                    _curTask.Update();
                    if (_curTask.IsCompleted)
                    {
                        _state = ManagerState.idle;
                        _curTask = null;
                    }
                    break;
                }
                case ManagerState.idle:
                default:
                    break;
            }
        }
        
        public void Stop()
        {
            _state = ManagerState.idle;
        }
    }
}