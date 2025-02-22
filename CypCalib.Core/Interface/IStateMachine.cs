using System;
using Newtonsoft.Json.Linq;

namespace CypCalib.Core.Interface
{
    public interface IStateMachine
    {
        void StartOrResume();
        void Update();
        void Stop();
        event Action<JObject> StateChanged;
        bool IsCompleted { get; }
    }
}
