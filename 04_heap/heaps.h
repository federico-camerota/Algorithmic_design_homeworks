#ifndef HEAPS_H
#define HEAPS_H

#ifndef ITEM_TYPE
#define ITEM_TYPE int
#endif

//Declaration of the binary_heap struct
typedef struct {
    size_t max_size = 0;
    size_t current_size = 0;
    ITEM_TYPE *items = NULL;
} binary_heap;

//Function to create a new heap
binary_heap *bheap_new(ITEM_TYPE *items, size_t max_size, size_t current_size);
//Function to free a binary heap
void *bheap_free(binary_heap *heap);
//Function to get the left child of a node in a binary heap
size_t bheap_left (size_t parent);
//Function to get the right child of a node in a binary heap
size_t bheap_right (size_t parent);
//Function to get the parent of a node in a binary heap
size_t bheap_parent (size_t child);
//Function to test if a given index is a valid position in a binary heap
int bheap_is_valid_node (binary_heap *heap, size_t position);

#endif
