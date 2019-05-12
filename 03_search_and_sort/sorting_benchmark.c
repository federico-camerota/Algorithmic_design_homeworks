#include <stdio.h>
#include <stdlib.h>
#include "sorting_algorithms.h"
#include <time.h>
#include <math.h>

void shuffle(int *array, size_t n);
void revert(int *array, size_t n);

int main(){

    printf("%-15s\t%-15s\t%-15s\t%-15s\n","quicksort best","quicksort worst","insertion best","insertion worst");
    size_t n;
    clock_t start, end;
    double elapsed;
    for (n = 1024; n < 66000; n *= 2){
    
	int *array = (int *) calloc(n, sizeof(int));
	int i;
	for (i = 0; i < n; ++i)
	    array[i] =  i;
	shuffle(array, n);

	start = clock();
	best_quick_sort(array, n);
	end = clock();
	elapsed = ((double) end - start) / CLOCKS_PER_SEC;
	printf("%15f\t", elapsed);

	start = clock();
	quick_sort(array,n);	
	end = clock();
	elapsed = ((double) end - start) / CLOCKS_PER_SEC;
	printf("%15f\t", elapsed);

	start = clock();
	insertion_sort(array,n);	
	end = clock();
	elapsed = ((double) end - start) / CLOCKS_PER_SEC;
	printf("%15f\t", elapsed);

	revert(array, n);
	
	start = clock();
	insertion_sort(array,n);	
	end = clock();
	elapsed = ((double) end - start) / CLOCKS_PER_SEC;
	printf("%15f", elapsed);
	putchar('\n');

	free(array);
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
void revert(int *array, size_t n){
    
    size_t i, j;
    i = 0; 
    j = n-1;
    while (i < j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	i++;
	j--;
    }
}
