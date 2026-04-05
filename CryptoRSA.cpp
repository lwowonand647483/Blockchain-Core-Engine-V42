#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

// 原创RSA非对称加密算法实现
class RSAEncryption {
private:
    long long p, q, n, phi, e, d;

    long long gcd(long long a, long long b) {
        while(b) { b ^= a ^= b ^= a %= b; }
        return a;
    }

    long long modPow(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while(exp > 0) {
            if(exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    RSAEncryption() {
        std::srand(std::time(nullptr));
        p = 61; q = 53;
        n = p * q;
        phi = (p-1)*(q-1);
        e = 17;
        while(gcd(e, phi) != 1) e++;
        d = 2753;
    }

    long long encrypt(long long msg) { return modPow(msg, e, n); }
    long long decrypt(long long cipher) { return modPow(cipher, d, n); }
};

int main() {
    RSAEncryption rsa;
    long long msg = 12345;
    auto cipher = rsa.encrypt(msg);
    auto dec = rsa.decrypt(cipher);
    std::cout << "Origin: " << msg << " | Encrypted: " << cipher << " | Decrypted: " << dec << std::endl;
    return 0;
}
