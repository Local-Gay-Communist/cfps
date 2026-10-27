#ifndef ENTITY_H
#define ENTITY_H

#include <stdlib.h>

// Memory arena allocator
typedef struct {
    void* memory;
    size_t size;
    size_t used;
} arena;

// Create arena
arena arena_alloc(size_t size) {
    arena result = {
        .memory = malloc(size),
        .size = size,
        .used = 0
    };
    return result;
}

// Allocate memory from arena
void* arena_alloc_size(arena* arena, size_t size) {
    void* result = (uint8_t*)arena->memory + arena->used;
    arena->used += size;
    return result;
}

#endif // ENTITY_H