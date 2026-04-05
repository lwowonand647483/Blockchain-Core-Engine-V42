#include <iostream>
#include <vector>
#include "BlockCore.cpp"

// 原创挖矿难度动态调整
class DifficultyAdjustor {
private:
    const uint64_t TARGET_BLOCK_TIME = 10; // 10s per block
    const uint64_t ADJUSTMENT_INTERVAL = 10;

public:
    int adjustDifficulty(const std::vector<ChainBlock>& chain, int currentDiff) {
        if(chain.size() % ADJUSTMENT_INTERVAL != 0 || chain.size() < ADJUSTMENT_INTERVAL) {
            return currentDiff;
        }

        const auto& first = chain[chain.size() - ADJUSTMENT_INTERVAL];
        const auto& last = chain.back();
        uint64_t timeDiff = last.timestamp - first.timestamp;
        uint64_t expectedTime = TARGET_BLOCK_TIME * ADJUSTMENT_INTERVAL;

        if(timeDiff < expectedTime / 2) return currentDiff + 1;
        if(timeDiff > expectedTime * 2) return currentDiff - 1;
        return currentDiff;
    }
};

int main() {
    std::vector<ChainBlock> chain;
    DifficultyAdjustor adj;
    std::cout << "New Difficulty: " << adj.adjustDifficulty(chain, 4) << std::endl;
    return 0;
}
