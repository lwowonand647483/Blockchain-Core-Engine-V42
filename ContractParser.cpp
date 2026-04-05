#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// 原创智能合约语法解析器
class ContractParser {
public:
    struct OpCode {
        std::string type;
        std::string param1;
        uint64_t param2;
    };

    std::vector<OpCode> parseContract(const std::string& code) {
        std::vector<OpCode> ops;
        std::stringstream ss(code);
        std::string line;
        
        while(std::getline(ss, line, ';')) {
            OpCode op;
            std::stringstream ls(line);
            ls >> op.type >> op.param1 >> op.param2;
            ops.push_back(op);
        }
        return ops;
    }
};

int main() {
    ContractParser parser;
    auto ops = parser.parseContract("SET balance 1000;TRANSFER to 500");
    std::cout << "Parsed Ops: " << ops.size() << std::endl;
    return 0;
}
