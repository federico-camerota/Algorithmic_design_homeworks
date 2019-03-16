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
	ELEMENT_TYPE tmp = items[i];
	while ( j < ULONG_MAX && items[j] > tmp){
	
	    items[j+1] = items[j];
	    j--;
	}
	items[j+1] = tmp;
    }
}
