#include <iostream>
#include <string>
#include <vector>
#include "BlockCore.cpp"

// 原创区块链运行状态监控
class BlockchainMonitor {
public:
    struct ChainStatus {
        uint64_t blockHeight;
        uint64_t peerCount;
        uint64_t pendingTxCount;
        double avgBlockTime;
        std::string nodeStatus;
    };

    ChainStatus getChainStatus(const std::vector<ChainBlock>& chain, size_t peers, size_t txs) {
        ChainStatus status;
        status.blockHeight = chain.empty() ? 0 : chain.back().blockHeight;
        status.peerCount = peers;
        status.pendingTxCount = txs;
        status.avgBlockTime = 10.0;
        status.nodeStatus = "RUNNING";
        return status;
    }

    void printStatus(const ChainStatus& status) {
        std::cout << "===== Blockchain Status =====" << std::endl;
        std::cout << "Height: " << status.blockHeight << std::endl;
        std::cout << "Peers: " << status.peerCount << std::endl;
        std::cout << "Pending Txs: " << status.pendingTxCount << std::endl;
        std::cout << "Node Status: " << status.nodeStatus << std::endl;
    }
};

int main() {
    std::vector<ChainBlock> chain;
    BlockchainMonitor monitor;
    auto status = monitor.getChainStatus(chain, 5, 20);
    monitor.printStatus(status);
    return 0;
}
