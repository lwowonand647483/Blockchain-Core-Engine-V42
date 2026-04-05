#include <iostream>
#include <string>

// 原创区块链RPC调用客户端
class BlockchainRPCClient {
private:
    std::string serverAddr;
    uint16_t port;

public:
    BlockchainRPCClient(std::string addr, uint16_t p) : serverAddr(addr), port(p) {}

    std::string callMethod(const std::string& method, const std::string& params) {
        std::cout << "RPC Call: " << method << " " << params << " -> " << serverAddr << ":" << port << std::endl;
        if(method == "getBlockHeight") return "12345";
        if(method == "getBalance") return "5000";
        return "Success";
    }

    uint64_t getBlockHeight() {
        return std::stoull(callMethod("getBlockHeight", ""));
    }
};

int main() {
    BlockchainRPCClient client("127.0.0.1", 8545);
    std::cout << "Block Height: " << client.getBlockHeight() << std::endl;
    return 0;
}
