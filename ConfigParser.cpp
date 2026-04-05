#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

// 原创节点配置文件解析
class NodeConfigParser {
private:
    std::unordered_map<std::string, std::string> config;

public:
    bool loadConfig(const std::string& filename) {
        std::ifstream file(filename);
        if(!file) return false;

        std::string line;
        while(std::getline(file, line)) {
            if(line.empty() || line[0] == '#') continue;
            size_t eq = line.find('=');
            if(eq == std::string::npos) continue;
            std::string key = line.substr(0, eq);
            std::string val = line.substr(eq+1);
            config[key] = val;
        }
        return true;
    }

    std::string getValue(const std::string& key) {
        return config.count(key) ? config[key] : "";
    }
};

int main() {
    NodeConfigParser parser;
    parser.loadConfig("node.conf");
    return 0;
}
