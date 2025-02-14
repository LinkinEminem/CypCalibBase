using System;
using System.Security.Cryptography;
using System.Text;

namespace absLib.Services
{
    public static class Encryptor
    {
        public static void GenerateKeys(out string publicKey, out string privateKey)
        {
            using var rsa = new RSACryptoServiceProvider(2048); // 2048 位密钥
            publicKey = rsa.ToXmlString(false);  // 公钥（仅含 Modulus 和 Exponent）
            privateKey = rsa.ToXmlString(true);  // 私钥（含全部参数）
        }
        
        public static string Encrypt(string plainText, string publicKey)
        {
            try
            {
                using var rsa = new RSACryptoServiceProvider();
                rsa.FromXmlString(publicKey);
                var plainBytes = Encoding.UTF8.GetBytes(plainText);
                var encryptedBytes = rsa.Encrypt(plainBytes, false);
                return Convert.ToBase64String(encryptedBytes);
            }
            catch (Exception ex)
            {
                throw new CryptographicException("Failed to encrypt data.", ex);
            }
        }

        public static string Decrypt(string cipherText, string privateKey)
        {
            try
            {
                using var rsa = new RSACryptoServiceProvider();
                rsa.FromXmlString(privateKey); // 加载私钥
                var cipherBytes = Convert.FromBase64String(cipherText);
                var decryptedBytes = rsa.Decrypt(cipherBytes, false);
                return Encoding.UTF8.GetString(decryptedBytes);
            }
            catch (Exception ex)
            {
                throw new CryptographicException("Failed to decrypt data.", ex);
            }
        }
    }
}
