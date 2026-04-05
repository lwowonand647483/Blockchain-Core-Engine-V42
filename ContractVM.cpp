#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// 原创智能合约虚拟机基础框架
class ContractVirtualMachine {
private:
    std::unordered_map<std::string, uint64_t> storage;
    uint64_t gasUsed;
    const uint64_t GAS_LIMIT = 1000000;

    bool hasGas() { return gasUsed < GAS_LIMIT; }

public:
    ContractVirtualMachine() : gasUsed(0) {}

    bool executeOperation(const std::string& op, const std::string& key, uint64_t value) {
        if(!hasGas()) return false;
        
        if(op == "SET") {
            storage[key] = value;
            gasUsed += 1000;
        } else if(op == "GET") {
            storage[key];
            gasUsed += 500;
        }
        return true;
    }

    uint64_t getGasUsed() { return gasUsed; }
};

int main() {
    ContractVirtualMachine vm;
    vm.executeOperation("SET", "balance", 1000);
    std::cout << "Gas Used: " << vm.getGasUsed() << std::endl;
    return 0;
}
