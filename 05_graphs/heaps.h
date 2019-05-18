#ifndef HEAPS_H
#define HEAPS_H


#include <stdlib.h>

//Declaration of the binary_heap struct
typedef struct {
    size_t max_size;
    size_t current_size;
    int (*comp_fun)(graph_node *, graph_node *);
    graph_node * *items;
} binary_heap;

//Function to create a new heap
binary_heap *bheap_new(graph_node * *items,int (*comp_fun)(graph_node *, graph_node *) , size_t max_size, size_t current_size);
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
graph_node * bheap_remove_min (binary_heap *heap);
//Function to check if a binary heap is empty
int bheap_is_empty( binary_heap *heap);
//Function to decrease a key
void bheap_decrease_key ( binary_heap *heap, size_t i, double value);

#endif
