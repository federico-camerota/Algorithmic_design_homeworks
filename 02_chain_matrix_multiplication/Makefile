CC=gcc
CCFLAGS= -Wall -Wextra
complexity = complexity_test 
correctness = correctness_test
MATRIX_AUX = ../01_strassen/matrix.c
HEADERS = chain_matrix_multiplication.h ../01_strassen/matrix.h
FILES = chain_matrix_multiplication.c

all: ${complexity}.x ${correctness_test}.x

${complexity}.x: ${complexity}.c ${MATRIX_AUX} ${FILES}
	${CC} -o $@ $^

${complexity}.x: ${HEADERS}

${correctness}.x: ${correctness}.c ${MATRIX_AUX} ${FILES}
	${CC} -o $@ $^

${correctness}.x: ${HEADERS}

clean:
	rm ${correctness}.x ${complexity}.x

.PHONY: clean all
