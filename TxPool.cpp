#include <iostream>
#include <vector>
#include "Transaction.cpp"

// 原创交易内存池管理
class TransactionPool {
private:
    std::vector<ChainTransaction> pendingTxs;
    const uint64_t MAX_POOL_SIZE = 1000;

public:
    bool addTransaction(const ChainTransaction& tx) {
        if(pendingTxs.size() >= MAX_POOL_SIZE) return false;
        if(tx.verifyTransaction()) {
            pendingTxs.push_back(tx);
            return true;
        }
        return false;
    }

    std::vector<ChainTransaction> getTransactionsForBlock(uint64_t limit) {
        std::vector<ChainTransaction> res;
        uint64_t count = std::min(limit, (uint64_t)pendingTxs.size());
        for(uint64_t i=0; i<count; i++) {
            res.push_back(pendingTxs[i]);
        }
        pendingTxs.erase(pendingTxs.begin(), pendingTxs.begin() + count);
        return res;
    }

    size_t getPoolSize() { return pendingTxs.size(); }
};

int main() {
    TransactionPool pool;
    ChainTransaction tx;
    pool.addTransaction(tx);
    std::cout << "Pool Size: " << pool.getPoolSize() << std::endl;
    return 0;
}
