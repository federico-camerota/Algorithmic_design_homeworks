#ifndef __STRASSEN__

#include <stdlib.h>
#include "matrix.h"

void strassen(SCALAR_TYPE **C, SCALAR_TYPE **A, SCALAR_TYPE **B, const size_t n);
void improved_strassen(SCALAR_TYPE **C, SCALAR_TYPE **A, SCALAR_TYPE **B, const size_t n);

#endif // __STRASSEN__
