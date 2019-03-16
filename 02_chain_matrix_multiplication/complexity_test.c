#include "../01_strassen/matrix.h"
#include "chain_matrix_multiplication.h"
#include <stdio.h>

int main(){

    size_t n_max = 64;
    int p[n_max+1];
    for (size_t i = 0; i < n_max; ++i){
    
	p[i] = RANDOM_NUM;
    }
    float **m = improved_allocate_matrix(n_max,n_max);
    float **s = improved_allocate_matrix(n_max, n_max);

    
    matrix_chain (p, n, m, s);
    
    printf("M matrix:\n");
    for (size_t i = 0; i < n; ++i){
    
	for (size_t j = 0; j < n; ++j){
	
	   printf("%.0f\t", m[i][j]); 
	}
	putchar('\n');
    }
    printf("S matrix:\n");
    for (size_t i = 0; i < n - 1; ++i){
    
	for (size_t j = 0; j < n - 1; ++j){
	
	   printf("%.0f\t", s[i][j]); 
	}
	putchar('\n');
    }

    improved_deallocate_matrix(m);
    improved_deallocate_matrix(s);
}
