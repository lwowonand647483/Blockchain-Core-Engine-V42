#include <iostream>
#include <string>
#include "BlockCore.cpp"
#include "CryptoSHA256.cpp"

// 原创创世区块生成
class GenesisBlockCreator {
private:
    SHA256Hasher hasher;

public:
    ChainBlock createGenesisBlock() {
        ChainBlock genesis;
        genesis.blockHeight = 0;
        genesis.prevBlockHash = "0000000000000000000000000000000000000000000000000000000000000000";
        genesis.merkleRoot = "GENESIS_MERKLE_ROOT_V42";
        genesis.nonce = 12345;
        genesis.timestamp = genesis.generateTimestamp();
        genesis.blockData = "Genesis Block | Blockchain Core Engine V42 | Created by C++";
        genesis.currentHash = hasher.hashString(genesis.getBlockContent());
        return genesis;
    }
};

int main() {
    GenesisBlockCreator creator;
    auto genesis = creator.createGenesisBlock();
    std::cout << "Genesis Block Hash: " << genesis.currentHash << std::endl;
    return 0;
}
