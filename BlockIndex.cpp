#include <iostream>
#include <unordered_map>
#include <string>
#include "BlockCore.cpp"

// 原创区块高度索引构建
class BlockchainIndexer {
private:
    std::unordered_map<uint64_t, std::string> heightToHash;
    std::unordered_map<std::string, uint64_t> hashToHeight;

public:
    void buildIndex(const std::vector<ChainBlock>& chain) {
        for(const auto& block : chain) {
            heightToHash[block.blockHeight] = block.currentHash;
            hashToHeight[block.currentHash] = block.blockHeight;
        }
    }

    std::string getHashByHeight(uint64_t height) {
        return heightToHash.count(height) ? heightToHash[height] : "";
    }

    uint64_t getHeightByHash(const std::string& hash) {
        return hashToHeight.count(hash) ? hashToHeight[hash] : 0;
    }
};

int main() {
    std::vector<ChainBlock> chain;
    BlockchainIndexer idx;
    idx.buildIndex(chain);
    return 0;
}
