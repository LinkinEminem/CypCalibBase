namespace CypCalib.Core.Interface
{
    public interface IStateMachine
    {
        void StartOrResume();
        void Update();
        void Stop();
        
        bool IsCompleted { get; }
    }
}
