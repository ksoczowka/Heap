#pragma once

#include <climits>
#include <vector>

namespace my {
template<typename T>
class Heap {
public:
    struct Node {
        T value;
        int priority;
        Node() = delete;
        Node(T value, int priority) : value(value), priority(priority) {}
    };

    Heap() {
        nodes.push_back(Node(T{}, INT_MAX));
    }

    void addNode(const T& value, const int& priority);
    void addNode(const Node& node);

    void popTop();

    bool empty() const { return (nodes.size() <= 1); }
    size_t size() const { return nodes.size() - 1; }
    
    void showKeys() const;
    void showValues() const;
    void showKeysAndValues() const;

    Node top() const { __glibcxx_requires_nonempty(); return nodes[1]; }

private:
    std::vector<Node> nodes{};

    void upheap(int index);
    
    void downheap(int index);
};
}
#include "heap.tpp"