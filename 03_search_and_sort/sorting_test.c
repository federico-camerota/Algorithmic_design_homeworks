#include "sorting_algorithms.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(){

    size_t n = 20;
    int a[n], b[n];
    srand(time(NULL));
    for (size_t i = 0; i < n; ++i){
	a[i] = 5 + (abs(rand()) % (20));
	printf("%d\t", a[i]);	
    }
    putchar('\n');

    printf("Before sorting\n");
    printf("Is sorted: %d\n", is_sorted(a, n));
    counting_sort(a,b, n, 5, 24);
    printf("After sorting\n");
    printf("Is sorted: %d\n", is_sorted(b, n));
    for (size_t i = 0; i < n; ++i){
	printf("%d\t", b[i]);	
    }
    putchar('\n');
    
}
