# Heap
## Descrioption
Implementation of heap in C++. I tested this code with C++20. I used `std::vector` for storage of values in the heap. My container uses nested structure `Node` in class `Heap` for easier understanding of the code and making storing values and priorities easy and simple. I also used template for storing different kind of values. There should not be a problem with any variable with implemented `operator<<`. Without it you should not use implemented functions to display values, because they are implemented with this operator in mind and are using `std::cout`.
## Using
#### Compiling
##### Windows
```bash
g++ main.cpp -o heap.exe
```
##### Linux
```bash
g++ main.cpp -o heap
```
#### Running
##### Windows
```bash
./heap.exe
```
##### Linux
```bash
./heap
```
