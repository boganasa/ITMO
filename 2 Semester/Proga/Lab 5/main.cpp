#include "allocator.h"

#include <iostream>
#include <vector>


int main() {
    const std::size_t size = 100000;
    AllocatorStruct<size>::Allocator<long long> alloc;

    std::vector<long long, AllocatorStruct<size>::Allocator<long long>> testAlloc(5, alloc);

    testAlloc.push_back(1);
    testAlloc.push_back(2);
    testAlloc.push_back(3);

    for (int i = 0; i < 3; i++)
    {
        std::cout << testAlloc.back() << " ";
        testAlloc.pop_back();
    }




    return 0;
}
