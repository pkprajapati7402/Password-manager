#include "encryptor.h"
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <cstring>

const unsigned char key[32] = "your-32-byte-key";
const unsigned char iv[16] = "your-16-byte-iv";

std::string Encryptor::encrypt(const std::string &data) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    std::string ciphertext;
    ciphertext.resize(data.size() + AES_BLOCK_SIZE);
    int outlen1 = (int)ciphertext.size();

    EVP_EncryptUpdate(ctx, (unsigned char*)&ciphertext[0], &outlen1, (const unsigned char*)data.data(), (int)data.size());

    int outlen2;
    EVP_EncryptFinal_ex(ctx, (unsigned char*)&ciphertext[outlen1], &outlen2);
    EVP_CIPHER_CTX_free(ctx);

    ciphertext.resize(outlen1 + outlen2);
    return ciphertext;
}

std::string Encryptor::decrypt(const std::string &data) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    std::string plaintext;
    plaintext.resize(data.size());
    int outlen1 = (int)plaintext.size();

    EVP_DecryptUpdate(ctx, (unsigned char*)&plaintext[0], &outlen1, (const unsigned char*)data.data(), (int)data.size());

    int outlen2;
    EVP_DecryptFinal_ex(ctx, (unsigned char*)&plaintext[outlen1], &outlen2);
    EVP_CIPHER_CTX_free(ctx);

    plaintext.resize(outlen1 + outlen2);
    return plaintext;
}
