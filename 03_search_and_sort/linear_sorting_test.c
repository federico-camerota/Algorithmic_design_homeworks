#include "linear_sorting.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(){

    size_t n = 20;
    int a[n];
    srand(time(NULL));
    printf("Before sorting\n");
    for (size_t i = 0; i < n; ++i){
	a[i] = (200 - (abs(rand()) % (500)));
	printf("%d\t", a[i]);	
    }
    putchar('\n');

    radix_sort(a,n, 3);
    printf("After sorting\n");
    for (size_t i = 0; i < n; ++i){
	printf("%d\t", a[i]);	
    }
    putchar('\n');
    
}
