#include "sorting_algorithms.h"
#include <limits.h>

int is_sorted (ELEMENT_TYPE *items, size_t n){

    for (size_t i = 1; i < n; ++i){
    
	if (items[i] < items[i-1])
	    return 0;
    } 
    return 1;
}
void insertion_sort (ELEMENT_TYPE *items, size_t n){

    for (size_t i = 1; i < n; ++i){
    
	size_t j = i-1;
	while ( j < ULONG_MAX && items[j] > items[j+1]){
	
	    items[j+1] ^= items[j];
	    items[j] ^= items[j+1];
	    items[j+1] ^= items[j];
	    j--;
	}
    }
}
