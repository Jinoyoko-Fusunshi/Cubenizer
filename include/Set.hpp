#pragma once

#include <stdint-gcc.h>

typedef struct Pair{
    uint32_t id;
    void *data;
    struct Pair *next_pair;
} Pair;

typedef struct Set {
    uint32_t size;
    struct Pair *pairs;
} Set;

void InitSet(Set *set_reference);
void AddPair(Set *set_reference, uint32_t id, void *data);
Pair *GetPairById(Set *set_reference, uint32_t id);
void DeleteSet(Set *set_reference);