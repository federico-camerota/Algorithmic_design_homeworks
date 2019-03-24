#include "heaps.h"
#include <stdlib.h>
#include <stdio.h>

///////////////////////
// BHEAP_NEW
///////////////////////
    int min_comp (ITEM_TYPE a, ITEM_TYPE b){
    
	return a < b;
    }

    binary_heap *bheap_new(ITEM_TYPE *items,int (*comp_fun)(ITEM_TYPE, ITEM_TYPE) , size_t max_size, size_t current_size){

	binary_heap *new_heap = (binary_heap *) malloc(sizeof(binary_heap));
	new_heap->max_size = max_size;
	new_heap->current_size = current_size;
	new_heap->comp_fun = comp_fun;
	if (comp_fun == NULL)
	    new_heap->comp_fun = min_comp;
	new_heap->items = items;
	if (new_heap->items == NULL)
	    new_heap->items = (ITEM_TYPE *) calloc(max_size, sizeof(ITEM_TYPE));
	else{
	
	    for (size_t i = bheap_parent(current_size - 1); i > 0; --i)
		bheap_heapify(new_heap, i);

	    bheap_heapify(new_heap, 0);
	}

	return new_heap;
    }
///////////////////////
// BHEAP_FREE
///////////////////////
    void bheap_free(binary_heap *heap){

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
	
	return heap->current_size > position;
    }
///////////////////////
// BHEAP_HEAPIFY
///////////////////////
    void bheap_heapify (binary_heap *heap, size_t node){

	size_t current_parent = node;
	while (bheap_is_valid_node(heap, current_parent)){
	
	    //(current_parent >> (sizeof(size_t)*8 - 1)) && return;
	    size_t left, right, min_idx;
	    left = bheap_left(current_parent);
	    right = bheap_right(current_parent);
	    min_idx = current_parent;
	    
	    if (bheap_is_valid_node(heap, left) && 
		heap->comp_fun(heap->items[left] , heap->items[min_idx]))
	    {
		min_idx = left;
	    }
	    if (bheap_is_valid_node(heap, right) && 
		heap->comp_fun(heap->items[right] , heap->items[min_idx]))
	    {
		min_idx = right;
	    }
	    if (min_idx == current_parent)
		return;
	    ITEM_TYPE tmp = heap->items[current_parent];
	    heap->items[current_parent] = heap->items[min_idx];
	    heap->items[min_idx] = tmp;
	    current_parent = min_idx;
	}
    }
///////////////////////
// BHEAP_IS_HEAP
///////////////////////
    int bheap_is_heap (binary_heap *heap){

	size_t last_parent = bheap_parent(heap->current_size - 1);
	for (size_t i = 0; i <= last_parent ; ++i){
	
	    if (bheap_is_valid_node(heap, bheap_left(i)) && heap->comp_fun(heap->items[bheap_left(i)] , heap->items[i]))
		    return 0;
	    if (bheap_is_valid_node(heap, bheap_right(i)) && heap->comp_fun(heap->items[bheap_right(i)], heap->items[i]))
		    return 0;
	}
	return 1;
    }
///////////////////////
// BHEAP_REMOVE_MIN
///////////////////////
    ITEM_TYPE bheap_remove_min (binary_heap *heap){

	ITEM_TYPE min = heap->items[0];
	heap->items[0] = heap->items[heap->current_size-1];
	heap->current_size -= 1;

	bheap_heapify(heap, 0);

	return min;
    }
