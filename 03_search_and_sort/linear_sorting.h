#ifndef LINEAR_SORTING_H
#define LINEAR_SORTING_H

#include <stdlib.h>

#ifndef INTEGER_TYPE
#define INTEGER_TYPE int
#endif

void counting_sort (int *items, int *sorted_items, const size_t n, const int lo, const int hi);
void bucket_sort (double *items, const size_t n);

void radix_sort (INTEGER_TYPE *items, const size_t n, const unsigned digits);
#endif
