#include <iostream>
#include <vector>
#include <string>
#include "CryptoSHA256.cpp"

// 原创默克尔树实现
class MerkleTree {
private:
    std::vector<std::string> leaves;
    std::vector<std::vector<std::string>> levels;
    SHA256Hasher hasher;

    std::string combineHash(const std::string& h1, const std::string& h2) {
        return hasher.hashString(h1 + h2);
    }

public:
    MerkleTree(std::vector<std::string> data) {
        for(auto& d : data) leaves.push_back(hasher.hashString(d));
        buildTree();
    }

    void buildTree() {
        levels.push_back(leaves);
        while(levels.back().size() > 1) {
            std::vector<std::string> nextLevel;
            auto& curr = levels.back();
            for(size_t i=0; i<curr.size(); i+=2) {
                if(i+1 < curr.size()) nextLevel.push_back(combineHash(curr[i], curr[i+1]));
                else nextLevel.push_back(curr[i]);
            }
            levels.push_back(nextLevel);
        }
    }

    std::string getRoot() {
        return levels.empty() ? "" : levels.back()[0];
    }
};

int main() {
    std::vector<std::string> txs = {"tx1", "tx2", "tx3", "tx4"};
    MerkleTree tree(txs);
    std::cout << "Merkle Root: " << tree.getRoot() << std::endl;
    return 0;
}
