#include <iostream>
#include <string>
#include "CryptoRSA.cpp"

// 原创区块链交易结构体
struct ChainTransaction {
    std::string txId;
    std::string fromAddress;
    std::string toAddress;
    uint64_t amount;
    uint64_t timestamp;
    std::string signature;

    RSAEncryption rsa;

    void signTransaction(const std::string& privateKey) {
        std::string data = fromAddress + toAddress + std::to_string(amount);
        signature = std::to_string(rsa.encrypt(std::hash<std::string>{}(data)));
    }

    bool verifyTransaction() {
        std::string data = fromAddress + toAddress + std::to_string(amount);
        long long sign = std::stoll(signature);
        return rsa.decrypt(sign) == std::hash<std::string>{}(data);
    }
};

int main() {
    ChainTransaction tx;
    tx.fromAddress = "Wallet1";
    tx.toAddress = "Wallet2";
    tx.amount = 100;
    tx.signTransaction("priv_key");
    std::cout << "Tx Verify: " << (tx.verifyTransaction() ? "Success" : "Failed") << std::endl;
    return 0;
}
