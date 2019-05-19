#include "../01_strassen/matrix.h"
#include "chain_matrix_multiplication.h"
#include <stdio.h>
#include <time.h>

#define CMM(M, row, col) M[row][col]
#define REPETITIONS 3
#define BILLION 1E9

double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time);

float **evaluate_CMM_aux(float ***As, size_t *dims, const size_t n, size_t **S, size_t i, size_t j);
float **evaluate_CMM(float ***As, size_t *dims, const size_t n, size_t **S);
float **evaluate_naive_CMM(float ***As, size_t *dims, const size_t n);
size_t *build_dimensions(const size_t n);
float ***build_problem_instance(const size_t *dims, const size_t n);
float **copy_matrix(float **orig, const size_t rows, const size_t cols);
int float_naive_matrix_mult(float **C, float **A, float **B, const size_t A_rows, const size_t A_cols, const size_t B_rows, const size_t B_cols);

size_t **ChainMatrixMul(size_t *dim, size_t n);

int main() {
  size_t n = 15;

  size_t *dims = build_dimensions(n);
  float ***As = build_problem_instance(dims, n);

  struct timespec requestStart, requestEnd;
  double accum;

printf("Input Size\tOptimal Solution\tNaive Solution\n");
for (size_t d = 1; d < n; d++) {
	printf("%-10ld", d);
	clock_gettime(CLOCK_REALTIME, &requestStart);
	for (int r = 0; r < REPETITIONS; r++) {
	    size_t **S = ChainMatrixMul(dims, d);
	    float **R = evaluate_CMM(As, dims, d, S);

	    improved_deallocate_matrix((void **)R);
	    improved_deallocate_matrix((void **)S);
	}
	clock_gettime(CLOCK_REALTIME, &requestEnd);

	accum = (requestEnd.tv_sec - requestStart.tv_sec) +
	    (requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;

	printf("\t%16lf", (accum / REPETITIONS));
	clock_gettime(CLOCK_REALTIME, &requestStart);
	for (int r = 0; r < REPETITIONS; r++) {

	    float **R = evaluate_naive_CMM(As, dims, d);
	    improved_deallocate_matrix((void **)R);
	}
	clock_gettime(CLOCK_REALTIME, &requestEnd);

	accum = (requestEnd.tv_sec - requestStart.tv_sec) +
	    (requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;

	printf("\t%14lf\n", (accum / REPETITIONS));
  }

  for (size_t i = 0; i < n; i++) {
    improved_deallocate_matrix((void **)As[i]);
  }
  free(As);
  free(dims);
}

size_t **ChainMatrixMul(size_t *dim, size_t n){

    size_t **m =  improved_allocate_matrix(n,n);
    size_t **s =  improved_allocate_matrix(n, n);
    matrix_chain (dim, n, m, s);
    improved_deallocate_matrix((void **)m);
    return s;
}


double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
    return (e_time.tv_sec-b_time.tv_sec) +
		   (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}

float **evaluate_CMM_aux(float ***As, size_t *dims, const size_t n, size_t **S, size_t i, size_t j) {

    if (i == j) {
    return copy_matrix(As[i], dims[i], dims[j + 1]);
    }

    size_t p = CMM(S, i, j);

    float **C1 = evaluate_CMM_aux(As, dims, n, S, i, p);
    float **C2 = evaluate_CMM_aux(As, dims, n, S, p + 1, j);

    float **R = (float **) allocate_matrix(dims[i], dims[j + 1]);

    float_naive_matrix_mult(R, C1, C2, dims[i], dims[p + 1], dims[p + 1], dims[j + 1]);

    deallocate_matrix((void **)C1, dims[i]);
    deallocate_matrix((void **)C2, dims[p + 1]);
    return R;
}

float **evaluate_CMM(float ***As, size_t *dims, const size_t n, size_t **S) {
    return evaluate_CMM_aux(As, dims, n, S, 0, n - 1);
}                         

float **evaluate_naive_CMM(float ***As, size_t *dims, const size_t n) {
    float **C = copy_matrix(As[0], dims[0], dims[1]);
    float **R;

    for (size_t i = 1; i < n; i++) {
    R = (float **) allocate_matrix(dims[0], dims[i + 1]);

    float_naive_matrix_mult(R, C, As[i], dims[0], dims[i], dims[i], dims[i + 1]);

    deallocate_matrix((void **)C, dims[0]);
    C = R;
    }

    return C;
}

size_t *build_dimensions(const size_t n) {
    size_t *dims = (size_t *)malloc(sizeof(size_t) * (n + 1));

    for (size_t i = 0; i < n + 1; i++) {
    dims[i] = rand() % 600;
    }

    return dims;
}
float ***build_problem_instance(const size_t *dims, const size_t n) {
    float ***A = (float ***)malloc(sizeof(float **) * n);

    for (size_t i = 0; i < n; i++) {
    A[i] = (float **) improved_allocate_matrix(dims[i], dims[i + 1]);
    }

    return A;
}
float **copy_matrix(float **orig, const size_t rows, const size_t cols)
{
  float **C= (float **) allocate_matrix(rows, cols);

  for (size_t i=0; i<rows; i++) {
    for (size_t j=0; j<cols; j++) {
      C[i][j]=orig[i][j];
    }
  }

  return C;
}
int float_naive_matrix_mult(float **C, float **A, float **B, const size_t A_rows, const size_t A_cols, const size_t B_rows, const size_t B_cols)
{
  if (A_cols != B_rows) {
     return -1;
  }

  // for all rows in A
  for (size_t i=0; i<A_rows; i++) {

     // for all cols in B
     for (size_t j=0; j<B_cols; j++) {

       // reset C[i][j]
       C[i][j] = 0.0;

       // sum all the element mults
       for (size_t k=0; k<A_cols; k++) {
        C[i][j] += (A[i][k]*B[k][j]);
       }
     }
  }

  return 0;
}
