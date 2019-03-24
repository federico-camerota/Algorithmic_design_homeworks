#include "sorting_algorithms.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(){

    size_t n = 20;
    int a[n];
    srand(time(NULL));
    for (size_t i = 0; i < n; ++i){
	a[i] = (abs(rand()) % (20));
    }

    printf("Before sorting\n");
    printf("Is sorted: %d\n", is_sorted(a, n));
    heap_sort(a, n);
    printf("After sorting\n");
    printf("Is sorted: %d\n", is_sorted(a, n));
    for (size_t i = 0; i < n; ++i){
	printf("%d\t", a[i]);	
    }
    putchar('\n');
    
}
