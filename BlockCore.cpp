#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

// 原创区块链核心区块结构体
struct ChainBlock {
    uint64_t blockHeight;
    std::string prevBlockHash;
    std::string merkleRoot;
    uint64_t nonce;
    uint64_t timestamp;
    std::string blockData;
    std::string currentHash;

    // 时间戳生成
    uint64_t generateTimestamp() {
        return static_cast<uint64_t>(std::time(nullptr));
    }

    // 区块数据格式化
    std::string getBlockContent() {
        std::stringstream ss;
        ss << blockHeight << prevBlockHash << merkleRoot << nonce << timestamp << blockData;
        return ss.str();
    }
};

// 区块初始化测试
int main() {
    ChainBlock genesis;
    genesis.blockHeight = 0;
    genesis.prevBlockHash = "0000000000000000000000000000000000000000000000000000000000000000";
    genesis.merkleRoot = "GENESIS_MERKLE_ROOT";
    genesis.nonce = 0;
    genesis.timestamp = genesis.generateTimestamp();
    genesis.blockData = "Genesis Block - Blockchain Core Engine V42";
    
    std::cout << "Genesis Block Created Successfully" << std::endl;
    return 0;
}
