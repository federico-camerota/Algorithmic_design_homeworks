CC= gcc
CCFLAGS= -Wall -Wextra
searching= search_test.x 
sorting= sorting_test.x
SEARCH_FILES= search_algorithms.c
SORT_FILES= sorting_algorithms.c

all: ${searching} ${sorting}

${searching} : ${searching:x=c} ${MATRIX_AUX} ${SEARCH_FILES}
	${CC} -o $@ $^  ${CCFLAGS}


${sorting}: ${sorting:x=c} ${MATRIX_AUX} ${SORT_FILES}
	${CC} -o $@ $^  ${CCFLAGS}


clean:
	rm ${sorting} ${searching}

.PHONY: clean all
