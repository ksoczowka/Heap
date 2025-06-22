#pragma once

#include <climits>
#include <vector>

namespace my {
template<typename T>
class Heap {
public:
    // Structure to storage `T` value and `int` priority in one object. Comes with own set of operators and constructors.
    struct Node {
        T value;
        int priority;
        Node() = delete;
        Node(T value, int priority) : value(value), priority(priority) {}
        Node(const Node& other) : value(other.value), priority(other.priority) {}

        // Checks priority of `Nodes`. Returns `true` if priorities are the same, `false` otherwise.
        bool operator==(const Node& other) { return (priority == other.priority); }
        // Checks priority of `Nodes`. Returns `true` if priorities aren't the same, `false` otherwise.
        bool operator!=(const Node& other) { return (priority != other.priority); }
        // Checks priority of `Nodes`. Returns `true` if `this` priority is greater than `other` priority, `false` otherwise.
        bool operator>(const Node& other) { return (priority > other.priority); }
        // Checks priority of `Nodes`. Returns `true` if `this` priority is greater than or equal to `other` priority, `false` otherwise.
        bool operator>=(const Node& other) { return (priority >= other.priority); }
        // Checks priority of `Nodes`. Returns `true` if `this` priority is lower than `other` priority, `false` otherwise.
        bool operator<(const Node& other) { return (priority < other.priority); }
        // Checks priority of `Nodes`. Returns `true` if `this` priority is lower than or equal to `other` priority, `false` otherwise.
        bool operator<=(const Node& other) { return (priority <= other.priority); }
    };

    Heap() {
        nodes.push_back(Node(T{}, INT_MAX));
    }

    // Adds `Node` to the heap based on current `T` value and `int` priority.
    void addNode(const T& value, const int& priority);
    // Adds `Node` to the heap base on other `Node` .
    void addNode(const Node& node);

    // Removes value on top of the heap.
    void popTop();

    // Returns `true` if heap is empty and `false` if it isn't.
    bool empty() const { return (nodes.size() <= 1); }
    // Returns `size_t` size of the heap .
    size_t size() const { return nodes.size() - 1; }
    
    // Function to display with `std::cout` priorities (keys) [`int`] of the `Nodes` in the heap.
    void showKeys() const;
    // Function to display with `std::cout` values [`T`] of the `Nodes` in the heap.
    void showValues() const;
    // Function to display with `std::cout` priorities (keys) [`int`] and values [`T`] of the `Nodes` int the heap.
    void showKeysAndValues() const;

    // Returns reference to the `Node` with highest priority. Requires the heap to not be empty.
    Node& top() const { __glibcxx_requires_nonempty(); return nodes[1]; }

private:
    std::vector<Node> nodes{};

    // Function to move `Node` with the `size_t` index as far up the heap as possible.
    void upheap(size_t index);
    // Function to move `Node` with the `size_t` index as far down the heap as possible.
    void downheap(size_t index);
};
}
#include "heap.tpp"