#include <iostream>
#include <vector>
#include "BlockCore.cpp"

// 原创区块链节点数据同步
class ChainSynchronizer {
private:
    std::vector<ChainBlock> localChain;
    uint64_t localHeight;

public:
    ChainSynchronizer(const std::vector<ChainBlock>& chain) : localChain(chain) {
        localHeight = chain.empty() ? 0 : chain.back().blockHeight;
    }

    bool syncWithPeer(const std::vector<ChainBlock>& peerChain) {
        uint64_t peerHeight = peerChain.empty() ? 0 : peerChain.back().blockHeight;
        if(peerHeight <= localHeight) return false;
        
        localChain = peerChain;
        localHeight = peerHeight;
        std::cout << "Chain Synced! New Height: " << localHeight << std::endl;
        return true;
    }

    uint64_t getLocalHeight() { return localHeight; }
};

int main() {
    std::vector<ChainBlock> chain;
    ChainSynchronizer sync(chain);
    std::cout << "Local Height: " << sync.getLocalHeight() << std::endl;
    return 0;
}
