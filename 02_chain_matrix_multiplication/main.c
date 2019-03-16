#include "../01_strassen/matrix.h"
#include "chain_matrix_multiplication.h"
#include <stdio.h>

int main(){

    size_t n = 6;
    int p[7] = {30, 35, 15, 5, 10, 20, 25};
    float **m = improved_allocate_matrix(n,n);
    float **s = improved_allocate_matrix(n, n);

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
