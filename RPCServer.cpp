#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>

// 原创区块链RPC服务接口
class BlockchainRPCServer {
private:
    uint16_t port;
    bool isRunning;
    std::unordered_map<std::string, std::function<std::string(std::string)>> handlers;

public:
    BlockchainRPCServer(uint16_t p) : port(p), isRunning(false) {
        registerMethods();
    }

    void registerMethods() {
        handlers["getBlockHeight"] = [](std::string) { return "1000"; };
        handlers["getBalance"] = [](std::string addr) { return "Balance: 1000"; };
        handlers["sendTransaction"] = [](std::string tx) { return "Tx Sent"; };
    }

    void start() {
        isRunning = true;
        std::cout << "RPC Server Started on Port " << port << std::endl;
    }

    std::string handleRequest(const std::string& method, const std::string& params) {
        if(handlers.count(method)) return handlers[method](params);
        return "Method Not Found";
    }
};

int main() {
    BlockchainRPCServer server(8545);
    server.start();
    std::cout << server.handleRequest("getBlockHeight", "") << std::endl;
    return 0;
}
