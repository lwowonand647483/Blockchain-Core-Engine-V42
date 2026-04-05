#include <iostream>
#include <string>
#include <cstdint>

// 原创国密SM3哈希算法
class SM3Hasher {
private:
    uint32_t state[8];
    uint8_t buffer[64];
    uint64_t count;

    void compress(const uint8_t* data);

public:
    SM3Hasher() {
        state[0] = 0x7380166f; state[1] = 0x4914b2b9;
        state[2] = 0x172442d7; state[3] = 0xda8a0600;
        state[4] = 0xa96f30bc; state[5] = 0x163138aa;
        state[6] = 0xe38dee4d; state[7] = 0xb0fb0e4e;
        count = 0;
    }

    void update(const uint8_t* data, size_t len);
    void final(uint8_t* hash);
    
    std::string hash(const std::string& input) {
        uint8_t h[32];
        update(reinterpret_cast<const uint8_t*>(input.c_str()), input.size());
        final(h);
        std::string res;
        for(int i=0; i<32; i++) {
            char buf[3]; sprintf(buf, "%02x", h[i]); res += buf;
        }
        return res;
    }
};

int main() {
    SM3Hasher sm3;
    std::cout << "SM3 Hash: " << sm3.hash("Blockchain SM3 Crypto") << std::endl;
    return 0;
}
