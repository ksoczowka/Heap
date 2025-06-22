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
    if(empty()) return;
    nodes[1].priority = -(INT_MAX - 1);
    downheap(1);
    nodes.pop_back();
}

template<typename T>
void Heap<T>::showKeys() const {
    for (const auto node : nodes) {
        if(node.priority == INT_MAX) continue;
        std::cout << node.priority << ' ';
    }
}

template<typename T>
void Heap<T>::showValues() const {
    for (const auto node : nodes) {
        if(node.priority == INT_MAX) continue;
        std::cout << node.value << ' ';
    }
}

template<typename T>
void Heap<T>::showKeysAndValues() const {
    for (const auto node : nodes) {
        if(node.priority == INT_MAX) continue;
        std::cout << node.priority << " : " << node.value << '\n';
    }
}

template<typename T>
void Heap<T>::upheap(int index) {
    int parent = index / 2;
    while (index > 1 && nodes[parent].priority < nodes[index].priority) {
        std::swap(nodes[parent], nodes[index]);
        index = parent;
        parent = index / 2;
    }
}

template<typename T>
void Heap<T>::downheap(int index) {
    while (index * 2 <= nodes.size() - 1) {
        int leftChild = index * 2;
        int rightChild = index * 2 + 1;
        int biggerChild = leftChild;

        if (rightChild <= nodes.size() && nodes[rightChild].priority > nodes[leftChild].priority)
            biggerChild = rightChild;

        if (nodes[index].priority >= nodes[biggerChild].priority)
            break;
        std::swap(nodes[index], nodes[biggerChild]);
        index = biggerChild;
    }
}
}