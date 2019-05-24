CC= gcc
CCFLAGS= -Wall -Wextra -lm -ggdb

FILES = dijkstra.c heaps.c
heap_dijkstra=heap_dijkstra.x
array_dijkstra=array_dijkstra.x

all:  ${heap_dijkstra} ${array_dijkstra} 

heap : ${heap_dijkstra}
array : ${array_dijkstra}

${heap_dijkstra} : main.c ${FILES}
	${CC} -o $@ $^ ${CCFLAGS} 

${array_dijkstra} : main.c ${FILES}
	${CC} -o $@ $^ ${CCFLAGS} -DARRAY

clean:
	rm *.x
.PHONY: clean all
