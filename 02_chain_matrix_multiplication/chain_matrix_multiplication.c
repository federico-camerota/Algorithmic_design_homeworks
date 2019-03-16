#include "chain_matrix_multiplication.h"
#include <math.h>
#include <stdlib.h>

void chain_matrix_aux (int *p, float **m, float **s, size_t i, size_t j);

void matrix_chain (int *p, size_t n, float **m, float **s){

    for (size_t i=0; i < n; ++i){
    
	m[i][i] = 0;
    }
    for (size_t l = 1; l < n; ++l){
    
	for (size_t i = 0; i < (n - l); ++i){
	
	    size_t j = i + l;
	    chain_matrix_aux (p, m, s, i, j);
	}
    }
}

void chain_matrix_aux (int *p, float **m, float **s, size_t i, size_t j){

    m[i][j] = INFINITY;
    for (size_t k = i; k < j; ++k){
    
	float q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
	if ( q < m[i][j]){
	
	    m[i][j] = q;
	    s[i][j-1] = k+1;
	}
    }
}
