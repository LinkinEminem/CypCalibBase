using System;
using System.Collections.Generic;

namespace CypCalib.WPF.Services
{
    public class WindowsManager
    {
        private static Dictionary<string, Action<object>> _dir = new Dictionary<string, Action<object>>();

        private static bool IsRegistered(string key)
        {
            return !string.IsNullOrEmpty(key) && _dir.ContainsKey(key);
        }

        public static void Register(string key, Action<object> action)
        {
            if (!String.IsNullOrEmpty(key) && !_dir.ContainsKey(key))
            {
                _dir.Add(key, action);
            }
        }

        public static void Unregister(string key)
        {
            if (IsRegistered(key))
            {
                _dir.Remove(key);
            }
        }

        public static void DoAction(string key, object obj)
        {
            if (IsRegistered(key))
            {
                _dir[key].Invoke(obj);
            }
        }
    }
}
