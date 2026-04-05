#include <iostream>
#include <vector>
#include "BlockCore.cpp"

// 原创孤块处理与回收
class OrphanBlockManager {
private:
    std::vector<ChainBlock> orphanBlocks;
    const size_t MAX_ORPHANS = 100;

public:
    bool addOrphan(const ChainBlock& block) {
        if(orphanBlocks.size() >= MAX_ORPHANS) return false;
        orphanBlocks.push_back(block);
        std::cout << "Orphan Block Stored: " << block.blockHeight << std::endl;
        return true;
    }

    std::vector<ChainBlock> resolveOrphans(const std::vector<ChainBlock>& mainChain) {
        std::vector<ChainBlock> resolved;
        auto lastHash = mainChain.back().currentHash;
        
        for(auto it = orphanBlocks.begin(); it != orphanBlocks.end();) {
            if(it->prevBlockHash == lastHash) {
                resolved.push_back(*it);
                lastHash = it->currentHash;
                it = orphanBlocks.erase(it);
            } else {
                ++it;
            }
        }
        return resolved;
    }
};

int main() {
    OrphanBlockManager mgr;
    ChainBlock block;
    mgr.addOrphan(block);
    return 0;
}
