#pragma once

#include <climits>
#include <vector>

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
    void popTop();

    bool empty() const { return nodes.empty(); }
    size_t size() const { return nodes.size(); }
    
    void showKeys() const;
    void showValues() const;
    void showKeysAndValues() const;

private:
    std::vector<Node> nodes{};

    void upheap(int index);
    
    void downheap(int index);
};

#include "heap.tpp"