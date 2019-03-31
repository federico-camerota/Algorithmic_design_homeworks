#include "sorting_algorithms.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(){

    size_t n = 20;
    double a[n];
    srand(time(NULL));
    for (size_t i = 0; i < n; ++i){
	a[i] = 1.0/(5 + (abs(rand()) % (20))) + (abs(rand()) % 10);
	printf("%f\t", a[i]);	
    }
    putchar('\n');

    printf("Before sorting\n");
    printf("Is sorted: %d\n", is_sorted(a, n));
    insertion_sort(a, n);
    printf("After sorting\n");
    printf("Is sorted: %d\n", is_sorted(a, n));
    for (size_t i = 0; i < n; ++i){
	printf("%f\t", a[i]);	
    }
    putchar('\n');
    
}
