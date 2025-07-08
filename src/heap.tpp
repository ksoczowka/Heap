#include "heap.hpp"

#include <iostream>

namespace my {
template<typename T>
void Heap<T>::addNode(const T& value, const int& priority) {
    nodes.push_back(Node(value, priority));
    upheap(nodes.size() - 1);
}

template<typename T>
void Heap<T>::addNode(const Node& node) {
    nodes.push_back(node);
    upheap(nodes.size() - 1);
}

template<typename T>
void Heap<T>::popTop() {
    __glibcxx_requires_nonempty();
    nodes[1].priority = -(INT_MAX - 1);
    downheap(1);
    nodes.pop_back();
}

template<typename T>
void Heap<T>::showKeys() const {
    for (const auto& node : nodes) {
        std::cout << node.priority << ' ';
    }
}

template<typename T>
void Heap<T>::showValues() const {
    for (const auto& node : nodes) {
        std::cout << node.value << ' ';
    }
}

template<typename T>
void Heap<T>::showKeysAndValues() const {
    for (const auto& node : nodes) {
        std::cout << node.priority << " : " << node.value << '\n';
    }
}

template<typename T>
void Heap<T>::upheap(size_t index) {
    int parent = (index + 1) / 2 - 1;
    while (index > 1 && nodes[parent] < nodes[index]) {
        std::swap(nodes[parent], nodes[index]);
        index = parent;
        parent = index / 2;
    }
}

template<typename T>
void Heap<T>::downheap(size_t index) {
    while (index * 2 <= nodes.size() - 1) {
        int leftChild = (index + 1) * 2 - 1;
        int rightChild = (index + 1) * 2;
        int biggerChild = leftChild;

        if (rightChild <= nodes.size() && nodes[rightChild] > nodes[leftChild])
            biggerChild = rightChild;

        if (nodes[index] >= nodes[biggerChild])
            break;
        std::swap(nodes[index], nodes[biggerChild]);
        index = biggerChild;
    }
}
}