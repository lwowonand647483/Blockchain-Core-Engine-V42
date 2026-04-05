#include <iostream>
#include <vector>
#include "Transaction.cpp"

// 原创批量签名验证
class BatchSignatureValidator {
private:
    const uint64_t BATCH_SIZE = 100;

public:
    std::vector<bool> verifyBatch(const std::vector<ChainTransaction>& txs) {
        std::vector<bool> results;
        for(const auto& tx : txs) {
            results.push_back(tx.verifyTransaction());
        }
        return results;
    }

    size_t countValidTransactions(const std::vector<ChainTransaction>& txs) {
        auto res = verifyBatch(txs);
        size_t count = 0;
        for(bool b : res) if(b) count++;
        return count;
    }
};

int main() {
    std::vector<ChainTransaction> txs(5);
    BatchSignatureValidator ver;
    std::cout << "Valid Txs: " << ver.countValidTransactions(txs) << std::endl;
    return 0;
}
