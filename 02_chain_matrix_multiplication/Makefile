CC= gcc
CCFLAGS= -Wall -Wextra -ggdb
complexity= complexity_test.x 
correctness= correctness_test.x
MATRIX_AUX= ../01_strassen/matrix.c
HEADERS= chain_matrix_multiplication.h ../01_strassen/matrix.h
FILES= chain_matrix_multiplication.c
SCALAR_MACRO = -DSCALAR_TYPE=size_t

all: ${complexity} ${correctness}

${complexity} : ${complexity:x=c} ${MATRIX_AUX} ${FILES}
	${CC} -o $@ $^ ${SCALAR_MACRO} ${CCFLAGS}

${complexity}: ${HEADERS}

${correctness}: ${correctness:x=c} ${MATRIX_AUX} ${FILES}
	${CC} -o $@ $^ ${SCALAR_MACRO} ${CCFLAGS}

${correctness}: ${HEADERS}

clean:
	rm ${correctness} ${complexity}

.PHONY: clean all
