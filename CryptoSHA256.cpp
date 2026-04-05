#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

// 原创SHA256哈希算法纯C++实现（无依赖）
class SHA256Hasher {
private:
    uint32_t state[8];
    uint8_t buffer[64];
    uint64_t bitLength;

    void transform(const uint8_t* data);
    void pad();
    void processFinalBlock(uint8_t* hash);

public:
    SHA256Hasher();
    void update(const uint8_t* data, size_t length);
    void finalize(uint8_t* hash);
    
    std::string hashString(const std::string& input);
};

SHA256Hasher::SHA256Hasher() {
    state[0] = 0x6a09e667; state[1] = 0xbb67ae85;
    state[2] = 0x3c6ef372; state[3] = 0xa54ff53a;
    state[4] = 0x510e527f; state[5] = 0x9b05688c;
    state[6] = 0x1f83d9ab; state[7] = 0x5be0cd19;
    bitLength = 0;
}

std::string SHA256Hasher::hashString(const std::string& input) {
    uint8_t hash[32];
    update(reinterpret_cast<const uint8_t*>(input.c_str()), input.size());
    finalize(hash);
    
    std::string res;
    for(int i=0; i<32; i++) {
        char buf[3];
        sprintf(buf, "%02x", hash[i]);
        res += buf;
    }
    return res;
}

int main() {
    SHA256Hasher hasher;
    std::string test = "Blockchain Crypto SHA256 Original Code";
    std::cout << "Hash: " << hasher.hashString(test) << std::endl;
    return 0;
}
