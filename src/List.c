#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

Node* CreateNode(void* entry_data);
void DeleteNode(Node *node_reference, bool hasAllocatedMemory);

void InitList(List *list_reference) {
    list_reference->size = 0;
    list_reference->nodes = 0;
}

void AddListEntry(List *list_reference, void* entry_data) {
    if (!list_reference->nodes) {
        list_reference->nodes = CreateNode(entry_data);
        list_reference->size += 1;
        return;
    }

    Node* previous_node = 0;
    Node* current_node = list_reference->nodes;

    while (current_node) {
        previous_node = current_node;
        current_node = (Node*) current_node->next_element;
    }

    current_node = CreateNode(entry_data);
    previous_node->next_element = (Node*) current_node;

    list_reference->size += 1;
}

Node* CreateNode(void* entry_data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = entry_data;
    new_node->next_element = 0;
    return new_node;
}

void* GetListEntry(List *list_reference, uint32_t index) {
    Node* current_node = list_reference->nodes;

    if (!current_node)
        return 0;

    for (uint32_t i = 0; i < index; i++) {
        if (current_node->next_element)
            current_node = (Node *)current_node->next_element;
        else
            return 0;
    }

    return current_node->data;
}

void DeleteList(List *list_reference) {
    Node* head_node = list_reference->nodes;
    DeleteNode(head_node, false);
}

void DeleteListWithAllocations(List *list_reference) {
    Node* head_node = list_reference->nodes;
    DeleteNode(head_node, true);
}

void DeleteNode(Node *node_reference, bool hasAllocatedMemory) {
    if (node_reference->next_element)
        DeleteNode((Node *)node_reference->next_element, hasAllocatedMemory);

    if (hasAllocatedMemory)
        free(node_reference->data);

    free(node_reference);
}