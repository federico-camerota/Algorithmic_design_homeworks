#ifndef CHAIN_MATRIX_MUL_H
#define CHAIN_MATRIX_MUL_H

#include <stdlib.h>

/*
 * Computes the M and S matrices in the chain matrix multiplication algorithm.
 * - p is the vector of matrix dimensions
 * - n is the number of matrices in the chain
 * - m is the matrix in which the M matrix will be stored
 * - s is the matrix in which the S matrix will be stored
 *
 * Both m and s are asssumed to be n x n matrices.
 */
void matrix_chain (size_t *p, size_t n, size_t **m, size_t **s);

#endif
