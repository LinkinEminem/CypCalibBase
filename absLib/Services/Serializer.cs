using Newtonsoft.Json;

namespace absLib.Services
{
    public static class JsonSerializer
    {
        public static string Serialize(object obj)
        {
            return JsonConvert.SerializeObject(obj, Formatting.Indented);
        }

        public static object Deserialize(string data)
        {
            return JsonConvert.DeserializeObject(data);
        }
    }
}
