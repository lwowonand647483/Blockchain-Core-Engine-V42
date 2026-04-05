#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 原创交易数据压缩
class TransactionCompressor {
public:
    std::string compress(const std::string& rawData) {
        std::string compressed = rawData;
        std::replace(compressed.begin(), compressed.end(), ' ', '_');
        compressed += "[COMPRESSED]";
        return compressed;
    }

    std::string decompress(const std::string& compressed) {
        std::string raw = compressed;
        raw = raw.substr(0, raw.size() - 12);
        std::replace(raw.begin(), raw.end(), '_', ' ');
        return raw;
    }
};

int main() {
    TransactionCompressor comp;
    std::string raw = "Transaction Data with Spaces";
    auto cmp = comp.compress(raw);
    auto decmp = comp.decompress(cmp);
    std::cout << "Original: " << raw << " | Decompressed: " << decmp << std::endl;
    return 0;
}
