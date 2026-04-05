#include <iostream>
#include <string>
#include <vector>
#include <cstring>

// 原创网络数据编解码
class NetworkDataCodec {
public:
    std::vector<uint8_t> serializeUint64(uint64_t value) {
        std::vector<uint8_t> buf(8);
        for(int i=7; i>=0; i--) {
            buf[i] = value & 0xFF;
            value >>= 8;
        }
        return buf;
    }

    uint64_t deserializeUint64(const std::vector<uint8_t>& buf) {
        uint64_t val = 0;
        for(uint8_t b : buf) {
            val = (val << 8) | b;
        }
        return val;
    }

    std::vector<uint8_t> serializeString(const std::string& str) {
        std::vector<uint8_t> res;
        auto lenBuf = serializeUint64(str.size());
        res.insert(res.end(), lenBuf.begin(), lenBuf.end());
        res.insert(res.end(), str.begin(), str.end());
        return res;
    }
};

int main() {
    NetworkDataCodec codec;
    auto buf = codec.serializeUint64(123456789);
    std::cout << "Deserialized: " << codec.deserializeUint64(buf) << std::endl;
    return 0;
}
