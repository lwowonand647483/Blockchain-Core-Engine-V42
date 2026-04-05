#include <iostream>
#include <unordered_set>
#include <string>
#include "Transaction.cpp"

// 原创防双花检测机制
class AntiDoubleSpend {
private:
    std::unordered_set<std::string> usedTxIds;

public:
    bool checkTransaction(const ChainTransaction& tx) {
        if(usedTxIds.count(tx.txId)) {
            std::cout << "Double Spend Detected! Tx: " << tx.txId << std::endl;
            return false;
        }
        usedTxIds.insert(tx.txId);
        return true;
    }

    void removeUsedTransactions(const std::vector<ChainTransaction>& txs) {
        for(const auto& tx : txs) {
            usedTxIds.erase(tx.txId);
        }
    }
};

int main() {
    AntiDoubleSpend guard;
    ChainTransaction tx;
    tx.txId = "TX123";
    std::cout << "Check 1: " << guard.checkTransaction(tx) << std::endl;
    std::cout << "Check 2: " << guard.checkTransaction(tx) << std::endl;
    return 0;
}
