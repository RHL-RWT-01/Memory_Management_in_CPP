//
// Created by Rahul on 8/15/2024.
//
#include "MemoryPool.h"
#include <new>

MemoryPool::MemoryPool(size_t size, size_t blockSize)
    : blockSize(blockSize) {
    pool.reserve(size);
    for (size_t i = 0; i < size; ++i) {
        pool.push_back(::operator new(blockSize));
    }
}

MemoryPool::~MemoryPool() {
    for (void* ptr : pool) {
        ::operator delete(ptr);
    }
}

void* MemoryPool::allocate() {
    if (pool.empty()) {
        return ::operator new(blockSize);
    } else {
        void* ptr = pool.back();
        pool.pop_back();
        return ptr;
    }
}

void MemoryPool::deallocate(void* ptr) {
    pool.push_back(ptr);
}

