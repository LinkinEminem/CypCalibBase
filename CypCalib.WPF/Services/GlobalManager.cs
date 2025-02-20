using System;
using System.Collections.Generic;
using System.Windows;

namespace CypCalib.WPF.Services
{
    public static class GlobalManager
    {
        private static readonly Dictionary<string, Action<object>> Dir = new();

        private static bool IsRegistered(string key)
        {
            return !string.IsNullOrEmpty(key) && Dir.ContainsKey(key);
        }
        
        public static void Register(string key, Action<object> action)
        {
            if (!String.IsNullOrEmpty(key) && !Dir.ContainsKey(key))
            {
                Dir.Add(key, action);
            }
        }

        public static void Unregister(string key)
        {
            if (IsRegistered(key))
            {
                Dir.Remove(key);
            }
        }

        public static void DoAction(string key, object obj)
        {
            if (IsRegistered(key))
            {
                Dir[key].Invoke(obj);
            }
        }
        
        public static void WindowRegister<TOwner, TView, TViewModel>(string token, TOwner owner, Func<object, TViewModel> vmFactory)
            where TOwner : Window, new()
            where TView : Window, new()
            where TViewModel : class
        {
            GlobalManager.Register(token, obj =>
            {
                var view = new TView
                {
                    DataContext = vmFactory(obj),
                    Owner = owner
                };
                view.ShowDialog();
            });
        }
        
        // private static bool IsCallbackRegistered(string key)
        // {
        //     return !string.IsNullOrEmpty(key) && Callbacks.ContainsKey(key);
        // }
        //
        // public static void RegisterCallback(string key, Action<object> action)
        // {
        //     if (!IsCallbackRegistered(key))
        //     {
        //         Callbacks.Add(key, action);
        //     }
        // }
        //
        // public static void InvokeCallback(string key, object obj)
        // {
        //     if (IsCallbackRegistered(key))
        //     {
        //         Callbacks[key].Invoke(obj);
        //     }
        // }
    }
}
