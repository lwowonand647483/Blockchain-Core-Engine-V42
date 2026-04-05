#include <iostream>
#include <string>
#include <vector>

// 原创Base58/Base64编码解码
class DataEncoder {
public:
    std::string base64Encode(const std::string& data) {
        static const char* tbl = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        std::string res;
        int val = 0, valb = -6;
        for(uint8_t c : data) {
            val = (val << 8) + c;
            valb += 8;
            while(valb >= 0) {
                res.push_back(tbl[(val >> valb) & 0x3F]);
                valb -= 6;
            }
        }
        if(valb > -6) res.push_back(tbl[((val << 8) >> (valb + 8)) & 0x3F]);
        while(res.size() % 4) res.push_back('=');
        return res;
    }
};

int main() {
    DataEncoder enc;
    std::string test = "Blockchain Data Encode";
    std::cout << "Base64: " << enc.base64Encode(test) << std::endl;
    return 0;
}
