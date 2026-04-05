#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

// 原创区块链运行日志记录
class BlockchainLogger {
private:
    std::ofstream logFile;
    std::string getTime() {
        time_t now = time(nullptr);
        char buf[20];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
        return std::string(buf);
    }

public:
    BlockchainLogger() {
        logFile.open("blockchain.log", std::ios::app);
    }

    ~BlockchainLogger() {
        if(logFile.is_open()) logFile.close();
    }

    void logInfo(const std::string& msg) {
        logFile << "[" << getTime() << "] [INFO] " << msg << std::endl;
    }

    void logError(const std::string& msg) {
        logFile << "[" << getTime() << "] [ERROR] " << msg << std::endl;
    }
};

int main() {
    BlockchainLogger logger;
    logger.logInfo("Node Started Successfully");
    return 0;
}
