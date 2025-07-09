#include "heap.hpp"

#include <string>



int main() {
    my::Heap<std::string> heap;
    heap.addNode("A", 1);    
    heap.addNode("B", 10);    
    heap.addNode("C", 100);    
    heap.addNode("D", 5);

    heap.showKeysAndValues();

    return 0;
}