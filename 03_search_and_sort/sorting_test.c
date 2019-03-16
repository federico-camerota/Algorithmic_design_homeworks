#include "sorting_algorithms.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    size_t n = 200;
    int a[n];
    for (size_t i = 0; i < n; ++i){
	a[i] = rand();
    }

    printf("Before sorting\n");
    printf("Is sorted: %d\n", is_sorted(a, n));
    insertion_sort(a, n);
    printf("After sorting\n");
    printf("Is sorted: %d\n", is_sorted(a, n));
    
}
