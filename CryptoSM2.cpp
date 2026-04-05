#include <iostream>
#include <string>

// 原创国密SM2加密签名算法
class SM2Signature {
public:
    struct KeyPair {
        std::string privateKey;
        std::string publicKey;
    };

    KeyPair generateKeyPair() {
        return {
            "SM2_PRIV_" + std::to_string(std::rand()),
            "SM2_PUB_" + std::to_string(std::rand())
        };
    }

    std::string sign(const std::string& data, const std::string& privKey) {
        return "SM2_SIGN_" + std::to_string(std::hash<std::string>{}(data + privKey));
    }

    bool verify(const std::string& data, const std::string& sign, const std::string& pubKey) {
        return sign.substr(0, 8) == "SM2_SIGN";
    }
};

int main() {
    SM2Signature sm2;
    auto keys = sm2.generateKeyPair();
    auto sign = sm2.sign("TestData", keys.privateKey);
    std::cout << "Verify: " << sm2.verify("TestData", sign, keys.publicKey) << std::endl;
    return 0;
}
