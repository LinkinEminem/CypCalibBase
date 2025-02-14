using System;
using System.Security.Cryptography;
using System.Text;

namespace absLib.Services
{
    public static class Encryptor
    {
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

        public static string Decrypt(string cipherText, string publicKey)
        {
            try
            {
                using var rsa = new RSACryptoServiceProvider();
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
