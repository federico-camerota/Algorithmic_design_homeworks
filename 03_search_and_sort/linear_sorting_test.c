#include "linear_sorting.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(){

    size_t n = 20;
    double a[n];
    srand(time(NULL));
    printf("Before sorting\n");
    for (size_t i = 0; i < n; ++i){
	a[i] = 1.0 / (5 + (abs(rand()) % (20)));
	printf("%f\t", a[i]);	
    }
    putchar('\n');

    bucket_sort(a,n);
    printf("After sorting\n");
    for (size_t i = 0; i < n; ++i){
	printf("%f\t", a[i]);	
    }
    putchar('\n');
    
}
