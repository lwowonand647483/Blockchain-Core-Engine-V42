#include <iostream>
#include <string>
#include "ContractParser.cpp"

// 原创智能合约Gas消耗计算
class GasMeter {
private:
    const uint64_t BASE_GAS = 21000;
    const uint64_t STORAGE_WRITE_GAS = 10000;
    const uint64_t STORAGE_READ_GAS = 1000;

public:
    uint64_t calculateTransactionGas(const std::string& contractCode) {
        ContractParser parser;
        auto ops = parser.parseContract(contractCode);
        uint64_t gas = BASE_GAS;

        for(const auto& op : ops) {
            if(op.type == "SET") gas += STORAGE_WRITE_GAS;
            else if(op.type == "GET") gas += STORAGE_READ_GAS;
        }
        return gas;
    }
};

int main() {
    GasMeter meter;
    uint64_t gas = meter.calculateTransactionGas("SET balance 1000");
    std::cout << "Total Gas: " << gas << std::endl;
    return 0;
}
