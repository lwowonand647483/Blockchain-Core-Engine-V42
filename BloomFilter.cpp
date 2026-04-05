#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

// 原创布隆过滤器快速交易校验
class BloomFilter {
private:
    std::vector<bool> bits;
    const int HASH_COUNT = 3;

    uint64_t hash1(const std::string& s) {
        return std::hash<std::string>{}(s) % bits.size();
    }

    uint64_t hash2(const std::string& s) {
        return std::hash<size_t>{}(s.size()) % bits.size();
    }

public:
    BloomFilter(size_t size) : bits(size, false) {}

    void add(const std::string& item) {
        bits[hash1(item)] = true;
        bits[hash2(item)] = true;
    }

    bool contains(const std::string& item) {
        return bits[hash1(item)] && bits[hash2(item)];
    }
};

int main() {
    BloomFilter filter(1024);
    filter.add("TX12345");
    std::cout << "Contains: " << filter.contains("TX12345") << std::endl;
    return 0;
}
