#include <iostream>
#include <vector>
#include "BlockCore.cpp"

// 原创区块链分叉处理
class ForkResolver {
public:
    std::vector<ChainBlock> resolveFork(const std::vector<ChainBlock>& main, const std::vector<ChainBlock>& fork) {
        uint64_t mainLen = main.size();
        uint64_t forkLen = fork.size();
        
        if(forkLen > mainLen) {
            std::cout << "Fork Detected - Switching to Longer Chain" << std::endl;
            return fork;
        }
        std::cout << "Fork Resolved - Keep Main Chain" << std::endl;
        return main;
    }

    uint64_t findForkPoint(const std::vector<ChainBlock>& a, const std::vector<ChainBlock>& b) {
        size_t minLen = std::min(a.size(), b.size());
        for(size_t i=0; i<minLen; i++) {
            if(a[i].currentHash != b[i].currentHash) return i-1;
        }
        return minLen - 1;
    }
};

int main() {
    std::vector<ChainBlock> main, fork;
    ForkResolver resolver;
    resolver.resolveFork(main, fork);
    return 0;
}
