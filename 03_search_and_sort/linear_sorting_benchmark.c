#include <stdio.h>
#include <stdlib.h>
#include "linear_sorting.h"
#include <time.h>
#include <math.h>

void shuffle(int *array, size_t n);

int main(){
    printf("%-13s\t%-11s\t%-10s\n","counting sort","bucket sort","radix sort");
    size_t n;
    clock_t start, end;
    double elapsed;
    for (n = 1024; n < 66000; n *= 2){
    
	int array[n], b[n];
	double d_array[n];
	size_t i;
	for (i = 0; i < n; ++i)
	    array[i] =  i;
	shuffle(array, n);
	for (i = 0; i < n; ++i)
	    d_array[i] =  1.0/array[i];

	start = clock();
	counting_sort(array,b, n);
	end = clock();
	elapsed = ((double) end - start) / CLOCKS_PER_SEC;
	printf("%13f\t", elapsed);

	start = clock();
	bucket_sort(d_array,n);	
	end = clock();
	elapsed = ((double) end - start) / CLOCKS_PER_SEC;
	printf("%11f\t", elapsed);

	start = clock();
	radix_sort(array,n, 5);	
	end = clock();
	elapsed = ((double) end - start) / CLOCKS_PER_SEC;
	printf("%10f\t", elapsed);

	putchar('\n');
    }
}


void shuffle( int *array, size_t n){

    size_t i;
    for (i = n-1; i > 0; --i){
	size_t rand_idx = rand() % i;
	int temp = array[i];
	array[i] = array[rand_idx];
	array[rand_idx] = temp;
    }
}
