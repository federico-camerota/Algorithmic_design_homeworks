#ifndef __MATRIX__

#include <stdlib.h>

#ifndef SCALAR_TYPE
#define SCALAR_TYPE float
#endif
int naive_matrix_mult(  SCALAR_TYPE **C,
                        SCALAR_TYPE **A,
                        SCALAR_TYPE **B,
                        const size_t A_rows,
                        const size_t A_cols,
                        const size_t B_rows,
                        const size_t B_cols);

SCALAR_TYPE **allocate_matrix(const size_t rows,
                        const size_t cols);
SCALAR_TYPE **improved_allocate_matrix(const size_t rows,
				 const size_t cols);
void deallocate_matrix(SCALAR_TYPE **A, const size_t rows);
void improved_deallocate_matrix(SCALAR_TYPE **A);

int same_matrix(SCALAR_TYPE **A, const size_t A_rows, const size_t A_cols,
		SCALAR_TYPE **B, const size_t B_rows, const size_t B_cols);
void sum_matrix_blocks(SCALAR_TYPE **C,
                       const size_t C_f_row,
                       const size_t C_f_col,
                       SCALAR_TYPE ** A,
                       const size_t A_f_row,
                       const size_t A_f_col,
                       SCALAR_TYPE ** B,
                       const size_t B_f_row,
                       const size_t B_f_col,
                       const size_t n);
void sub_matrix_blocks(SCALAR_TYPE **C,
                       const size_t C_f_row,
                       const size_t C_f_col,
                       SCALAR_TYPE ** A,
                       const size_t A_f_row,
                       const size_t A_f_col,
                       SCALAR_TYPE ** B,
                       const size_t B_f_row,
                       const size_t B_f_col,
                       const size_t n);

#endif // __MATRIX__
