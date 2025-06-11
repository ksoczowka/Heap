#include "heap.hpp"

#include <string>

// for random heap values
#include <unordered_map>
#include <random>

int main() {
    // setting up randomisation
    std::random_device rd;
    std::mt19937 seed(rd());
    std::uniform_int_distribution<> dist(1, 100);

    std::unordered_map<std::string, int> map;

    // using ascii for keys
    for(int i = 65; i <= 75; i++) {
        char c = char(i);
        map[std::string(1, c)] = dist(seed);
    }

    Heap<std::string> heap;

    for(const auto& [key, value] : map) {
        heap.addNode(key, value);
    }

    heap.showKeysAndValues();

    return 0;
}