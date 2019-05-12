#include "sorting_algorithms.h"
#include <stdint.h>
#define ITEM_TYPE ELEMENT_TYPE
#include "../04_heap/heaps.h"
#include <math.h>

/////////////////////////
// IS SORTED AUXILIARY FUNCTION
/////////////////////////
    int is_sorted (ELEMENT_TYPE *items, size_t n){

	for (size_t i = 1; i < n; ++i){
	
	    if (items[i] < items[i-1])
		return 0;
	} 
	return 1;
    }
/////////////////////////
// INSERTION SORT
/////////////////////////
    void insertion_sort (ELEMENT_TYPE *items, size_t n){

	for (size_t i = 1; i < n; ++i){
	
	    size_t j = i-1;
	    ELEMENT_TYPE tmp = items[i];
	    while ( j < SIZE_MAX && items[j] > tmp){
	    
		items[j+1] = items[j];
		j--;
	    }
	    items[j+1] = tmp;
	}
    }
/////////////////////////
// QUICK SORT
/////////////////////////
    int quick_sort_partition_aux (ELEMENT_TYPE *items, int lo, int hi);
    void quick_sort_aux (ELEMENT_TYPE *items, int lo, int hi);

    void quick_sort (ELEMENT_TYPE *items, int n){
    
	quick_sort_aux(items, 0, n - 1);
    }

    void quick_sort_aux (ELEMENT_TYPE *items, int lo, int hi){

	if ( hi > lo ){
	
	    int pivot_idx = quick_sort_partition_aux(items, lo, hi);	
	    quick_sort_aux (items, lo, pivot_idx - 1);
	    quick_sort_aux (items, pivot_idx + 1, hi);
	}
    }

    int quick_sort_partition_aux (ELEMENT_TYPE *items, int lo, int hi){

	//use element items[lo] as pivot
	//partition from lo+1 to hi
	int i, j;
	i = lo + 1;
	j = hi;

	//swap elements in order to arrive at the following situation:
	//elements lo + 1 to i - 1 are less or equal to the pivot
	//elements j + 1 to hi are greater than the pivot
	while ( i < j ){
	
	    if (items[i] <= items[lo])
		++i; //if items[i] is already on the right side increment i
	    else if (items[j] > items[lo])
		--j; //if items[j] is already on the right side decrement j
	    else{	    
		//both items[i] and items[j] are on the wrong side
		//swap them and increment i and decrement j
		ELEMENT_TYPE tmp = items[i];
		items[i] = items[j];
		items[j] = tmp;
		++i;
		--j;
	    }
	}
	if (items[j] > items[lo])
	    --j; //if items[j] is already on the right side decrement j
	//set the pivot in the correct postion by swapping it with items[j]
	ELEMENT_TYPE tmp = items[j];
	items[j] = items[lo];
	items[lo] = tmp;
	return j;
    }
/////////////////////////
// BEST QUICK SORT
/////////////////////////
    size_t select_pivot (ELEMENT_TYPE *items, const size_t lo, const size_t hi){
	size_t n = hi - lo + 1;
	size_t groups = (size_t) floor(n/5.0);
	size_t last_size = n % 5;
	
	for (size_t i = 0; i < groups; ++i){
	
	    size_t group_lo, group_size;
	    group_lo = lo + 5*i;
	    group_size = (i == groups - 1) ? last_size : 5;

	    quick_sort (items + group_lo, group_size);
	    ELEMENT_TYPE tmp = items[lo + i];
	    items[lo + i] = items[group_lo + (group_size / 2)];
	    items[group_lo + (group_size / 2)] = tmp;
	}

	return lo;
    }
    void best_quick_sort_aux (ELEMENT_TYPE *items, int lo, int hi);
    int best_quick_sort_partition_aux (ELEMENT_TYPE *items, int lo, int hi);

    void best_quick_sort (ELEMENT_TYPE *items, int n){
    
	best_quick_sort_aux(items, 0, n - 1);
    }

    void best_quick_sort_aux (ELEMENT_TYPE *items, int lo, int hi){

	if ( hi > lo ){
	
	    int pivot_idx = best_quick_sort_partition_aux(items, lo, hi);	
	    best_quick_sort_aux (items, lo, pivot_idx - 1);
	    best_quick_sort_aux (items, pivot_idx + 1, hi);
	}
    }

    int best_quick_sort_partition_aux (ELEMENT_TYPE *items, int lo, int hi){

	//use element items[lo] as pivot
	//partition from lo+1 to hi
	select_pivot(items, lo, hi);// put median value at the beginning
	int i, j;
	i = lo + 1;
	j = hi;

	//swap elements in order to arrive at the following situation:
	//elements lo + 1 to i - 1 are less or equal to the pivot
	//elements j + 1 to hi are greater than the pivot
	while ( i < j ){
	
	    if (items[i] <= items[lo])
		++i; //if items[i] is already on the right side increment i
	    else if (items[j] > items[lo])
		--j; //if items[j] is already on the right side decrement j
	    else{	    
		//both items[i] and items[j] are on the wrong side
		//swap them and increment i and decrement j
		ELEMENT_TYPE tmp = items[i];
		items[i] = items[j];
		items[j] = tmp;
		++i;
		--j;
	    }
	}
	if (items[j] > items[lo])
	    --j; //if items[j] is already on the right side decrement j
	//set the pivot in the correct postion by swapping it with items[j]
	ELEMENT_TYPE tmp = items[j];
	items[j] = items[lo];
	items[lo] = tmp;
	return j;
    }
/////////////////////////
// HEAP SORT
/////////////////////////
    int max_comp(ELEMENT_TYPE a, ELEMENT_TYPE b){
    
	return a > b;
    }
    void heap_sort (ELEMENT_TYPE *items, size_t n){

	binary_heap *heap = bheap_new(items,max_comp, n, n);	
	for (size_t i = n - 1; i > 0; --i)
	    heap->items[i] = bheap_remove_min(heap);
    }
