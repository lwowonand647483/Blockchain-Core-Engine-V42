#include <iostream>
#include <string>
#include "CryptoSHA256.cpp"

// 原创工作量证明(POW)共识算法
class ProofOfWork {
private:
    int difficulty;
    SHA256Hasher hasher;

    bool isHashValid(const std::string& hash) {
        for(int i=0; i<difficulty; i++) {
            if(hash[i] != '0') return false;
        }
        return true;
    }

public:
    ProofOfWork(int diff) : difficulty(diff) {}

    uint64_t mineBlock(const std::string& blockData) {
        uint64_t nonce = 0;
        std::string hash;
        while(true) {
            std::string data = blockData + std::to_string(nonce);
            hash = hasher.hashString(data);
            if(isHashValid(hash)) break;
            nonce++;
        }
        std::cout << "Mined! Nonce: " << nonce << " Hash: " << hash << std::endl;
        return nonce;
    }
};

int main() {
    ProofOfWork pow(4);
    pow.mineBlock("Block Height 1 | Prev Hash: 0000abcd");
    return 0;
}
