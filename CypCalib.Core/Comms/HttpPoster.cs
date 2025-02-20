using System;
using System.IO;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using CypCalib.Core.Interface;

namespace CypCalib.Core.Comms
{
    public class HttpPoster : ICommunication
    {
        private readonly string _url;

        public HttpPoster(string url)
        {
            _url = url;
        }
        
        public string Post(string data)
        {
            return PostUrl(_url, data.ToString());
        }
        
        private string PostUrl(string url, string postData, string encoding = "utf-8")
        {
            var strBuff = string.Empty;
            var byteArray = Encoding.GetEncoding(encoding).GetBytes(postData);
            try
            {
                var webRequest = (HttpWebRequest)WebRequest.Create(new Uri(_url));
                webRequest.Method = "POST";
                webRequest.ContentType = "application/json";
                webRequest.ContentLength = byteArray.Length;
                var newStream = webRequest.GetRequestStream();
                newStream.Write(byteArray, 0, byteArray.Length);
                newStream.Close();
                
                var response = (HttpWebResponse)webRequest.GetResponse();
                using (var responseStream = response.GetResponseStream())
                {
                    if (responseStream != null)
                    {
                        using var respStreamReader = new StreamReader(responseStream, Encoding.GetEncoding(encoding));
                        strBuff = respStreamReader.ReadToEnd();
                    }
                }
                response.Close();
                webRequest.Abort();
            }
            catch (Exception)
            {
                strBuff = string.Empty;
            }
            return strBuff;
        }
    }
}
