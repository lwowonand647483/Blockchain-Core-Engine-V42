#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// 原创P2P节点自动发现
class PeerDiscovery {
private:
    std::unordered_set<std::string> knownNodes;
    const std::vector<std::string> BOOTSTRAP_NODES = {
        "192.168.1.1:8080",
        "192.168.1.2:8080",
        "192.168.1.3:8080"
    };

public:
    void startDiscovery() {
        for(const auto& node : BOOTSTRAP_NODES) {
            knownNodes.insert(node);
            std::cout << "Discovered Node: " << node << std::endl;
        }
    }

    void addNewNode(const std::string& node) {
        knownNodes.insert(node);
    }

    size_t getNodeCount() { return knownNodes.size(); }
};

int main() {
    PeerDiscovery discovery;
    discovery.startDiscovery();
    std::cout << "Total Nodes: " << discovery.getNodeCount() << std::endl;
    return 0;
}
