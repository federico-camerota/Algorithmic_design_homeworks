#include <stdlib.h>
#include <math.h>
#include "matrix.h"

int naive_matrix_mult(SCALAR_TYPE **C,
                        SCALAR_TYPE **A,
                        SCALAR_TYPE **B,
                        const size_t A_rows,
                        const size_t A_cols,
                        const size_t B_rows,
                        const size_t B_cols)
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

SCALAR_TYPE **allocate_matrix(const size_t rows,
                        const size_t cols)
{
   SCALAR_TYPE **A=(SCALAR_TYPE **)malloc(sizeof(SCALAR_TYPE *)*rows);

   for (size_t i=0; i<rows; i++) {
     A[i]=(SCALAR_TYPE *)malloc(sizeof(SCALAR_TYPE)*cols);
   }

   return A;
}
void deallocate_matrix(void **A, const size_t rows)
{
  for (size_t i=0; i<rows; i++) {
    free(A[i]);
  }

  free(A);
}

SCALAR_TYPE **improved_allocate_matrix(const size_t rows,
                        const size_t cols)
{
   SCALAR_TYPE **A=(SCALAR_TYPE **)malloc(sizeof(SCALAR_TYPE *)*rows);
   SCALAR_TYPE *data = (SCALAR_TYPE *) calloc(cols*rows, sizeof(SCALAR_TYPE));

   for (size_t i=0; i<cols*rows; i += cols) {
     A[i/cols] = data + i;
   }

   return A;
}
void improved_deallocate_matrix(void **A)
{
  free(A[0]);
  free(A);
}


int same_matrix(SCALAR_TYPE **A, const size_t A_rows, const size_t A_cols,
		SCALAR_TYPE **B, const size_t B_rows, const size_t B_cols)
{
   if ((A_rows != B_rows) || (A_cols != B_cols)) {
     return 0;
   }

   for (size_t i=0; i<A_rows; i++) {
     for (size_t j=0; j<A_cols; j++) {
        if (abs(A[i][j] - B[i][j]) > 1e-13) {
	         return 0;
        }
     }
   }

   return 1;
}
void sum_matrix_blocks(SCALAR_TYPE **C,
                       const size_t C_f_row,
                       const size_t C_f_col,
                       SCALAR_TYPE ** A,
                       const size_t A_f_row,
                       const size_t A_f_col,
                       SCALAR_TYPE ** B,
                       const size_t B_f_row,
                       const size_t B_f_col,
                       const size_t n)
{
  // for all the rows in the blocks
  for (size_t i=0; i<n; i++) {

    // for all the cols in the blocks
    for (size_t j=0; j<n; j++) {
      C[C_f_row+i][C_f_col+j] = A[A_f_row+i][A_f_col+j] +
                                B[B_f_row+i][B_f_col+j];
    }
  }
}

void sub_matrix_blocks(SCALAR_TYPE **C,
                       const size_t C_f_row,
                       const size_t C_f_col,
                       SCALAR_TYPE ** A,
                       const size_t A_f_row,
                       const size_t A_f_col,
                       SCALAR_TYPE ** B,
                       const size_t B_f_row,
                       const size_t B_f_col,
                       const size_t n)
{
  // for all the rows in the blocks
  for (size_t i=0; i<n; i++) {

    // for all the cols in the blocks
    for (size_t j=0; j<n; j++) {
      C[C_f_row+i][C_f_col+j] = A[A_f_row+i][A_f_col+j] -
                                B[B_f_row+i][B_f_col+j];
    }
  }
}
