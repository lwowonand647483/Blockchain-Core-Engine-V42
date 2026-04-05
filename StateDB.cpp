#include <iostream>
#include <unordered_map>
#include <string>

// 原创账户状态数据库
class AccountStateDatabase {
private:
    std::unordered_map<std::string, uint64_t> balances;
    std::unordered_map<std::string, uint64_t> nonces;

public:
    void setBalance(const std::string& addr, uint64_t bal) {
        balances[addr] = bal;
    }

    uint64_t getBalance(const std::string& addr) {
        return balances.count(addr) ? balances[addr] : 0;
    }

    void incrementNonce(const std::string& addr) {
        nonces[addr]++;
    }

    uint64_t getNonce(const std::string& addr) {
        return nonces.count(addr) ? nonces[addr] : 0;
    }
};

int main() {
    AccountStateDB db;
    db.setBalance("Wallet1", 1000);
    std::cout << "Balance: " << db.getBalance("Wallet1") << std::endl;
    return 0;
}
