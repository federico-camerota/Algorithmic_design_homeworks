#include "select.h"
#include <math.h>
#include "sorting_algorithms.h"

size_t select_aux (int *items, const size_t idx, const size_t lo, const size_t hi);
size_t select_pivot (int *items, const size_t lo, const size_t hi);
size_t partition_aux (int *items, const size_t lo, const size_t hi);
size_t partition_pivot_aux (int *items, const size_t lo, const size_t hi);


size_t select_alg (int * items, const size_t n, const size_t idx){

    return select_aux (items, idx - 1, 0, n - 1);
}


/////////////////////
// SELECT AUX
/////////////////////
    size_t select_aux (int *items, const size_t idx, const size_t lo, const size_t hi){

	size_t k = select_pivot (items, lo, hi);
	size_t j = partition_aux (items, lo, hi);

	if ( j == idx)
	    return j;

	if (j < idx)
	    return select_aux (items, idx, j + 1, hi);
	else{

	    size_t l = partition_pivot_aux(items, lo, k);
	    if (idx >= l)
	       return 	j;
	    else
		return select_aux (items, idx, 0, l - 1);
	}
    }

/////////////////////
// SELECT PIVOT
/////////////////////
    size_t select_pivot (int *items, const size_t lo, const size_t hi){

	size_t n = hi - lo + 1;
	size_t groups = (size_t) floor(n/5.0);
	size_t last_size = n % 5;
	
	for (size_t i = 0; i < groups; ++i){
	
	    size_t group_lo, group_size;
	    group_lo = lo + 5*i;
	    group_size = (i == groups - 1) ? last_size : 5;

	    quick_sort (items + group_lo, group_size);
	    int tmp = items[lo + i];
	    items[lo + i] = items[group_lo + (group_size / 2)];
	    items[group_lo + (group_size / 2)] = tmp;
	}

	return lo;
    }

/////////////////////
// PARTITION AUX
/////////////////////
    size_t partition_aux (int *items, const size_t lo, const size_t hi){

	//use element items[lo] as pivot
	//partition from lo+1 to hi
	size_t i, j;
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
		int tmp = items[i];
		items[i] = items[j];
		items[j] = tmp;
		++i;
		--j;
	    }
	}
	if (items[j] > items[lo])
	    --j;
	//set the pivot in the correct postion by swapping it with items[j]
	int tmp = items[j];
	items[j] = items[lo];
	items[lo] = tmp;
	return j;
    }

/////////////////////
// PARTITION PIVOT AUX
/////////////////////
    size_t partition_pivot_aux (int *items, const size_t lo, const size_t hi){

	    //use element items[lo] as pivot
	    //partition from lo+1 to hi
	    size_t i, j;
	    i = lo;
	    j = hi - 1;

	    //swap elements in order to arrive at the following situation:
	    //elements lo + 1 to i - 1 are less or equal to the pivot
	    //elements j + 1 to hi are greater than the pivot
	    while ( i < j ){
	    
		if (items[i] < items[hi])
		    ++i; //if items[i] is already on the right side increment i
		else if (items[j] >= items[hi])
		    --j; //if items[j] is already on the right side decrement j
		else{	    
		    //both items[i] and items[j] are on the wrong side
		    //swap them and increment i and decrement j
		    int tmp = items[i];
		    items[i] = items[j];
		    items[j] = tmp;
		    ++i;
		    --j;
		}
	    }
	    if (items[j] < items[hi])
		++j;
	    return j;
    }
