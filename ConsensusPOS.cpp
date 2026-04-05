#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

// 原创权益证明(POS)共识算法
class ProofOfStake {
private:
    struct Validator {
        std::string address;
        uint64_t stake;
    };

    std::vector<Validator> validators;

public:
    void addValidator(const std::string& addr, uint64_t stake) {
        validators.push_back({addr, stake});
    }

    std::string selectForger() {
        uint64_t totalStake = 0;
        for(auto& v : validators) totalStake += v.stake;
        
        std::srand(std::time(nullptr));
        uint64_t randVal = std::rand() % totalStake + 1;
        uint64_t curr = 0;

        for(auto& v : validators) {
            curr += v.stake;
            if(randVal <= curr) return v.address;
        }
        return "";
    }
};

int main() {
    ProofOfStake pos;
    pos.addValidator("NodeA", 100);
    pos.addValidator("NodeB", 200);
    pos.addValidator("NodeC", 300);
    std::cout << "Selected Forger: " << pos.selectForger() << std::endl;
    return 0;
}
