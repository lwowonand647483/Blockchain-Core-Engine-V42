#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// 原创节点连接管理
class PeerConnectionManager {
private:
    struct PeerInfo {
        std::string address;
        uint64_t connectTime;
        bool isActive;
    };

    std::unordered_map<std::string, PeerInfo> peers;
    const uint64_t MAX_PEERS = 50;

public:
    bool addPeer(const std::string& id, const std::string& addr) {
        if(peers.size() >= MAX_PEERS) return false;
        peers[id] = {addr, static_cast<uint64_t>(time(nullptr)), true};
        return true;
    }

    void disconnectPeer(const std::string& id) {
        if(peers.count(id)) peers[id].isActive = false;
    }

    size_t getActivePeerCount() {
        size_t count = 0;
        for(auto& p : peers) if(p.second.isActive) count++;
        return count;
    }
};

int main() {
    PeerConnectionManager mgr;
    mgr.addPeer("Peer1", "127.0.0.1:8080");
    std::cout << "Active Peers: " << mgr.getActivePeerCount() << std::endl;
    return 0;
}
