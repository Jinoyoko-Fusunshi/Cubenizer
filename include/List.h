#pragma once

#include <stdint-gcc.h>

typedef struct Node{
    void *data;
    struct Node *next_element;
} Node;

typedef struct List{
    uint32_t size;
    Node *nodes;
} List;

void InitList(List *list_reference);
void AddListEntry(List *list_reference, void* entry_data);
void* GetListEntry(List *list_reference, uint32_t index);
void DeleteList(List *list_reference);
void DeleteListWithAllocations(List *list_reference);