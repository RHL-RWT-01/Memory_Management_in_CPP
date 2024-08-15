//
// Created by Rahul on 8/15/2024.
//

#ifndef MEMORYPOOL_H
#define MEMORYPOOL_H

#include <vector>

class MemoryPool {
    std::vector<void*> pool;
    const size_t blockSize;

public:
    MemoryPool(size_t size, size_t blockSize);
    ~MemoryPool();

    void* allocate();
    void deallocate(void* ptr);
};

#endif // MEMORYPOOL_H

