#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)
#define GROW_ARRAY(type, pointer, oldCount, newCount)                          \
  (type *)reallocate(pointer, sizeof(type) * (oldCount),                       \
                     sizeof(type) * (newCount))
#define FREE_ARRAY(type, pointer, oldCount)                                    \
  reallocate(pointer, sizeof(type) * oldCount, 0)

/*
Reallocate the space at 'pointer' to accomodate for the new size.
The cases are:
    `0 -> n`: Allocate a new block
    `n -> 0`: Free memory
    `0 -> m` with `m < oldSize`: Shrink memory region
    `0 -> m` with `m > oldSize`: Grow memory region

When memory is free'd, a NULL-Pointer is returned.
*/
void *reallocate(void *pointer, size_t oldSize, size_t newSize);

#endif