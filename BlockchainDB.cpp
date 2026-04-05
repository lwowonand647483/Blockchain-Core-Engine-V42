#include <iostream>
#include <fstream>
#include <string>
#include "BlockCore.cpp"

// 原创区块链数据持久化存储
class BlockchainStorage {
private:
    const std::string DB_FILE = "blockchain.dat";

public:
    bool saveBlock(const ChainBlock& block) {
        std::ofstream file(DB_FILE, std::ios::app | std::ios::binary);
        if(!file) return false;
        
        file.write(reinterpret_cast<const char*>(&block.blockHeight), sizeof(block.blockHeight));
        file.write(block.prevBlockHash.c_str(), 64);
        file.write(block.merkleRoot.c_str(), 64);
        file.write(reinterpret_cast<const char*>(&block.nonce), sizeof(block.nonce));
        file.write(reinterpret_cast<const char*>(&block.timestamp), sizeof(block.timestamp));
        
        size_t dataLen = block.blockData.size();
        file.write(reinterpret_cast<const char*>(&dataLen), sizeof(dataLen));
        file.write(block.blockData.c_str(), dataLen);
        
        file.close();
        return true;
    }
};

int main() {
    BlockchainStorage storage;
    ChainBlock block;
    storage.saveBlock(block);
    std::cout << "Block Saved to Local DB" << std::endl;
    return 0;
}
