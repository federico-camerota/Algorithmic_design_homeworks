#include "linear_sorting.h"
#include <math.h>

//Include sorting algorithms to use in bucket sort
#include "sorting_algorithms.h"

/////////////////////////
// COUNTING SORT
/////////////////////////
    void counting_sort (int *items, int *sorted_items, const size_t n, const int lo, const int hi){

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

	free(c);
    }
/////////////////////////
// BUCKET SORT
/////////////////////////
    void bucket_sort (double *items, const size_t n){

	double **buckets = (double **) calloc(n, sizeof(double *));	
	size_t *buckets_size = (size_t *) calloc(n, sizeof(size_t));
	for (size_t i = 0; i < n; ++i){
	    buckets[i] = (double *) calloc(n, sizeof(double));
	    buckets_size[i] = 0;
	}

	//fill buckets
	for (size_t i = 0; i < n; ++i){

	    size_t bucket_id = (size_t) floor(items[i]*n);
	    buckets[bucket_id][buckets_size[bucket_id]] = items[i];
	    buckets_size[bucket_id]+=1;
	}

	//sort buckets
	for (size_t i = 0; i < n; ++i)
	    quick_sort(&(buckets[i][0]), buckets_size[i]);

	size_t pos = 0;	
	for (size_t i = 0; i < n; ++i){

	    size_t size = buckets_size[i];
	    for (size_t j = 0; j < size; ++j){
		items[pos] = buckets[i][j];
		++pos;
	    }
	}

	for (size_t i = 0; i < n; ++i){
	    free(buckets[i]);
	}
	free(buckets);
	free(buckets_size);
	
    }
/////////////////////////
// RADIX SORT
/////////////////////////
void radix_sort (INTEGER_TYPE *items, const size_t n, const unsigned digits){

    int is_signed = ((INTEGER_TYPE) -1 ) < 0;// check if INTEGER_TYPE is signed
    if (is_signed){
    
	size_t neg_count = 0;
	for (size_t i = 0; i < n; ++i){
	
	    if (items[i] < 0){
	    
		INTEGER_TYPE tmp = items[i];
		items[i] = items[neg_count];
		items[neg_count++] = tmp;
	    }
	}

	radix_sort_aux (items, neg_count);// sort negative numbers
	radix_sort_aux ((items + neg_count), (n - neg_count));//sort positive numbers

	for (size_t i = 0; i < neg_count - i - 1; ++i){// revert order of negative numbers
	
	    INTEGER_TYPE tmp = items[i];
	    items[i] = items[neg_count - i - 1];
	    items[neg_count - i - 1] = tmp;
	}

	return;
    }

    radix_sort_aux(items, n);
}

