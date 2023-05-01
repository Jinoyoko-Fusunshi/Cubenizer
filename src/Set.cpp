#include <malloc.h>
#include "Set.hpp"

Pair* CreatePair(uint32_t id, void* data) {
    Pair *pair = (Pair*)malloc(sizeof (Pair));
    pair->id = id;
    pair->data = data;
    return pair;
}

void InitSet(Set *set_reference) {
    set_reference->size = 0;
    set_reference->pairs = 0;
}

void AddPair(Set *set_reference, uint32_t id, void *data) {
    if (!set_reference->pairs) {
        Pair *found_pair = GetPairById(set_reference, id);

        if (!found_pair)
            found_pair = CreatePair(id, data);

        set_reference->pairs = found_pair;
        set_reference->size += 1;
        return;
    }

    Pair* previous_pair = 0;
    Pair* current_pair = set_reference->pairs;

    while (current_pair) {
        previous_pair = current_pair;
        current_pair = (Pair*) current_pair->next_pair;
    }

    current_pair = CreatePair(id, data);
    previous_pair->next_pair = (Pair*)current_pair;

    set_reference->size += 1;
}

Pair *GetPairById(Set *set_reference, uint32_t id) {
    Pair* current_pair = set_reference->pairs;

    while (current_pair) {
        if (current_pair->id == id)
            break;

        current_pair = (Pair*) current_pair->next_pair;
    }

    return current_pair;
}

void DeleteSet(Set *set_reference) {

}