#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// 原创P2P消息序列化
enum MessageType { BLOCK, TRANSACTION, PEER_DISCOVERY, CHAIN_SYNC };

struct P2PMessage {
    MessageType type;
    std::string senderId;
    std::string receiverId;
    std::string payload;
    uint64_t timestamp;

    std::string serialize() {
        std::stringstream ss;
        ss << type << "|" << senderId << "|" << receiverId << "|" << payload << "|" << timestamp;
        return ss.str();
    }

    void deserialize(const std::string& data) {
        std::stringstream ss(data);
        std::string t;
        std::getline(ss, t, '|'); type = (MessageType)std::stoi(t);
        std::getline(ss, senderId, '|');
        std::getline(ss, receiverId, '|');
        std::getline(ss, payload, '|');
        std::getline(ss, t, '|'); timestamp = std::stoull(t);
    }
};

int main() {
    P2PMessage msg;
    msg.type = TRANSACTION;
    msg.senderId = "NODE1";
    msg.payload = "TX_DATA";
    auto ser = msg.serialize();
    std::cout << "Serialized: " << ser << std::endl;
    return 0;
}
