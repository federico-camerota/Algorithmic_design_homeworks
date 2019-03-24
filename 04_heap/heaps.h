#ifndef HEAPS_H
#define HEAPS_H

#ifndef ITEM_TYPE
#define ITEM_TYPE int
#endif

#include <stdlib.h>

//Declaration of the binary_heap struct
typedef struct {
    size_t max_size;
    size_t current_size;
    ITEM_TYPE *items;
} binary_heap;

//Function to create a new heap
binary_heap *bheap_new(ITEM_TYPE *items, size_t max_size, size_t current_size);
//Function to free a binary heap
void bheap_free(binary_heap *heap);
//Function to get the left child of a node in a binary heap
size_t bheap_left (size_t parent);
//Function to get the right child of a node in a binary heap
size_t bheap_right (size_t parent);
//Function to get the parent of a node in a binary heap
size_t bheap_parent (size_t child);
//Function to test if a given index is a valid position in a binary heap
int bheap_is_valid_node (binary_heap *heap, size_t position);
//Function to restore the heap property in a heap
void bheap_heapify (binary_heap *heap, size_t node);
//Function to test the heap property in a heap
int bheap_is_heap (binary_heap *heap);
//Function to remove the minimum element from a binary heap
ITEM_TYPE bheap_remove_min (binary_heap *heap);

#endif
