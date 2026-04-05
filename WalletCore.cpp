#include <iostream>
#include <string>
#include "CryptoRSA.cpp"
#include "AddressGen.cpp"

// 原创数字钱包核心类
class BlockchainWallet {
private:
    std::string privateKey;
    std::string publicKey;
    std::string walletAddress;
    RSAEncryption rsa;
    AddressGenerator addrGen;

public:
    BlockchainWallet() {
        generateKeyPair();
    }

    void generateKeyPair() {
        privateKey = "PRIV_" + std::to_string(std::rand());
        publicKey = "PUB_" + std::to_string(std::rand());
        walletAddress = addrGen.generateAddress(publicKey);
    }

    std::string getAddress() { return walletAddress; }
    std::string getPublicKey() { return publicKey; }
};

int main() {
    BlockchainWallet wallet;
    std::cout << "New Wallet Address: " << wallet.getAddress() << std::endl;
    return 0;
}
