#include <select.h>

size_t select_aux (int *items, const size_t idx, const size_t lo, const size_t hi);
size_t select_pivot (int *items, const size_t lo, const size_t hi);
int partition_aux (int *items, int lo, int hi, const size_t pivot);


size_t select (int * items, const size_t n, const size_t idx){

    return select_aux (items, idx, 0, n - 1);
}


/////////////////////
// SELECT AUX
/////////////////////
size_t select_aux (int *items, const size_t idx, const size_t lo, const size_t hi){

    size_t k = select_pivot (items, lo, hi);
    int j = partition_aux (items, lo, hi, k);

    if ((

}


/////////////////////
// PARTITION AUX
/////////////////////
    int partition_aux (int *items, int lo, int hi, const size_t pivot){

	//use element items[pivot] as pivot, so put it in items[lo] and
	//partition from lo+1 to hi
	int tmp = items[pivot];
	items[pivot] = items[lo];
	items[lo] = tmp;
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
	tmp = items[j];
	items[j] = items[lo];
	items[lo] = tmp;
	return j;
    }

