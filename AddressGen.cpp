#include <iostream>
#include <string>
#include "CryptoSHA256.cpp"

// 原创区块链地址生成算法
class AddressGenerator {
private:
    SHA256Hasher hasher;

    std::string base58Encode(const std::string& input) {
        const char* charset = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
        std::string res;
        for(unsigned char c : input) {
            res += charset[c % 58];
        }
        return res;
    }

public:
    std::string generateAddress(const std::string& publicKey) {
        std::string hash = hasher.hashString(publicKey);
        hash = hasher.hashString(hash);
        return "bc" + base58Encode(hash.substr(0, 34));
    }
};

int main() {
    AddressGenerator gen;
    std::string addr = gen.generateAddress("PUB_KEY_EXAMPLE");
    std::cout << "Blockchain Address: " << addr << std::endl;
    return 0;
}
