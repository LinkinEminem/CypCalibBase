using System;
using CypCalib.Core.Interface;
using Newtonsoft.Json.Linq;

namespace CypCalib.WPF.Services.FSM
{
    public class RobotLaserCalibFSM : IStateMachine
    {
        private enum StateMachineState
        {
            idle,
            running,
            paused,
            error
        }
        
        private StateMachineState _state = StateMachineState.idle;
        private int _substate = 0;
        public bool IsCompleted { get; private set; } = false;
        private readonly object _lockObject = new();

        public event Action<JObject> StateChanged = delegate { };
        private int _test = 0;
        
        public void StartOrResume()
        {
            lock (_lockObject)
            {
                if (_state == StateMachineState.running) return;
                
                _state = StateMachineState.running;
                _substate = 0;
            }
        }

        public void Update()
        {
            lock (_lockObject)
            {
                if (_state != StateMachineState.running) return;

                ProcessMoving();
            }
        }

        private void ProcessMoving()
        {
            switch (_substate)
            {
                case 0:
                {
                    try
                    {
                        StateChanged?.Invoke(new JObject
                        {
                            ["test"] = _test
                        });
                        LogHelper.Debug($"Test = {_test}");
                    }
                    catch (Exception)
                    {
                        DoMoveError();
                        return;
                    }
                    _substate += 1;
                    break;
                }

                case 1:
                {
                    StateChanged?.Invoke(new JObject
                    {
                        ["test"] = _test
                    });
                    _substate += 1;
                    break;
                }

                case 2:
                {
                    StateChanged?.Invoke(new JObject
                    {
                        ["test"] = _test
                    });
                    _test += 1;
                    _substate += 1;
                    break;
                }

                case 3:
                {
                    StateChanged?.Invoke(new JObject
                    {
                        ["test"] = _test
                    });
                    if (_test > 5)
                    {
                        DoMoveDone();
                    }
                    _substate = 0;
                    break;
                }
            }
        }

        private void DoMoveDone()
        {
            IsCompleted = true;
        }

        private void DoMoveError()
        {
            _state = StateMachineState.error;
        }

        public void Pause()
        {
            if (_state == StateMachineState.running)
            {
                _state = StateMachineState.paused;
            }
        }
        
        public void Stop()
        {
            if (_state is StateMachineState.running or StateMachineState.paused)
            {
                _state = StateMachineState.idle;
            }
        }
    }
}
