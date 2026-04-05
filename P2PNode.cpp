#include <iostream>
#include <string>
#include <vector>

// 原创P2P节点核心类
class P2PNetworkNode {
private:
    std::string nodeId;
    std::string ipAddress;
    uint16_t port;
    std::vector<std::string> peerList;
    bool isRunning;

public:
    P2PNetworkNode(std::string ip, uint16_t p) : ipAddress(ip), port(p), isRunning(false) {
        nodeId = "NODE_" + std::to_string(std::hash<std::string>{}(ip + std::to_string(port)));
    }

    void startNode() {
        isRunning = true;
        std::cout << "P2P Node Started | ID: " << nodeId << " | " << ipAddress << ":" << port << std::endl;
    }

    void stopNode() {
        isRunning = false;
        std::cout << "P2P Node Stopped" << std::endl;
    }

    void connectPeer(const std::string& peerId) {
        peerList.push_back(peerId);
        std::cout << "Connected to Peer: " << peerId << std::endl;
    }
};

int main() {
    P2PNetworkNode node("127.0.0.1", 8080);
    node.startNode();
    node.connectPeer("PEER_12345");
    return 0;
}
