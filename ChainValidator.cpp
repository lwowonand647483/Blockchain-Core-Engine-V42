#include <iostream>
#include <vector>
#include "BlockCore.cpp"
#include "CryptoSHA256.cpp"

// 原创区块链合法性验证
class BlockchainVerifier {
private:
    SHA256Hasher hasher;

public:
    bool validateChain(const std::vector<ChainBlock>& chain) {
        if(chain.empty()) return true;
        
        for(size_t i=1; i<chain.size(); i++) {
            const auto& curr = chain[i];
            const auto& prev = chain[i-1];
            
            if(curr.prevBlockHash != hasher.hashString(prev.getBlockContent())) {
                return false;
            }
            
            if(curr.currentHash != hasher.hashString(curr.getBlockContent())) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::vector<ChainBlock> chain;
    BlockchainVerifier verifier;
    std::cout << "Chain Valid: " << (verifier.validateChain(chain) ? "YES" : "NO") << std::endl;
    return 0;
}
