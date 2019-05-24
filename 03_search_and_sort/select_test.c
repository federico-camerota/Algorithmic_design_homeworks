#include "select.h"
#include "sorting_algorithms.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(){

    size_t n;
    printf("Array size\tElement position\tExecution time\n");
    for (n = 32; n < 10E6; n*=2){

	printf("%-10ld\t", n);
	int *a = (int *) calloc(n, sizeof(int));
	srand(time(NULL));
	for (size_t i = 0; i < n; ++i){
	    a[i] = (5 + (rand() % (20))) + (abs(rand()) % 10);
	}

	size_t pos = (abs(rand()) % n) + 1;

	printf("%15ld\t", pos);

	clock_t start, elapsed;
	start = clock();
	select_alg(a,n, pos);
	elapsed = clock() - start;

	printf("%20lf\n", ((double)elapsed/CLOCKS_PER_SEC));
	free(a);
    }
}
