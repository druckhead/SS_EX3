CC=gcc
AR=ar -rcs
CFLAGS= -Wall -g
EXE=stringProg


all: ${EXE}

stringProg: main.c sequence.o seqlib.a
	${CC} ${CFLAGS} -o ${EXE} main.c seqlib.a

sequence.o: sequence.c seq_lib.o
	${CC} ${CFLAGS} sequence.c seq_lib.o -o sequence.o

seq_lib.o: seq_lib.c seq_lib.h
	${CC} ${CFLAGS} -c seq_lib.c

.PHONY: clean all main

clean: 
	rm -f *.o *.a *.exe stringProg
run:
	./stringProg