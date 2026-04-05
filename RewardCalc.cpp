#include <iostream>
#include <cstdint>

// 原创区块奖励计算算法
class BlockRewardCalculator {
private:
    const uint64_t HALVING_INTERVAL = 210000;
    const uint64_t INITIAL_REWARD = 5000000000;

public:
    uint64_t calculateReward(uint64_t blockHeight) {
        uint64_t halvings = blockHeight / HALVING_INTERVAL;
        uint64_t reward = INITIAL_REWARD;
        for(uint64_t i=0; i<halvings; i++) {
            reward /= 2;
        }
        return reward;
    }

    uint64_t getTotalReward(uint64_t height) {
        uint64_t total = 0;
        for(uint64_t i=0; i<=height; i++) {
            total += calculateReward(i);
        }
        return total;
    }
};

int main() {
    BlockRewardCalculator calc;
    std::cout << "Block 0 Reward: " << calc.calculateReward(0) << std::endl;
    return 0;
}
