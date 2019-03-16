#include "search_algorithms.h"

size_t linear_search (ELEMENT_TYPE *items, size_t n, ELEMENT_TYPE query){

    size_t i = 0;
    for (; i < n; ++i){
    
	if (items[i] == query)
	    break;
    }
    return i; //returns a value 0 <= i < n if the elements is in the array
	      //and n if the element is not in the array.
}

size_t binary_search (ELEMENT_TYPE *items, size_t n, ELEMENT_TYPE query){

    size_t lo, hi;
    lo = 0;
    hi = n - 1;
    while (lo < hi){
    
	size_t mid = lo + ((hi - lo) >> 1);
	if (items[mid] == query)
	    return mid;
	else if (items[mid] > query)
	    hi = mid - 1;
	else
	    lo = mid + 1;
    }
    if (items[lo] == query)//avoid underflow if query is smaller then
	return lo;         //every element in items
	
    return n;
}
