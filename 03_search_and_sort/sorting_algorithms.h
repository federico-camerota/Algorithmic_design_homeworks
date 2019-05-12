#ifndef _SORTING_ALGS_H_
#define _SORTING_ALGS_H_

#ifndef ELEMENT_TYPE
#define ELEMENT_TYPE int
#endif

#include <stdlib.h>

void insertion_sort (ELEMENT_TYPE *items, size_t n);
void quick_sort (ELEMENT_TYPE *items, int n);
void best_quick_sort (ELEMENT_TYPE *items, int n);
void heap_sort (ELEMENT_TYPE *items, size_t n);
int is_sorted (ELEMENT_TYPE *items, size_t n);

#endif
