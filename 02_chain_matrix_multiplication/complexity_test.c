#include "../01_strassen/matrix.h"
#include "chain_matrix_multiplication.h"
#include <stdio.h>
#include <time.h>

double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time);

int main(){

    size_t k = 10;
    size_t n_max = (1U << k);
    int p[n_max+1];
    for (size_t i = 0; i < n_max; ++i){
    
	p[i] = rand() % 20;
    }
    size_t **m = improved_allocate_matrix(n_max,n_max);
    size_t **s = improved_allocate_matrix(n_max, n_max);

    double elapsed[k];
    struct timespec b_time, e_time;

    for (size_t n = 2, k_i = 0; n <= n_max; n *= 2, ++k_i){

	clock_gettime(CLOCK_REALTIME, &b_time);
	matrix_chain (p, n, m, s);
	clock_gettime(CLOCK_REALTIME, &e_time);
	elapsed[k_i] = get_execution_time(b_time, e_time);
	printf("%lu: %lf\n", k_i, elapsed[k_i]);
    }

    for (size_t k_i = 1; k_i < k; ++k_i){
    
        printf("%f\n", elapsed[k_i]/elapsed[k_i - 1]);
    }
    

    improved_deallocate_matrix(m);
    improved_deallocate_matrix(s);
}


double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
  return (e_time.tv_sec-b_time.tv_sec) +
                   (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}
