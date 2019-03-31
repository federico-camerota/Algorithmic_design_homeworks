#include "linear_sorting.h"

/////////////////////////
// COUNTING SORT
/////////////////////////
    void counting_sort (int *items, int *sorted_items, size_t n, int lo, int hi){

	int k = hi - lo + 1;
	size_t *c = (size_t *) calloc(k, sizeof(size_t));
	for (int i = 0; i < k; ++i)
	    c[i] = 0U;
	
	for (size_t i = 0; i < n; ++i)
	    c[(items[i] - lo)]++;

	for (int i = 1; i < k; ++i)
	    c[i] += c[i-1];

	for (size_t j = n - 1; j > 0; --j)
	    sorted_items[--c[(items[j]-lo)]] = items[j];
	sorted_items[--c[(items[0]-lo)]] = items[0];
    }

