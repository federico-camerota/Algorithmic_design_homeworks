#include "../01_strassen/matrix.h"
#include "chain_matrix_multiplication.h"
#include <stdio.h>

int main(){

    size_t n = 4;
    size_t p[5] = {3, 5, 10, 2 , 3};
    size_t **m = improved_allocate_matrix(n,n);
    size_t **s = improved_allocate_matrix(n, n);

    matrix_chain (p, n, m, s);
    
    printf("M matrix:\n");
    for (size_t i = 0; i < n; ++i){
    
	for (size_t j = 0; j < n; ++j){
	
	   printf("%lu\t", m[i][j]); 
	}
	putchar('\n');
    }
    printf("S matrix:\n");
    for (size_t i = 0; i < n ; ++i){
    
	for (size_t j = 0; j < n ; ++j){
	
	   printf("%lu\t", s[i][j]); 
	}
	putchar('\n');
    }

    improved_deallocate_matrix( (void **) m);
    improved_deallocate_matrix( (void **)s);
}
