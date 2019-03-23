#include "heaps.h"
#include <stdlib.h>

///////////////////////
// BHEAP_NEW
///////////////////////
    binary_heap *bheap_new(ITEM_TYPE *items, size_t max_size, size_t current_size){

	binary_heap *new_heap = (binary_heap *) malloc(sizeof(binary_heap));
	new_heap->max_size = max_size;
	new_heap->current_size = current_size;
	new_heap->items = items;
	if (new_heap->items == NULL)
	    new_heap->items = (ITEM_TYPE *) calloc(max_size, sizeof(ITEM_TYPE));

	return new_heap;
    }
///////////////////////
// BHEAP_FREE
///////////////////////
    void *bheap_free(binary_heap *heap){

	free(heap->items);
	free(heap);
    }
///////////////////////
// BHEAP_LEFT 
///////////////////////
    size_t bheap_left (size_t parent){

	return 2*parent + 1;
    }
///////////////////////
// BHEAP_RIGHT 
///////////////////////
    size_t bheap_right (size_t parent){

	return 2*parent + 2;
    }
///////////////////////
// BHEAP_PARENT 
///////////////////////
    size_t bheap_parent (size_t child){

	return (child - 1)/2;
    }
///////////////////////
// BHEAP_IS_VALID_NODE 
///////////////////////
    int bheap_is_valid_node (binary_heap *heap, size_t position){

    }
