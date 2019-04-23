#include "select.h"
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
	a[i] = (5 + (rand() % (20))) + (abs(rand()) % 10);
	printf("%d\t", a[i]);	
    }
    putchar('\n');
    printf("5th element is: %d\n", a[select_alg(a,n, 5)]);
    quick_sort(a, n);
    printf("After sorting\n");
    for (size_t i = 0; i < n; ++i){
	printf("%d\t", a[i]);	
    }
    putchar('\n');
}
